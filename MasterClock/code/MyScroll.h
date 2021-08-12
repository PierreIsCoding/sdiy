// Code by L.Geerinckx 28-1-2021 | https://github.com/PierreIsCoding

class MyScroll
{
private:
    int _index;
    int _len;
    bool _loopScroll;
    void (*_handler)(int);
    int _x; // x start cursor;
    int _y; // y start cursor;
    String _label;
    int minValue;

public:
    MyScroll(int, void handler(int), int, int, bool);
    int getIndex();
    int UP();
    int DOWN();
    void start();
    void toggleIncrement();
    void setIndex(int);

    int fine = 1;
    int course = 10;
    int increment = course;
};

MyScroll::MyScroll(int len, void handler(int), int _minValue = 0, int start = 0, bool loopScroll = 0)
{
    _len = len;
    _loopScroll = loopScroll;
    _index = start;
    _handler = handler;
    minValue = _minValue;
}

int MyScroll::getIndex()
{
    return _index;
}

void MyScroll::start()
{
    _handler(_index);
}

int MyScroll::UP()
{
    if (_index < (_len - increment))
    {

        _index += increment;
        _handler(_index);
    }
    else if (_loopScroll)
    {
        _index = 0;
    }
    return _index;
}

int MyScroll::DOWN()
{
    if (_index >= increment + minValue)
    {
        _index -= increment;
        _handler(_index);
    }
    else if (_loopScroll)
    {
        _index = _len - 1;
    }
    return _index;
}

void MyScroll::toggleIncrement()
{
    if (increment == course)
    {
        increment = fine;
    }
    else
    {
        increment = course;
    }
}

void MyScroll::setIndex(int index)
{
    if (index <= _len && index >= minValue)
    {
        _index = index;
    }
}
