# CEM3340

This Project is an optimised VCO design for home single layer etching. It is a powerful VCO with the almighty and classic CEM3340. I looked at the version of [Kassutronics](https://kassu2000.blogspot.com/2018/06/vco-3340.html), [Electricdruid](https://electricdruid.net/cem3340-vco-voltage-controlled-oscillator-designs/) and  [Digisound](https://www.eddybergman.com/2020/01/synthesizer-build-part-18-really-good.html) as a starting point.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/CEM3340_VCO/images/20210808_181042.jpg" width="300" />


## Design Changes
I eventually looked mainly at Kassutronics version. Compared to his design I changed the following :
* Dual board layout instead of single with wider tracks and pads for etching.
* New PWM input. At Kassutronics version the PWM potentiometer becomes an attenuator after instering a jack-cable. I changed this to a bias-with-cv-mix alternative together with extra input protection.
* A different triangle to sine conversion. This part uses Thomas Henry's design. Here you need two standard but matched transistors instead of difficult to source j201's. 
* Cascading multiple VCO's headers. I gave the breaking pins of the input jacks extra connector points in the pcb layout. With this you can create a semi modular dual vco more easily. For instance: instead of two seperated VCO's you can link the 1V/OCT from VCO 1 with the breaking input pin of the 1V/OCT of  VCO 2. This will save you Eurorack cables when using multiple VCO's but keeps the flexibility of using them. Furthermore you could build a front panel with two VCO's mounted on its back.

## Build Notes
* Please also read the documentation on [Kassutronics Github](https://github.com/kassu/kassutronics/tree/master/documentation/VCO%203340) and [Eddy Bergmans](https://www.eddybergman.com/2020/01/synthesizer-build-part-18-really-good.html)
* Please look the ibom file components placement.
* The design uses some wiring within the board. See the "SINGLE_CEM3340-F_Cu.pdf" for those connections. See also images below
* For drilling holes see my general [Builnotes](https://github.com/PierreIsCoding/sdiy/tree/main/buildnotes)
* I designed "board converters" that enables you to stack multiple ecthed single layer boards. See also my general Buildnotes

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/CEM3340_VCO/images/20210808_181119.jpg" width="300" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/CEM3340_VCO/images/20210808_181134.jpg" width="300" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/CEM3340_VCO/images/20210808_181208.jpg" width="300" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/CEM3340_VCO/images/20210808_181221.jpg" width="300" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/CEM3340_VCO/images/20210808_181314.jpg" width="300" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/CEM3340_VCO/images/20210813_130437.jpg" width="300" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/CEM3340_VCO/images/20210809_103506.jpg" width="300" />

