#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#define F_CPU = 8000000

int steps[] = {0x09, 0x0A, 0x06, 0x05};
int step_index = 0;
bool recursive_mode = false; 
volatile uint32_t timer0_overflows = 0;

void initial_timer0()
{
    TCCR0 |= _BV(CS02);

    TCNT0 = 0;

    TIMSK |= _BV(TOIE0);

    timer0_overflows = 0;
}

ISR(TIMER0_OVF_vect)
{
    timer0_overflows++;
}

int main()
{
    DDRA = 0xFF;
    DDRC = 0x00;

    initial_timer0();
    sei();

    while (PINC == _BV(PINC2))
    {
    }

    while (1)
    {

        if (timer0_overflows >= 61)
        {
            if (TCNT0 >= 9)
            {
                PORTA = steps[step_index];
                if (recursive_mode)
                {
                    if (step_index <= 0)
                    {
                        recursive_mode = !recursive_mode;
                    }
                    else
                    {
                        step_index--;
                    }
                }
                else
                {
                    if (step_index >= 3)
                    {
                        recursive_mode = !recursive_mode;
                    }
                    else
                    {
                        step_index++;
                    }
                }
                TCNT0 = 0;
                timer0_overflows = 0;
            }
        }
    }
    return 0;
}