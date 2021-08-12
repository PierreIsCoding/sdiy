// Code by L.Geerinckx 28-1-2021 | https://github.com/PierreIsCoding


// dot,G,F,E,D,C,B,A

int ledData[11][8] = {
    {1, 1, 0, 0, 0, 0, 0, 0}, // 0
    {1, 1, 1, 1, 1, 0, 0, 1}, // 1
    {1, 0, 1, 0, 0, 1, 0, 0}, // 2
    {1, 0, 1, 1, 0, 0, 0, 0}, // 3
    {1, 0, 0, 1, 1, 0, 0, 1}, // 4
    {1, 0, 0, 1, 0, 0, 1, 0}, // 5
    {1, 0, 0, 0, 0, 0, 1, 0}, // 6
    {1, 1, 1, 1, 1, 0, 0, 0}, // 7
    {1, 0, 0, 0, 0, 0, 0, 0}, // 8
    {1, 0, 0, 1, 0, 0, 0, 0}, // 9
    {1, 1, 1, 1, 1, 1, 1, 1}, // empty
};

class MyShiftDisplay
{
private:
    int dataPin = 4;
    int clockPin = 2;
    int latchPin = 3;
    int commonPins[3] = {5, 7, 8}; 
    void updateRegister(int);      // update next segment
    int numArr[3];
    int curSeg=0;
    int prevSeg=0;
    

public:
    MyShiftDisplay();
    void begin();
    void setValue(int);
    void updateNext();
};

MyShiftDisplay::MyShiftDisplay()
{
    numArr[0] = 0;
    numArr[1] = 0;
    numArr[2] = 0;

}

void MyShiftDisplay::begin()
{
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    for (int i = 0; i < 3; i++)
    {
        pinMode(commonPins[i], OUTPUT);
        digitalWrite(commonPins[i], LOW);
    }
    updateRegister(0);
}

void MyShiftDisplay::setValue(int num){
    numArr[0] = num / 100 % 10; // third digit
    numArr[1] = num / 10 % 10;  // second digit
    numArr[2] = num % 10;       // first digit

    if (numArr[0] == 0)
    {
        numArr[0] = 10;  // empty
        if (numArr[1] == 0)
        {
            numArr[1] = 10; // empty
        }
    }
  }

void MyShiftDisplay::updateNext()
{
    digitalWrite(commonPins[prevSeg], LOW);
    updateRegister(numArr[curSeg]);
    digitalWrite(commonPins[curSeg], HIGH);
    prevSeg=curSeg;
    curSeg=curSeg<2?curSeg+1:0;
}

void MyShiftDisplay::updateRegister(int num)
{
    digitalWrite(latchPin, LOW);
    for (int i = 0; i < 8; i++)
    {
        digitalWrite(dataPin, ledData[num][i]);
        digitalWrite(clockPin, HIGH);
        digitalWrite(clockPin, LOW);
    }
    digitalWrite(latchPin, HIGH);
}
