/*
*Authors : Connor Musick
* Handles input as analog and converts to digital
*/
#include "adc.h"
#include <avr/io.h>

//reading an analog signal from the potentiometer from pin A0
void initADC0()
{
    //set ADMUX to use AVCC
    ADMUX |= (1<<REFS0);
    ADMUX &= ~(1<<REFS1);

    //set ADLAR to RIGHT_JUSTIFIED
    ADMUX &= ~(1<<ADLAR);

    //setting MUX5:0 to single ended input for A0
    ADMUX &= ~(1<<MUX0);
    ADMUX &= ~(1<<MUX1);
    ADMUX &= ~(1<<MUX2);
    ADMUX &= ~(1<<MUX3);
    ADMUX &= ~(1<<MUX4);
    ADCSRB &= ~(1<<MUX5);

    //set auto-trigger to free-running mode
    ADCSRB &= ~(1<<ADTS2 | 1<<ADTS1 | 1<<ADTS0);

    //enable auto-trigger and turn on ADC
    ADCSRA |= (1<<ADEN | 1<<ADATE);

    //set adc prescaled to 128
    //time is calculated to 104us
    ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);

    //disable digital input mode for pin ADC0
    DIDR0 |= (1<<ADC0D);

    //start initial sample
    ADCSRA |= (1<<ADSC);
        
}

int detectLaser(){
    return ADCL + (ADCH<<8);
}