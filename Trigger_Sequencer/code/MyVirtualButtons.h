// Code By L.Geerinckx 12-2-2021 // https://github.com/PierreIsCoding




#ifndef MYVIRTUALBUTTONS_H
#define MYVIRTUALBUTTONS_H

class MyVirtualButtons
{
private:
    byte _num;
    byte *_btnPins;
    byte *buttonState;
    byte *lastButtonState;
    void (*_handler)(byte, button);
    KeyPad *test;

public:
    MyVirtualButtons(byte arr[], byte, KeyPad *, void handler(byte, button));
    bool on();
    bool checkIndex(byte);
};

MyVirtualButtons::MyVirtualButtons(byte btnPins[], byte num, KeyPad *_test, void handler(byte, button))
{
    _num = num;
    _handler = handler;
    test = _test;
    _btnPins = new byte[_num];
    buttonState = new byte[_num];
    lastButtonState = new byte[_num];

    // populate arrays
    for (int i = 0; i < _num; i++)
    {
        _btnPins[i] = btnPins[i];
        lastButtonState[i] = 0;
        buttonState[i] = 0;
    }
}

bool MyVirtualButtons::on()
{
    for (byte i = 0; i < _num; i++)
    {
        buttonState[i] = test->virtualRead(_btnPins[i]);
        if (buttonState[i] != lastButtonState[i]) // if change
        {
            if (buttonState[i] == 1)
            {
                _handler(i, PRESSED);
            }
            if (buttonState[i] == 0)
            {
                _handler(i, RELEASED);
            }
            lastButtonState[i] = buttonState[i];
            return true;
        }
    }
    return false;
}

bool MyVirtualButtons::checkIndex(byte index)
{
    if (buttonState[index] == 1)
    {
        return true;
    }
    return false;
}

#endif
