/* 
-----------------------------------
The original code for max7219 only was  written for the Wiring board by:
 * Nicholas Zambetti and Dave Mellis /byteeraction Design Institute Ivrea /Dec 2004
 * https://www.potemkin.org/uploads/Wiring/MAX7219.txt
 * Simplified, extended and wrapped in class by L. Geerinckx // https://github.com/PierreIsCoding
 -----------------------------------
*/

class MyLedMatrix
{
private:
    byte dataPin;
    byte loadPin;
    byte clockPin;
    void setByte(byte);
    void maxInit(byte, byte);
    byte *displayBuffer[8];
    byte arrayToByte(byte[8]);
    void setColumn(byte, byte);

public:
    MyLedMatrix(byte, byte, byte);
    void begin();
    void print();
    void setPixel(byte, byte, byte);
    void printSprite(byte[8][8]);
    void togglePixel(byte, byte);
    void clearBuffer();
    void clearArrea(byte,byte,byte,byte);
    void verticalLine(byte,byte,byte,byte);
    void horizontalLine(byte,byte,byte,byte);
};

MyLedMatrix::MyLedMatrix(byte _dataPin, byte _loadPin, byte _clockPin)
{
    dataPin = _dataPin;
    loadPin = _loadPin;
    clockPin = _clockPin;

    for (byte i = 0; i < 8; i++)
    {
        displayBuffer[i] = new byte[8];
        for (byte j = 0; j < 8; j++)
        {
            displayBuffer[i][j] = 0;
        }
    }
}

void MyLedMatrix::maxInit(byte reg, byte col)
{
    digitalWrite(loadPin, LOW); // begin
    setByte(reg);               // specify register
    setByte(col);               //((data & 0x01) * 256) + data >> 1); // put data
    digitalWrite(loadPin, LOW);
    digitalWrite(loadPin, HIGH);
}

void MyLedMatrix::begin()
{
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(loadPin, OUTPUT);

    byte max7219_reg_decodeMode = 0x09;
    byte max7219_reg_byteensity = 0x0a;
    byte max7219_reg_scanLimit = 0x0b;
    byte max7219_reg_shutdown = 0x0c;
    byte max7219_reg_displayTest = 0x0f;

    //initiation of the max 7219
    maxInit(max7219_reg_scanLimit, 0x07);
    maxInit(max7219_reg_decodeMode, 0x00);    // using an led matrix (not digits)
    maxInit(max7219_reg_shutdown, 0x01);      // not in shutdown mode
    maxInit(max7219_reg_displayTest, 0x00);   // no display test
    maxInit(0, 0);                            // empty registers, turn all LEDs off
    maxInit(max7219_reg_byteensity, 0 & 0x0f); // the first 0x0f is the value you can set  //0-15 sets display byteensity
}

void MyLedMatrix::setByte(byte data)
{
    byte i = 8;
    byte mask;
    while (i > 0)
    {
        mask = 0x01 << (i - 1);      // get bitmask
        digitalWrite(clockPin, LOW); // tick
        if (data & mask)
        {                                // choose bit
            digitalWrite(dataPin, HIGH); // send 1
        }
        else
        {
            digitalWrite(dataPin, LOW); // send 0
        }
        digitalWrite(clockPin, HIGH); // tock
        --i;                          // move to lesser bit
    }
}

void MyLedMatrix::setColumn(byte column, byte data)
{
    digitalWrite(loadPin, LOW); // begin
    setByte(column + 1);        // specify register
    setByte(data);              //((data & 0x01) * 256) + data >> 1); // put data
    digitalWrite(loadPin, LOW); // and loadPin da stuff
    digitalWrite(loadPin, HIGH);
}

byte MyLedMatrix::arrayToByte(byte boolArray[8])
{
    byte result = 0;
    for (byte i = 0; i < 8; i++)
    {
        if (boolArray[i])
        {
            result = result | (1 << i);
        }
    }
    return result;
}

void MyLedMatrix::print()
{
    // deploy buffer to led matrix
    for (byte i = 0; i < 8; i++)
    {
        setColumn(i, arrayToByte(displayBuffer[i]));
    }
}

void MyLedMatrix::setPixel(byte x, byte y, byte value)
{
    displayBuffer[x][y] = value;
}

void MyLedMatrix::horizontalLine(byte x, byte y, byte len, byte value)
{
    for(byte i=0;i<len;i++){
         displayBuffer[x+i][y] = value;
    }
}

void MyLedMatrix::verticalLine(byte x, byte y, byte len, byte value)
{
    for(byte i=0;i<len;i++){
          displayBuffer[x][y+i] = value;
    }

}

void MyLedMatrix::togglePixel(byte x, byte y)
{
    displayBuffer[x][y] = !displayBuffer[x][y];
}

void MyLedMatrix::printSprite(byte sprite[8][8])
{
    for (byte i = 0; i < 8; i++)
    {
        for (byte j = 0; j < 8; j++)
        {
            displayBuffer[i][j] = sprite[j][i];
        }
    }
}
void MyLedMatrix::clearBuffer()
{
    for (byte i = 0; i < 8; i++)
    {
        for (byte j = 0; j < 8; j++)
        {
            displayBuffer[i][j] = 0;
        }
    }
}

void MyLedMatrix::clearArrea(byte x_start, byte y_start,byte x_end, byte y_end)
{
    for (byte i = x_start; i < x_end; i++)
    {
        for (byte j = y_start; j < y_end; j++)
        {
            displayBuffer[i][j] = 0;
        }
    }
}
