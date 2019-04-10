// PB1 Switch
#include "switch.h"
#include <avr/io.h>

void initSwitchPB1(){
  DDRB &= ~(1 << DDB1); // Initializes pull-up resistor on PB3 and sets it into input mode
  PORTB |= (1 << PORTB1); // enable pull-up for PORTB3

  PCICR |= (1 << PCIE0);      // enable PCINT for 7-0
  PCMSK0 |= (1 << PCINT1);    // enable PCINT for PCINT3
}