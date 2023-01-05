# Spark - An Analog Burst Generator
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Spark/images/Spark_Front_Panel.png" width="180" />

Spark can creates gates, envelopes, fade ins, fade outs and more. The module gives you analog control to create lively and complex rhythmic effects.

# Manual
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Spark/images/numbers.png" width="300" />

1. Duration (bias) knob
2. Burst LED's
3. Slope knob.
4. Trigger Mode switch.
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

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Spark/images/Explainations_Spark.png" width="400" />

When Spark receives an input trigger a number of things are set in motion:
- First and foremost Spark sends out a basic burst of gates (9). These gates can be used to trigger other modules like kicks, snares, hats, envelope generators etc. 
- On the same time Spark outputs a simple envelope on the slope output (7). This envelope internally determines the duration of the burst. When the slope is at its end the burst gates stop to be produced.
- This slope / envelope can have either a "fade in" or fade out" shape. This determinded by the slope knob (3).
- Also on the same time Spark combines this slope with the burst gates to produce "fading" envelopes at the "burst envelope output" (10). Their individual decay's are set by the envelope knob (14). See image above how this all looks like.



<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Spark/images/Explainations_2_Spark.png" width="400" />







# Build Notes
