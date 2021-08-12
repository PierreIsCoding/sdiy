// Code by L.Geerinckx 28-1-2021 | https://github.com/PierreIsCoding

#include "MyButtons.h"

class MyRotary
{
private:
    MyButtons *rotaryBtns;
    bool pinA;
    bool pinB;
    int dir = 0; // direction
    int pulseCounter = 0;

public:
    MyRotary(int, int);
    void begin();
    bool on();
    int checkDirection();
};

MyRotary::MyRotary(int _pinA, int _pinB)
{
    int pinArray[] = {
        _pinA,
        _pinB};
    rotaryBtns = new MyButtons(pinArray, 2, 0);
}

void MyRotary::begin()
{
    rotaryBtns->begin();
    pinA = rotaryBtns->checkButton(0);
    pinB = rotaryBtns->checkButton(1);
}

bool MyRotary::on()
{
    int previousDir = dir;

    if (rotaryBtns->on())
    {
        if (rotaryBtns->checkButton(0) && !rotaryBtns->checkButton(1))
        {
            if (!pinA && !pinB)
            {
                dir = -1;
            }
            else if (pinA && pinB)
            {
                dir = 1;
            }
        }

        if (!rotaryBtns->checkButton(0) && rotaryBtns->checkButton(1))
        {
            if (!pinA && !pinB)
            {
                dir = 1;
            }
            else if (pinA && pinB)
            {
                dir = -1;
            }
        }

        if (!rotaryBtns->checkButton(0) && !rotaryBtns->checkButton(1))
        {
            if (pinA && !pinB)
            {
                dir = 1;
            }
            else if (!pinA && pinB)
            {
                dir = -1;
            }
        }

        if (rotaryBtns->checkButton(0) && rotaryBtns->checkButton(1))
        {
            if (!pinA && pinB)
            {
                dir = 1;
            }
            else if (pinA && !pinB)
            {
                dir = -1;
            }
        }

        pinA = rotaryBtns->checkButton(0);
        pinB = rotaryBtns->checkButton(1);

        // every click of rotary encoder gives four pulses
        if (previousDir == dir && dir != 0)
        {
            pulseCounter++;
            if (pulseCounter == 4)
            {
                pulseCounter = 0;
                return true;
            }
        }
    };
    return false;
}

int MyRotary::checkDirection()
{
    return dir;
}
