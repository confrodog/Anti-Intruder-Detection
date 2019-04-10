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

int getX(){
    int x = 0;
    beginTransmission(accel_module);
    write(0x32);
    requestFrom(accel_module, 1); //x LSB register
    x += read();
    endTransmission();

    beginTransmission(accel_module);
    write(0x33);
    requestFrom(accel_module, 1);
    x += (read()<<8);
    endTransmission();
    x+=5;
    Serial.print("X = ");
    Serial.print(x);
    return x;
}

int getY(){
    int y = 0;
    beginTransmission(accel_module);
    write(0x34);
    requestFrom(accel_module, 1); //x LSB register
    y += read();
    endTransmission();

    beginTransmission(accel_module);
    write(0x35);
    requestFrom(accel_module, 1);
    y += (read()<<8);
    endTransmission();
    Serial.print("\tY = ");
    Serial.print(y);
    return y;
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
    // Serial.print("Z = ");
    // Serial.println(z+3);
    // Serial.flush();
    return z + 3;
}