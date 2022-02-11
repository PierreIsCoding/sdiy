# DUAL LFO With Mix

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Dual_LFO/images/20220211_143323.jpg" height="500" />  <img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Dual_LFO/images/front.PNG" height="500" />

This Project is a dual version of a simple traingle LFO. It features and extra CV mixer. This design is based on a much older LFO design also seen in:
*  [Simple LFO by David Haillant](https://www.davidhaillant.com/simple-lfo-1-5/#more-2112)
*  [CGS utility LFO](https://sdiy.info/wiki/CGS_utility_LFO)

<!--  style="margin:20px;" -->


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


## Buildnotes
* The LEDs can be soldered in both ways. Negative leg to the right (seen from the front) will give you a green light at positive LFO voltages.
* Check images below for soldering the extra wires.
* Use colored wires for easy debugging
* The original designs also have a switch for choosing between triangle or

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Dual_LFO/images/sub_pcb_wiring.PNG" width="300" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Dual_LFO/images/switches_wiring.PNG" width="400" />



<!-- 

This Project is an optimised VCO design for home single layer etching. It is a powerful VCO with the almighty and classic CEM3340. I looked at the version of [Kassutronics](https://kassu2000.blogspot.com/2018/06/vco-3340.html), [Electricdruid](https://electricdruid.net/cem3340-vco-voltage-controlled-oscillator-designs/) and  [Digisound](https://www.eddybergman.com/2020/01/synthesizer-build-part-18-really-good.html) as a starting point.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/CEM3340_VCO/images/20210808_181042.jpg" width="300" /> -->
