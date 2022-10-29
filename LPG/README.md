# DUAL Low Pass Gate with integrated "envelope"
This vactrol based module converts any sound into a drum sound. It is a simple but very nice project to build.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/LPG/images/20210906_212035.jpg" width="400" />

## Features
- Inputs:
  - Gate Input.
  - Signal Input.
- Outputs:
  - Short and natural "feeling" (due to vactrols) drum sound.
  - A very short trigger useful for combining with external VCA's etc.
- Two channels. Each channel has a simple switch for changing the decay length.


## How It Works
The gate signal is converted into a very fast trigger which open and closes the vactrol by lighting its inner LED. Due to the capacitors near the vactrols and the vactrol itself that trigger is converted into more natural slopy decay. Furthermore the vactrols filter out higher frequencies while closing. Giving it a "natural" sounding effect. See image below. I inserted a square wave from a VCO. Notice two things:

- It has a nice slopy decay.
- The wave in the beginning is still square-like but at the end it changes more and more to triangle-isch shapes. This is actually the filter effect from the LPG, and is the part why it sounds more "natural".

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/LPG/images/20210907_183115.jpg" width="600" />




## Build Notes
- Make sure you connect the LEDs inside the vactrols according to the circuit diagram. So + pin to the 1k and the - pin to ground.
- Just use some heatshrink tubing (maybe use the ones with glue as I did) to bundle a LDR and a white LED. See [Youtube](https://www.youtube.com/watch?v=8BOnvSQpoGY) for tips on this topic.
- Experiment with different capacitors for the decays. I used fairly modest values but you can get creative with it. Please note that higher values will not a close the signal that well but can create an interesting effect anyway.
- The trimpots are not needed really, but can by handy. They set the output gain. I left mine in the middle. Alternatively you could use some fixed resistors (2x47K for instance).
- Please note the connection of the breaking pins with ground at U3 and U8 in the schematic. If you use banana jacks instead add a large pull down resistor (1M - 4.7M) at the + pin of the opamp at the signal input.
- For the LDR's just use small and cheap ones that have at least 1M at dark resistance. I used something ones from Banggood.com (50Pcs 5MM Light Dependent Resistor Photoresistor GL5528 LDR). But type shouldn't matter.
- I made the perfboard perfboard design pretty dense so check your connections carefully with the circuit design.

ps. I will add some better looking labels on the front panel;)

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/LPG/images/front.jpg" width="600" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/LPG/images/20210906_211956.jpg" width="600" />



