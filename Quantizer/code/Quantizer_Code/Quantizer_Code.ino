
// Quantizer.
// Code by Luther / l.Geerinckx
// 12 March 2022

#include "MyPWM.h" // dual PWM 16 bit via D9 and D10
#include "MyButtons.h"
#include "MyAnalog.h"
#include "MyCharlieLeds.h"
#include "MyTrigger.h"
#include "MyDivision.h"
#include "MyLowPass.h"

// ------------------------- GLOBALS --------------------------------

#define semitone 1105 // <--------- CALIBRATION VALUE! This determines the PWM value between two intervals.

#define maxQntz 59   // 2^16/1105; Higher values will lead to overflow of 16 bit integers
#define biMonoPin 17 // uni-polar: 0V/+5V, bi-polar: -3.5V/+5V
#define trigPin 8
#define octaves 5       // 0-5 results in 4 octaves
#define glideFactor 100 // defines the increase in glide amounth
#define offsetCount 9   // defines transpose options

bool biCV = false;  // startup value of incomming CV range. uni-polar: 0V/+5V, bi-polar: -3.5V/+5V
byte shMode = true; // Sample & Hold mode
byte qntz;          // variable for storing quantized value;
byte note;
byte offset = 0; // transpose offset
byte glideIndex = 0;
byte btnState = 0; // binairy flags for storing button states [UP, DOWN, SCALE, TRANSPOSE, GLIDE]
uint16_t scaleIndex = 0;

LowPass glide(glideFactor * 6);                                 // buffer length
MyDivision checkUtils(100);                                     // checking utilities a bit slower so it is less intensive for CPU and usefull for slowing down glide.
MyAnalog adc(A4, 10, octaves * 12);                             // pin, error margin, max value (5*12 semitones).
byte transpose[offsetCount] = {0, 2, 4, 7, 10, 12, 24, 36, 48}; // transpose intervals

// ------------------------- SCALES --------------------------------

// integer notation of scales and triads  https://en.wikipedia.org/wiki/Pitch_class#Integer_notation
// http://musictheoryfundamentals.com/MusicTheory/modes.php
// first element stores length of array

byte scales[12][13] = {
    {12, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, // Chromatic scale
    {7, 0, 2, 4, 5, 7, 9, 10, 0, 0, 0, 0, 0},   // Major scale
    {7, 0, 2, 3, 5, 7, 8, 10, 0, 0, 0, 0, 0},   // Minor scale
    {7, 0, 2, 3, 5, 7, 9, 10, 0, 0, 0, 0, 0},   // Dorian scale
    {5, 0, 2, 4, 7, 9, 0, 0, 0, 0, 0, 0, 0},    // Pentatonic scale
    {6, 0, 3, 5, 6, 7, 10, 0, 0, 0, 0, 0, 0},   // Blues scale
    {7, 0, 2, 4, 5, 7, 9, 10, 0, 0, 0, 0, 0},   // Mixolydian scale
    {3, 0, 4, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0},    // major triad (0-4-7)
    {3, 0, 3, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0},    // minor triad (0-3-7)
    {3, 0, 4, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0},    // Augmented triad (0-4-8)
    {3, 0, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0},    // Diminshed triad (0-3-6)
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},    // Octave
};

byte scaleLen = scales[scaleIndex][0];

// ------------------------- LEDS --------------------------------

byte charliePins[4] = {2, 3, 4, 5};   // pins
MyCharlieLeds myLeds(charliePins, 4); // array of pins for charlieplexing, number of pins

byte ledNoteMap[12] = {11, 10, 8, 5, 4, 7, 0, 1, 3, 6, 2, 9};  // remaps the indexes for the Charlie Plexing LEDS
byte ledLogicMap[12] = {11, 8, 4, 7, 1, 6, 9, 10, 5, 0, 3, 2}; // remaps the indexes for the Charlie Plexing LEDS

// ------------------------- OUTPUT TRIGGER --------------------------------

void triggerHandler(bool on)
{
    digitalWrite(trigPin, on);
}

MyTrigger triggerOut(triggerHandler, 10); // handler, countdown (speed also depends on CPU speed)

// ------------------------- BUTTONS --------------------------------

