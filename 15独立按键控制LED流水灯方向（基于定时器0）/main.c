#include <REGX52.H>
#include "Timer0.h"
#include <INTRINS.H>
#include "Key.h"

unsigned char KeyNum;
unsigned char LEDMode;

void main()
{
	Timer0_Init();
	P2 = 0xFE;
	while(1)
	{
		KeyNum = KeyNumber();
		if(KeyNum)
		{
			if(KeyNum == 1)
			{
				LEDMode = 0;
			}
			if(KeyNum == 2)
			{
				LEDMode = 1;
			}
		}
	}
}


void Timer0_Rountine() interrupt 1
{
	static unsigned int T0count;
	
	//低8位寄存器赋初始值TL0：
	TL0 = 0x66;
	//高8位寄存器赋初始值TH0:
	TH0 = 0xFC;
	T0count++;
		
	if(T0count >= 500)
	{
		T0count = 0;
		if(LEDMode == 0)
		{
			P2 = _cror_(P2, 1);
		}
		if(LEDMode == 1)
		{
			P2 = _crol_(P2, 1);
		}
	}
}