// Code By L.Geerinckx 12-2-2021 // https://github.com/PierreIsCoding

#include "MyButtons.h"
#include "MyShiftKeyPad.h"
#include "ToggleState.h"
#include "MyRotary.h"
#include "MyVirtualButtons.h"
#include "MyLedMatrix.h"
#include "MyTimer.h"
#include "MySequence.h"
#include "MyClock.h"

MyTimer inputChecker(100); //hz

//--------------------------- Init Clock -----------------------

byte pulsesPerStep=12;
MyClock pulseClock(pulsesPerStep); // 
MyTimer testClock(2); // hz, scalar

// ----------------------------- init KEYPAD & Sequencer------------

MyLedMatrix display(18, 17, 16); //data, load, clock
MySequence sequence_1(&display, 22, pulsesPerStep); // display, outputPin, scalar
MySequence sequence_2(&display, 21, pulsesPerStep);
MySequence sequence_3(&display, 20, pulsesPerStep);
MySequence *sequencers[3] = {&sequence_1, &sequence_2, &sequence_3};

byte readPins[1] = {12};          // common read pins
KeyPad keyPad(1, readPins, 3, 2); // readpins length , aray, readPins, dataPin, clockPin

//--------------------------- Init Rotary -----------------------
MyRotary myRotary(14, 15);
ToggleState toggleRotary(true);
