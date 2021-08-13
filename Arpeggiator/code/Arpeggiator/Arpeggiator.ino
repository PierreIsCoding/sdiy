
// sources:
// https://www.codesdope.com/blog/article/set-toggle-and-clear-a-bit-in-c/
// https://create.arduino.cc/projecthub/instrumentation-system/dac-8-bit-using-r-2r-ladder-964837
// https://www.electronics-tutorials.ws/combination/r-2r-dac.html
// https://en.wikipedia.org/wiki/Chord_(music)

// Code by L.Geerinckx 

#include "AnalogSwitch.h"
#include "MyButtons.h"
#include "MyNode.h"

byte currentStep = 0;
byte currentOctave = 0;
byte maxSteps = 4;
const byte pinOut[6] = {2, 3, 4, 5, 6, 7};
byte repeatStepCounter = 0;
bool bounceToggle = false;

//{0, 12, 24, 36, 48}; // Volts =0,1,2,3,4
// 0 , 1100, 00011000, 00100100, 00110000

byte scaleLen[12] = {3, 4, 4, 3, 4, 3, 4, 4, 3, 4, 3, 4};
byte scale[12][4] = {
    //    {0, 24, 36, 48}, // Volts =1,2,3,4
    {0, 4, 7, 0},  // Major
    {0, 4, 7, 10}, // Major 7
    {0, 4, 7, 11}, // Dominant 7
    {0, 3, 7, 0},  // Minor
    {0, 3, 7, 10}, // Minor 7
    {0, 3, 6, 0},  // Diminished
    {0, 3, 6, 10}, // Half Diminished 7
    {0, 3, 6, 9},  // Full Diminished 7
    {0, 4, 8, 0},  // Augmented
    {0, 4, 8, 10}, // Agmented 7
    {0, 5, 7, 0},  // Sus 4
    {0, 5, 7, 11}, // Sus 4 Maj 7 ---
};

// analog switching arreas
int octSwArray[3][2] = {
    {0, 350},
    {450, 700},
    {800, 1025},
};

AnalogSwitch octaveSwitch(A2, 50, octSwArray, 3); // (pin, error margin, array, array length)

// ---------------Markov Chain nodes ------------------


byte nodeProb_A0[4] = {30, 50, 10, 0}; //0-100%
byte nodeProb_A1[4] = {0, 20, 30, 0};   //0-100%
byte nodeProb_A2[4] = {0, 0, 50, 30};  //0-100%
byte nodeProb_A3[4] = {30, 0, 0, 20};  //0-100%

MyNode node_A0(nodeProb_A0, 4);
MyNode node_A1(nodeProb_A1, 4);
MyNode node_A2(nodeProb_A2, 4);
MyNode node_A3(nodeProb_A3, 4);

MyNode *markovChain_A[4] = {&node_A0, &node_A1, &node_A2, &node_A3};


byte nodeProb_B0[4] = {0, 20, 60, 3}; //0-100%
byte nodeProb_B1[4] = {30, 20, 0, 20};   //0-100%
byte nodeProb_B2[4] = {20, 50, 20, 60};  //0-100%
byte nodeProb_B3[4] = {10, 20, 0, 60};  //0-100%

MyNode node_B0(nodeProb_B0, 4);
MyNode node_B1(nodeProb_B1, 4);
MyNode node_B2(nodeProb_B2, 4);
MyNode node_B3(nodeProb_B3, 4);

MyNode *markovChain_B[4] = {&node_B0, &node_B1, &node_B2, &node_B3};

// ---------------Helper functions------------------

void octaveUp()
{
    currentOctave = currentOctave < octaveSwitch.getCurrent() ? currentOctave + 1 : 0;
}

void octaveDown()
{
    currentOctave = currentOctave > 0 ? currentOctave - 1 : octaveSwitch.getCurrent();
}

void stepUp()
{
    if (currentStep < maxSteps - 1)
    {
        currentStep++;
    }
    else
    {
        currentStep = 0;
        octaveUp();
    }
}

void stepDown()
{
    if (currentStep > 0)
    {
        currentStep--;
    }
    else
    {
        currentStep = maxSteps - 1;
        octaveDown();
    }
}

void reset()
{
    currentStep = 0;
    currentOctave = 0;
    repeatStepCounter = 0;
    bounceToggle = false;
}

// ---------------INIT INPUT------------------

// analog switching arreas
int dirSwArray[12][2] = {
    {945, 1025}, //  1024
    {855, 945},  //  930
    {765, 855},  //  863
    {675, 765},  //  741
    {585, 675},  //  649
    {495, 585},  //  555
    {405, 495},  //  463
    {315, 405},  //  371
    {225, 315},  //  279
    {135, 225},  //  186
    {45, 135},   //  92
    {0, 45},     //  0
};

