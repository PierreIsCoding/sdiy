# DUAL Low Pass Gate with integrated "envelope"
This vactrol based module converts any sound into a drum sound. It is a simple but very nice project to build.

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/LPG/images/20210906_212035.jpg" height="400" />

## Features
- Inputs:
  - Gate Input.
  - Signal Input.
- Outputs:
-   Short and natural "feeling" (due to vactrols) drum sound.
-   A very short trigger useful for combining with external VCA's etc.
- Two channels. each channel has a simple switch for changing the decay length.

## How It Works
The gate signal is converted into a very fast trigger which open and closes the vactrol by lighting its inner LED. Due to the capacitors near the vactrols and the vactrol itself that trigger is converted into more natural slopy decay. Furthermore the vactrols filter out higher frequencies while closing. Giving it a "natural" sounding effect.


## Build Notes
- Just use some heatshrink tubing (maybe use the ones with glue as I did) to bundle a LDR and a white LED. See Youtube for tips on this topic.
- Experiment with different capacitors for the decays. I used fairly modest values but you can get creative with it. Please note that higher values will not a close the signal that well but can create an interesting effect anyway.
- The trimpots are not needed really, but can by handy. They set the output gain. I left mine in the middle. Alternatively you could use some fixed resistors (2x47K for instance).
- Please note the connection of the breaking pins with ground at U3 and U8 in the schematic.
- For the LDR's just use small and cheap ones that have at least 1M at dark resistance. I used something ones from Banggood.com (50Pcs 5MM Light Dependent Resistor Photoresistor GL5528 LDR). But type shouldn't matter. 
- If you use banana jacks add a large pull down resistor (1M - 4.7M) at the + pin of the opamp at the signal input.

ps. I will add some better looking labels on the front panel;)

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/LPG/images/front.jpg" height="400" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/LPG/images/20210906_211956.jpg" height="400" />



