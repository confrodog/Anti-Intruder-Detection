#ifndef ADXL345_H
#define ADXL345_H

#include <avr/io.h>
#include <Arduino.h>
#include "i2c.h"

void initADXL345();
int getX();
int getY();
int getZ();

#endif