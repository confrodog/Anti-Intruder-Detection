#ifndef I2C_H
#define I2C_H

#include <avr/io.h>

void initI2C();
void beginTransmission(int i2c_address);
void endTransmission();
void write(int data);
void requestFrom(int address, int quantity);
char read();


#endif