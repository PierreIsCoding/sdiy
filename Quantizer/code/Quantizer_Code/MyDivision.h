#ifndef MYDIVISION_H
#define MYDIVISION_H

// Code by Luther / l.Geerinckx
// 12 March 2022
// A clock division utility


class MyDivision
{
private:
    long count;
    long current = 0;

public:
    MyDivision(long);
    bool onNext();
    void setDivision(long);
    long getCurrent();
    long getDivision();
};

MyDivision::MyDivision(long _count)
{
    count = _count;
}

void MyDivision::setDivision(long _count)
{
    count = _count;
    onNext();
}

long MyDivision::getCurrent()
{
    return current;
}

long MyDivision::getDivision()
{
    return count;
}

bool MyDivision::onNext()
{
    if (current >= count)
    {
        current = 0;
        return true;
    }
    else
    {
        current++;
        return false;
    }
}

#endif
