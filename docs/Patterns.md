# Patterns

**Note**: Any pattern in the list/menu prefixed with `(!)` should not be used above the waist, as channel isolation - where only one channel pulses at the exact same moment - is disabled.

## Waves
Gradually increasing and decreasing intensity on all channels at different rates. Varying intensity is achieved by altering the gap between pulses rather than changing the power level.
Can NOT be used with shock collars.

### Menu options
* Frequency - controls how fast the intensity increases/decreases. 1-64, lower is faster.



## Orgasm
Pleasurable increasing and decreasing sensation, achieved by varying both pulse width and frequency. A full cycles takes a few minutes.

### Menu options
* Frequency - controls how fast the intensity increases/decreases. 15-255, lower is faster.



## Climb
Gradually increasing intensity.

### Menu options
* Frequency - controls how fast the intensity increases/decreases. 15-255, lower is faster.



## Phasing 2
An intensity ramp program, note that this is not triphase.

### Menu options
* Pulse Speed 



## Stroke
Channels 1+3 pulse to full set power, gradually reduce, then switch off. Channels 2+4 gently pulses around the present power level.


### Menu options
* Speed - lower is faster



## Rhythm
Outputs are enabled/disabled, with both the frequency and pulse widths changing.

### Menu options
* Spikeyness



## Torment
Short, activation of channels 1+3 and 2+4 and random intervals.

### Menu options
* (none)



## Combo

A mix of difference effects

### Menu options
* Speed - lower is faster



## Random 2

A mixture of different randomised effects, including varying pulse widths, frequency and power.

### Menu options
* (none)



## Intense
Continuous output on channels 1 & 2, with 3 & 4 switching/toggling. 

### Menu options
* Toggle delay - Delay between switching from channel 3 to 4 and back 100ms - 1000ms
* Chan 1&2 freq - Output frequency of channel 1 & 2
* Chan 3&4 freq - Output frequency of channel 3 & 4



## Toggle
Switches between Channel 1+3 and 2+4. 
Can be used with shock collars.

### Menu options
* Speed - controls how fast it switches between 1+3 and 2+4. Higher is faster.
* Pulse/Cont.
  - Pulse - gives a brief (100ms) pulse on each channel
  - Continuous -  keeps the channel on until it's time to switch to the next



## RoundRobin
Cycles through channels 1->2->3->4.
Can be used with shock collars.

### Menu options
* Delay - How long (in ms) to wait before switching to the next channel. Lower is faster.
* Pulse/Cont.
  - Pulse - gives a brief (100ms) pulse on each channel
  - Continuous -  keeps the channel on until it's time to switch to the next



## TENS
Approximation of TENs style output, with all channels outputting the same.
Can NOT be used with shock collars.
If the aim is solely to achieve absolute maximum intensity, this is the mode to use.

### Menu options
* Pulse width - Pulse width in microseconds. Lower is weaker. Most other modes use 150us.
* Frequency - Frequency in Hz of signal. Most other modes use 150Hz



## Triggered Climb
Power increases on channels 1+2 until a remote button is pressed, then a pulse is delivered on channels 3+4, and 1+2 is reset. Every time the button is pressed the shock delivered on channels 3+4 is increased.
Suggest bipolar nipple clamps for channels 3+4, 1-2 anywhere else, then handing the button to the person connected.
Channels 3+4 can be shock collars. Unlike Climb, this achieves increasing intensity by varying the power level (as can be seen on the display).

### Menu options
* Climb Duration - Approximately how long, in seconds, it takes to reach full power on channels 1+2
* Shock increment by - How many percentage points to increase the power level on channels 3+4 by every time the remote button is pressed (e.g. if the current power was 20%, a setting of "10" would mean increase from 20% -> 30%). Can be set to zero.
* Shock duration - How long, in milliseconds, should the shock delivered on channels 3+4 last.
* Soft button "Reset" - Reset power levels back to zero

### Extra hardware required
A remote button wired to trigger input 1.


## Fire
When either soft button or a remote button is pressed, trigger a shock on all channels.
Can be used with shock collars.

### Menu options
* Mode
  - Continuous - shock is delivered for as long as the button is held down
  - Pulse - a shock of preset (see below) length is delivered when the button is pushed
* Pulse length - When in pulse mode, how long, in milliseconds, the pulse should be
* Soft button "Fire" - deliver shock

### Extra hardware required
Optional: A remote button wired to trigger input 1 can be used as an alternative to the Fire soft button



