// Code by L.Geerinckx
// A simple class for triggering events


class MyTrigger
{
private:
    long count;
    long current;
    void (*handler)(byte);
    bool triggerOn;

public:
    MyTrigger(void _handler(bool), long);
    void start();
    void next();
};

MyTrigger::MyTrigger(void _handler(bool), long _count)
{
    handler = _handler;
    count = _count;
}

void MyTrigger::start()
{
    handler(true);
    current = 0;
    triggerOn = true;
}

void MyTrigger::next()
{
    if (current < count)
    {
        current++;
    }
    else if (triggerOn)
    {
        triggerOn = false;
        handler(false);
    }
}
