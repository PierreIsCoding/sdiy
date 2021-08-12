// Code By L.Geerinckx 12-2-2021 // https://github.com/PierreIsCoding


#ifndef MYSEQUENCE_H
#define MYSEQUENCE_H

#include "MyPulse.h"

class MySequence
{
private:
    byte playStep = 0;
    byte previousStep = 0;
    byte pulseCounter = 0;
    byte sequenceLength = 8;
    byte stepValues[32] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    byte divisions[4]={1,2,3,4};
    byte euclidianSteps = 1;
    byte outPin;
    MyLedMatrix *leds;
    MyPulse *outPulse;
    bool playProbability = false;
    bool needsNewProbability = false;
    byte shiftPosition = 1;
    byte scalar = 1;
    byte clockDivider = 0;

    byte stepToIndex(byte);
    bool play = true;
    byte pulsesPerStep;
    bool show = false;
    byte factorCount; // division or multiplication of incomming pulses
    byte burstPlay = 0;
    byte triggerMode = 0;
    bool editCursor = false;
    byte editStep = 0;
    byte dutyCycle = 4; // 4=50%

public:
    MySequence(MyLedMatrix *, byte, byte);
    void begin();
    void showSequence();
    void shiftSequence(bool);
    void scrollEuclidian(bool);
    void scrollStepValue(bool);
    void nextPulse();
    void enforceNext();
    void setShow(bool);
    void stepUP();
    void stepDOWN();
    void scrollLength(bool);
    void randStepValue();
    void randStepPosition();
    void clearSequence();
    void showLength();
    void deployEuclidian();
    void setPlay(bool);
    void shiftValues(bool);
    void scrollTrigger(bool);
    void trigger(bool);
    void setEditMode(bool);
    void scrollEditStep(bool);
    void scrollDutyCycle(bool);
    void showDutyCycle();
    void scrollDivision(bool);
    void showDivision();
};

MySequence::MySequence(MyLedMatrix *_leds, byte _outPin, byte _scalar)
{
    scalar = _scalar;
    pulsesPerStep = 1 * scalar;
    leds = _leds;
    outPin = _outPin;
    outPulse = new MyPulse(pulsesPerStep);
}

void MySequence::begin()
{
    pinMode(outPin, OUTPUT);
    outPulse->begin();
}

