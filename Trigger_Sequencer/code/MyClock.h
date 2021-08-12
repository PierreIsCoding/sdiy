// Code By L.Geerinckx 12-2-2021 // https://github.com/PierreIsCoding

#include "MyTimer.h"

class MyClock
{
private:
    unsigned long currentMillis;
    unsigned long previousMillis = 0;
    MyTimer *clockTimer;
    int pulseCount = 0;
    int errorCount=0;
    int error;

public:
    MyClock(byte);
    bool onTime();
    void update();
    byte pulsesPerStep;
};

MyClock::MyClock(byte _num)
{
    pulsesPerStep = _num;
    clockTimer = new MyTimer(10, pulsesPerStep);
}

bool MyClock::onTime()
{
    if (clockTimer->onTime())
    {
//        errorCount++;
        if (pulseCount < pulsesPerStep)
        {
            pulseCount++;
            return true;
        }
    };
    return false;
}

void MyClock::update()
{
//    Serial.print(errorCount);
//    Serial.print(",");
    
//    error=pulsesPerStep-errorCount;
    currentMillis = micros();
    float BPM = 60 / ((currentMillis - previousMillis) * 0.000001); // calculate time between incomming cv
    Serial.println(BPM);
    previousMillis = currentMillis;
    clockTimer->setFreq(BPM / 60); // adjust clock frequency
    pulseCount = 0;
    errorCount=0;


}
