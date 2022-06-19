# Digital Sample & Hold

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Digital_Sample_And_Hold/IMAGES/front.png" height="500" />

A handy dandy Attiny84 based CV module with more features than parts, for the SDIY enthusiast.

## Features
* Digital Samle & Hold; Sample CV sources without the "droop" of a traditional analog Sample & Hold.
* Track & Hold; When the module is in "tracking" state the output signal is exactly similar to the input until you hold it.
* Glide knob; Create glide effects on the outgoing CV signal.
* Quantisation; Turn quantisation on to create stepped output voltages. 1/12 V each.
* Random out; The module generates random output CV when no cable is inserted into the "IN-Jack". Attenuate the range of this random output CV.
* Probability; When a cable is inserted into the "signal-in-jack" the noise knob is reused for setting the probability. Change the probability of the incomming clock signals between 0% to 100%.
* Momentary or Toggle clock; 
  * When in S&H mode and 1:1 the incomming clock pulses directly set the next sample.
  * When in S&H mode and 1:2 the incomming clock pulses are divided by two. 
  * When in T&H mode and 1:1 a high sets the module in "Hold" state and a low sets the module in "Track" state.
  * When in T&H mode the 1:2 the incomming clock pulse toggle between "Track" and "Hold".
* A button for manual clock inputs.
* A buffered out; Get a nice copy of the origial signal.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Digital_Sample_And_Hold/IMAGES/front_image.jpg" height="500"/>

## Build Notes
* This module has build-in ISP (in system programmer) headers to connect with a programmer and to upload the code to the Attiny84. For this I creates a little adapter on a piece of perfboard so I could connect it wiht my DIY Arduino Nano programmer. See [Attiny Programmer](https://github.com/PierreIsCoding/sdiy/tree/main/Attiny_Programmer)   
* Please note the extra wires underneath the IC's. 


<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Digital_Sample_And_Hold/IMAGES/programming.jpg" height="500" />



