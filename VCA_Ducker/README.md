# VCA Ducker
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCA_Ducker/images/front_small.jpg" width="400" />

This module helps you to push your kickdrum through a bussy mix with a technique called "ducking". Ideal for techno music where your kickdrum needs to get heard! 

For this the module only requires you to insert your kickdrum and separately your main audiomix. The module converts then the kickdrum-audio into an envelope-cv, also called an "envelope-follower". That envelope pushes the volume of the main mix down exactly when you hear the kickdrum. With this technique the kickdrum simply gets all the space it requires whenever it is represented instead of getting overpowered by all the other (noisy) audio signals.

But wait.. why not use a standard VCA, envelope generator and some cv-inverter for this? Simply because this module makes it super easy for you. You only need a kickdrum and a main audiomix. Thus this is an all-in-one-module that serves you all the control you need to master your ducking-game. 


## Features
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCA_Ducker/images/labels.png" width="200" />

* Convert an audio signal into an 'envelope follower' or 'AD envelope'.
  * An AD envelope (attack-decay) is not affected by the sustain of a signal as is with the envelope follower. This ideal if you like to create shorter envelopes.
* Alternatively convert an external gate signal into an AD envelope.
* Change the decay of the envelope signal.
* Use that envelope to increase (standard VCA operation) or decrease (Ducking operation) the main signal.
  * For this an attenuverter is present that changes the incomming (envelope) cv.
* Alternatively use any external cv source to control the VCA.
* Mix the kickdrum together with the main signal with a dedicated knob.
* Toggle between 'kickdrum + main signal mix', 'solo kickdrum', or 'solo main signal'.

## How it works
The module basically has two main sections: An envelope generator and an VCA.

### Section 1: Envelope Generator
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCA_Ducker/images/rectifier.png" width="1200" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCA_Ducker/images/gate_convert.png" width="1200" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCA_Ducker/images/trigger.png" width="1200" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCA_Ducker/images/envelope_follower.png" width="1200" />

### Section 2: VCA
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCA_Ducker/images/attenuverter.png" width="1200" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCA_Ducker/images/VCA.png" width="1200" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCA_Ducker/images/spdt.png" width="1200" />



## Build Notes
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCA_Ducker/images/back_small.jpg" width="400" />