## Audio Threshold
Only available if audio enabled. 
If the volume goes above the level set, triggers the output on all 4 channels. Intended to be used with a microphone.

### Menu options
* Audio trigger - Shows mini spectrum analyzer, with a horizontal red line that can be moved up/down using the adjust dial. Whenever the volume is loud enough to cross the line, the output is triggered.

![Audio Threshold]

### Extra hardware required
Audio output board fitted and audio source



## Audio Wave
Only available if audio enabled. 

Well suited to estim audio tracks, with the audio [configured](./AudioInput-Operation.md) for line level input. It works with a triphase setup, where two channels are connected with a common electrode. Both frequency and volume of audio input affects the output.

The left audio channel is output on channels 1+2, the right on 3+4. It probably makes most sense to only use channel 1+3 (or 2+4) with this mode. 

*Warning*: Enables triphase mode / disables channel isolation, so should not be used above the waist. 

### Menu options
* Stereo view - Shows two wave forms - for left and right channels. 
* Triphase view - Shows three wave forms - left, right and a virtual / calculated triphase effect.

Note that the selected view does not affect the output, and the indicated triphase effect will only be felt if channel 1+3 (or 2+4) have a common electrode. The adjust dial changes the gain, which is displayed on the thin yellow bar at the bottom of the waveform display.

![Audio Wave Stereo]

### Extra hardware required
Audio output board fitted and audio source



## Audio intensity
Only available if audio enabled. 

Intended for use with a microphone (see [audio config](./AudioInput-Operation.md) to switch to mic mode), but also allows for stereo input. 

The louder the sound, the greater the output. Not much more to this pattern.

### Menu options
* Mono - Shows one waveform corresponding to the left channel, and all output channels are the same intensity depending on the input from the left channel
* Stereo - Shows two waveform corresponding to the left and right channels. Output channels 1+2 have an intensity corresponding to the left channel, and channels 3+4 have an intensity corresponding to the right channel

The adjust dial changes the gain, which is displayed on the thin yellow bar at the bottom. 

![Audio intensity mono]

### Extra hardware required
Audio output board fitted and audio source



## Audio virtual 3
Only available if audio enabled. 

Well suited to estim audio tracks, with the audio [configured](./AudioInput-Operation.md) for line level input. Generates a 3rd channel from the difference between the left and right channels, and outputs it on channel 3 (channel 4 is not used).

Unlike the "Audio Wave" pattern, this does not disable channel isolation, so could be used above the waist with suitable electrode placement (usual warnings still apply). This also means the channels should *not* be connected with a common electrode.

### Menu options
* Audio view - Shows three wave forms - left (channel 1), right (channel 2) and simulated "triphase" effect (channel 3).

The adjust dial changes the gain, which is displayed on the thin yellow bar at the bottom. 

![Audio virtual 3]

### Extra hardware required
Audio output board fitted and audio source



## Climb with pulse
Channels 1+2 behave the same as Climb, but when full intensity is reached, channels 3+4 are enabled/pulsed (depending on mode).
Channels 3+4 can be shock collars.

### Menu options
* Duration - Approximately how long, in seconds, it takes to reach full power
* Reset after climb
  - Yes - once full power is reached, start over
  - No - once full power is reached, stay there
* Pulse duration - how long, in milliseconds, the pulse delivered on channels 3+4 should be
* Soft button "Reset" - Reset power levels back to zero



## Predicament
Designed for predicament bondage scenarios. I'm finding this difficult to explain, so hopefully some examples will help.
Requires at least one input, ideally two, connected to the Trigger1 & Trigger2 ports. Based on the settings, delivers a shock
based on which inputs have been triggered.
For example, if two foot pedals are used, it can deliver a shock unless both are kept pressed (this is the default settings).

### Menu options
(assumes a Normally Open switch connected to both trigger inputs)
* Trigger1 invert - If "yes", the rest of the logic assumes that trigger1 is high if *not* pressed
* Trigger2 invert - As above, but for trigger 1
* Logic - "Or" or "And". If "Or", then either trigger being high will result in shock. If "And", both need to be high for a shock
* Output invert - Inverts the result of the above. I.e. if set to yes and "And" is set for Logic, then with both triggers high no shock is delivered

