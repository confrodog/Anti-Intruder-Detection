
#include "timer.h"

void initTimer1(){
    // set timer to CTC mode
    TCCR1A &= ~(1 << WGM10);
    TCCR1A &= ~(1 << WGM11);
    TCCR1B |= (1 << WGM12);
    TCCR1B &= ~(1 << WGM13);

    //sets prescaler to 64
    TCCR1B |= (1 << CS11) | (1<<CS10);

    //for millisecond timer
    OCR1A = 250;
}

void delayMs(unsigned int delay){
    unsigned int delayCnt = 0;
    TIFR1 |= (1 << OCF1A);
    TCNT1 = 0;


    // counts 1us up until the inputted delay
    while(delayCnt < delay){
        if(TIFR1 & (1 << OCF1A)){
            delayCnt++;
            TIFR1 |= (1 << OCF1A);
        }
    }
}