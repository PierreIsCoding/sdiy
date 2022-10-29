# Attiny Programmer
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Attiny_Programmer/images/20220211_144253.jpg" width="600" />

A programmer for the Attiny 84 and 85 with breadboard helpers.

## Features
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Attiny_Programmer/images/20220211_145036.jpg" width="600" />

* Program the Attiny 84 or 85 with an Arduino Nano.
* Indication leds for the programmer
  * Heartbeat. Shows that the programmer is live.
  * Programming. Lights up while programming the Attiny's.
  * Error. Lights up when the programmer hits an issue.
* Breadboard helpers. These little sub-boards let you connect your Attiny directly with a breadboard for testing your new program, so you don't need to constantly swap your Attiny between your prototype and the programmer.
* Power jumper. Quickly set the power supply for the Attiny's: from USB or from Breadboard.
* A buildin testing LED for your blinking test program. This can also be disconnected completely with a jumper.

## Files
* Pdf for etching the pcb's on a single layer.
* Pdf for adding artwork to those pcb's.
* Interactive BOM file.

## Installing the software
* Maybe I will update this with my own tutorial, but these ones should help you.
  * https://www.hackster.io/arjun/programming-attiny85-with-arduino-uno-afb829
  * https://create.arduino.cc/projecthub/arjun/programming-attiny85-with-arduino-uno-afb829
  * http://highlowtech.org/?p=1229 
  * http://highlowtech.org/?p=1706
  * http://highlowtech.org/?p=1695

## Testing
Copy these lines into a new sketch for your blink test.

``` C++
int led = 3;  

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
```

## Buildnotes
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Attiny_Programmer/images/20220211_144756.jpg" width="600" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Attiny_Programmer/images/20220211_144345.jpg" width="400" />
<img src="https://raw.githubusercontent.com/PierreIsCoding/sdiy/main/Attiny_Programmer/images/20220211_144227.jpg" width="400" />



