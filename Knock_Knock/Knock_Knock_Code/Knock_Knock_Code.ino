// Knock Knock, Euclidean Rhythm Generator
// Version 2-4-2023
// Code by L. Geerinckx.

#include "ShiftPrinter.h"
#include "KeyPadReader.h"
#include "DisplayDriver.h"
#include "MyClock.h"
#include "MyRotary.h"
#include "Sequencer.h"

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


// ----------------------- GLOBALS -----------------------

#define shiftDataPin 8
#define shiftClockPin 2
#define shiftLatchPin 7
#define clockInputPin 3
#define cableCheckPin 6
#define rotaryPinA 0
#define rotaryPinB 1
#define commonReadPin 4

enum Mode {
  CHANNEL,
  SEQUENCE,
  DIVISION,
  LENGTH,
  CLOCK,
  SHIFT
};

bool testToggle = false;
Mode displayMode = SEQUENCE;
unsigned long count = 0;
byte activeSeq = 0;
byte channelMap[5] = { 4, 3, 2, 1, 0 };


// ----------------------- -----------------------

ShiftPrinter shift(shiftDataPin, shiftClockPin, shiftLatchPin, 16);      // data pin, clock pin, latch pin, bits.
DisplayDriver display(&shift, 15 );                                      // pointer to display, index of shift register current sink.
MyClock clock(&display, &count, 10, clockInputPin, cableCheckPin);       // pointer to display, pointer to clockCounter, initial frequency in Hz (cycle per second), clockPin, checkPin.

// ----------------------- SEQUENCERS -----------------------

Sequencer sequence_1(&shift, &count, &display, 6, 0);  // pointer to shiftPrinter, pointer to clockCounter, pointer to display, clockOutput index, clock division.
Sequencer sequence_2(&shift, &count, &display, 5, 1);
Sequencer sequence_3(&shift, &count, &display, 7, 2);
Sequencer sequence_4(&shift, &count, &display, 3, 3);
Sequencer sequence_5(&shift, &count, &display, 4, 4);


Sequencer *seqs[5] = { &sequence_1, &sequence_2, &sequence_3, &sequence_4, &sequence_5 };

// ----------------------- BUTTON LOGIC -----------------------

void keyPadHandler(byte index, button type) {

  //  Button indexes:
  //  PLAY_BTN = 0
  //  DIVISION_BTN = 1
  //  LENGTH_BTN = 2
  //  SHIFT_BTN = 3
  //  CLOCK_BTN = 4
  //  ROTARY_BTN = 5

  if (type == PRESSED) {
    if (index == 5) {
      displayMode = CHANNEL;
      display.clearBuffer();
      display.setCursor(activeSeq);
    } else if (displayMode == CHANNEL) {
      activeSeq = index;
      display.clearBuffer();
      display.setCursor(activeSeq);
    } else {
      if (index == 0) {
        clock.togglePlay();
      } else if (index == 1) {
        displayMode = DIVISION;
        seqs[activeSeq]->showDivision();
      } else if (index == 2) {
        displayMode = LENGTH;
        seqs[activeSeq]->showLength();
      } else if (displayMode == SHIFT && index == 4 || displayMode == CLOCK && index == 3 ) {
        clock.reset();
        display.setCursor(0);
        seqs[activeSeq]->showPage();
      } else if (index == 3) {
        displayMode = SHIFT;
        display.setCursor(20); // hide cursor
      } else if (index == 4) {
        displayMode = CLOCK;
        clock.showClock();
      }
    }
  } else {
    // else = when button is released
    if (displayMode == CHANNEL && index != 5 ) {
      return;
    }
    displayMode = SEQUENCE;
    seqs[activeSeq]->showPage();
  }
}

KeyPadReader keyPad(commonReadPin, 6, &shift, keyPadHandler);  // common readPin , amount of buttons, pointer to shiftRegister, callback.

// ----------------------- ROTARY ENCODER -----------------------

void rotaryHandler(byte dir)  // red buttons
{
  if (displayMode == DIVISION) {
    seqs[activeSeq]->setDivision(dir); // division
  }  else if (displayMode == LENGTH) {
    seqs[activeSeq]->setLength(dir); // length
  }  else if (keyPad.getButtonState(3)) {
    seqs[activeSeq]->setOffset(dir); // offset
  }  else if (displayMode == CLOCK) {
    clock.setClock(dir); // clock button
  }  else {
    seqs[activeSeq]->setSteps(dir);
  }
}

MyRotary rotary(rotaryPinA, rotaryPinB, rotaryHandler);  // pin A, pin B, callback.


// ----------------------- HELPER FUNCTIONS -----------------------

void counter() {
  if (count < 4000000000) {
    count++;
  } else {
    count = 0;
  }
}

// ----------------------- SETUP & LOOP -----------------------

void setup() {
  shift.begin();
  shift.clearBuffer();
  keyPad.begin();
  sequence_1.showPage();
  rotary.begin();
}

void loop() {
  rotary.on();
  if (clock.onTime()) {
    counter();
    sequence_1.next();
    sequence_2.next();
    sequence_3.next();
    sequence_4.next();
    sequence_5.next();
    if (displayMode == SEQUENCE) {
      seqs[activeSeq]->showStep();
    }
  }
  display.next();
  shift.print();
  keyPad.onChange();
}
