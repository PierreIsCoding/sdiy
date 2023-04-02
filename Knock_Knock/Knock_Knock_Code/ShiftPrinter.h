
// ShiftPrinter.h
// By L. Geerinckx.
// Printing data to one or more 74hc595 shift register(s) in series.

//-----
// clock: SRCLK
// RCLK: copy buffered data to output pins from low to high (latch)
// clear: SRCLR // reset buffered data. low is reset
// data in: SER
// output enable: OE (When the voltage on it is high, the output pins are disabled)
//-----

// shift print indexes
// 0 = LEDS_A
// 1 = ROTARY_BTN
// 2 = LEDS_D
// 3 = CLOCK_OUT_4
// 4 = CLOCK_OUT_5
// 5 = CLOCK_OUT_2
// 6 = CLOCK_OUT_1
// 7 = CLOCK_OUT_3
// 8 = LEDS_C
// 9 = LEDS_B
// 10 = CLOCK_BTN
// 11 = SHIFT_BTN
// 12 = LENGTH_BTN
// 13 = DIVISION_BTN
// 14 = PLAY_BTN
// 15 = LED_SINK

#ifndef SHIFTPRINTER_H
#define SHIFTPRINTER_H

class ShiftPrinter {
private:
  byte _dataPin;
  byte _clockPin;
  byte _latchPin;
  byte *_buffer;
  byte _bits;

public:
  ShiftPrinter(byte, byte, byte, byte);
  void begin();
  void print();
  void clearBuffer();
  void fillBuffer();
  void showBuffer();
  void setValue(byte, byte);
};

ShiftPrinter::ShiftPrinter(byte dataPin, byte clockPin, byte latchPin, byte bits) {
  _dataPin = dataPin;
  _clockPin = clockPin;
  _latchPin = latchPin;
  _bits = bits;
  _buffer = new byte[_bits];
  clearBuffer();
}

void ShiftPrinter::begin() {
  pinMode(_dataPin, OUTPUT);
  pinMode(_clockPin, OUTPUT);
  pinMode(_latchPin, OUTPUT);
  print();
}

void ShiftPrinter::fillBuffer() {
  for (byte i = 0; i < _bits; i++) {
    _buffer[i] = 1;
  }
}

void ShiftPrinter::clearBuffer() {
  for (byte i = 0; i < _bits; i++) {
    _buffer[i] = 0;
  }
}

void ShiftPrinter::setValue(byte value, byte index) {
  _buffer[index]=value;
}

// For testing on Arduino Nano's etc.
// void ShiftPrinter::showBuffer() {
//   for (byte i = 0; i < _bits; i++) {
//     Serial.print(_buffer[i]);
//     Serial.print(",");
//   }
//   Serial.println("");
// }

void ShiftPrinter::print() {
  digitalWrite(_latchPin, LOW);
  for (int i = 0; i < _bits; i++) {
    digitalWrite(_clockPin, LOW);
    digitalWrite(_dataPin, _buffer[i]);
    digitalWrite(_clockPin, HIGH);
  }
  digitalWrite(_latchPin, HIGH);
}

#endif
