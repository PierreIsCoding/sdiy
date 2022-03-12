# Quantizer

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Quantizer/images/labels.jpg" height="300" /><img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Quantizer/images/20220312_134829.jpg" height="300" />     


## Features
- Quantizes incomming cv signals to a 7 scales, 4 triades or octaves.
- Trigger out with led for detecting changes. Every time an incomming cv-signal gets quantized to a new signal the trigger out sends a pulse for external envelope generators etc.
- "Sample and Hold" mode. When a jack is inserted into the clock input the device goes automatically into S&H mode. Here the quantizer outputs only a new quantized value after a new clock input.
- Add glide to the ouput cv.
- Change on the fly how the module receives bipolar and unipolar input cv-signals.
- The leds represent piano keys.

## Files

## How to use it;



## How to use it; example 1 (LFO)
- Connect the output cv with the 1V/oct of your favourite VCO.
- Insert a bipolar LFO into the cv-in of the module.
- Press the UP and DOWN buttons together. Now the module goes into bipolar mode.
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


# Buildnotes

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Quantizer/images/20220312_135047.jpg" height="500" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Quantizer/images/20220312_135254.jpg" height="500" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Quantizer/images/20220312_135047.jpg" height="500" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Quantizer/images/20220312_135308.jpg" height="500" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Quantizer/images/cut.jpg" height="500" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Quantizer/images/tri_state.PNG" height="500" />
