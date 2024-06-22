# Swoop

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Swoop/images/SWOOP_FRONT.png" width="100" />

Swoop is a 2:2 analog multiplexer module for Eurorack. It can be used used for a many interesting things.

## Features
* Route two analog or digital signal to two outputs. With this you can:
  * 2:1 Use two input signals and select one of them as output.
  * 1:2 Use one input signal and select to which output you want it.
  * 2:2 Swap two signals with each other.
* Use momentary or toggle selection.
* Use a button and clock input to change state
* Two gate outputs.
  * At momentary mode you get: A direct gate and inversed gate
  * At toggle mode you get: A clock divider output and its inverse.
*  Use it as a wave shaper. For this you just insert your signal in to the clock input (CLK IN). For this:
  *  The clock input (CLK IN) is normalized to the left signal input (SIG IN A).
  *  The inverse of the left signal input is normalized with the right signal input (SIG IN B).
*  Use the COMP potentiometer and COMP IN cv to change the waveshape (PWM-like).

Be aware:
* That for normal clock you want the COMP potentiomer at 13.00 o'clock.
* The different normalizations of the inout jacks.

## Build notes

[iBom](https://htmlpreview.github.io/?https://github.com/PierreIsCoding/sdiy/blob/main/Swoop/ibom.html)
