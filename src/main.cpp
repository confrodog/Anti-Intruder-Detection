
#include <Arduino.h>
#include "adxl345.h"
#include "led.h"
#include "timer.h"
#include "pir.h"
#include "pwm.h"
#include "switch.h"
#include "adc.h"
#include "math.h"

#define thresh 300

typedef enum stateType_enum{
  waitPress, debouncePress, waitRelease, debounceRelease
} stateType;
volatile stateType state = waitPress;
volatile bool deviceOn = false;

int main(void){
  sei();
  Serial.begin(9600);
  
  //checks for tripping the alarm
  bool motionB = false; 
  bool tooFar = false;
  int light = 0;

  bool prevMotion = false;
  bool prevTooFar = false;
  int prevLight = 0;
  initTimer1(); //for testing
  initLED(); //for testing
  initPIR(); //motion sensor
  delayMs(30000); //PIR takes a minute to warm up
  
  initADXL345(); //accelerometer
  initPWMTimer3();
  initSwitchPB1();
  initADC0();

  while(1) {

    switch(state){
      case waitPress:
        break;
      case debouncePress:
        delayMs(100);
        state = waitRelease;
        break;
      case waitRelease:
        break;
      case debounceRelease:
        delayMs(100);
        state = waitPress;
        break;
    }
      //read the photoresistor
      light = detectLaser();

      //bool to check if the device has been moved past the thresh value
      tooFar = (abs(getZ()) > thresh);

      //uses PIR sensor to check if any motion
      motionB = detectMotion();
      
      //Serial.print("Device on?: \t");
      //Serial.println(deviceOn);
      if (motionB != prevMotion) {
        Serial.print("Motion: \t");
        Serial.println(motionB);
        Serial.flush();
        prevMotion = motionB;
      }
      if (tooFar != prevTooFar) {
        Serial.print("isMoved: \t");
        Serial.println(tooFar);
        Serial.flush();
        prevTooFar = tooFar;
      }
      if (light != prevLight) {
        Serial.print("laser interrupted: \t");
        Serial.println(light);
        Serial.flush();
        prevLight = light;
      }
  
      while(deviceOn && (tooFar|| motionB || (light > thresh))){ // took out motion here, but will need later
        lightLED();
        triggerAlarm();
      }
      
      turnOffLED();
        
    } 
}

 ISR(PCINT0_vect){
  if(state == waitPress){

    state = debouncePress;
  }
  else if (state == waitRelease){
    deviceOn = !deviceOn;
    state = debounceRelease;
  }  
}   
