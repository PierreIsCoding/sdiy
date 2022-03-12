// Based on: http://wiki.openmusiclabs.com/wiki/PWMDAC
// Code wrapper by L.Geerinckx

// Reference text from "Atmel ATmega328P" documentation:
// The Timer/Counter (TCNT1), output compare registers (OCR1A/B), and input capture register (ICR1) are all 16-bit registers.
// The Timer/Counter control registers (TCCR1A/B) are 8-bit registers and The TCNT1, OCR1A/B, and ICR1 are 16-bit registers that can be accessed by the AVR® CPU via the 8-bit data bus.
// The 16-bit register must be byte accessed using two read or write operations.
// To do a 16-bit write, the high byte must be written before the low byte. For a 16-bit read, the low byte must be read before the high byte.
// output high 8bit on pin D9
// output low 8bit on pin D10

namespace MyPWM
{
    #define PWM_FREQ 0x00FF // pwm frequency
    #define PWM_MODE 0      // Fast (1) or Phase Correct (0)
    #define PWM_QTY 2       // number of pwms, either 1 or 2
    #define maxPWM 65536    // 2^16
    uint16_t pwmVal = 0;

    init()  // setup PWM
    {
        TCCR1A = (((PWM_QTY - 1) << 5) | 0x80 | (PWM_MODE << 1)); // set different mode flags in binairy format
        TCCR1B = ((PWM_MODE << 3) | 0x11);                        // set different mode flags in binairy format
        TIMSK1 = 0x20;                                            // interrupt on capture interrupt
        ICR1H = (PWM_FREQ >> 8);
        ICR1L = (PWM_FREQ & 0xff);
        DDRB |= ((PWM_QTY << 1) | 0x02); // turn on outputs
        sei();                           // turn on interrupts - not really necessary with arduino
    }

    write(uint16_t val)
    {
        pwmVal = val;
    }
}

ISR(TIMER1_CAPT_vect)
{
    uint16_t tempHIGH = MyPWM::pwmVal >> 8; // get high 8bit (byte)
    uint16_t tempLOW = MyPWM::pwmVal;

    // output high 8bit on OC1A (3.9k resistor / D9)
    OCR1AH = tempHIGH >> 8; // 8 bit // prevents overflowing overflow
    OCR1AL = tempHIGH;      // 8 bit

    // output low 8bit on OC1B (1M resistor / D10)
    OCR1BL = tempLOW; // takes bottom 8 bits, constantly overflows
}
