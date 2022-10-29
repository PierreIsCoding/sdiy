# Quantizer

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Quantizer/images/labels.jpg" width="400" /><img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Quantizer/images/20220312_134829.jpg" width="300" />     

Another Quantizer? Yes! This project represents a powerfull, precize and flexible quantizer with not so many components and only 6HP wide. It lets you quantize cv-levels with a 16-bit pwm based DAC using only two pins and the internal timers of an Arduino Nano. Musically it really can change your game. So why not build this one for yourself?

## Features
- Quantizes incomming cv signals to 7 scales, 4 triades or octaves, with a 16-bit precision output.
- Trigger output. Every time an incomming cv-signal gets quantized to a new signal the trigger out sends a pulse for external envelope generators etc.
- A "Sample and Hold" mode. When a jack is inserted into the clock input the device goes automatically into S&H mode. In this mode the quantizer only outputs a new quantized value after receiving the next clock pulse.
- Add glide to the output cv.
- Change on the fly how the module receives bipolar and unipolar input cv-signals. 
  - Uni-polar: 0V to +5V.
  - Bi-polar: -3.5V to +5V.
- The leds represent piano keys.

## Attention
- Building and using this module is on your own risk.
- This module does not have protecion diodes for connection the power wrongly. So please be carefull.
- Be carefull of the orientation of certain components like the diodes. See image below.

## Files
- Files for etching this project on a single board and single layer.
- The code for an Arduino Nano.
- Front panel dimensions.
- File for labels....updated soon.
- iBom.

## How to use it; example 1 (LFO)
- Connect the output cv with the 1V/oct of your favourite VCO.
- Insert a bipolar LFO into the cv-in of the module.
- Press the UP and DOWN buttons together. Now the module goes into bipolar mode. Notice that in unipolar mode negative values will be rejected by the module, while in bipolar mode both negative and positive values will be quantized and scaled accordingly.
- Change the scale by keep pressing the SCALE button while tapping either the UP ow DOWN buttons

## How to use it; example 2 (sequencer)
- Connect the output cv with the 1V/oct of your favourite VCO.
- Insert a cv-sequencer into the cv-in of the module.
- The module is in unipolar mode by default. If it is not press the UP and DOWN buttons together again.
- Check if the lowest led is on. This led represents a C-note. Tune your VCO accordingly.
- Change the scale by keep pressing the SCALE button while tapping either the UP ow DOWN buttons.
- Transpose the output by keep pressing the TRANSPOSE button while tapping either the UP ow DOWN buttons.

## How to use it; example 3 (sample and hold)
- Connect the output cv with the 1V/oct of your favourite VCO.
- insert a clock signal into the clock-input.
- insert a noise source into the cv-in.
- Press the UP and DOWN buttons together. Now the module goes into bipolar mode
- Change the scale by keep pressing the scale button while tapping either the UP ow DOWN buttons.
- Connect the output trigger to an envelope generator which opens and closes the VCO signal.

## How it works; leds
There are many ways to drive leds with a microprocessor. One of the less known ways is using a technique called "Charlie Plexing". I really wanted to try out this techniue once and I found this project the perfect candidate for it. The benefit of this technique is that it only requires 4 digital pins for managing 12 leds. Check the simulation [here.](https://tinyurl.com/ybuk2pdh)

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Quantizer/images/tri_state.PNG" width="600" />

The maximum usable leds is calculated by 2 * ( [number of pins] nCr 2 ). Check out my code class, since it can be used for other numbers as well. 
See this [wiki](https://en.wikipedia.org/wiki/Charlieplexing) for more info about this technique.

# Buildnotes

## Uploading code
Uploading code to your arduino can be tricky since doing it wrong can potentially damage your computer or your module. Let's say you have inserted the Arduino in the module, consider these things:
-  When you directly connect the Arduino of the module to your computer your usb turns on the Arduino, but not the rest of your module, beacuse the other parts need that special -12V and +12V of your synth power supply. This means that the Arduino sends voltages to the opamp while it is currently turned off. Opamps do not like that.
- When your synthesizer powers your module with the inserted Arduino, and on the same time you also connect that Arduino to your usb-port you can damage your USB-port!
- So the best and simple way is to remove the Arduino, upload the code, disconnect your usb, insert the Arduino into the module and turn the module on with your synth power supply.
- Or make a special cable that only connects the USB-data pins to your Arduino but NOT the USB-power. Now you can upload the code while powering the module from your synth.

## Calibration [optional]
- Technique 1:
  - Measure the output voltage.
  - Use the transpose function to change the output level from 0V to 4V.
- Technique 2:
  - Connect the output CV to a well calibrated and warmed up VCO.
  - Use a tuner. I really like the Universal Tuner app on Android. 
  - Tune the lowest note to C1.
  - Check if the highest note is a C5. Use the transpose function for this.
  - The advantage of this technique is that the tuner is more precise than a cheap multimeter.
- Adjusting:
  - See the "Globals section" in the quantizer code.
  - If the tracking overshoots decrease the "semitone" parameter.
  - If the tracking undershoot increase the "semitone" parameter.

## LEDs
- Take extra notice of the orientation of the leds. Please consult the iBom or f-silkscreen pdf. If one is off multiple leds will turn on unwantedly.
- Solder the leds before solder the female header pins for the Arduino.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Quantizer/images/20220312_135047.jpg" width="400" /> <img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Quantizer/images/20220312_135308.jpg" width="400" />


## Bypass caps
- If your bypass caps (C1 and C2) are too large bent them horizontally. See image. 

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Quantizer/images/20220312_135254.jpg" width="600"" />


## 1N5817 and 1N4148
- Make sure D2 and D4 are oriented correctly. See image below.
- Solder those jack afterwards.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Quantizer/images/orientation.png" width="600" />

## Power connector
- I used for this project male header pins with angled pins, sourced from Reichelt. However mine were to large, so I had to cut them smaller. See image below.
- Add a red mark for your -12V.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Quantizer/images/cut.jpg" width="600" />

## Improvements
- Lowering R16 to let's say 100 ohm, or even remove it lowers the output impedance. Do this if the modules you connect the output to have a relatively low input impedance. 


