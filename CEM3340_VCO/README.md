# CEM3340

This Project is an optimised VCO design for home etching. It is a powerful VCO with the almighty and classic CEM3340. I used the CEM3340 version of Kassutronics and the Digitone as a starting point.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/CEM3340_VCO/images/20210808_181042.jpg" width="300" />

The following things are changed in this design:
* Dual board layout instead of single with wider tracks etc.
* New PWM input. At Kassutronics version the PWM potentiometer becomes an attenuator after instering a jack-cable. I changed this to a bias-with-cv-mix alternative together with extra input protection.
* A different triangle to sine conversion. This part uses Thomas Henry's design. Here you need two standard but matched transistors instead of difficult to source j201's. 
* Cascading multiple VCO's headers. I gave the breaking pins of the input jacks extra connector points   in the pcb layout. With this you can create a semi modular dual vco more easily. For instance: instead of two seperated VCO's you can link the 1V/OCT from VCO 1 with the breaking input pin of the 1V/OCT of  VCO 2. This will save you Eurorack cables when using multiple VCO's but keeps the flexibility of using them.


<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/CEM3340_VCO/images/20210808_181119.jpg" width="300" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/CEM3340_VCO/images/20210808_181134.jpg" width="300" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/CEM3340_VCO/images/20210808_181208.jpg" width="300" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/CEM3340_VCO/images/20210808_181221.jpg" width="300" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/CEM3340_VCO/images/20210808_181314.jpg" width="300" />