// button press logic
void btnHandler(byte index, button type)
{
    if (type == PRESSED)
    {
        if (index == 0) // UP
        {
            if (bitRead(btnState, 1)) // UP + DOWN = toggle polarity
            {
                biCV = !biCV;
                digitalWrite(biMonoPin, biCV);
            }
            else if (bitRead(btnState, 2)) // UP + SCALE
            {
                scaleIndex = scaleIndex < 11 ? scaleIndex + 1 : 0;
                myLeds.printLed(ledLogicMap[scaleIndex]);
            }
            else if (bitRead(btnState, 3)) // UP + TRANSPOSE
            {
                offset = offset < (offsetCount - 1) ? offset + 1 : 0;
                myLeds.printLed(ledNoteMap[transpose[offset] % 12]);
            }
            else if (bitRead(btnState, 4)) // UP + GLIDE
            {
                glideIndex = glideIndex < 6 ? glideIndex + 1 : 0;
                myLeds.printLed(ledLogicMap[glideIndex]);
                glide.setCutOff(glideIndex * glideFactor);
            }
            bitWrite(btnState, 0, 1);
        }
        else if (index == 1) // DOWN
        {
            if (bitRead(btnState, 0)) // UP + DOWN = toggle polarity
            {
                biCV = !biCV;
                digitalWrite(biMonoPin, biCV);
            }
            else if (bitRead(btnState, 2)) // DOWN + SCALE
            {
                scaleIndex = scaleIndex > 0 ? scaleIndex - 1 : 11;
                myLeds.printLed(ledLogicMap[scaleIndex]);
            }
            else if (bitRead(btnState, 3)) // DOWN + TRANSPOSE
            {
                offset = offset > 0 ? offset - 1 : (offsetCount - 1);
                myLeds.printLed(ledNoteMap[transpose[offset] % 12]);
            }
            else if (bitRead(btnState, 4)) // DOWN + GLIDE
            {
                glideIndex = glideIndex > 0 ? glideIndex - 1 : 6;
                myLeds.printLed(ledLogicMap[glideIndex]);
                glide.setCutOff(glideIndex * glideFactor);
            }
            bitWrite(btnState, 1, 1);
        }
        else if (index == 2) // SCALE or GLIDE
        {
            if (bitRead(btnState, 3)) // GLIDE
            {
                myLeds.printLed(ledLogicMap[glideIndex]);
                bitWrite(btnState, 3, 0);
                bitWrite(btnState, 4, 1);
            }
            else // SCALE
            {
                bitWrite(btnState, 2, 1);
                myLeds.printLed(ledLogicMap[scaleIndex]);
            }
        }
        else if (index == 3) // TRANSPOSE or GLIDE
        {
            if (bitRead(btnState, 2)) // GLIDE
            {
                myLeds.printLed(ledLogicMap[glideIndex]);
                bitWrite(btnState, 2, 0);
                bitWrite(btnState, 4, 1);
            }
            else // TRANSPOSE
            {
                bitWrite(btnState, 3, 1);
                myLeds.printLed(ledNoteMap[transpose[offset % 12]]);
            }
        }

        scaleLen = scales[scaleIndex][0];
        adc.setMax(octaves * scaleLen);
        quantize(adc.getCurrent());
    }
    else // release
    {
        if (index == 0) // UP
        {
            bitWrite(btnState, 0, 0);
        }
        else if (index == 1) // DOWN
        {
            bitWrite(btnState, 1, 0);
        }
        else
        {
            btnState = 0; // release all buttons
            myLeds.printLed(ledNoteMap[note]);
        }
    }
}

byte btnPins[4] = {15, 16, 11, 12};         //UP, DOWN , ATTENUATE, TRANSPOSE
MyButtons btns(btnPins, 4, btnHandler, 50); // buttonpins, pin count, handler, debounce time

// ------------------------- CLOCK IN --------------------------------

void clockHandler(byte index, button type)
{
    if (index == 0)
    {
        if (type == PRESSED)
        {
            quantize(adc.read());
        }
    }
    else
    {
        shMode = type == RELEASED ? true : false; // set sample and hold mode if a cable is plugged into the clock jack
    }
}

byte clockPins[2] = {14, 7};                      // clock, check clock jack
MyButtons clockIn(clockPins, 2, clockHandler, 0); // buttonpins, pin count, handler, debounce

// ------------------------- HELPER FUNCTIONS --------------------------------

void quantize(byte val)
{
    qntz = val + transpose[offset];
    static byte oldQntz;
    byte division = qntz / scaleLen;
    byte remainder = qntz % scaleLen;
    note = scales[scaleIndex][remainder + 1];

    qntz = division * 12 + note;
    qntz = qntz < maxQntz ? qntz : maxQntz; // preventing overflow

    if (qntz != oldQntz)
    {
        triggerOut.start();
        oldQntz = qntz;
        if (btnState == 0)
        {
            myLeds.printLed(ledNoteMap[note]); // index 0-11;
        }
    }
}

// ------------------------- SETUP & LOOP --------------------------------

void setup()
{
    //    Serial.begin(9600);
    //    Serial.println("start");
    MyPWM::init();
    btns.begin();
    clockIn.begin();
    myLeds.printLed(ledNoteMap[scaleIndex]);
    pinMode(trigPin, OUTPUT);
    pinMode(biMonoPin, OUTPUT);
    digitalWrite(biMonoPin, biCV);
}

void loop()
{
    if (checkUtils.onNext())
    {
        if (!shMode)
        {
            if (adc.onChange())
            {
                quantize(adc.getCurrent());
            }
        }

        MyPWM::write(glide.getNext(qntz * semitone)); // write result to DAC
        triggerOut.next();
        btns.on();
        clockIn.on();
    }
}
