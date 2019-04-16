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

void triggerAlarm(){
// change the duty cycle
    // decide which motor needs to change, change the duty cycle
    

        //Play first section
      firstSection();
      
      //Play second section
      secondSection();
      
      //Variant 1
      beep(f, 250);  
      beep(gS, 500);  
      beep(f, 350);  
      beep(a, 125);
      beep(cH, 500);
      beep(a, 375);  
      beep(cH, 125);
      beep(eH, 650);
      
        delayMs(500);
      //Repeat second section
      secondSection();
      
      //Variant 2 
      beep(f, 250);  
      beep(gS, 500);  
      beep(f, 375);  
      beep(cH, 125);
      beep(a, 500);  
      beep(f, 375);  
      beep(cH, 125);
      beep(a, 650);  

      delayMs(650);
    

    OCR3A = 0;
}

void beep(int note, unsigned int duration)
{
  //Play tone on buzzerPin
  
  DDRE |= (1 << DDE3);
  OCR3A = note;
  delayMs(duration);
 
  //Stop tone on buzzerPin
  DDRE &= ~(1 << DDE3);
  delayMs(50);
}

void firstSection()
{
  beep(a, 500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delayMs(500);

  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);  
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  
delayMs(500);
  
}
 
void secondSection()
{
  beep(aH, 500);
  beep(a, 300);
  beep(a, 150);
  beep(aH, 500);
  beep(gSH, 325);
  beep(gH, 175);
  beep(fSH, 125);
  beep(fH, 125);    
  beep(fSH, 250);
  
  delayMs(325);
  
  beep(aS, 250);
  beep(dSH, 500);
  beep(dH, 325);  
  beep(cSH, 175);  
  beep(cH, 125);  
  beep(b, 125);  
  beep(cH, 250);  
  
  delayMs(350);
}