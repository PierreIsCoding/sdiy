// Code by L.Geerinckx 

class AnalogSwitch
{
  private:
    int **_arr;
    uint8_t _pin;
    float current;
    float oldValue;
    int _error;
    int _rows;
    int currentIndex;
    bool changed();

  public:
    AnalogSwitch(uint8_t, int, int arr[][2], int);
    bool onChange();
    int getCurrent();
};

AnalogSwitch::AnalogSwitch(uint8_t pin, int error, int arr[][2], int rows)
{
    _pin = pin;
    current = analogRead(_pin);
    oldValue = current;
    _error = error;
    _rows = rows;
    currentIndex = 0;
    _arr = new int *[rows];
    for (int i = 0; i < rows; ++i)
    {
        _arr[i] = new int[2];
        _arr[i][0] = arr[i][0];
        _arr[i][1] = arr[i][1];
    }
}

bool AnalogSwitch::changed()
{
    current = analogRead(_pin);
    int temp = abs(oldValue - current);

    if (temp > _error)
    {
        oldValue = current;
        
        return true;
    }
    return false;
}

bool AnalogSwitch::onChange()
{
    if (changed())
    {
        for (int i = 0; i < _rows; i++)
        {
            if (_arr[i][0] <= current && _arr[i][1] > current)
            {
                if (i != currentIndex)
                {
                    currentIndex = i;
                    return true;
                }
            }
        }
    }
    return false;
}


int AnalogSwitch::getCurrent()
{
//    Serial.println(currentIndex);
    return currentIndex;
}