AnalogSwitch directionSwitch(A0, 10, dirSwArray, 12); // (pin, error margin, array, array length)

// analog switching arreas
int chordSwArray[12][2] = {
    {945, 1025}, //  1024
    {855, 945},  //  930
    {765, 855},  //  863
    {675, 765},  //  741
    {585, 675},  //  649
    {495, 585},  //  555
    {405, 495},  //  463
    {315, 405},  //  371
    {225, 315},  //  279
    {135, 225},  //  186
    {45, 135},   //  92
    {0, 45},     //  0
};

AnalogSwitch chordSwitch(A1, 10, chordSwArray, 12); // (pin, error margin, array, array length)

void triggerHandler(byte index, button type)
{
    if (type == RELEASED && index == 0) // clock
    {
        if (directionSwitch.getCurrent() == 0) // up
        {
            stepUp();
        }
        else if (directionSwitch.getCurrent() == 1) // down
        {
            stepDown();
        }
        else if (directionSwitch.getCurrent() == 2) // bounce ex
        {
            if (bounceToggle)
            {
                if (currentStep < maxSteps - 1)
                {
                    currentStep++;
                }
                else
                {
                    if (currentOctave < octaveSwitch.getCurrent())
                    {
                        currentOctave++;
                        currentStep = 0;
                    }
                    else
                    {
                        bounceToggle = false;
                        currentStep--;
                    }
                }
            }
            else
            {
                if (currentStep > 1)
                {
                    currentStep--;
                }
                else
                {
                    if (currentOctave > 0)
                    {
                        currentOctave--;
                        currentStep = maxSteps - 1;
                    }
                    else
                    {
                        bounceToggle = true;
                        currentStep++;
                    }
                }
            }
        }
        else if (directionSwitch.getCurrent() == 3) // bounce inc
        {
            if (bounceToggle)
            {
                if (currentStep < maxSteps - 1)
                {
                    currentStep++;
                }
                else
                {
                    if (currentOctave < octaveSwitch.getCurrent())
                    {
                        currentOctave++;
                        currentStep = 0;
                    }
                    else
                    {
                        bounceToggle = false;
                        //                        currentStep--;
                    }
                }
            }
            else
            {
                if (currentStep > 1)
                {
                    currentStep--;
                }
                else
                {
                    if (currentOctave > 0)
                    {
                        currentOctave--;
                        currentStep = maxSteps - 1;
                    }
                    else
                    {
                        bounceToggle = true;
                    }
                }
            }
        }
        else if (directionSwitch.getCurrent() == 4) // UPx2
        {
            if (repeatStepCounter == 0)
            {
                repeatStepCounter++;
            }
            else
            {
                stepUp();
                repeatStepCounter = 0;
            }
        }
        else if (directionSwitch.getCurrent() == 5) // DOWNx2
        {
            if (repeatStepCounter == 1)
            {
                repeatStepCounter--;
            }
            else
            {
                stepDown();
                repeatStepCounter = 1;
            }
        }
        else if (directionSwitch.getCurrent() == 6) // random
        {
            currentStep = random(maxSteps - 1);
            currentOctave = random(octaveSwitch.getCurrent());
        }
        else if (directionSwitch.getCurrent() == 7)
        {
            currentStep = markovChain_A[currentStep]->next();
//            Serial.println(currentStep);
        }
        else
        {
            currentStep = markovChain_B[currentStep]->next();
//            Serial.println(currentStep);
        }
        for (byte i = 0; i < 6; i++)
        {
            digitalWrite(pinOut[i], bitRead(scale[chordSwitch.getCurrent()][currentStep] + 12 * currentOctave, i));
        }
    }

    if (type == RELEASED && index == 1) // reset
    {
        reset();
    }
}

MyButtons gateJacks((byte[2]){11, 12}, 2, triggerHandler); // buttonpins, pins, handler

// ---------------SETUP & LOOP ------------------

void setup()
{
    Serial.begin(9600);
    Serial.println("test");
    gateJacks.begin();
    for (byte i = 0; i < 6; i++)
    {
        pinMode(pinOut[i], OUTPUT); // set the pins as output
    }
    maxSteps = scaleLen[chordSwitch.getCurrent()];
}

void loop()
{
    if (directionSwitch.onChange())
    {
        reset();
        //        Serial.println(directionSwitch.getCurrent());
    }
    if (chordSwitch.onChange())
    {
        reset();
        maxSteps = scaleLen[chordSwitch.getCurrent()];
        //        Serial.println(chordSwitch.getCurrent());
    }
    if (octaveSwitch.onChange())
    {
        reset();
        //        Serial.println(octaveSwitch.getCurrent());
    }
    gateJacks.on();
}
