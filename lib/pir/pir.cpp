#include "pir.h"

void initPIR(){
    //using pin A0 as input
    DDRA &= ~(1 << DDA0);
    PORTA |= (1 << PORTA0);
}

bool detectMotion(){
    return PINA & (1 << PINA0);
}