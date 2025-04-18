# Digital Sample & Hold

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Digital_Sample_And_Hold/IMAGES/front.png" width="600" />

A handy dandy Attiny84 based CV module with more features than parts. For the SDIY enthusiast.

## Features
* Digital Sample & Hold; Sample bipolar CV sources without the "droop" of a traditional analog Sample & Hold. Ideal for slower backtrack melodies.
* Track & Hold mode; When the module is in "tracking-state" the output signal matches exactly the input signal until you "hold" it.
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
* A buffered THRU; Get a nice copy of the origial signal.
* A Gate out; Get a gate signal set by the probability and the clock mode.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Digital_Sample_And_Hold/IMAGES/front_image.jpg" width="600"/>

## How It Works
The goal for me, appart from having the features the module comes with, was to experiment with the Attiny84 by designing a module for it. The Attiny84 is a powerfull little MCU, small and cheap. By adding an external 16MHz crystal it is as fast as an Arduino Nano, or even faster by using a 20MHz crystal. The formfactor is ideal for small SDIY projects. Especially if you don't need all those pins.

For the DAC (digital to analog converter) I used the same PWM setup as with my [quantizer moddule](https://github.com/PierreIsCoding/sdiy/tree/main/Quantizer), because that one just works great. For the ADC (analog to digital converter) I wanted to use something else. The onboard ADC is just 10 bit. That is not much if you want to use it for a more precise and wide range bipolar digital Sample & Hold module. I also didn't want to use a dedicated chip for it, since those require a lot of extra programming, more pins and it can interfere with the ADC. I figured that the most simple solution would be an hack... Using the 16 bit PWM-based output for finding the input!

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Digital_Sample_And_Hold/IMAGES/search.png" width="600"/>

The image above shows you what happens. The module finds the incomming signal by swirling around the signal with a search signal. At each step the module only needs to now if the search signal is bigger or lower than the incomming signal. Then the search signal subsequently narrows it down until the difference between the search signal and the incomming signal is smaller than the 16-bit DAC can actually produce. In other words it "found" the signal. This happens of course super fast in just a few milliseconds.

For the search signal I used the same signal as for the actuall output, because the Attiny84 doesn't come with more pins, and why not using that nice 16-bit DAC that is already available? The downside of this is that the search algoritm can be hearable just a tiny bit when the output cv signal is used for a VCO. Nevertheless a few milliseconds are almost not noticable and with some experimentation this will be further optimized. Otherwise adding a tiny bit of glide will remove this tiny noise at the beginning, or just use the gate out from the module icm an envelope generator and VCA, since the gate signal is generated after the search signal and thus the tiny noise will be cancelled out.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Digital_Sample_And_Hold/IMAGES/ADC_hack.png" width="900"/>

## iBOM
[iBom](https://htmlpreview.github.io/?https://github.com/PierreIsCoding/sdiy/blob/main/Digital_Sample_And_Hold/BOM/ibom.html)

## Build Notes
* Please note the extra wires underneath the IC's. See PDF's
* This module has build-in ISP (in system programmer) headers to connect with a programmer and to upload the code to the Attiny84. For this I created a little adapter on a piece of perfboard so I could connect it with my DIY Arduino Nano programmer. See [Attiny Programmer](https://github.com/PierreIsCoding/sdiy/tree/main/Attiny_Programmer)   
* When uploading the code set the Clock Division switch to 1:2 (downwards), else the programmer will be interfered.


<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Digital_Sample_And_Hold/IMAGES/programming.jpg" width="600" />



