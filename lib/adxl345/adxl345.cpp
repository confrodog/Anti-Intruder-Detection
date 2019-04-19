#include "adxl345.h"

#define accel_module 0x53

void initADXL345(){
    //write 0x08 to power control register (0x2d), enables measurement mode in POWER_CTRL
    //write 0x0b to data format register (0x31), sets measurement range
    //intialize offsets (maybe)
    
    beginTransmission(accel_module);
    write(0x2D); //POWER_CTRL
    write(0x00); //enables measurement mode
    endTransmission();
    beginTransmission(accel_module);
    write(0x2D); //POWER_CTRL
    write(0x08); //enables measurement mode
    endTransmission();
}

int getZ(){
    int z = 0;
    beginTransmission(accel_module);
    write(0x36);
    requestFrom(accel_module, 1); //x LSB register
    z += read();
    endTransmission();

    beginTransmission(accel_module);
    write(0x37);
    requestFrom(accel_module, 1);
    z += (read()<<8);
    endTransmission();
    return z;
}