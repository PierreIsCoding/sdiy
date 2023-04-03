# Spark - An Analog Burst Generator
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Spark/images/Spark_Front_Panel.png" width="180" />

Spark creates gates, envelopes, fade-ins, fade-outs and more. The module gives you analog control to create lively and complex rhythmic effects.

# Manual
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Spark/images/numbers.png" width="300" />

1. Duration (bias) knob.
2. Burst LED's.
3. Slope shape knob.
4. Trigger mode.
5. Duration CV input with attenuator.
6. Trigger / Gate input.
7. Slope output.
8. EOC output (End Of Cycle).
9. Burst gates output.
10. Burst envelopes output.
11. External clock input.
12. Rate CV input with attenuator.
13. Manual trigger button.
14. Envelope knob.
15. Rate (bias) knob.

## Basic Operation
To start a burst you need to trigger it. For this you have three options:
- Insert a clock in the trigger input (6).
- Push the manual trigger button (13).
- Toggle the trigger mode to loop (4).

For basic operation and for learning the module first set the trigger mode switch to "RETRIG", and the attenuator for the rate cv fully counter-clock-wise.

<br>

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Spark/images/Explainations_Spark.png" width="400" />

When Spark receives an input trigger a number of things are set in motion (see also image above):
- First and foremost Spark sends out a basic burst of gates (9). These gates can be used to trigger other modules like kicks, snares, hats, envelope generators etc. 
- On the same time Spark outputs a simple slope envelope on the slope output (7). This slope internally determines the duration of the burst. When that envelope is at its end, the burst is stopped to be produced.
- That slope can have either have a "fade-in", "no fade", or fade-out" shape. This is determinded by the slope shape knob (3). See section below about this in more detail.
- Spark also combines that slope with the burst gates and the internal envelope generator (14) to produce even another shape. This is a"fading-in" or "fading -out" burst with envelopes at the "burst envelope output" (10).
- The individual decay's of the burst envelopes are set by the envelope knob (14). See image above for how this all looks like.

## Duration
The Duration of the burst is controlled by the duration knob, the duration CV and its associated attenuator. By changing this you also directly change the duration of the slope output. You can use this output (7) as a CV-controllable decay generator to control external VCA's etc.

Internally the duration has a "sample & hold" circuit. With this you can use a noise source or similar into the duration CV input (5). The module will store that CV value at the moment of receiving a trigger. A new trigger is required to reset the duration to a new value. During a burst new values are blocked.

Tip: it can happen that the duration becomes super looooong when the duration knob is set to its max and a high duratio CV input was applied. Any change on the duration input will not change the process while the burst is still in action, because of this S&H circuit. To overcome this make sure the trigger mode switch (4) is set to RETRIG, then lower the duration values and press the manual button to trigger a new burst and to reset the Sample & Hold. 

## Rate
The rate of the internal clock is controlled by the rate knob, the rate CV and its associated attenuator. Please be aware that the input CV for the clock rate is normalized with the slope output. This means that opening the associated attenuator for the rate CV allows the slope to effect the rate of the clock. When the slope shape is set to fade-in the rate will ramp up during a burst generation and when the slope is set to fade-out the speed will slow down during a burst generation.

Tip: if you don't want the slope to mess up with the rate speed make sure the attenuator for the rate cv is fully counter-clock-wise.

## Slope Control

<br>
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Spark/images/Explainations_2_Spark.png" width="500" />
<br>

A little bit more about the  Slope shape knob (3).
- Fully counter-clock-wise and the slope and envelope out will fade in.
- Fully clock-wise and the slope and envelope out will fade out.
- Put it in the center:
  - All burst envelopes will have their maximum travel.
  - The slope output is a straight line at its max value.
- See for yourself what happens in between.

Also notice that the fade-in looks actually a bit funny. Technically it's an inversed version of the fade-out with an offset. This gives the fade-in an high output outside the burst generation. You won't notice this for the burst envelopes, but if you use the slope output seperately you have to consider this.

## Trigger Mode
You can set the trigger mode to three positions:
- Single.
- Retrigger (standard mode).
- Loop.

If you set the switch to it's center position any new input trigger will reset the burst, slope and fading to their start position immediately, even if Spark is already deploying a burst. If you only want to receive a new burst when the current one is completely finished, then set the trigger mode to "single". This can be handy when you want a long burst generation but your input triggers are fast. For looping....just set it to looping. Input triggers don't realy work for this mode. It's fun to play with the duration and rate though.

Tip: Due to the nature of the analog circuitry it might happen that the looping stops when you keep pressing the manual button etc during a loop. If that happens just toggle momentarily between retrig and loop mode.

## Envelope
<br>
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Spark/images/Envelope.png" width="300" />
<br>

With the envelope knob you can set the envelope of each individual gate burst....sparks ;) Turn it counter-clock-wise to get a more sparky output and turn it clock-wise to have longer envelopes. If the burst rate is fast you probably want to have more narrow envelopes here, else you wont notice the individual envelopes at the burst envelope output. Also the relationship between these envelopes and the fade-in or fade-out of the slope is interesting.

## EOC
The EOC / End Of Cycle (8) is on when there is no burst generation going on. 

- You can use this for a gate delay with the duration to control the timing, for instance.
- Set the trigger mode to retrig and connect the EOC output with the trigger input via a cable. Now it loops! This is actually how the looping works behind the scenes. With this setup can add additional modules to turn the looping on or off ;)

## External Clock
Insert an external clock (11) to control the burst envelopes output (10). It doesn't affect the burst gates output (9). That will still be set by the internal clock.

# Build Notes

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Spark/images/front.jpg" width="800" />

ps, I soldered R1 on the backside only for testing purposes, so you don'tneed to.

## Bugs
- Keep notice that in pcb "Version 1" the silkscreen of R21 en R17 are swapped.

## Files
The files for building and sourcing this project are in this folder. See
- Spark_Schematic.pdf; as reference.
- Spark_Part_List.xlsx; for sourcing your parts.
- ibom.html; download is file and open it with your browser. It is ideal for placing the components.
- Spacer_11mm.stl; For 3D-printing a spacer between the two PCB's. I used a 2mm wood screws to mount it.

## Calibrating the rate knob.
- On the front panel between the duration knob and envelope knob you see a little hole. Behind it sets trimpot RV6.
- Turn on the device.
- Turn the duration knob fully clock-wise.
- Turn the rate knob fully counter-clock-wise.
- Set the module in loop mode.
- Make sure the rate cv attenuator is fully counter-clock-wise.
- Connect the burst gate output to a module that requires a gate or trigger to start, like a drum module and listen to it.
- Insert a 2mm screw-driver in the little hole mentioned above.
- Turn the trimpot fully counter-clock-wise. 
- Now slowly turn it clock-wise until the gate output is firing.
- This sets the minimum clock speed of the internal clock for the rate knob.
- Set it to your own tasting.
- You can always get slower clock speeds by using a negative rate CV.
- At a certain level the internal clock completely stops. This can be a desired effect.

## Calibrating the fade-in offset.
- On the back side you find trimpot RV3.
- Set the trimpot in the center. This would probably be good enough.
- Opionally use an oscilloscope and compare the shapes of a fully fade-in and fade-out slope.
- If the starting point of the fade-in is not equal to the end point of the fase-out then adjust the trimmer.
- I might remove this calibration option for next version. Let me know. 


Good luck !
Luther / L.Geerinckx




