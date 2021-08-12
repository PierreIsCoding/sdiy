// Code by L.Geerinckx 28-1-2021 | https://github.com/PierreIsCoding

#include "MyTimer.h"
#include "MyRotary.h"
#include "MyButtons.h"
#include "MyScroll.h"
#include "MyShiftDisplay.h"
#include "MyPulse.h"
#include "MeasureTime.h"

MyShiftDisplay myDisplay;

MyPulse pulse_1(9, 160); // pin, buffer length
MyPulse pulse_2(10, 80); // pin, buffer length
MyPulse pulse_3(11, 40); // pin, buffer length
MyPulse pulse_4(12, 20); // pin, buffer length
MyTimer updatePulse(60, pulse_1.pulseLen);
MyTimer updateDisplay(150); // hz

MeasureTime tapTimer(6);

// ---------------------------- init  Scroll Functions ----------------------------
int scrollIndex = 0;
MyRotary myRotary(A3, A2);

void tempoHandler(int index)
{
    updatePulse.setFreq((float)index / 60);
}

MyScroll tempoScroll(251, tempoHandler, 0, 60); // max value, handler,min value=0, start=0, loop=0

void dutyHandler(int index)
{
    pulse_1.setDutyCycle((float)index / 100);
    pulse_2.setDutyCycle((float)index / 100);
    pulse_3.setDutyCycle((float)index / 100);
    pulse_4.setDutyCycle((float)index / 100);
}
MyScroll dutyCycleScroll(96, dutyHandler, 5, 50);

void swingHandler(int index)
{
    pulse_1.setSwing(1 - (float)index / 100);
    pulse_2.setSwing(1 - (float)index / 100);
    pulse_3.setSwing(1 - (float)index / 100);
    pulse_4.setSwing(1 - (float)index / 100);
}
MyScroll swingScroll(76, swingHandler);

MyScroll *allScrolls[3] = {&tempoScroll, &dutyCycleScroll, &swingScroll};

// ---------------------------- init  buttons ----------------------------

MyButtons pushButtons((int[5]){A1, 6, A4, A5, A0}, 5); // dutycycle, swing, rotary push, start/stop , tap-tempo

void checkButtons()
{
    if (pushButtons.on())
    {
        if (pushButtons.checkButton(2)) // Rotary Push
        {
            allScrolls[0]->toggleIncrement();
            allScrolls[1]->toggleIncrement();
            allScrolls[2]->toggleIncrement();
        }
        else if (pushButtons.checkButton(0)) // duty
        {
            scrollIndex = 1;
            myDisplay.setValue(allScrolls[1]->getIndex());
        }
        else if (pushButtons.checkButton(1)) // swing
        {
            scrollIndex = 2;
            myDisplay.setValue(allScrolls[2]->getIndex());
        }
        else if (pushButtons.checkButton(3)) // start/stop
        {
            updatePulse.toggleRun();
            if (!updatePulse.getState())
            {
                pulse_1.reset(false);
                pulse_2.reset(false);
                pulse_3.reset(false);
                pulse_4.reset(false);
            }
        }
        else if (pushButtons.checkButton(4)) // tap tempo
        {
            //            Serial.println("tap");
            tapTimer.addSample();
            int newBPM = tapTimer.getTiming();
            if (newBPM != -1)
            {
                updatePulse.setFreq((float)newBPM / 60);
                pulse_1.reset(HIGH);
                pulse_2.reset(HIGH);
                pulse_3.reset(HIGH);
                pulse_4.reset(HIGH);
                allScrolls[0]->setIndex(newBPM);
            }
        }
        else
        {
            scrollIndex = 0; // tempo
            myDisplay.setValue(allScrolls[0]->getIndex());
        }
    }

    if (myRotary.on())
    {
        if (myRotary.checkDirection() == 1)
        {
            allScrolls[scrollIndex]->UP();
        }
        else if (myRotary.checkDirection() == -1)
        {
            allScrolls[scrollIndex]->DOWN();
        }
        myDisplay.setValue(allScrolls[scrollIndex]->getIndex());
    }
}

// ---------------------------- SETUP & LOOP ----------------------------

void setup()
{
    Serial.begin(9600);
    Serial.println("start");
    myDisplay.begin();
    pulse_1.begin();
    pulse_2.begin();
    pulse_3.begin();
    pulse_4.begin();
    myRotary.begin();
    pushButtons.begin();
    updatePulse.setFreq(1);
}

void loop()
{

    if (updateDisplay.onTime())
    {
        myDisplay.updateNext();
    }

    if (updatePulse.onTime())
    {
        pulse_1.next();
        pulse_2.next();
        pulse_3.next();
        pulse_4.next();
    }

    checkButtons();
}
