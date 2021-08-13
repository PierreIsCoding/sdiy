# Arpeggiator

This project is the design of a simple Arduino based argpeggiator for the sdiy enthusiast. 

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Arpeggiator/images/20210813_130817.jpg" height="400" />

## Features
* Set different chords with a rotary switch
* Set different patterns with a rotary switch
* Change the octave range with a switch 0,+1,+2.
* Change the current octave with a switch 0,+1,+2.
* Clock and reset inputs

## R2R resistor network
This project uses an R2R resistor network as a diy DAC (Digital to analog convert). I did this because I got really inspired by this (article)[https://www.electronics-tutorials.ws/combination/r-2r-dac.html]. The R2R resistor is a handy tool useful for many other projects. See also: [Arduino example](https://create.arduino.cc/projecthub/instrumentation-system/dac-8-bit-using-r-2r-ladder-964837)

## Build notes
* For more accuracy the resistors in the R2R networks need to be matched.
* RV1 and RV2 sets the octave offset. The idea is that you set with RV1 to exactly 1V and RV2 to 2V. Then you can simply change the base octave with SW4. However you can trim this to your own liking.  

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Arpeggiator/images/20210813_130710.jpg" width="400" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Arpeggiator/images/20210813_130742.jpg" width="600" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Arpeggiator/images/20210813_130747.jpg" width="600" />
