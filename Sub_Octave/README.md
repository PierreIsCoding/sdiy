# Sub Octave Generator
This module creates a square wave sub octave for your DIY synthesizer. It is a simple means to create a two tone chord without adding another complex VCO. I personally use it often to create really fat sounds. 

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Sub_Octave/images/20210829_091935.jpg" width="400" />

## Features
* Select the sub chord with a rotary switch: -1,-2,-3,-4,-5,-6,-7.
* Transform each waveform into a square wave.
* Mix the sub chord with that square wave version.

## How it works
The module works with a clock divider. The pulses of a square wave signal are just divided into two or four etc. So a 1000hz becommes a 500hz, and a 120hz becommes a 60hz. Fun fact is that an octave lower is exactly half a frequency. Thus the octave is always is "sync" with the original source. That makes this thing simple but powerful.

## Toughts
* I also added a comparator knob. I did this because "back in the days" I had some VCO's that weren't AC coupled. But if you have nicely bipolar signels it is not really useful, enless you also want to use the module as a clock divider with unipolar clock signals. So I probably will remove that comparator knob in a later version for simplification and connect pin 12 of the TL074 to ground.
* The module mixes the sub octave with the square wave version of the original signal, but why not mixing it with the real original signal? So maybe add a switch so you can choose with what to mix the sub with.




