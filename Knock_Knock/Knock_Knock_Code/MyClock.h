
// MyClock.h
// Code By L.Geerinckx

#ifndef MyClock_H
#define MyClock_H

class MyClock {
  private:
    DisplayDriver *_display;
    unsigned long currentMicros;
    unsigned long previousMicros = 0;
    float _period = 0;
    bool runTimer = true;
    byte _clockPin;
    byte _checkPin;
    byte _cableCheck;
    bool _oldClock = false;
    int _bpm;
    int _maxBPM;
    int _deltaBPM;
    int _minBPM;
    int _steps;
    void setBPM(bool);
    void togglePPQ();
    bool _24PPQ = false;
    void showPPQ();
    byte _ppqCount;
    unsigned long *_count;

  public:
    MyClock(DisplayDriver *, unsigned long *count, float, byte, byte);
    void begin();
    bool onTime();
    void showClock();
    void setFreq();
    void togglePlay();
    bool getState();
    void setClock(bool);
    void reset();
};


MyClock::MyClock(DisplayDriver *display, unsigned long *count, float freq, byte clockPin, byte checkPin) {
  _display = display;
  _clockPin = clockPin;
  _checkPin = checkPin;
  _count = count;              // pointer to current clockCount

  _bpm = 250;
  _maxBPM = 500;
  _minBPM = 50;
  _steps = 10;
  _deltaBPM = (_maxBPM - _minBPM) / (_steps - 1);
  setFreq();
  reset();
}

void MyClock::begin() {
  pinMode(_clockPin, INPUT);
  pinMode(_checkPin, INPUT);  // this input checks if a cable in the clock jack is inserted
}

void MyClock::setFreq() {
  _period = 1000000 / ((float)_bpm / 30);
  previousMicros = 0;
}

bool MyClock::onTime() {
  if (!runTimer) {
    return false;
  }
  if (digitalRead(_checkPin)) {
    _cableCheck = false;  // no cable is inserted into the clock jack
    currentMicros = micros();
    if (currentMicros - previousMicros >= _period) {
      previousMicros = currentMicros;
      return true;
    }
    return false;
  } else {
    _cableCheck = true;  // a cable is inserted into the clock jack
    bool _newClock = !digitalRead(_clockPin);
    if (_newClock != _oldClock) {
      _oldClock = _newClock;
      if (_24PPQ && _ppqCount < 23) {
        _ppqCount++;
        return false;
      } else {
        _ppqCount = 0;
        return true;
      }
    } else {
      return false;
    }
  }
}

void MyClock::togglePlay() {
  runTimer = !runTimer;
}

bool MyClock::getState() {
  return runTimer;
}

void MyClock::showClock() {
  if (digitalRead(_checkPin)) {
    // no cable is inserted thus show bpm
    _display->clearBuffer();
    _display->setCursor(9 - (_bpm - _minBPM) / _deltaBPM);
  } else {
    showPPQ();
  }
}

void MyClock::setClock(bool dir) {
  if (digitalRead(_checkPin)) {
    // no cable is inserted thus set bpm
    setBPM(dir);
  } else {
    togglePPQ();
  }
}

void MyClock::setBPM(bool dir) {
  if (!dir) {
    _bpm += _deltaBPM;
    _bpm = _bpm > _maxBPM ? _maxBPM : _bpm;
  } else {
    _bpm -= _deltaBPM;
    _bpm = _bpm > _minBPM ? _bpm : _minBPM;
  }
  showClock();
  setFreq();
}

void MyClock::togglePPQ() {
  _24PPQ = !_24PPQ;
  reset();
  showPPQ();
}


void MyClock::showPPQ() {
  _display->setCursor(20); // hide cursor to random index
  if (_24PPQ) {
    byte showPPQ[10] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 };
    _display->setBuffer(showPPQ);
  } else {
    byte showPPQ[10] = { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 };
    _display->setBuffer(showPPQ);
  }
}


void MyClock::reset() {
  *_count = 1;
  _ppqCount = 23;
  _oldClock = false;
}


#endif
