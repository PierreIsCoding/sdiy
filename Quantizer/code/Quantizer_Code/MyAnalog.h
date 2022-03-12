

// Code by Luther / l.Geerinckx
// 12 March 2022

class MyAnalog
{
  private:
    byte pin;
    float current;
    float oldValue;
    int error;
    uint16_t maxValue;

  public:
    MyAnalog(byte, int, uint16_t);
    bool changed;
    bool onChange();
    uint16_t getCurrent();
    void setMax(uint16_t);
    uint16_t read();
};

MyAnalog::MyAnalog(byte _pin, int _error, uint16_t _maxValue)
{
    pin = _pin;
    current = analogRead(_pin);
    oldValue = current;
    changed = false;
    error = _error;
    maxValue = _maxValue;
}


bool MyAnalog::onChange()
{
    current = analogRead(pin);
    if (current - oldValue > error || oldValue - current > error)
    {
        oldValue = current;
        return true;
    }
    return false;
}

void MyAnalog::setMax(uint16_t _maxValue){
  maxValue = _maxValue;
}

uint16_t MyAnalog::getCurrent(){
  return maxValue*(current/1024);  // 10 bit ADC
}

uint16_t MyAnalog::read(){
  current = analogRead(pin);
  return maxValue*(current/1024);  // 10 bit ADC
}
