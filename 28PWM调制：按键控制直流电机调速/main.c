#include <REGX52.H>
#include <INTRINS.H>
#include "Timer0.h"
#include "Key.h"
#include "NixieTube.h"
#include "Delay.h"

unsigned char Counter, Compare;
unsigned char KeyNum, Speed;

void main()
{
	Timer0_Init();
	while(1)
	{
		KeyNum = KeyNumber();
		if(KeyNum == 1)
		{
			Speed++;
			Speed = Speed % 4;
			if(Speed == 0){Compare = 0;}
			if(Speed == 1){Compare = 50;}
			if(Speed == 2){Compare = 75;}
			if(Speed == 3){Compare = 100;}
		}
		NixieTube(1, Speed);
		
		
	}
}

void Timer0_Routine() interrupt 1
{
    TL0 = 0xA4;  // 低8位初值
	TH0 = 0xFF;  // 高8位初值
    
	Counter++;
	Counter = Counter % 100;
	
	if(Counter < Compare)
	{
		P1_0 = 1;
	}
	else
	{
		P1_0 = 0;
	}
}