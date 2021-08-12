// Code by L.Geerinckx 28-1-2021 | https://github.com/PierreIsCoding

#ifndef MYBUTTONS_H
#define MYBUTTONS_H

class MyButtons
{
private:
    int _num;
    int *_btnPins;
    int *lastButtonState;
    int *buttonState;
    unsigned long lastDebounceTime;
    unsigned long debounceDelay;

public:
    MyButtons(int arr[], int, int); // constructor
    int *reading;

    // methods
    void begin();
    bool on();
    bool checkButton(int);
};

MyButtons::MyButtons(int btnPins[], int num, int debounce = 50)
{
    _num = num;
    debounceDelay = debounce;
    _btnPins = new int[_num];
    lastButtonState = new int[_num];
    buttonState = new int[_num];
    lastDebounceTime = 0;
    reading = new int[_num];

    // populate arrays
    for (int i = 0; i < _num; ++i)
    {
        _btnPins[i] = btnPins[i];
        lastButtonState[i] = 1;
        buttonState[i] = 1;
    }
}

void MyButtons::begin()
{
    for (int i = 0; i < _num; i++)
    {
        pinMode(_btnPins[i], INPUT);
    }
}

bool MyButtons::on()
{
    for (int i = 0; i < _num; i++)
    {
        reading[i] = digitalRead(_btnPins[i]);
        if (reading[i] != lastButtonState[i]) // if change
        {
            lastDebounceTime = millis();
        }

        if ((millis() - lastDebounceTime) > debounceDelay) // check na een bepaalde tijd nog een keertje
        {
            if (reading[i] != buttonState[i])
            {
                buttonState[i] = reading[i];
                return true;
            }
        }
        lastButtonState[i] = reading[i];
    }
    return false;
}

bool MyButtons::checkButton(int index)
{
    if (reading[index] == 1)
    {
        return true;
    }
    return false;
}

#endif
