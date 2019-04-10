#include "Arduino.h"
#include "i2c.h"

// #define wait_for_completion while(!(TWCR & (1 << TWINT)));

void initI2C() 
{
  TWSR |= (1 << TWPS0);
  TWSR &= ~(1 << TWPS1); // prescaler = 1
  TWBR = 0xFF; // bit rate generator
  
  TWCR |= (1 << TWINT | 1 << TWEN); // enable two wire interface 
  
}

void beginTransmission(int i2c_address){
    //start transmission
    TWCR = ((1 << TWEN) | (1 << TWINT) | (1 << TWSTA));
    
    while(!(TWCR & (1 << TWINT)));
    // Serial.println("start");
    // Serial.println(TWSR & 0b11111000);
    write((i2c_address<<1));
}

void endTransmission(){
    // Serial.println("endtransmission");
    // Serial.println(TWSR & 0b11111000);
    TWCR = (1<<TWINT)|(1<<TWEN)|(1<< TWSTO);
    //while(!(TWCR & (1 << TWINT)));
}

void write(int data){
    TWDR = data;
    TWCR = (1<<TWINT)|(1<<TWEN);
    while(!(TWCR & (1 << TWINT)));
}

char read(){
    char temp = 0;
    TWCR = ((1 << TWEN)|(1 << TWINT));
    while(!(TWCR & (1 << TWINT))); 
    temp = TWDR;
    return temp;
}

void requestFrom(int address, int quantity){
    //int register_value = 0;

    TWCR = ((1 << TWEN) | (1 << TWINT) | (1 << TWSTA));
    while(!(TWCR & (1 << TWINT)));

    TWDR = (address << 1) | 0x01; //for the read bit
    TWCR = ((1 << TWINT) | (1 << TWEN));
    while(!(TWCR & (1 << TWINT)));
   
}
