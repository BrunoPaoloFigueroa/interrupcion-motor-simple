#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>
char pos=0x00;

ISR(INT1_vect) {
    _delay_ms(50); 

    switch (pos) {
        case 1:
            _delay_ms(500);
            PORTD |= 0x80; 
            pos = 2;
            break;
        case 2:
            _delay_ms(500);
            PORTD &= ~(0x80); 
            _delay_ms(500);
            PORTD |= 0x40; 
            pos = 3;
            break;
        case 3:
            _delay_ms(500);
            PORTD &= ~(0x40); 
            pos = 1;
            break;
    }
}
