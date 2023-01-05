# Spark - An Analog Burst Generator
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Spark/images/Spark_Front_Panel.png" width="180" />

Spark creates gates, envelopes, fade-ins, fade-outs and more. The module gives you analog control to create lively and complex rhythmic effects.

# Manual
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Spark/images/numbers.png" width="300" />

1. Duration (bias) knob
2. Burst LED's
3. Slope knob.
4. Trigger Mode.
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

For basic operation and for learning the module first set the trigger mode switch to "retrig".

<br>

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Spark/images/Explainations_Spark.png" width="400" />

When Spark receives an input trigger a number of things are set in motion:
- First and foremost Spark sends out a basic burst of gates (9). These gates can be used to trigger other modules like kicks, snares, hats, envelope generators etc. 
- On the same time Spark outputs a simple envelope on the slope output (7). This envelope internally determines the duration of the burst. When the slope is at its end the burst gates stop to be produced.
- This slope / envelope can have either a "fade-in" or fade-out" shape. This determinded by the slope knob (3).
- Also on the same time Spark combines this slope with the burst gates to produce "fading" envelopes at the "burst envelope output" (10). 
- The individual decay's of the burst envelopes are set by the envelope knob (14). See image above how this all looks like.

## Duration
The Duration of the burst is controlled by the duration knob, the duration CV and its associated attenuator. By changing this you also directly change the duration of the slope output. You can use this output as a CV-controllable decay generator to control external VCA's etc.

Internally the duration has a "sample & hold" circuit. With this you can use a noise source or similar into the CV input and the module will store that CV value at the moment of receiving a trigger input to set and keep the duration of the burst. A new trigger is required to reset the duration to a new value.

Tip: it can happen that the duration becomes super looooong when the duration knob is set to its max and a high CV input was applied. To overcome this make sure the trigger mode is set to single, lower the duration values and press the manual button to reset the Sample & Hold. 

## Rate
The rate of the internal clock is controlled by the rate knob, the rate CV and its associated attenuator. Please be aware that the input CV is normalized with the slope output. This means that opening the associated attenuator allows to slope to effect the internal clock. When the slope shape is set to fade-in the rate will speed up during a burst and when the slope is set to fade-out the speed will slow down during a burst.

## Slope Control

<br>
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Spark/images/Explainations_2_Spark.png" width="400" />
<br>

A little bit more about the slope control:
- Fully counter-clock-wise (to the left) and the slope and envelope out will fade in.
- Fully clock-wise (to the right) and the slope and envelope out will fade out.
- Put it in the center:
  - All burst envelopes will have their maximum travel.
  - The slope output is a straight line at its max value.
- See for yourself what happens in between.

## Trigger Mode
You can set the trigger mode to three positions:
- Single
- Retrigger (standard mode)
- Loop

If you set the switch to it's center position any new input trigger will reset the burst, slope and fading to their start position immediately. Also when Spark is already deploying a burst. When you only want to get a new burst when the current one is completely finished set the trigger mode to "single". This can be handy when you want a long burst generation but your input triggers are fast.

For looping....just set it to looping. Input triggers don't realy work for this mode.

## EOC
The EOC / End Of Cycle (8) is on when their is no burst going on. You can use this for a gate delay for instance with the duration to control the timing.

## External Clock
Insert an external clock (11) to control the burst envelopes output(10). It doesn't affect the burst gates output (9). That will still be set by the internal clock.









# Build Notes
