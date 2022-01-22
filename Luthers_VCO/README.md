# Luthers_VCO
A very simple and powerful VCO for the synth DIY enthusiast. 

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Luthers_VCO/images/20210610_174556.jpg" width="400" />

This design is the result of a redesign of Moritz Klein's "Shapes VCO".
https://www.youtube.com/watch?v=OCAb2UoSPs0

## Before you start
* Moritz Klein's version is quite similar as the Rene Schmitz ['CMOS VCO'](https://www.schmitzbits.de/vco4069.html), which also comes with those NTC resistors and with CMOS Schmitt Triggers. So please take a look there as well.
* Moritz Klein created a very nice written manual, in collaboration with Erica Synth, that explains a lot about his VCO. [See here](https://www.ericasynths.lv/media/VCO_FINAL.pdf)
* I would rather use a 1k multiturn trimpot than the 2k single-turn as depictured below (and as in my pdfs).
* I also designed a [DUAL VCO](https://github.com/PierreIsCoding/sdiy/tree/main/Dual_VCO) version. It has a lot more feature: hard sync, octave switch and wave select. However it is a very complex design. That is the beauty of this thing. It works well with only a few components.

## No more 40106
Moritz included in his design a 40106 schmitt trigger. I wanted to simplify that by using an opamp in schmitt trigger configuration. This results in a much simpler and economical design since the 40106 has 6 schmitt triggers and you would use only two of those for a single VCO. Alternatively I could have build 3 VCO's together with that 40106, but I rather have the option to start with one VCO and just add another as I please in a modular fashion.

## PWM
Using a gentle form of PWM (Pulse Width Modulation) is a great way to beef up the sound of square wave vco's. Since my previous alteration added extra opamps I could add this great feature without any costs. Note: Moritz added also PWM in later design versions, but not exactly in the same way.

## Conclude
Finally I named this design after my Synth DIY nickname: Luther. Since I changed the design more than 50%,  and the fact of that the core of Moritz design is something you can find in other much older designs too, I thought I could do that. What do you think? ;)

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Luthers_VCO/images/20210610_174519.jpg" width="400" /> <img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Luthers_VCO/images/20210610_174454.jpg" width="400" />
