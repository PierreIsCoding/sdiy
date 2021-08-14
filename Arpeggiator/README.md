# Arpeggiator

This project is the design of a simple Arduino based arpeggiator for the sdiy enthusiast. 

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Arpeggiator/images/20210813_130817.jpg" height="400" />

## Features
* Set 12 different chords with a rotary switch
* Set 12 different patterns with a rotary switch
* Change the octave range with a switch 0,+1,+2.
* Change the current octave with a switch 0,+1,+2.
* Clock and reset inputs
* Markov Chains

## R2R resistor network
This project uses an R2R resistor network as a diy DAC (Digital to analog convert). I did this because I got really inspired by this (article)[https://www.electronics-tutorials.ws/combination/r-2r-dac.html]. The R2R resistor is a handy tool useful for many other projects. See also: [Arduino example](https://create.arduino.cc/projecthub/instrumentation-system/dac-8-bit-using-r-2r-ladder-964837)

## Chords
Current build in chords with intervals. See also: [https://en.wikipedia.org/wiki/Chord_(music)](https://en.wikipedia.org/wiki/Chord_(music))
* {0, 4, 7, 0},  // Major
* {0, 4, 7, 10}, // Major 7
* {0, 4, 7, 11}, // Dominant 7
* {0, 3, 7, 0},  // Minor
* {0, 3, 7, 10}, // Minor 7
* {0, 3, 6, 0},  // Diminished
* {0, 3, 6, 10}, // Half Diminished 7
* {0, 3, 6, 9},  // Full Diminished 7
* {0, 4, 8, 0},  // Augmented
* {0, 4, 8, 10}, // Augmented 7
* {0, 5, 7, 0},  // Sus 4
* {0, 5, 7, 11}, // Sus 4 Maj 7

## Patterns
* UP
* DOWN
* BOUNCE EXCLUSIVE
* BOUNCE INCLUSIVE
* UP x 2
* DOWN x 2
* RANDOM
* Markov Chain V1
* Markov Chain V2
* Markov Chain V2
* Markov Chain V2
* Markov Chain V2

## Markov Chain
A Markov chain creates is a semi random pattern. This is currently in beta. 

## Build notes
* For more accuracy the resistors in the R2R networks need to be matched.
* With RV4 you trim the 1V/OCT. For doing this please set the first "chord" temporarily within the code to:  {0, 24, 36, 48}. Set the ocatve switches to 0, and insert a slow clock. Now measure your output with a multimeter so you should get 1,2,3,4 volts depending on your current step. Adjust the trimmer accordingly.
* RV1 and RV2 sets the octave offset. The idea is that you set with RV1 to exactly 1V and RV2 to 2V. Then you can simply change the base octave with SW4. However you can trim this to your own liking.  

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Arpeggiator/images/20210813_130710.jpg" width="400" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Arpeggiator/images/20210813_130742.jpg" width="600" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Arpeggiator/images/20210813_130747.jpg" width="600" />
