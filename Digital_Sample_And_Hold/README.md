# Digital Sample & Hold

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Digital_Sample_And_Hold/IMAGES/front.png" height="500" />

A handy dandy Attiny84 based CV module with more features than parts. For the SDIY enthusiast.

## Features
* Digital Sample & Hold; Sample bipolar CV sources without the "droop" of a traditional analog Sample & Hold. Ideal for longer back melodies.
* Track & Hold mode; When the module is in "tracking" state the output signal is exactly similar to the input until you "hold" it.
* Glide knob; Create glide effects on the outgoing CV signal.
* Quantization; Turn quantization on to create stepped output voltages quantized to 1/12 volts.
* Random out; The module generates random output CV when no cable is inserted into the "signal-in-jack". Attenuate the range of this random CV between 0 and 7 volts.
* Probability; When a cable is inserted into the "signal-in-jack" the noise knob is reused for setting the probability. Change the probability of the incomming clock signals between 0% to 100%.
* Momentary or Toggle clock; 
  * When in S&H mode and 1:1 the incomming clock pulses directly set the next sample.
  * When in S&H mode and 1:2 the incomming clock pulses are divided by two. 
  * When in T&H mode and 1:1 a high clock input sets the module in "Hold" state and a low sets the module in "Track" state.
  * When in T&H mode the 1:2 the incomming clock pulse toggle between "Track" and "Hold".
* A button for manual clock inputs.
* A buffered out; Get a nice copy of the origial signal.
* A Gate out; Get a gate signal set by the probability and the clock mode.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Digital_Sample_And_Hold/IMAGES/front_image.jpg" height="500"/>

## How It Works
The goal for me, appart from having the features the module comes with, was to experiment with the Attiny84 by designing a module for it. The Attiny84 is a powerfull little MCU, small and cheap. By adding an external 16MHz crystal its as fast a an Arduino Nano, or even better you can make it faster by using an 20MHz. The formfactor is ideal for small SDIY projects. Especially if you don't need al those pins.

For the DAC (digital to analog converter) I used the same PWM setup as with my quantizer module, since it just works great. For the ADC (analog to digital converter) I wanted to use something else. The onboard ADC is just 10 bit. That is not much if you want to use it for a more precise and wide range bipolar Sample & Hold module. I also didn't want to use a dedicated chip for it, since those  require a lot of extra programming, more pins and it can interfere with the ADC. I figured that the most simple solution would be hack... Using the 16 bit PWM-based output for finding the input!

## Build Notes
* This module has build-in ISP (in system programmer) headers to connect with a programmer and to upload the code to the Attiny84. For this I creates a little adapter on a piece of perfboard so I could connect it wiht my DIY Arduino Nano programmer. See [Attiny Programmer](https://github.com/PierreIsCoding/sdiy/tree/main/Attiny_Programmer)   
* Please note the extra wires underneath the IC's. 


<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Digital_Sample_And_Hold/IMAGES/programming.jpg" height="500" />



