// Code By L.Geerinckx 12-2-2021 // https://github.com/PierreIsCoding


#ifndef MYPULSE_H
#define MYPULSE_H


class MyPulse
{
private:
    byte bufferIndex = 0;
    void makePulse();
    float dutyCycle=0.5;
    byte *pulseBuffer;

public:
    MyPulse( byte);
    byte bufferLen;
    void setDutyCycle(float);
    void next();
    bool getCurrent();
    void begin();
    void reset();
};

MyPulse::MyPulse(byte len)
{
    pulseBuffer = new byte[len];
    bufferLen=len;
}

void MyPulse::begin()
{
    makePulse();
}

void MyPulse::setDutyCycle(float _dutyCycle)
{
    dutyCycle = _dutyCycle;
    makePulse();
}


void MyPulse::makePulse()
{
    byte counter=0;
    for (byte i = 0; i < (float)bufferLen*dutyCycle ; i++)
    {
        pulseBuffer[i] = 1;
        counter++;
    }
    for (byte i = counter; i < bufferLen ; i++)
    {
        pulseBuffer[i] = 0;
    }
}

void MyPulse::next()
{
    if (bufferIndex < bufferLen - 1)
    {
        bufferIndex++;
    }
    else
    {
        bufferIndex = 0;
    }
}

bool MyPulse::getCurrent()
{
    return pulseBuffer[bufferIndex];
}

void MyPulse::reset(){
  bufferIndex = 0;
}

#endif
