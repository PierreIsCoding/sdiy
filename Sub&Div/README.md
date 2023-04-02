# SUB & DIV

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Sub%26Div/images/explain.png" width="250" />

SUB & DIV is a 4HP wide sub octave generator and clock divider with CV.

## Manual
1. Sub oscillator mix knob.
2. Division selection and bias knob.
3. Input CV attenuator.
4. Selected division.
5. CV input jack.
6. Oscillator input jack.
7. Mixer output jack.
8. Clock output jack.
9. Clock reset button.

## Sub Octave Generator.
With SUB & DIV you can beef up your vco signals with sub octaves. A sub octave is technically a frequency division and musically one or more octave(s) lower, than the original signal you used for it. 

To use the module as a sub octave generator:
* Insert a vco signal into the OSC input jack (6).
* Listen to the MIX output (7).
* Crossfade between your inserted signal and sub octave with the sub oscillator mix knob (1).
* Change the selected division with the DIV knob (2).

SUB & DIV allows you to select 4 divisions/ sub octaves. The selected one is visualised with the 4 leds.

## Clock Division.
The clock division is quite similar to the sub octave generation, however you would normally use slower signals into the OSC input jack. 

To use the module for clock division:
* Insert an LFO or any clock source into the OSC input jack (6).
* Connect external modules like drum sounds to the DIV output jack (8).
* The sub mix knob (1) has no effect on this ouput.
* Change the selected division with the DIV knob (2).
* To restart the counting at zero press the reset button (9). 

The four leds (4) also change brightness at the speed of the clock division. You won't notice this for fast clocks like your VCO, but for slower clocks you will.

## CV
The main trick of this module is CV! I don't know other modules like this with CV do you? With this you can change the selected clock division / sub octave.
* Insert a cv into the CV input jack (5).
* Attenuate this CV signal (3).
* Bias this CV signal with the DIV knob (2).

## Tips

* Use other clock signals into the CV input and attenuate those to your desired range.
* Use CV at audio rate to create cool effects. At the right speed you can listen to mutliple octaves at the same time.
* Insert an signals into the CV input to just visualize their wave form.
* Connect the mix output (7) with the CV input (5). You will get new and interesting rhythms !

That's all! Have fun.

# Build Notes.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Sub%26Div/images/sub_front.jpg" width="600" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Sub%26Div/images/sub_back.jpg" width="600" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Sub%26Div/images/sub_side.jpg" width="600" />

Tips:
* This module is pretty dense. Therefore there isn't space for a shrouded power header. I used a red male header for the -12V power line, so it is always obvious how to push in your IDC connector correctly.
* The trimpot (RV3) is optional. Use R21 if you don't use the trimpot and vica versa, so don't use both.
* If you use the trimpot (RV3) center the Sub oscillator mix knob (1) and match the gain of your favorite VCO in and the sub oscillator. You might change this to your own taste since.


