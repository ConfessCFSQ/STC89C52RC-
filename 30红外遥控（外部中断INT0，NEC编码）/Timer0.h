#ifndef __TIMER0__H__
#define __TIMER0__H__

void Timer0_Init();
void Timer0_SetCounter(unsigned int Value);
unsigned int Timer0_GetCounter();
void Timer0_StartStop(unsigned char Flag);


#endif