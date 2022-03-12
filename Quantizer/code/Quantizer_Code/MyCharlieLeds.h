
// Code by Luther / l.Geerinckx
// 12 March 2022


class MyCharlieLeds
{
private:
    byte *_pinArray;
    byte _pinNum;
    byte _ledNum;
    byte **_ledCombis;
    byte _factorial(byte);
    byte _nCr(byte, byte);

public:
    MyCharlieLeds(byte[], byte);
    void printLed(byte);
    void printCombis();  // usefull for debugging
};

MyCharlieLeds::MyCharlieLeds(byte pinArray[], byte pinNum)
{
    _pinNum = pinNum;               // number of pins
    _pinArray = new byte[_pinNum];  // array of pins
    _ledNum = _nCr(_pinNum, 2) * 2; // calculates the max possible combinations of charlieplexed leds

    _ledCombis = new byte *[_ledNum]; // create a 2-dimensional array and populate it with the default value (INPUT)
    for (byte i = 0; i < _ledNum; i++)
    {
        _ledCombis[i] = new byte[_pinNum];
        for (byte j = 0; j < _pinNum; j++)
        {
            _ledCombis[i][j] = 3; // INPUT
        }
    }

    byte ledIndex = 0;
    while (ledIndex < _ledNum) // pupulate 2-dimensional array with all possible combinations
    {
        for (byte j = 0; j < _pinNum; j++)
        {
            for (byte k = 0; k < _pinNum; k++)
            {
                if (k != j)
                {
                    _ledCombis[ledIndex][j] = 1; // HIGH
                    _ledCombis[ledIndex][k] = 0; // LOW
                    ledIndex++;
                }
            }
        }
    }

    // populate ledPin array
    for (byte i = 0; i < _pinNum; ++i)
    {
        _pinArray[i] = pinArray[i];
    }
}

// --------------HELPER FUNCTIONS -----------------

byte MyCharlieLeds::_factorial(byte n)
{
    byte factorial = 1;
    for (byte i = 2; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}

byte MyCharlieLeds::_nCr(byte n, byte r)
{
    return _factorial(n) / (_factorial(r) * _factorial(n - r));
}

void MyCharlieLeds::printCombis()
{
    for (byte i = 0; i < _ledNum; i++)
    {
        for (byte j = 0; j < _pinNum; j++)
        {
            if (_ledCombis[i][j] == 0)
            {
                Serial.print("LOW");
            }
            else if (_ledCombis[i][j] == 1)
            {
                Serial.print("HIGH");
            }
            else
            {
                Serial.print("INPUT");
            }
            Serial.print(",");
        }
        Serial.println("");
    }
}

// --------------MAIN FUNCTIONS -----------------

void MyCharlieLeds::printLed(byte index)
{
    for (byte j = 0; j < _pinNum; j++)
    {
        if (_ledCombis[index][j] == 0)
        {
            pinMode(_pinArray[j], OUTPUT);
            digitalWrite(_pinArray[j], LOW);
        }
        else if (_ledCombis[index][j] == 1)
        {
            pinMode(_pinArray[j], OUTPUT);
            digitalWrite(_pinArray[j], HIGH);
        }
        else
        {
            pinMode(_pinArray[j], INPUT);
        }
    }
}
