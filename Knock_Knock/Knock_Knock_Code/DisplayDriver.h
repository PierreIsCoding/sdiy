
// DisplayDriver.h
// Code by L Geerinckx.
// Writing to a 10 segment led bar via 74hc595 (shift register) and cd4028 (3-bit to decimal encoder)
// Only one led is illuminated at a time.
// Showing multiple leds at the "same time" is achieved by blinking them sequentially very fast.
// This building block requires ShiftPrinter.h
// The led at the cursor position is brighter by changing its current sink on the fly, see schematic.

byte pinMap[4] = {0, 9, 8, 2}; // remaps the indexes of the shift register to the input pins of cd4028.
byte ledMap[11] = {3, 1, 4, 2, 0, 8, 6, 5, 9, 7, 10}; // remaps the led pins of the led bar. Last index = 10 decimal = 1010 binary = all off (datasheet cd4028)

class DisplayDriver {
  private:
    ShiftPrinter *_shift;
    bool _displayBuffer[10];
    byte _cursorPos = 0;
    void _mapValueToRegister(byte);
    byte _bufferPos;
    bool _toggle = false;
    byte _show = 0;
    byte _brightIndexPin;

  public:
    DisplayDriver(ShiftPrinter *, byte);
    void next();
    void clearBuffer();
    void setBuffer(byte arr[]);
    void setCursor(byte);
};

DisplayDriver::DisplayDriver(ShiftPrinter *shift, byte brightIndexPin) {
  _shift = shift;
  _brightIndexPin = brightIndexPin;
}

void DisplayDriver::clearBuffer() {
  for (byte i = 0; i < 10; i++) {
    _displayBuffer[i] = 0;
  }
}

void DisplayDriver::next() {
  if (_bufferPos < 9) {
    _bufferPos++;
  } else {
    _bufferPos = 0;
  }
  if (_bufferPos == _cursorPos) {
    _shift->setValue(0, _brightIndexPin); // makes the led brighter
    _mapValueToRegister(_cursorPos);
  } else {
    _shift->setValue(1, _brightIndexPin);
    if (_displayBuffer[_bufferPos]) {
      _mapValueToRegister(_bufferPos);
    } else {
      _mapValueToRegister(10); // all off
    }
  }
}

void DisplayDriver::_mapValueToRegister(byte value) {
  for (byte i = 0; i < 4; i++) {
    _shift->setValue(bitRead(ledMap[value], i), pinMap[i]);  // maps decimal value for binary value for cd4028
  }
}

void DisplayDriver::setCursor(byte value) {
  _cursorPos = value;
}

void DisplayDriver::setBuffer(byte value[]) {
  for (byte i = 0; i < 10; i++) {
    _displayBuffer[i] = value[i];
  }
}
