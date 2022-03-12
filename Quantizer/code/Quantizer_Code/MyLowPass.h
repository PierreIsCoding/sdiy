#ifndef LOWPASS_H
#define LOWPASS_H

// A simple moving average filter by L.Geerinckx
// Constantly writes new data to a buffer
// Calculates average over that buffer
// The longer that array is the more it filters out high frequencies. Thus Cutoff frequency is set by array length

class LowPass
{
private:
    uint16_t len;
    uint16_t maxLen;
    uint16_t *buffer;
    uint16_t current;
    uint16_t writePos = 0;

public:
    LowPass(uint16_t, uint16_t);
    uint16_t getCurrent();
    uint16_t getNext(uint16_t);
    uint16_t getCutOff();
    void setToMax();
    void setCutOff(uint16_t);
};

LowPass::LowPass(uint16_t _max, uint16_t _len = 0)
{
    maxLen = _max;
    setCutOff(_len);
    buffer = new uint16_t[maxLen];
    for (uint16_t i = 0; i < maxLen; i++)
    {
        buffer[i] = 0;
    }
}

uint16_t LowPass::getNext(uint16_t val)
{
    buffer[writePos] = val;
    if (len == 0)
    {
        return val;
    }
    else
    {
        writePos = writePos < len ? writePos + 1 : 0;
    }

    // calc average
    long temp = 0;
    for (uint16_t i = 0; i < len; i++)
    {
        temp += buffer[i];
    }

    current = temp / len;

    return current;
}

void LowPass::setCutOff(uint16_t _len)
{
    len = _len >= maxLen ? maxLen - 1 : _len; // check
}

uint16_t LowPass::getCurrent()
{
    return current;
}

void LowPass::setToMax()
{
    setCutOff(maxLen);
}

uint16_t LowPass::getCutOff()
{
    return len;
}

#endif
