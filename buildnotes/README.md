# PCB etching

## Board Converter
After some frustration with lots of wiring to nicely etched pcb's I needed a solution to stack multiple board on top of each other, just like with double sided pcb's. The main issue is here that the headers need to be on the wrong side of the pcb. A single layer pcb just doesn't allow you to flip a part or a header the other direction. That is why I created these little helpers and called them "board converters".

* It requires a small piece of perfboard for each connection.
* Extra holes are requires for the connecting wire between each layer
* It is best used with male and female headers with longer legs, like with stacking headers

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/buildnotes/images/board_convert_b.jpg" height="200" />  <img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/buildnotes/images/20210813_130330.jpg" height="200" />

<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/CEM3340_VCO/images/20210813_130437.jpg" width="400" />


## Drilling 
This is a list with drill sizes I am currently using for my pcb etching projects.


| Component        | Drill size (mm) |
| -------------   |:-------------:|
| Default         | 0.8 | 
| Resistors      |0.8|
| Thonk Jacks    | 1 | 
| Alpha potmeters (pins) |1|
| Alpha potmeters (mount) |1.5|
| Male header pins |1|
| Female header pins |0.8|
| IDC header pins |1|
| Toggle switch |2.2|


