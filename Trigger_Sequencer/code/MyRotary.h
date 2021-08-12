// Code By L.Geerinckx 12-2-2021 // https://github.com/PierreIsCoding

class MyRotary
{
private:
    byte pinA;
    byte pinB;
    bool readA;
    bool readB;
    bool prevA;
    bool prevB;
    bool dir = 0; // direction
    byte pulseCounter = 0;

public:
    MyRotary(byte, byte);
    void begin();
    bool on();
    bool getDirection();
};

MyRotary::MyRotary(byte _pinA, byte _pinB)
{
    pinA = _pinA;
    pinB = _pinB;
}

void MyRotary::begin()
{
    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);
    readA = digitalRead(pinA);
    readB = digitalRead(pinB);
}

bool MyRotary::on()
{
    bool previousDir = dir;
    readA = digitalRead(pinA);
    readB = digitalRead(pinB);

    if (readA != prevA || readB != prevB)
    {
        if (readA && !readB)
        {
            if (!prevA && !prevB)
            {
                dir = 0;
            }
            else if (prevA && prevB)
            {
                dir = 1;
            }
        }

        if (!readA && readB)
        {
            if (!prevA && !prevB)
            {
                dir = 1;
            }
            else if (prevA && prevB)
            {
                dir = 0;
            }
        }

        if (!readA && !readB)
        {
            if (prevA && !prevB)
            {
                dir = 1;
            }
            else if (!prevA && prevB)
            {
                dir = 0;
            }
        }

        if (readA && readB)
        {
            if (!prevA && prevB)
            {
                dir = 1;
            }
            else if (prevA && !prevB)
            {
                dir = 0;
            }
        }
        prevA = readA;
        prevB = readB;

        // every click of rotary encoder gives four pulses
        if (previousDir == dir)
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

bool MyRotary::getDirection()
{
    return dir;
}
