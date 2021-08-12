# Dual Xorbell

The Xorbell is very simple and cool little drum module. 
It gives a metallic cowbell like sound with its XOR logic chip; hence the name.

The Original concept came from Elliot Williams: https://hackaday.com/2015/04/10/logic-noise-more-cmos-cowbell/
However I got the idea from Kristian Blåsol's Modular in a week day 9.3: https://youtu.be/50Wdc--Ln-g

I added two opamp output buffers, and changed the potentiometers to fixed values and added two switches that let you choose between two sounds each. The dual Xorbell gives you two lower tweaked and two higher tweaked Xorbells. The pots let you change the decay of the sound. I encourage you to breadboard this project first and find your sweetspot values for R1, R2, R8, R9, R10 and R11. 

Keep in mind that this module uses a trick for the input gates + decay. By this the output volume depends on the input voltage and how that incomming trigger / gate is buffered. Therefore an improvement would be to add proper input buffers.


Tip: If you would use SPDT toggle switches (a tripple legged switch) instead of a SPST switch you will get an extra sound for each channel in their "off" positions.


<img src="https://raw.githubusercontent.com/PierreIsCoding/Xorbell/main/images/xorbell.jpg" width="300" />

