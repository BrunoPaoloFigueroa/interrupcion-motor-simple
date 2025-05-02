#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>
char pos=0x00;

void config_PCI(void) {

    EIMSK |= 0x03;      
    EICRA |= 0x0A;         

    DDRD &= ~(0x08);     
    PORTD |= 0x08;        

       
}

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

int main(void){

    DDRD|=0xC0;


    config_PCI();
    sei();

    while(1){



    }

    return 0;
}