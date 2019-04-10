#ifndef LED_H
#define LED_H

#include <avr/io.h>

void initLED();
void lightLED();
void turnOffLED();
void toggleLED(bool motion, bool deviceOn);

#endif