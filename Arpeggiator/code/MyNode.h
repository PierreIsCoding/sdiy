#ifndef MYNODE_H
#define MYNODE_H

// Markov Chain Node
// probability between 0-100
// Code by L.Geerinckx 

class MyNode
{
private:
    byte num;
    byte *probabilityArr;
    byte *outArr;
    byte outNum;

public:
    MyNode(byte[], byte);
    byte next();
};

MyNode::MyNode(byte _probabilityArr[], byte _num)
{
    num = _num;
    probabilityArr = new byte[num];
    outArr = new byte[num];

    for (byte i = 0; i < num; ++i)
    {
        probabilityArr[i] = _probabilityArr[i];
    }
}

byte MyNode::next()
{
    outNum = 0;
    for (byte i = 0; i < num; ++i)
    {
        if (probabilityArr[i] > random(0, 99))
        {
            outArr[outNum] = i;
            outNum++;
        }
    }

    // run again with all equal if none of the nodes got the change
    if (outNum == 0)
    {
        for (byte i = 0; i < num; ++i)
        {
            if (probabilityArr[i] > 0)
            {
                outArr[outNum] = i;
                outNum++;
            }
        }
    }
    return outArr[random(0, outNum)];
}

#endif
