# VCA Ducker
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCA_Ducker/images/front_small.jpg" width="400" />

The VCA Ducker helps you to push your kickdrum through a busy mix with a technique called "ducking". Ideal for techno music where your kickdrum needs to get heard! 

The module only requires you to insert your kickdrum and separately your main audiomix. The module converts then the kickdrum-audio into an envelope-cv, also called an "envelope-follower". That envelope pushes the volume of the main mix down exactly when you hear the kickdrum. With this technique the kickdrum simply gets all the space it requires whenever it is represented instead of getting overpowered by all the other (noisy) audio signals.

But wait.. why not use a standard VCA, envelope generator and some cv-inverter for this? Simply because the Ducker makes it super easy for you. You only need a kickdrum and a main audiomix. Thus this is an all-in-one-module that serves you all the control you need to master your ducking-game. 


## Features
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCA_Ducker/images/labels.png" width="200" />

* Convert an audio signal into an 'envelope follower' or 'trigger envelope'.
  * A trigger envelope is not affected by the sustain of a signal as is with the envelope follower. This is ideal if you like to create shorter envelopes.
* Alternatively convert an external gate signal into a simple trigger envelope.
* Change the decay of the envelope signal.
* Use that envelope to increase (standard VCA operation) or decrease (ducking operation) the main signal.
* Alternatively use any external cv source to control the VCA.
* Mix the kickdrum together with the main signal with a dedicated knob.
* Toggle between kick only, kick mixed with audio signal, or audio signal only.

## How it works
[please double click the images to see them in more detail, or alternatively open the schematic pdf]

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCA_Ducker/images/envelopes.png" width="1200" />

An envelope follower continues to 'follow' the shape of the audio signal where a trigger is always spikey and short.

### Section 1: Half wave precision rectifier
[Note the labels show connected traces from different boards. Thus for example: KICK_IN_F and KICK_IN_B are actually connected]
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCA_Ducker/images/rectifier.png" width="1200" />

Here the kickdrum signal is converted into a fully possitive signal. This helps later stages to convert the kickdrum signal into a(n) gate and/or envelope.

### Section 2: Signal to gate converter
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCA_Ducker/images/gate_convert.png" width="1200" />

With SW1 you decide how the signal from section 1 is further developed. As trigger envelope or as envelope follower.
* When you set it to 'trigger' this section converts the signal into a clean gate first (one single on off signal). This is done by actually a second envelope follower that is set by C1, RV3 and comparator U4A. 
  * Note that when an external gate is applied C1 and RV1 have no affect. 
  * Also note that RV3 is a trimpotentiometer that you have to calibrate in order to get a clean gate at this stage. Set the decay of this calibration envelope follower too short and you will get multiple gates from one kick and thus multiple triggers on the end. Set it too long and the trigger won't get a falling edge on time before the next kickdrum comes in.
* When you set SW1 to 'envelope' the kickdrum signal will be converted to an envelope signal from which you can control its decay with RV6.

### Section 3: Gate to trigger converter [trigger path]
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCA_Ducker/images/trigger.png" width="1200" />

### Section 4: Decay
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCA_Ducker/images/envelope_follower.png" width="1200" />

Set either the decay of the trigger envelope or envelope follower.

### Section 2: Attenuverter
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCA_Ducker/images/attenuverter.png" width="1200" />

The incommig (envelope) CV can be scalled, inverted and biased. This is a delicate play between the bias knob and the attenuverter knob. 
Link to simulation:  https://tinyurl.com/2nnkwsqm

### Section 4: VCA
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCA_Ducker/images/VCA.png" width="1200" />

A transistor based VCA.

### Section 4: Mix / Mute
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCA_Ducker/images/spdt.png" width="1200" />

This section is based on a basic crossfader but instead of using a traditional potentiometer to pan between two signals a SPDT switch is used. This configuration allows you to have three different signal outputs depending on the position of the switch!
* UP: kick only.
* CENTER: mix of kick with audio signal.
* DOWN: audio signal only.

## Build Notes
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCA_Ducker/images/back_small.jpg" width="400" />

