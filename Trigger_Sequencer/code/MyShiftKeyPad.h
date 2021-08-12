// Code By L.Geerinckx 12-2-2021 // https://github.com/PierreIsCoding


class KeyPad
{
  private:
    byte _rows;
    byte _cols;
    byte *_rowPins;
    byte *reading;
    byte *lastButtonState;
    byte *buttonState;
    byte buttonTotal;
    byte _dataPin;
    byte _clockPin;
    byte _shiftBits;
    unsigned long lastDebounceTime=0;
    unsigned long debounceDelay;
  public:
    KeyPad(byte, byte[], byte, byte, byte);
    void begin();
    bool on();
    byte getPressed();
    bool virtualRead(byte);
};

KeyPad::KeyPad(byte rows, byte rowPins[], byte dataPin, byte clockPin, byte shiftBits=8)
{
    debounceDelay = 0;
    _rows = rows;
    _rowPins = new byte[rows];
    buttonTotal = shiftBits * rows;
    _dataPin = dataPin;
    _clockPin = clockPin;
    _shiftBits = shiftBits;

    reading = new byte[buttonTotal];
    lastButtonState = new byte[buttonTotal];
    buttonState = new byte[buttonTotal];

    // initialize arrays
    for (byte i = 0; i < rows; i++)
    {
        _rowPins[i] = rowPins[i];
    }

    for (byte i = 0; i < buttonTotal; i++)
    {
        lastButtonState[i] = 0;
        buttonState[i] = 0;
    }
}

void KeyPad::begin()
{
    pinMode(_dataPin, OUTPUT);  
    pinMode(_clockPin, OUTPUT);
    for (byte i = 0; i < _rows; i++)
    {
        pinMode(_rowPins[i], INPUT_PULLUP);
    }
}

bool KeyPad::on()
{
    bool flag = false;
    for (byte i = 0; i < _rows; ++i)
    {
        // set one high
        digitalWrite(_dataPin,LOW);
        delayMicroseconds(1); // for Teensy
        digitalWrite(_clockPin,HIGH);
        digitalWrite(_dataPin,HIGH);

        for (byte j = 0; j < _shiftBits; ++j)
        {
            byte index = i * _shiftBits + j;
            digitalWrite(_clockPin,HIGH);
            delayMicroseconds(1); // for Teensy
            digitalWrite(_clockPin,LOW);

            reading[index] = 1 - digitalRead(_rowPins[i]);
            if (reading[index] != lastButtonState[index]) // if change
            {
                lastDebounceTime = millis();
            }
            if ((millis() - lastDebounceTime) > debounceDelay) // check na een bepaalde tijd nog een keertje
            {
                if (reading[index] != buttonState[index])
                {
                    buttonState[index] = reading[index];
                    flag = true;
                }
            }
            lastButtonState[index] = reading[index];
        }
    }
    return flag;
}


byte KeyPad::getPressed()
{
    for (byte i = 0; i < buttonTotal; ++i)
    {
        if (reading[i] == 1)
        {
            return i;
        }
    }
    return -1;
}

bool KeyPad::virtualRead(byte num)
{
  return reading[num]==true;
}
