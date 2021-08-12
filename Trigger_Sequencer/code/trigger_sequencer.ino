// Code By L.Geerinckx 12-2-2021 // https://github.com/PierreIsCoding


#include "init.h"
byte selectedSeq = 0;
byte clockCounter = 0;

// ----------------------------- init Toggle Switch ------------
void switchHandler(byte index, button type)
{
    if (type == PRESSED)
    {
        sequencers[0]->setEditMode(1);
        sequencers[1]->setEditMode(1);
        sequencers[2]->setEditMode(1);
    }
    else
    {
        sequencers[0]->setEditMode(0);
        sequencers[1]->setEditMode(0);
        sequencers[2]->setEditMode(0);
    }
}

byte togglePin[1] = {23};
MyButtons toggleSwitch(togglePin, 1, switchHandler);

// ----------------------------- init ALT Buttons ------------

void altButtonHandler(byte index, button type)
{
    if (index == 0) // Length
    {
        if (type == PRESSED)
        {
            sequencers[selectedSeq]->setShow(false);
            if (toggleRotary.getState())
            {
                sequencers[selectedSeq]->showLength();
            }
            else
            {
                sequencers[selectedSeq]->showDivision();
            }
        }
        else
        {
            sequencers[selectedSeq]->setShow(true);
            sequencers[selectedSeq]->showSequence();
        }
    }
    if (index == 3) // Duty Cycle
    {
        if (type == PRESSED)
        {
            sequencers[selectedSeq]->setShow(false);
            sequencers[selectedSeq]->showDutyCycle();
        }
        else
        {
            sequencers[selectedSeq]->setShow(true);
            sequencers[selectedSeq]->showSequence();
        }
    }
    else if (index == 4 && type == PRESSED) // rotary push
    {
        toggleRotary.toggle();
    }
}

byte altButtonPins[5] = {2, 1, 0, 3, 7};                                  // Length, Random, Shift, Rotary_push (array of virtual button pins)
MyVirtualButtons altButtons(altButtonPins, 5, &keyPad, altButtonHandler); // button array, array length, keypad, altKeyIndex, handler

// ----------------------------- init CHANNEL Buttons ------------

void channelButtonHandler(byte index, button type)
{
    if (type == PRESSED)
    {
        sequencers[selectedSeq]->setShow(false);
        if(index==selectedSeq){
            sequencers[selectedSeq]->trigger(true);          
        }
        
        selectedSeq = index;

        
        sequencers[selectedSeq]->setShow(true);
        sequencers[selectedSeq]->setEditMode(toggleSwitch.checkIndex(0));
        sequencers[selectedSeq]->showSequence();

    }
    else
    {
        sequencers[selectedSeq]->trigger(false);
    }
}

byte channelButtonIndexes[3] = {6, 5, 4};                                                // array of virtual button pins
MyVirtualButtons channelButtons(channelButtonIndexes, 3, &keyPad, channelButtonHandler); // button array, array length, keypad, altKeyIndex, handler

// ----------------------------- init ROTARY  ------------
void checkRotary()
{
    if (myRotary.on())
    {
        if (altButtons.checkIndex(0)) //Length is pressed
        {
            if (toggleRotary.getState())
            {
                sequencers[selectedSeq]->scrollLength(myRotary.getDirection());
                sequencers[selectedSeq]->deployEuclidian();
                sequencers[selectedSeq]->showLength();
            }
            else
            {
                sequencers[selectedSeq]->scrollDivision(myRotary.getDirection());
                sequencers[selectedSeq]->showDivision();
            }
        }
        else if (altButtons.checkIndex(1)) //Random is pressed
        {
            if (toggleRotary.getState())
            {
                sequencers[selectedSeq]->randStepValue();
            }
            else
            {
                sequencers[selectedSeq]->randStepPosition();
            }
        }
        else if (altButtons.checkIndex(2)) //shift is pressed
        {
            if (toggleRotary.getState())
            {
                sequencers[selectedSeq]->shiftSequence(myRotary.getDirection());
            }
            else
            {
                sequencers[selectedSeq]->shiftValues(myRotary.getDirection());
            }
        }
        else if (altButtons.checkIndex(3)) //Duty is pressed
        {
            sequencers[selectedSeq]->scrollDutyCycle(myRotary.getDirection());
        }
        else if (channelButtons.checkIndex(0)) //channel 1 is pressed
        {
            sequencers[0]->scrollTrigger(myRotary.getDirection());
        }

        else if (channelButtons.checkIndex(1)) //channel 2 is pressed
        {
            sequencers[1]->scrollTrigger(myRotary.getDirection());
        }
        else if (channelButtons.checkIndex(2)) //channel 3 is pressed
        {
            sequencers[2]->scrollTrigger(myRotary.getDirection());
        }
        else
        {
            if (toggleSwitch.checkIndex(0)) // manual mode is on
            {
                if (toggleRotary.getState())
                {
                    sequencers[selectedSeq]->scrollEditStep(myRotary.getDirection());
                }
                else
                {
                    sequencers[selectedSeq]->scrollStepValue(myRotary.getDirection());
                }
            }
            else // euclidian mode is on
            {
                sequencers[selectedSeq]->scrollEuclidian(myRotary.getDirection());
            }
        }
    }
}

//---------------------------INIT CV-----------------------
void cvHandler(byte index, button type)
{
    if (type == PRESSED)
    {
        sequencers[index]->trigger(true);
    }
    else
    {
        sequencers[index]->trigger(false);
    }
}

byte cvInputPins[3] = {8, 9, 10}; // channel cvs 3x
MyButtons cvInput(cvInputPins, 3, cvHandler, 20);

void clockHandler(byte index, button type)
{
    if (type == PRESSED)
    {
        // gets executed at new external clock pulse
        pulseClock.update(); // send cv value to clock
        sequence_1.enforceNext();
        sequence_2.enforceNext();
        sequence_3.enforceNext();
    }
}

byte clockPin[1] = {11}; // clock pin
MyButtons clockInput(clockPin, 1, clockHandler, 0);

//---------------------------SETUP-----------------------

void setup()
{
    Serial.begin(9600);
    Serial.println("start");
    keyPad.begin();
    display.begin();
    sequence_1.begin();
    sequence_2.begin();
    sequence_3.begin();

    sequence_1.setShow(true);
    sequence_1.showSequence();

    myRotary.begin();
    cvInput.begin();
    display.setPixel(7, 7, 1); // current mode
    toggleSwitch.begin();
}

//---------------------------MAIN LOOP-----------------------

void loop(void)
{
    //    if (testClock.onTime()) // internal clock for test purposes
    //    {
    //        sequence_1.enforceNext();
    //        sequence_2.enforceNext();
    //        sequence_3.enforceNext();
    //        pulseClock.update();
    //    }

    clockInput.on();
    if (inputChecker.onTime())
    {
        cvInput.on();
        toggleSwitch.on();
        if (keyPad.on())
        {
            channelButtons.on();
            altButtons.on();
        }
        checkRotary();
    }

    if (pulseClock.onTime())
    {
        sequence_1.nextPulse();
        sequence_2.nextPulse();
        sequence_3.nextPulse();
    }
}
