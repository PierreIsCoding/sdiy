# Sample And Hold Module with Gate Output

This module is a simple but fun module for the sdiy enthusiast!

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Sample_And_Hold/images/20210829_091957.jpg" width="400" />

## Features
* Standard analog Sample And Hold
* Added comparator for random gates

To clarify, a sample and hold module has nothing to do with "samples" in a musical sence. It doesn't record a piece of music that can be play back again. It only samples a single value, while a musical sample requires often 44100 samples per second. 

## How To
The S&H module stores (samples) everytime it gets a clock pulse the current value on the signal input. If you would use a random noise signal it will create random values and hold that value until it gets the next clock pulse; hence its name. You can use this for random cv signal etc etc.

I designed this module with the addition of an extra comparator. With the connected potentiometer you can change the level that is compared with the cv output of the S&H core part. If the S&H signal is higher than the level signal the LED with light up and you get a high out, else you get a low out. To conclude you can also add some other value into the LEVEL-IN jack if you want to use the comparator as stand-alone.

## Idea
If you would use a noise signal and combine this signal with an AND gate together with the original clock you have a probability gate! 

