
// Sequencer.h
// By L. Geerinckx.
// This building block requires ShiftPrinter.h
// This building block requires DisplayDriver.h


#ifndef Sequencer_H
#define Sequencer_H


int divMap[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

class Sequencer {
  private:
    byte _length;
    byte _division;
    byte _steps;
    int _offset;
    byte _stepIndex = 0;
    byte _clockOutput;
    unsigned long _divCount;
    unsigned long *_count;
    byte _sequence[10];
    ShiftPrinter *_shift;
    DisplayDriver *_display;
    void buildSequence();

  public:
    Sequencer(ShiftPrinter *, unsigned long *, DisplayDriver *, byte, byte);
    void next();
    void setSequence(byte arr[]);
    void setLength(bool);
    void setSteps(bool);
    void setOffset(bool);
    void setDivision(bool);
    void showDivision();
    void showPage();
    void showStep();
    void showLength();
};

Sequencer::Sequencer(ShiftPrinter *shift, unsigned long *count, DisplayDriver *display, byte clockOutput, byte division) {
  _shift = shift;              // pointer to shiftPrinter
  _count = count;              // pointer to current clockCount
  _clockOutput = clockOutput;  // stores the index on the shift register for outputting the clock;
  _display = display;
  _division = division;

  _length = 10;
  _steps = 10;
  _offset = 0;
  buildSequence();
}


void Sequencer::next() {
  _divCount = *_count / divMap[_division];
  _stepIndex = (_divCount / 2) % _length;
  bool clockState = !bitRead(_divCount % 10, 0);
  _shift->setValue(!(clockState && _sequence[_stepIndex]), _clockOutput);  // sets clockOutput
}


void Sequencer::setSequence(byte value[]) {
  for (byte i = 0; i < 10; ++i) {
    _sequence[i] = value[i];
  }
}


void Sequencer::buildSequence() {
  for (byte i = 0; i < 10; i++) {
    _sequence[i] = 0;  // reset whole sequence to zero
  }

  float factor = (float)_length / _steps;

  for (byte i = 0; i < _steps; i++) {
    byte pos = (_offset + round(i * factor)) % _length;
    _sequence[pos] = 1;
  }
}

void Sequencer::setSteps(bool dir) {
  if (dir) {
    _steps++;
    _steps = _steps > _length ? _length : _steps;
  } else {
    _steps = _steps > 1 ? _steps - 1 : 1;
  }
  buildSequence();
  _display->setBuffer(_sequence);
}


void Sequencer::setLength(bool dir) {
  if (dir) {
    _length++;
    _length = _length > 10 ? 10 : _length;
  } else {
    _length = _length > 1 ? _length - 1 : 1;
  }
  _steps = _steps > _length ? _length : _steps;

  showLength();
  buildSequence();
}

void Sequencer::setOffset(bool dir) {
  if (dir) {
    _offset++;
  } else {
    _offset--;
  }
  buildSequence();
  _display->setBuffer(_sequence);
}

void Sequencer::setDivision(bool dir) {
  if (dir) {
    _division++;
    _division = _division > 9 ? 9 : _division;
  } else {
    _division = _division > 0 ? _division - 1 : 0;
  }
  _display->setCursor(_division);
}

void Sequencer::showPage() {
  _display->setBuffer(_sequence);
}

void Sequencer::showStep() {
  _display->setCursor(_stepIndex);
}

void Sequencer::showLength() {
  byte lengthBuf[10] = { 0 };
  for (byte i = 0; i < _length; ++i) {
    lengthBuf[i] = 1;
  }
  _display->setBuffer(lengthBuf);
  //  _display->setCursor(_length - 1);
  _display->setCursor(20); // hide cursor to random index
}

void Sequencer::showDivision() {
  _display->clearBuffer();
  _display->setCursor(_division);
}

#endif
