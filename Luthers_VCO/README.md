# Luthers_VCO
A very simple and powerful VCO for the synth DIY enthusiast. 

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Luthers_VCO/images/20210610_174556.jpg" width="400" />

This design is the result of a redesign of Moritz Klein's "Shapes VCO". 
https://www.youtube.com/watch?v=OCAb2UoSPs0


## No more 40106
Moritz included in his design a 40106 schmitt trigger. I wanted to simplify that by using an opamp in schmitt trigger configuration. This results in a much simpler and economical design since the 40106 has 6 schmitt triggers and you would use only two of those for a single VCO. Alternatively I could have build 3 VCO's together with that 40106, but I rather have the option to start with one VCO and just add another as I please in a modular fashion.

## PWM
Using a gentle form of PWM (Pulse Width Modulation) is a great way to beef up the sound of square wave vco's. Since my previous alteration added extra opamps I could add this great feature without any costs. 

## Conclude
Finally I named this design after my Synth DIY nickname: Luther. Since I changed the design more than 50%,  and the fact of that the core of Moritz design is something you can find in other much older designs too, I thought I could do that. What do you think? ;)

PS, I would rather use a multiturn trimpot than a single one as depictured below.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Luthers_VCO/images/20210610_174519.jpg" width="400" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Luthers_VCO/images/20210610_174454.jpg" width="400" />
