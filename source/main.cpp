#include <avr/io.h>
#include <util/delay.h>
#include "SevenSegment.h"
#include "UART.h"

#define MCLOCK  16000000
#define MBAUD   9600
#define MUBRR   (MCLOCK/16/MBAUD-1)

int main( void )
{
    SevenSegment seg7;
    UART U0;
    seg7.init();
    U0.init(MUBRR);
    while(1) {
        for (uint8_t i=0; i<10; i++) {
            seg7.display(i);
            U0.transmit(i + 48);// ASCII code
            U0.transmit(0x20); // Space character
            _delay_ms(1000);
        }
    }
}