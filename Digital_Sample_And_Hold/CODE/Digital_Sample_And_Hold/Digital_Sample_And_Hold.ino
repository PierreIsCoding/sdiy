// Digital Sample and Hold.
// Code by Luther / l.Geerinckx

#include "MyPWM.h" // dual PWM 16 bit
#include "MyButtons.h"

#define attenuatePin 0    // Sets range of random cv 
#define clockPin 2        // Incomming clock
#define gatePin 8         // Gate out
#define cableCheckPin 1   // Checks if a signal cable is inserted
#define clockModePin 3    // Clock mode: 1:1 (momentary) or 1:2 (toggle)
#define comparePin 7      // ADC
#define qtzModePin 4      // Quantize mode: continues, quantized

// -----------------------------------
uint16_t fiveOctaves = 20250; // <--------------- CALIBRATION VALUE !!

float pwmNote = (float)fiveOctaves / (5 * 12);
uint16_t dacValue = 0;
uint16_t delta;
bool clockState = false;

// -----------------------------------

void clockHandler(byte index, button type)
{
    // when signal cable is inserted use attuante pot for setting probability
    if(digitalRead(cableCheckPin) == LOW && random(1000) > analogRead(attenuatePin))return;
  
    if (digitalRead(clockModePin) == HIGH && type == PRESSED)  // toggle gate
    {
        clockState = !clockState;
        if (!clockState)
        {
             digitalWrite(gatePin, LOW);
        }
    }
    else if (digitalRead(clockModePin) == LOW && type == PRESSED)  // momentary clock
    {
        clockState = true;
    }
    else if (digitalRead(clockModePin) == LOW && type == RELEASED)
    {
         digitalWrite(gatePin, LOW);
    }

    if (type == PRESSED && clockState)  // 
    {
        if (digitalRead(cableCheckPin) == LOW) // when cable is inserted: check incomming CV
        {
            search();
        }
        else // when no signal cable is inserted: generate random CV instead and use attanuate pot for setting range
        {
            dacValue = random(0, fiveOctaves * 1.5) * analogRead(attenuatePin) / 1024 + 32768;
        }
        quantize();
//        MyPWM::write(dacValue); // only for test
        digitalWrite(gatePin, HIGH);
    }
}

byte clockPins[1] = {clockPin};
MyButtons clockIn(clockPins, 1, clockHandler, 0); // buttonpins, pin count, handler, debounce

void quantize()
{
    if (!digitalRead(qtzModePin))  // if quantize is on (pin inverted)
    {
        byte note = dacValue / pwmNote;
        if ((float)dacValue / pwmNote - note > 0.5) // round up if needed
            note++;
        MyPWM::write((float)note * pwmNote);
    }
    else
    {
        MyPWM::write(dacValue);
    }
}

void adjustDac()
{
    if (!digitalRead(comparePin)) // if search signal > input signal
    {
        dacValue = dacValue - delta;
    }
    else
    {
        dacValue = dacValue + delta;
    }
}

void search()
{
    delta = 65536 / 4;
    dacValue = 65536 / 2;
    while (delta > 65536 / 16) // fast and course search
    {
        MyPWM::write(dacValue);
        adjustDac();
        delta = delta / 4;
    }

    while (delta > 0) // slower and fine search
    {
        MyPWM::write(dacValue);
        delayMicroseconds(200);
        adjustDac();
        delta = delta / 1.1;
    }
}

// -----------------------------------

void setup()
{
    pinMode(comparePin, INPUT_PULLUP);
    pinMode(qtzModePin, INPUT_PULLUP);
    pinMode(clockModePin, INPUT_PULLUP);
    pinMode(cableCheckPin, INPUT);
    pinMode(gatePin, OUTPUT);

    clockIn.begin();
    MyPWM::init();
}

void loop()
{
    clockIn.on();
}
