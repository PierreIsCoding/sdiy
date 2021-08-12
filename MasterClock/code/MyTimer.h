// Code by L.Geerinckx 28-1-2021 | https://github.com/PierreIsCoding
#ifndef MYTIMER_H
#define MYTIMER_H


class MyTimer
{
private:
    unsigned long currentMicros;
    unsigned long previousMicros = 0;
    double period=0;
    int _scalar;
    bool runTimer=true;

public:
    MyTimer(double,int);
    bool onTime();
    void setFreq(double);
    void start();
    void stop();
    void toggleRun();
    bool getState();
};

MyTimer::MyTimer(double freq, int scalar=1)
{
    _scalar=scalar;
    setFreq(freq);
}

bool MyTimer::onTime()
{
    if (runTimer){
      currentMicros = micros();
      if (currentMicros - previousMicros >= period)
      {
          previousMicros=currentMicros;
          return true;
      }      
    }

    return false;
}

void MyTimer::setFreq(double freq){
  period = 1000000/(freq * _scalar);
}

void MyTimer::start(){
  runTimer=true;
}

void MyTimer::stop(){
  runTimer=false;
}

void MyTimer::toggleRun(){
  runTimer=!runTimer;
}

bool MyTimer::getState(){
  return runTimer;
}

#endif
