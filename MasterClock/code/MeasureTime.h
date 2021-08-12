// Code by L.Geerinckx 28-1-2021 | https://github.com/PierreIsCoding


class MeasureTime
{
private:
    int samples;
    unsigned long currentMillis;
    unsigned long previousMillis = 0;
    int *sampleBank;
    int index = 0;
    unsigned long minTap; // minimal tap tempo 10 BPM

public:
    MeasureTime(int,int);
    void addSample();
    void on();
    int getTiming();
    void reset();
};

MeasureTime::MeasureTime(int _samples, int _minTap=60000)
{
    minTap=_minTap;
    samples = _samples;
    sampleBank = new int[_samples];
    reset();
    previousMillis = millis();
}

void MeasureTime::addSample()
{
    currentMillis = millis();
    int timeDif = currentMillis - previousMillis;
    if (timeDif <= minTap && timeDif > 0) // check if timing is ok
    {
        sampleBank[index] = timeDif;
        if (index < samples - 1)
        {
            index++;
        }
        else
        {
            index = 0;
        }
    }
    else
    {
        // else reset samplebank
        reset();
    }
    previousMillis = currentMillis;
}

void MeasureTime::reset()
{
    for (int i = 0; i < samples; i++)
    {
        sampleBank[index] = 0;
    }
}

int MeasureTime::getTiming()
{
    int total = 0;
    int count = 0;
    for (int i = 0; i < samples; i++)
    {
        if (sampleBank[i] > 0)
        {
            total += sampleBank[i];
            count++;
        }
    }

    if (count != 0)
    {
        return 60 * count / (total * 0.001);
    }
    else
    {
        return -1;
    }
}
