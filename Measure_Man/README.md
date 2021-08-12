# Measure_Man
Measure man helps you to save the day! This simple but powerful utility is a "handy to have" little tool that helps you to quickle measure a few important specs for a synth diy / Eurorack enthusiast!

<img src="https://raw.githubusercontent.com/PierreIsCoding/Measure_Man/main/images/overview.bmp" width="400" />

## Disclamer
- This project is only for experienced users/ builders.
- If not used and/or build correctly you might create a short circuit that destroyes your module(s) and or you power supply.
- This project is totally on your own risk.`

## DO NOT
- Put your multimeter on Ampere mode and "Measure Man" on Volt Mode. 
- This will short circuit your powersupply !!
- Otherwise add fuse F1 to protect this from happening. See schematic.
- Lookup your power supply for the max  Ampere it can deliver to choose the appropriate fuse.

## Files
- Pdf of the schematic
- 3D file (.stl) for 3d printing the casing
- images

## Requirements
- Multimeter.
- Eurorack modules.
- Eurorack cables.
- Eurorack power.
- Banana plugs.

## Tip
- After your build, use this tool first only for "checking Eurorack cables", before measuring current and voltages.

## Check Eurorack cables
<img src="https://raw.githubusercontent.com/PierreIsCoding/Measure_Man/main/images/20210422_192843.jpg" width="400" />

- Set the switch of "Measure Man" to "Voltage Mode".
- Add one end of your cable to the input and the other end to the output.
- Set your multimeter to "Continuity mode" and plug it to the correct banana jacks.
- Set the upper rotary to -12V.
- Change the position of the lower rotary switch to check continuity between lines.
- By this you scan if -12V is connected to -12V and not connected with any of the other lines.
- Repeat this step with +12V and +5V.


## Measure current
<img src="https://raw.githubusercontent.com/PierreIsCoding/Measure_Man/main/images/20210422_192646.jpg" width="400" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/Measure_Man/main/images/20210422_192658.jpg" width="400" />

- Make sure to have a switch off power supply before continue.
- Set the switch of "Measure Man" to "Ampere Mode".
- Add one 16 dip cable to the idc input of "Measure Man".
- Set your multimeter to "Ampere mode" and plug it to the correct banana jacks.
- Add another 16 dip cable between "Measure Man" its output and an Eurorack module.
- Turn your power supply on.
- Change the position of the upper rotary switch to measure the different power lines.


## Measure voltages
- Make sure to have a switch off power supply before continue.
- Set the switch of "Measure Man" to "Voltage Mode".
- Add one 16 dip cable to the idc input of "Measure Man".
- Set your multimeter to "Voltage mode" and plug it to the correct banana jacks.
- Set the lower rotary switch to ground.
- Turn your power supply on.
- Change the position of the upper rotary switch to measure the voltages of the power lines.





