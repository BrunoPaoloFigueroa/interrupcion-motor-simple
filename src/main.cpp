#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>
char pos=0;

void config_INT(void) {

    EIMSK |= 0x03;      
    EICRA |= 0x0A;         

    DDRD &= ~(0x0C);     
    PORTD |= 0x0C;        

       
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
    pos=1;
    
    DDRD|=0xC0;



    config_INT();
    sei();

    while(1){



    }

    return 0;
}