# Wavefolder

This 6HP Eurorack module contains an alternative version of the Buchla Wavefolder redesigned by Non Lineair Circuits. I redesigned the complete pcb design for through hole and changed the panel design. It is a fun module to have and you create interesting timbres for your VCO's (sine, triangle and saw).

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Wavefolder/images/20211202_220416.jpg" width="400" /> 
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Wavefolder/images/20211217_100119.jpg" width="300" />

See here 'Non Lineair Circuits' design:
[Buchla Timbre](https://www.nonlinearcircuits.com/search?q=timbre&f_collectionId=5e753b733558ab3e79ff1235)

## Simulation
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Wavefolder/images/simulation.png" width="800" />

Many thanx to [HarmO](https://github.com/harmo). He gave us a very nice simulation of this project. See [link](https://tinyurl.com/y38unska) .

## Usage notes
* The module needs at least signals of 10 Volts peak to peak in order to fold.

## Buildnotes
* Please check the attached BOM files. This design doesn't use the smd BC857 but a through hole 2n3906 instead
* The J112 can be sourced at tayda. See A-3967
* Some tracks are only 0.5mm, so you need to be sure your toner transfer is decent.
* The copper side of the module is pretty exposed to whatever, so make sure when installing this module those copper traces cannot touch any other modules. Alternatively use some insulation tape to cover the pcb, or make the front panel wider.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Wavefolder/images/20211202_220630.jpg" width="400" /> <img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Wavefolder/images/20211202_220437.jpg" width="400" />

## Troubleshooting
Here are some photos of signals you should more or less get. See schematic for testpoint


The original signal at the input. A sine wave from my CEM3340.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Wavefolder/images/input_signal.jpg" width="400" />

@pin 1 of the TL072. Input signal at 100%. The signal gets scaled down a bit

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Wavefolder/images/Full_signal_pin1_tl072.jpg" width="400" />

@testpoint. Input signal at 100%, Timbre at 100%. When those both are at 100% the signal clips to its rail supplies.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Wavefolder/images/fully_open_all_at_testpoint.jpg" width="400" />

@testpoint. Input signal at 50%, Timbre at 100%. The timbre is mainly created after this testpoint. But you should get a good signal here.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Wavefolder/images/Half%20input%20signal_full_timre_testpoint.jpg" width="400" />

@output. Input signal at 100%, Timbre at 0%.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Wavefolder/images/full_input_timbre_off.jpg" width="400" />

@output. Input signal at 100%, Timbre at 50%. This is the signal where it is all about :) Alternatively you can also lower the input signal. If it gets too hot it just clips everything and you dont get much wavefolding anyways.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Wavefolder/images/Timbre_half_way.jpg" width="400" />



