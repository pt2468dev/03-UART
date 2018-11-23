#ifndef UART_H_
#define UART_H_

#include <avr/io.h>

class UART {
  public:
    void init(unsigned int ubrr);
    void transmit(unsigned char data);
};

#endif // UART_H_