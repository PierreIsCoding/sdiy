# Chit Chat - An Analog Probability Generator

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Chit_Chat/images/Chit_Chat_Front_Panel.png" width="110" />

With Chit Chat you can create awesome lifelike rhythms with ease by simply setting the probability between one of the two output gates.
When Chit Chat receives a clock input it randomly translates this either to gate 1 or 2, as a coin toss. Depending on the probability setting between 0-100% it will go more likely to one of the two gates. This is not only a simple but powerfull module, but the tech behind it consists completely of analog and discrete electronics. No software is involved !

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
Chit Chat allows you to control the probability via CV, unipolar or bipolar. The probability knob biases how Chit Chat receives this CV.

* Probability knob center: CV: -2.5V to 2.5V
* Probability knob fully CW: CV: 0V to 5V
* Probability knob fully CCW: CV: -5V to 0V


# Build Notes
Added soon.


[Old version](https://github.com/PierreIsCoding/sdiy/tree/main/Probability_Gate)
