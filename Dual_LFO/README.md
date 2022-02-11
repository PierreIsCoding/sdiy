# DUAL LFO With Mix

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Dual_LFO/images/20220211_143323.jpg" height="500" />  <img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Dual_LFO/images/front.PNG" height="500" />

This Project is a dual version of a simple traingle LFO. It also features and extra CV mixer. Thats it; simple and effective. Need another LFO?...build this one. You will use it 99% of your patches ;)

The design is based on a much older LFO design also seen in:
*  [Simple LFO by David Haillant](https://www.davidhaillant.com/simple-lfo-1-5/#more-2112)
*  [CGS utility LFO](https://sdiy.info/wiki/CGS_utility_LFO)



## Features
* Two independad LFO's with the triangle waveform.
* Each LFO has a:
  * Rate switch.
  * Rate potentiometer.
  * Amplitude potentiometer.
* CV mixer of both LFO outputs.
* Bi colored LED's to see the up and down motion.
* Etching files for single board pcb.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Dual_LFO/images/20220211_143504.jpg" width="300" />

## Simulation
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Dual_LFO/images/falstad.PNG" width="300" />
[Check simulation here](https://tinyurl.com/yawfhe7n)

How it works
* capacitor charges up at first op amp
* this gives a rising voltages at input of second opamp
* The second opampis in comparator configuration
* When that voltage is high enough switches from high to negative
* That negative voltage discharges the capacitor
* The comparator goes into postive and the capacitor charges again
* The main trick here is giving the comparator that extra feedback transistor. That makes the comparator a "Schmitt Trigger".
* Since that feedback transistor is relatively small the Schmitt Trigger zone is pretty large. See in the simulation what happens if you change it ;)


## Buildnotes
* The LEDs can be soldered in both ways. Negative leg to the right (seen from the front) will give you a green light at positive LFO voltages.
* Check images below for soldering the extra wires.
* Use colored wires for easy debugging
* The original designs also have a switch for choosing between triangle or

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Dual_LFO/images/sub_pcb_wiring.PNG" width="300" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Dual_LFO/images/switches_wiring.PNG" width="400" />

