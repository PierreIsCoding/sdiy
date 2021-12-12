# Wavefolder

This 6HP Eurorack module contains an alternative version of the Buchla Wavefolder redesigned by Non Lineair Circuits. I redesigned the complete pcb design for through hole and changed the panel design. it is a fun module to have and you create interesthing timbres for your VCO's; mainly sine and triangle and saw.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Wavefolder/images/20211202_220416.jpg" height="800" />

See here 'Non Lineair Circuits' design:
[Buchla Timbre](https://www.nonlinearcircuits.com/search?q=timbre&f_collectionId=5e753b733558ab3e79ff1235)

## Buildnotes
* Please check the attached BOM files. This design doesn't use the smd BC857 but a through hole 2n3906 instead
* The J112 can be sourced at tayda. See A-3967
* Some tracks are only 0.5mm, so you need to be sure your toner transfer is decent.
* The copper side of the module is pretty exposed to whatever, so make sure when installing this module those copper traces cannot touch any other modules. Alternatively use some insulation tape to cover the pcb, or make the front panel wider.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Wavefolder/images/20211202_220630.jpg" height="600" /> <img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Wavefolder/images/20211202_220437.jpg" height="600" />

## Troubleshooting
Here are some photos of signals you should more or less get.


The original signal at the input. A sine wave from my CEM3340.
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Wavefolder/images/input_signal.jpg" height="400" />

@pin 1 of the TL072. Input sigal at 100%.
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Wavefolder/images/Full_signal_pin1_tl072.jpg" height="400" />

@testpoint. Input sigal at 100%, Timbre at 100%.
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Wavefolder/images/fully_open_all_at_testpoint.jpg" height="400" />

@testpoint. Input sigal at 50%, Timbre at 100%.
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Wavefolder/images/Half%20input%20signal_full_timre_testpoint.jpg" height="400" />

@output. Input sigal at 100%, Timbre at 0%.
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Wavefolder/images/full_input_timbre_off.jpg" height="400" />

@output. Input sigal at 50%, Timbre at 0%. This is the signal where it is all about :) Alternatively you can also lower the input signal. If it gets too high it just clips everything and you dont get much wavefolding anyways.
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Wavefolder/images/Timbre_half_way.jpg" height="400" />



