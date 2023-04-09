# Chit Chat - An Analog Probability Generator

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Chit_Chat/images/Chit_Chat_Front_Panel.png" width="110" />

With Chit Chat you can create a lifelike and rhytmic conversation with ease by simply setting the probability between one of the two output gates.
When Chit Chat receives a clock input it randomly translates this either to gate 1 or 2, as a coin toss. Depending on the probability setting between 0-100% it will go more likely to one of the two gates. This is not only a simple but powerfull module, but the tech behind it consists completely of analog and discrete electronics. No software is involved !

## Video

Many thanx to MeeBilt who created a build and demo video of this module ! 

<a href="https://www.youtube.com/watch?v=In5H7uLO6ec&t=187s"><img src="https://img.youtube.com/vi/In5H7uLO6ec/sddefault.jpg" width="300" /></a>

https://www.youtube.com/watch?v=In5H7uLO6ec&t=187s


# Manual
Chit Chat has two channels to work with: Channel A on the left side and channel B on the right side.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Chit_Chat/images/Chit_Chat_Numbers.png" width="150" />

1. Probability knobs.
2. CV inputs.
3. Gate / clock inputs.
4. Gate outputs (A1 and B1).
4. Gate outputs (A2 and B2).

## Probability Knobs
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Chit_Chat/images/Explainations.png" width="600" />
<br>

* If you set the probability knobs at the center, thus at 50%, both gate outputs have an equal chance to "copy" the incomming clock signal to the output.
* If you set the probability knobs fully to the left (CCW), gate output 1 as a 100% chance and gate output 2 a 0% chance, and vice versa.
* Any other position will favour one over the other but won't exclude neither of them.

## Gate Inputs
* A great start to use Chit Chat is to insert a steady clock in the input gate and the probility at 50%. However you can also use more rythmic gate inputs or clocks at audio rates. Please experiment.
* Also know that gate input B is normalized to gate output A1. Thus if gate output A1 fires one of the gate outputs of channel B will fire as well. Inserting a cable into gate input B will override that normalization.

## CV Control
Chit Chat allows you to control the probability via CV, unipolar or bipolar. The probability knob biases how Chit Chat receives this CV. Please mind these values might differ a bit. It's not an exact science.

* Probability knob center: CV: -2.5V to 2.5V
* Probability knob fully CW: CV: 0V to 5V
* Probability knob fully CCW: CV: -5V to 0V

# Build Notes

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Chit_Chat/images/front.jpg" width="400" />   <img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Chit_Chat/images/parts.jpg" width="150" />

## Files
The files for building and sourcing this project are in this folder. See
- Chit_Chat_Schematic.pdf; as reference
- Probability_Gate_2022_BOM.xlsx; for sourcing your parts
- ibom.html; download is file and open it with your browser. It is ideal for placing the components.

## Calibration.
The front panel has a little hole next to the top probability knob. With this you calibrate the noise gain / probability. How to calibrate:
- Insert a fast clock / VCO at audio rate (you can use a square, sine, saw etc wave) into the gate in of the left channel.
- Turn the top probability knob fully counter-clock-wise.
- Turn the calibration trimpot fully clock-wise.
- You can use a 2mm screw-driver for this. If you only have larger ones, you need to unscrew the front panel to reach the trimpot...sorry ;)
- Then connect the first gate output to your audio out.
- Now you should hear that same clock, but in square waves.
- Turn the top probability knob fully clock-wise. While you do this you hear the clock falling appart.
- If you hear still little bits of that fast clock you need to turn the calibration slowly counter-clock-wise, until you hear no pulses any more.
- If you now turn your probability knob a little bit counter-clock-wise you should hear the first pulses of the clock coming back again.
- Done !


[Old version](https://github.com/PierreIsCoding/sdiy/tree/main/Probability_Gate)
