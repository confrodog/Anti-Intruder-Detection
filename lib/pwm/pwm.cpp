// Author: Kris Rockowitz       
// Net ID: rockowitzks      
// Date: 10 March 2019   
// Assignment:     Lab 4
// Description: This file implements the PWM element.
//----------------------------------------------------------------------//



#include "pwm.h"
#include "timer.h"  
#include <avr/io.h>



void initPWMTimer3(){
// pin E3 for timer 3, OC3A
    DDRE |= (1 << DDE3);
// set the timer mode to fast PWM, non inverting
    TCCR3A = (1 << COM3A0);
    TCCR3B = (1 << WGM32)|(1 << CS30);

    OCR3A = 0; //1024
}

void triggerAlarm(volatile bool* deviceOn){
// change the duty cycle
    // decide which motor needs to change, change the duty cycle
    
    //while(*deviceOn){
   
        //Play first section
      firstSection(deviceOn);
      
      //Play second section
      secondSection(deviceOn);
      
      //Variant 1
      beep(f, 250, *deviceOn);  
      beep(gS, 500, *deviceOn);  
      beep(f, 350, *deviceOn);  
      beep(a, 125, *deviceOn);
      beep(cH, 500, *deviceOn);
      beep(a, 375, *deviceOn);  
      beep(cH, 125, *deviceOn);
      beep(eH, 650, *deviceOn);
      
      if (*deviceOn) {
        delayMs(500);
      }
      else{
        return;
      }
      //Repeat second section
      secondSection(deviceOn);
      
      //Variant 2 
      beep(f, 250, *deviceOn);  
      beep(gS, 500, *deviceOn);  
      beep(f, 375, *deviceOn);  
      beep(cH, 125, *deviceOn);
      beep(a, 500, *deviceOn);  
      beep(f, 375, *deviceOn);  
      beep(cH, 125, *deviceOn);
      beep(a, 650, *deviceOn);  

      if (*deviceOn)
        delayMs(650);
    

    OCR3A = 0;
}

void beep(int note, unsigned int duration, volatile bool on)
{
  //Play tone on buzzerPin
  
  if (!on) 
    return;
  
  DDRE |= (1 << DDE3);
  OCR3A = note;
  delayMs(duration);
 
  //Stop tone on buzzerPin
  DDRE &= ~(1 << DDE3);
  delayMs(50);
}

void firstSection(volatile bool *deviceOn)
{
  beep(a, 500, *deviceOn);
  beep(a, 500, *deviceOn);    
  beep(a, 500, *deviceOn);
  beep(f, 350, *deviceOn);
  beep(cH, 150, *deviceOn);  
  beep(a, 500, *deviceOn);
  beep(f, 350, *deviceOn);
  beep(cH, 150, *deviceOn);
  beep(a, 650, *deviceOn);
 
  if (*deviceOn)
    delayMs(500);
  else 
    return;

  beep(eH, 500, *deviceOn);
  beep(eH, 500, *deviceOn);
  beep(eH, 500, *deviceOn);  
  beep(fH, 350, *deviceOn);
  beep(cH, 150, *deviceOn);
  beep(gS, 500, *deviceOn);
  beep(f, 350, *deviceOn);
  beep(cH, 150, *deviceOn);
  beep(a, 650, *deviceOn);
 
  if (*deviceOn) {
    delayMs(500);
  }
}
 
void secondSection(volatile bool *deviceOn)
{
  beep(aH, 500, *deviceOn);
  beep(a, 300, *deviceOn);
  beep(a, 150, *deviceOn);
  beep(aH, 500, *deviceOn);
  beep(gSH, 325, *deviceOn);
  beep(gH, 175, *deviceOn);
  beep(fSH, 125, *deviceOn);
  beep(fH, 125, *deviceOn);    
  beep(fSH, 250, *deviceOn);
  
  if (*deviceOn) {
    delayMs(325);
  }
  else 
    return;

  beep(aS, 250, *deviceOn);
  beep(dSH, 500, *deviceOn);
  beep(dH, 325, *deviceOn);  
  beep(cSH, 175, *deviceOn);  
  beep(cH, 125, *deviceOn);  
  beep(b, 125, *deviceOn);  
  beep(cH, 250, *deviceOn);  
  
  if (*deviceOn)
    delayMs(350);
}