# VCD

Voltage Controlled Decay Generator

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCD/images/VCD.png" width="230" />

A simple envelope generator (decay only) suited for creating dynamic accents in your sequence.

## Features
1. Decay; duration of the decay
2. Level bias; height of decay
3. Level CV input attenuverter.
4. Level CV input.
5. Trigger input.
6. Decay output.
7. Hard / Soft mode switch.

## Decay vs Level
The decay knob allows you to change the duration of an envelope decay, while the Level knob + Level CV allows you to set the height of the decay. By changing the height you also effectivly change its timing. let me explain.

<br>

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCD/images/explain_1.png" width="300" />
<br>

In the image above you see the level set by the Level knob. After you give the module a gate or trigger input it creates an internal pulse where the height of that pulse is set by the "Level knob + Level CV". This internal pulse is then shaped into a simple decay envelope. Note that a shorter decay time naturally causes the stage to finish earlier.

Because this module utilizes a Sample & Hold circuit, the Level CV is only latched at the moment of a trigger; changing the Level CV between triggers will have no effect on the current cycle.

<br>

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCD/images/explain_2.png" width="400" />

If you would simply change the input level CV while using a steady clock it creates a higly dynamic sequence. Ideal for accents or fast arpeggios.

## Hard / Soft Mode

The Hard or Soft mode effects the influence of level changes.

<br>
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCD/images/explain_3.png" width="300" />

If the next decay is triggered with a lower Level CV, while the previous decay is still ongoing, the Soft mode would simply ignore the new decay. See image above.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/VCD/images/explain_4.png" width="300" />

Hard mode abruptly pushes the ongoing decay down to the new level (see image above). As a rule of thumb, Soft mode creates more natural-sounding decays, while Hard mode provides starker contrast between consecutive notes.

## Optional changes before building the module
* Removing capacitor C7 allows higher-frequency signals, such as noise, to pass through. This can be used to generate randomized decay times.
* Increase resistor value R17. This allows for higher decays.
* Decrease C2 for even snappier decays.

## iBOM
[iBom](https://htmlpreview.github.io/?https://github.com/PierreIsCoding/sdiy/blob/main/VCD/ibom.html)
