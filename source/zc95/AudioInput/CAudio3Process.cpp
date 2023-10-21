/*
 * ZC95
 * Copyright (C) 2022  CrashOverride85
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#include <stdlib.h>
#include "../globals.h"
#include "CAudio3Process.h"
#include "pico/util/queue.h"

/* Audio3 mode
 *  Attempt to process audio in a vaguely similar way to the Audio3 mode of a 312b box. 
 * 
 * Basic approach:
 *  - Every time the audio signal cross zero, trigger a pulse (but limit to one pulse every 4ms, so 250Hz)
 *  - Change the output power based on volume. Use the difference between min and max value over a 341 sample capture as the volume
 * 
 * Complicating factors:
 *  - Audio is captured via DMA in blocks of about 341 (1/3 of 1024) samples per channel, therefore by the time this class gets the
 *    audio data, the first sample is going to be around 16ms old (at best)
 *  
 *  - This processing is happening on core0, which deals with the UI and, well, most things. So the delay between these processing 
 *    functions is going to vary a bit. However, we know fairly accurately when then the capture finished, and how long it was. 
 *    So we can use that information to effectively schedule pulses to happen 25ms after the audio event that caused it. The downside 
 *    is that this introduces 25ms of latency.
 *    These scheduled pulses get picked up by core1 which has almost nothing else to do, so jitter should be kept down.
 */

CAudio3Process::CAudio3Process(uint8_t output_channel, CAnalogueCapture *analogue_capture)
{
    if (output_channel >= MAX_CHANNELS)
    {
        printf("CAudio3Process::CAudio3Process(): invalid output channel: %d\n", output_channel);
        output_channel = 0;
    }
    _output_channel   = output_channel;
    _analogue_capture = analogue_capture;
}

void CAudio3Process::process_samples(uint16_t sample_count, uint8_t *buffer, uint8_t *out_intensity)
{
    uint32_t capture_duration_us = _analogue_capture->get_capture_duration();
    uint64_t capture_end_time_us = _analogue_capture->get_capture_end_time_us();
    double sample_duration_us  = (double)capture_duration_us / (double)sample_count;

    uint64_t sample_time_start_us = capture_end_time_us - capture_duration_us;

    // Figure out min, max and average (mean) sample values
    uint32_t total = 0;
    int16_t min = INT16_MAX;
    int16_t max = INT16_MIN;
    for (uint16_t x = 0; x < sample_count; x++)
    {
        if (buffer[x] > max)
            max = buffer[x];

        if (buffer[x] < min)
            min = buffer[x];
    
        total += buffer[x];
    }
    uint8_t avg = total / sample_count;

    // Noise filter. If no/very weak signal, don't continue (don't want to trigger on noise)
    if (abs(min-avg) < 5 && abs(max-avg) < 5)
    {
        *out_intensity = 0;
        return;
    }

    *out_intensity = max - min; // crude approximation of volume

    for (uint16_t sample_idx=0; sample_idx < sample_count; sample_idx++)
    {
        uint16_t sample_time_offset_us = (sample_duration_us * (double)sample_idx);

        // Call process_sample with the time the sample happened, and the value -128 to +128 (or thereabouts)
        process_sample(sample_time_start_us + sample_time_offset_us, avg-buffer[sample_idx]);
    }
}

void CAudio3Process::process_sample(uint64_t time_us, int16_t value)
{
    pulse_message_t pulse_msg;

    // Look for crossing zero
    if (value > 0 && _last_sample_value <= 0)
    {
        uint64_t zero_cross_time_us = _last_sample_time_us + get_zero_cross_time(0, _last_sample_value, time_us - _last_sample_time_us, value);

        // At most one pulse every 2.6ms
        uint64_t pulse_time = zero_cross_time_us + (1000 * 25);  // 25ms in future
        if (pulse_time - _last_pulse_us > 2666)
        {
            // do pulse
            pulse_msg.abs_time_us = pulse_time;
            pulse_msg.neg_pulse_us = DEFAULT_PULSE_WIDTH;
            pulse_msg.pos_pulse_us = DEFAULT_PULSE_WIDTH;

            if (!queue_try_add(&gPulseQueue[_output_channel], &pulse_msg))
            {
                printf("gPulseQueue FIFO was full for chan %d\n", _output_channel);
            }

            _last_pulse_us = pulse_time;
        }
    }

    _last_sample_value = value;
    _last_sample_time_us = time_us;
}

// Use linear interpolation to have a better guess at the zero cross time
uint64_t CAudio3Process::get_zero_cross_time(uint64_t time0, int16_t value0, uint64_t time1, int16_t value1)
{
    if (value0 == 0)
        return time0;

    if (value1 == 0)
        return time1;

    if ((value0 > 0 && value1 > 0) || (value0 < 0 && value1 < 0))
    {
        // no zero cross!
        printf("get_zero_cross_time: ERROR - no zero cross. (%llu, %d) => (%llu, %d)\n", time0, value0, time1, value1);
        return value0;
    }

    double slope = ((double)value1 - (double)value0) / ((double)time1 - (double)time0);
    uint64_t zero_crossing_time = time0 - (value0 / slope);

    return zero_crossing_time;
}
