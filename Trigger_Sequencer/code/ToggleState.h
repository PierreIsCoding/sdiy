// Code By L.Geerinckx 12-2-2021 // https://github.com/PierreIsCoding

#ifndef TOGGLESTATE_H
#define TOGGLESTATE_H

class ToggleState
{
private:
    int _initState;
    bool state;

public:
    ToggleState(bool);
    void setState(bool);
    void toggle();
    bool getState();
    void setHigh();
    void setLow();
};

ToggleState::ToggleState(bool initState = true)
{
    state = initState;
}

void ToggleState::setState(bool newState)
{
    state = newState;
}

void ToggleState::toggle()
{
    if (state)
    {
        state = false;
    }
    else
    {
        state = true;
    }
}

void ToggleState::setHigh()
{
    if (state == false)
    { // only when not already high
        state = true;
        setState(state);
    }
}

void ToggleState::setLow()
{
    if (state == true)
    { // only when not already low
        state = false;
        setState(state);
    }
}

bool ToggleState::getState()
{
    return state;
}

#endif