byte MySequence::stepToIndex(byte step)
{
    if (step < 8)
    {
        return 0;
    }
    else if (step < 16)
    {
        return 1;
    }
    else if (step < 24)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

void MySequence::showSequence()
{
    byte step = editCursor ? editStep : playStep;
    if (show)
    {
        leds->clearBuffer();
        for (byte i = 0; i < 8; i++)
        {
            byte value = stepValues[i + stepToIndex(step) * 8];
            if (value != 0)
            {
                leds->setPixel(value - 1, i, 1);
            }
            else
            {
                leds->setPixel(0, i, 0);
            }
        }
        leds->setPixel(7, triggerMode, 1); // show trigger mode
        byte index = stepToIndex(step);
        if(play){
            leds->setPixel(5, step - index * 8, 1); // show step          
        }

        leds->verticalLine(6, 0, index + 1, 1); // show page
        leds->print();
    }
}

void MySequence::stepUP()
{
    pulseCounter = 0;
    previousStep = playStep;
    needsNewProbability = true;
    if (playStep < sequenceLength - 1)
    {
        playStep++;
    }
    else
    {
        playStep = 0;
        if (burstPlay > 1)
        {
            burstPlay--;
        }
        else if (burstPlay == 1)
        {
            play = false;
        }
    }
    showSequence();
}

void MySequence::stepDOWN()
{
    previousStep = playStep;
    playStep = playStep > 0 ? playStep - 1 : sequenceLength - 1;
    showSequence();
}

void MySequence::nextPulse()
{
        pulseCounter++;
        if (pulseCounter >= pulsesPerStep)
        {
            stepUP();
        }
        if (stepValues[playStep] == 1)
        {
            if (play){
                digitalWrite(outPin, outPulse->getCurrent());              
            }

            outPulse->next();
        }
        else if (stepValues[playStep] > 1) // probability
        {
            if (needsNewProbability)
            {
                byte test = random(50);
                playProbability = test > stepValues[playStep] * 10 - 10;
                needsNewProbability = false;
            }

            if (playProbability)
            {
                digitalWrite(outPin, outPulse->getCurrent());
                outPulse->next();
            }
        }
        else
        {
            digitalWrite(outPin, LOW);
        }
}

void MySequence::enforceNext()
{
    pulseCounter = pulsesPerStep;
    outPulse->reset(); // reset pulses
    //    Serial.println("enforce");
}

void MySequence::shiftSequence(bool dir)
{
    byte temp[sequenceLength];

    if (dir == 1)
    {
        temp[0] = stepValues[sequenceLength - 1];
        for (byte i = 0; i < sequenceLength - 1; i++)
        {
            temp[i + 1] = stepValues[i];
        }
    }
    else
    {
        temp[sequenceLength - 1] = stepValues[0];
        for (byte i = 0; i < sequenceLength - 1; i++)
        {
            temp[i] = stepValues[i + 1];
        }
    }
    for (byte i = 0; i < sequenceLength; i++)
    {
        stepValues[i] = temp[i];
    }
    showSequence();
}

void MySequence::setShow(bool value)
{
    show = value;
}

void MySequence::clearSequence()
{
    for (byte i = 0; i < 32; i++)
    {
        stepValues[i] = 0;
    }
}

void MySequence::scrollEuclidian(bool dir)
{
    if (dir == 1)
    {
        if (euclidianSteps < sequenceLength - 1)
        {
            euclidianSteps++;
        }
        else
        {
            euclidianSteps = sequenceLength;
        }
    }
    else
    {
        if (euclidianSteps > 1)
        {
            euclidianSteps--;
        }
    }
    deployEuclidian();
}

void MySequence::deployEuclidian()
{
    clearSequence();
    float delta = float(sequenceLength) / float(euclidianSteps);
    float counter = 0;
    for (byte i = 0; i < euclidianSteps; i++)
    {
        counter += delta;
        stepValues[sequenceLength - byte(counter)] = shiftPosition;
    }
    showSequence();
}

void MySequence::scrollStepValue(bool dir)
{
    if (dir == 1 && stepValues[editStep] < 5)
    {
        stepValues[editStep]++;
    }
    else if (dir == 0 && stepValues[editStep] > 0)
    {
        stepValues[editStep]--;
    }
    showSequence();
}

void MySequence::setPlay(bool val)
{
    play = val;
}

void MySequence::scrollLength(bool dir)
{
    if (dir && sequenceLength < 32)
    {
        sequenceLength++;
    }
    else if (!dir && sequenceLength > 2)
    {
        sequenceLength--;
    }
    if (euclidianSteps > sequenceLength)
    {
        euclidianSteps = sequenceLength;
    }
    if (editStep > sequenceLength)
    {
        editStep = sequenceLength - 1;
    }
}

void MySequence::randStepValue()
{
    for (int i = 0; i < sequenceLength; i++)
    {
        if (stepValues[i] != 0)
        {
            stepValues[i] = random(1, 5);
        }
    }
    showSequence();
}

void MySequence::randStepPosition()
{
    for (int i = 0; i < sequenceLength; i++)
    {
        stepValues[random(0, sequenceLength)] = random(0, 2);
    }
    showSequence();
}

void MySequence::showLength()
{
    leds->clearBuffer();
    for (byte i = 0; i < sequenceLength; i++)
    {
        int index = stepToIndex(i);
        leds->setPixel(index, i - index * 8, 1);
    }
    leds->print();
}

void MySequence::shiftValues(bool dir)
{
    leds->clearBuffer();

    if (dir && shiftPosition < 5)
    {
        shiftPosition++;
    }
    else if (!dir && shiftPosition > 1)
    {
        shiftPosition--;
    }

    for (byte i = 0; i < sequenceLength; i++)
    {
        if (dir && stepValues[i] < 5 && stepValues[i] != 0)
        {
            stepValues[i]++;
        }
        else if (!dir && stepValues[i] > 1)
        {
            stepValues[i]--;
        }
    }
    showSequence();
}

void MySequence::scrollTrigger(bool dir)
{
    if (dir && triggerMode < 7)
    {
        triggerMode++;
    }
    else if (!dir && triggerMode > 0)
    {
        triggerMode--;
    }
    showSequence();
    burstPlay = 0;
    play = triggerMode == 0 ? true : play;
}

void MySequence::trigger(bool value)
{
    if (value)
    {
        if (triggerMode == 1) // toggle play
        {
            play = !play;
        }
        else if (triggerMode == 3) // shift
        {
            play = true;
            shiftSequence(true);
        }
        else if (triggerMode == 4) // Reset step
        {
            play = true;
            playStep = sequenceLength;
        }
        else if (triggerMode == 5) // burst play
        {
            burstPlay = 2;
            play = true;
            playStep = sequenceLength;
//            enforceNext();
        }
        else if (triggerMode == 6) // Random 1
        {
            play = true;
            randStepPosition();
        }
        else if (triggerMode == 7) // Random 2
        {
            play = true;
            randStepValue();
        }
    }
    if (triggerMode == 2)
    {
        play = value;
    }
    if(!play){
       digitalWrite(outPin, LOW);    
    }
}

void MySequence::setEditMode(bool value)
{
    editCursor = value;
    editStep = playStep;
}

void MySequence::scrollEditStep(bool dir)
{
    if (dir && editStep < sequenceLength - 1)
    {
        editStep++;
    }
    else if (!dir && editStep > 0)
    {
        editStep--;
    }
    showSequence();
}

void MySequence::scrollDutyCycle(bool dir)
{
    if (dir && dutyCycle < 6)
    {
        dutyCycle++;
    }
    else if (!dir && dutyCycle > 1)
    {
        dutyCycle--;
    }
    float temp = (float)dutyCycle * 0.125;
    outPulse->setDutyCycle(temp);
    showDutyCycle();
}

void MySequence::showDutyCycle()
{
    leds->clearBuffer();
    leds->horizontalLine(0, 1, dutyCycle, 1);
    leds->verticalLine(dutyCycle, 1, 6, 1);
    leds->horizontalLine(dutyCycle, 6, 8 - dutyCycle, 1);
    leds->print();
}

void MySequence::scrollDivision(bool dir)
{
    if (dir && clockDivider < 3)
    {
        clockDivider++;
    }
    else if (!dir && clockDivider > 0)
    {
        clockDivider--;
    }

    pulsesPerStep = scalar /divisions[clockDivider];
    outPulse = new MyPulse(pulsesPerStep);
    outPulse->begin();
    showDivision();
}

void MySequence::showDivision()
{
    leds->clearBuffer();
    leds->verticalLine(2, 4, 1, 1);
    leds->verticalLine(3, 3, 2, 1);
    leds->verticalLine(4, 2, 3, 1);
    leds->verticalLine(5, 1, 4, 1);
    leds->togglePixel(clockDivider+2, 6);
    leds->print();
}

#endif
