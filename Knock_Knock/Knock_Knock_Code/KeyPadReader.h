
// KeyPadReader.h
// Code by L. Geerinckx.
// Reading buttons via an 74hc595 shift register
// This building block requires ShiftPrinter.h

// 14 = PLAY_BTN (0)
// 13 = DIVISION_BTN (1)
// 12 = LENGTH_BTN (2)
// 11 = SHIFT_BTN (3)
// 10 = CLOCK_BTN (4)
// 1 = ROTARY_BTN (5)

byte btnMap[6] = {14, 13, 12, 11, 10, 1}; // maps the correct indexes to shift register

enum button {
  RELEASED,
  PRESSED,
};

class KeyPadReader {
  private:
    byte _commonPin;
    byte _btnLen;
    ShiftPrinter *_shift;
    byte *_readBuffer;
    byte *_btnState;
    byte *_lastBtnState;
    void (*_handler)(byte, button);
    unsigned long _debounceDelay;
    unsigned long _lastDebounceTime = 0;

  public:
    KeyPadReader(byte, byte, ShiftPrinter *, void handler(byte, button));
    void begin();
    bool onChange();
    bool getButtonState(byte);
};

KeyPadReader::KeyPadReader(byte commonPin, byte buttonLen, ShiftPrinter *shift, void handler(byte, button)) {
  _debounceDelay = 10;
  _commonPin = commonPin;
  _btnLen = buttonLen;
  _shift = shift;
  _handler = handler;

  _readBuffer = new byte[_btnLen];    // stores readings in an array
  _lastBtnState = new byte[_btnLen];  // previous state
  _btnState = new byte[_btnLen];      // button state after debounce

  for (byte i = 0; i < _btnLen; i++) {
    _lastBtnState[i] = 0;
    _btnState[i] = 0;
    _readBuffer[i] = 0;
  }
}

void KeyPadReader::begin() {
  pinMode(_commonPin, INPUT);
}

bool KeyPadReader::onChange() {
  bool flag = false;

  for (byte i = 0; i < _btnLen; i++) {
    _shift->setValue(1, btnMap[i]);
    _shift->print();
    _readBuffer[i] = digitalRead(_commonPin);

    if (_readBuffer[i] != _lastBtnState[i])  // if change
    {
      _lastDebounceTime = millis();
    }
    if ((millis() - _lastDebounceTime) > _debounceDelay)  // check after debounce time again
    {
      if (_readBuffer[i] != _btnState[i]) {
        _btnState[i] = _readBuffer[i];
        if (_btnState[i] == 1) {
          _handler(i, PRESSED);
        } else {
          _handler(i, RELEASED);
        }
        flag = true;
      }
    }
    _lastBtnState[i] = _readBuffer[i];
    _shift->setValue(0, btnMap[i]);
  }

  return flag;
}

bool KeyPadReader::getButtonState(byte index)
{
  return _btnState[index] == true;
}
