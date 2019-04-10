// Description: Function prototypes for pwm.h
//----------------------------------------------------------------------//

#ifndef PWM_H
#define PWM_H

#include <Arduino.h>

const int C_FREQ = 261;
const int D_FREQ = 294;
const int E_FREQ = 329;
const int F_FREQ = 349;
const int G_FREQ = 391;
const int gS_FREQ = 415;
const int A_FREQ = 440;
const int aS_FREQ = 455;
const int B_FREQ = 466;
const int cH_FREQ = 523;
const int cSH_FREQ = 554;
const int dH_FREQ = 587;
const int dSH_FREQ = 622;
const int eH_FREQ = 659;
const int fH_FREQ = 698;
const int fSH_FREQ = 740;
const int gH_FREQ = 784;
const int gSH_FREQ = 830;
const int aH_FREQ = 880;

#define TIMER1_PRESCALER (uint8_t) 8
#define c (F_CPU / (C_FREQ * TIMER1_PRESCALER * 2) - 1)
#define d (F_CPU / (D_FREQ * TIMER1_PRESCALER * 2) - 1)
#define e (F_CPU / (E_FREQ * TIMER1_PRESCALER * 2) - 1)
#define f (F_CPU / (F_FREQ * TIMER1_PRESCALER * 2) - 1)
#define g (F_CPU / (G_FREQ * TIMER1_PRESCALER * 2) - 1)
#define gS (F_CPU / (gS_FREQ * TIMER1_PRESCALER * 2) - 1)
#define a (F_CPU / (A_FREQ * TIMER1_PRESCALER * 2) - 1)
#define aS (F_CPU / (aS_FREQ * TIMER1_PRESCALER * 2) - 1)
#define b (F_CPU / (B_FREQ * TIMER1_PRESCALER * 2) - 1)
#define cH (F_CPU / (cH_FREQ * TIMER1_PRESCALER * 2) - 1)
#define cSH (F_CPU / (cSH_FREQ * TIMER1_PRESCALER * 2) - 1)
#define dH (F_CPU / (dH_FREQ * TIMER1_PRESCALER * 2) - 1)
#define dSH (F_CPU / (dSH_FREQ * TIMER1_PRESCALER * 2) - 1)
#define eH (F_CPU / (eH_FREQ * TIMER1_PRESCALER * 2) - 1)
#define fH (F_CPU / (fH_FREQ * TIMER1_PRESCALER * 2) - 1)
#define fSH (F_CPU / (fSH_FREQ * TIMER1_PRESCALER * 2) - 1)
#define gH (F_CPU / (gH_FREQ * TIMER1_PRESCALER * 2) - 1)
#define gSH (F_CPU / (gSH_FREQ * TIMER1_PRESCALER * 2) - 1)
#define aH (F_CPU / (aH_FREQ * TIMER1_PRESCALER * 2) - 1)

void initPWMTimer3();
void triggerAlarm(volatile bool* deviceOn);
void firstSection(volatile bool* deviceOn);
void secondSection(volatile bool* deviceOn);
void beep(int note, unsigned int duration, volatile bool on);


#endif