### Examples
| Trigger1 inv | Trigger2 inv | Logic | Output inv | Description  
| ------------ | ------------ | ----- | ---------- | ------------- 
| No           | No           | And   | Yes        | Default. Shock if either button not pressed
| No           | No           | And   | No         | Shock if both both buttons pressed
| No           | No           | Or    | No         | Shock if either button pressed
| Yes          | Yes          | Or    | No         | Shock if either button not pressed (different way achieving the default behavior)
| No           | No           | Or    | Yes        | If only one button connected to trigger1, shock when it is not pressed


### Extra hardware required
Yes - Sensors (e.g. foot pedals) connected to trigger inputs 1 & 2



## Shock choice
Gives the subject a choice of where to receive a shock, with no decision resulting in both (and for longer).

Requires a remote button connected to each of the two trigger inputs.

Every _Choice frequency_ seconds, channel 4 is briefly pulsed as an indication that a choice needs to be made (channel 4 being configured as a shock collar in "beep" mode works well). If button A is pressed, a 0.5s shock is delivered on channel 1. If button B is pressed a 0.5s shock is delivered on channels 2+3 (think a pair of bipolar nipple clamps). If no choice is made within 3 seconds, a 1s shock is delivered on channels 1, 2 & 3.
Each time a shock is delivered, the power level for that channel(s) is increased.

### Menu options
* Choice frequency - How often, in seconds, does a shock need to be delivered
* Shock increment by - How many percentage points to increase the power level on channels 3+4 by every time the remote button is pressed (e.g. if the current power was 20%, a setting of "10" would mean increase from 20% -> 30%). Can be set to zero.
* Soft button "Reset" - Reset power levels back to zero

### Extra hardware required
Remote buttons wired to trigger inputs 1 & 2.



## Camera Trigger
When the "Trigger" soft button is pressed, a shock is delivered on all channels, then a preset amount of time later ACC_IO_1 (pin 9 on the DB9 socket) is pulsed low. The intention is for this to be connected to a remote camera trigger.
At present, there is a hard-coded assumption that the camera will take 300ms to react to the pulse (this was the case for me using a cheap wireless camera trigger).
This is only really practical if the camera is in manual focus mode.

### Menu options
* Shock Length - how long, in milliseconds, the shock should be
* Camera delay - how long to wait after delivering the shock before taking a photo. Note that if set to zero, ACC_IO_1 will be pulsed low 300ms _before_ the shock is delivered: i.e. assuming a 300ms response time from the camera should mean that the photo is taken as the shock is delivered. For good results, 500ms seems to work well.
* Soft button "Trigger" - deliver shock and take photo

### Extra hardware required
Something connected to the accessory port that triggers a photo on pin 9 being pulsed low.



## Buzz
Intended to be used with a buzz wire game, probably better explained with a photo:

![Buzz wire game]

Whenever the wand touches the wire, a shock is delivered on channels **3+4**. The shock level increases as the wire is touched.
As an option to make things more interesting, channels 1+2 generates a slowly increasing power level, to hurry things along a bit - although probably not worth the effort of connecting.

The game finishes (all outputs go to zero) when the wand is used touch a contact at the end.

Note: This mode works well enough when just channel 3 (or 4) is used with a pair of pads.

### Menu options
* Game length - how long, in seconds, it takes channels 1+2 to reach full power
* Shock increment - How many percentage points to increase the power level on channels 3+4 by when the wand touches the wire. Can be set to zero.
* Initial shock power - percentage power level shock delivered on channels 3+4 starts at
* Min shock length - the minimum length, in milliseconds, of the shock delivered on channels 3+4. The shock will continue to be delivered for as long as the wand touches the wire, this only sets the minimum duration that applies to brief touches
* Soft button "Start" - starts the game: channels 1+2 are switched on and start increasing, and touching the wand against the wire results in a shock from channel 3+4

### Extra hardware required
Yes! Trigger input 1 needs a stereo Tip, Ring, Sleeve (TRS) 3.5mm plug wired as follows:
* Tip = wand (common ground)
* Ring = contact at end of wire (green)
* Sleeve = wire (red)


[Buzz wire game]: images/BuzzGame.jpg "Buzz wire game"
[Audio Threshold]: images/screen_pattern_audioThreshold.jpg "Audio Threshold"
[Audio Wave Stereo]: images/screen_pattern_audioWave.jpg "Audio Wave"
[Audio virtual 3]: images/screen_pattern_audioVirtual3.jpg "Audio virtual 3"
[Audio intensity mono]: images/screen_pattern_audioIntensity.jpg "Audio intensity mono"
