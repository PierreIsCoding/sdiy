// Code by L.Geerinckx 28-1-2021 | https://github.com/PierreIsCoding


class MyPulse
{
private:
    int bufferIndex = 0;
    int pin;
    void makePulse();
    void addPulse(int);
    float dutyCycle;
    int *pulseBuffer;
    float swing;

public:
    MyPulse(int, int, float,float);
    int bufferLen;
    int pulseLen;
    void setDutyCycle(float);
    void setSwing(float);
    void next();
    int getCurrent();
    void begin();
    void reset(int);
};

MyPulse::MyPulse(int _pin, int len, float duty = 0.5, float _swing=1)
{
    pin = _pin;
    bufferLen = len;
    pulseLen=(float)len/2;
    pulseBuffer = new int[bufferLen];
    dutyCycle = duty;
    swing=_swing;
}

void MyPulse::begin()
{
    pinMode(pin, OUTPUT);
    makePulse();
}

void MyPulse::setDutyCycle(float _dutyCycle)
{
    dutyCycle = _dutyCycle;
    makePulse();
}

void MyPulse::setSwing(float _swing)
{
    swing=_swing;
    makePulse();
}

void MyPulse::makePulse()
{
    for (int i = 0; i < bufferLen ; i++)
    {
        pulseBuffer[i] = 0;
    }
    addPulse(0);
    int temp = (float)pulseLen*swing;
    addPulse(temp);
}

void MyPulse::addPulse(int offset)
{
    for (int i = offset; i < offset+(float)pulseLen*dutyCycle; i++)
    {
        pulseBuffer[i] = 1;
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

    digitalWrite(pin, pulseBuffer[bufferIndex]);
}

int MyPulse::getCurrent()
{
    return pulseBuffer[bufferIndex];
}

void MyPulse::reset(int resetValue){
  bufferIndex = 0;
  digitalWrite(pin, resetValue);
}
