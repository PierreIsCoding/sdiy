# Knock Knock

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Knock_Knock/images/Front.png" width="110" />

Knock Knock is a simple to use, only 6HP wide, and powerfull 5 channel euclidian rhythm generator, for creating interesting patterns on the fly. What are euclidean rhythms? [Link Wikipedia](https://en.wikipedia.org/wiki/Euclidean_rhythm)

# Manual

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Knock_Knock/images/explain_1.png" width="300" /> 

1. Play button.
2. Division button.
3. Length button.
4. Shift button.
5. Clock button.
6. Clock input jack.
7. Five output jacks.
8. Rotary encoder and button.
9. LED bar.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Knock_Knock/images/explain_2.png" width="300" /> 

10. 1-PPQ.
11. Main clock speed in BPM (Beats per minute).
12. 24-PPQ
13. Channel or step number.

## Basic Operation.
As a starter Knock Knock has its own internal clock, so you don't need to feed it any external one. 

If the module runs you will see in the LED bar (9) the ON-steps, and the current position of the pattern moving downwards. The ON-steps are visualised with a lower LED brightness, and the current position is visualised with a higher LED brightness. To start or stop all rhythms simply press the play button (1).

To change the pattern of your active channel do the following:
1. Turn the rotary encoder (8) (without pressing any other button) left or right to decrease or increase the amounth of ON-steps in the pattern.
2. Press the division button (2) and rotate the encoder (8) to change the clock division. Completely up is the fastest without a division. Going downward the speed of the active channel is a division of the main clock: /2, /4, /8, /16, /32, /64 etc .
3. Press the length button (3) and rotate the encoder (8) to change the length of the pattern. 
4. Press the shift button (4) and rotate the encoder (8) to move the pattern up or down.

While pressing any of these buttons you see the current state of that parameter visualised in the LED bar.

## Clock
Knock Knock detects if you have inserted a cable into the clock input jack (6). Depending on if you have inserted a cable or not the module reacts slightly differently:
* Pressing the clock button (5) with NO cable inserted lets you set the speed of the module by rotating the encoder (8). Also have a look at clock speed labels (11).
* Pressing the clock button (5) with A cable inserted lets you set you the PPQ (Pulses Per Quarter) of the module by rotating the encoder (8). This is usefull if you have something that generates clock pulses with a 24PPQ like MIDI does.
* All other settings work the same in each mode.

Keep in mind that the internal clock of Knock Knock is not highly accurate BPM wise (Beats Per Minute). If you want an accurate BPM use an external clocks instead.

## Resetting 
By pressing both the shift button (4) and the clock button (5) you reset all patterns to their starting position. This is handy for syncing different clocks.

Tip for synchronisation: 
* If you want to sync Knock Knock with external gear use an external clock.
* Pause your external clock. Knock Knock also stops now.
* Reset Knock Knock and your other gear, so all the clocks are in their starting position.
* Start your external clock again.

## Change The Active Channel
To view and edit a different active channel please press first the rotary encoder (8). Yes, the encoder can be used as a button as well ! While pressing the encoder (and without rotating it) press secondly one of the small buttons (1-5) to change the active channel. 

That's all. Have fun!

# Build Notes

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Knock_Knock/images/knock_front.jpg" width="600" /> 
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Knock_Knock/images/knock_back.jpg" width="600" /> 
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Knock_Knock/images/knock_side.jpg" width="600" /> 

## Files
The following files are in this folder:
* Knock_Knock_Code; Arduino Code.
* Knock_Knock_Schematic (pdf).
* Knock_Knock_BOM; Part list (Excel).
* Spacer_10mm.stl; A 3D file for 3d printing the standoff.
* iBom file for part placement. Download this file and open this file from your file explorer.

## Led bar

Before solderig the LED bar:
* Make sure you have the correct orientation, else it won't work. The PCB has a hint for how the LEDS should be oriented. Check with your multimeter before soldering.
* Make sure the LED bar is flush with the front panel.

## Programming the Attiny84
* For uploading you need a programmer. I used an Arduino nano as ISP programmer, and the Arduino IDE. Example on how follows...else theck the web ;)
* The module needs to be powered via your Eurorack for the uploading process.
* Please make sure you select "20 MHZ External CLOCK" !
* Don't forget to burn bootloader before uploading the code.








