// Code By L.Geerinckx 12-2-2021 // https://github.com/PierreIsCoding


#ifndef MYTIMER_H
#define MYTIMER_H


class MyTimer
{
private:
    unsigned long currentMicros;
    unsigned long previousMicros = 0;
    float period=0;
    byte _scalar;
    bool runTimer=true;

public:
    MyTimer(float,byte);
    bool onTime();
    void setFreq(float);
    void start();
    void stop();
    bool getState();
};

MyTimer::MyTimer(float freq, byte scalar=1)
{
    _scalar=scalar;
    setFreq(freq);
}

bool MyTimer::onTime()
{
    currentMicros = micros();
    if (currentMicros - previousMicros >= period)
    {
        previousMicros=currentMicros;

        return true;
    }      
    return false;
}

void MyTimer::setFreq(float freq){
  period = 1000000/(freq * _scalar);
  previousMicros=0;
}

void MyTimer::start(){
  runTimer=true;
}

void MyTimer::stop(){
  runTimer=false;
}

bool MyTimer::getState(){
  return runTimer;
}

#endif
