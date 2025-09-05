#include <REGX52.H>
#include "LCD1602.h"
#include "Timer0.h"

unsigned int Hours = 23, Minutes = 59, Second = 55;
unsigned int Year = 2025, Mouth = 11, Day = 29;

void main()
{
	LCD_Init();
	Timer0_Init();

	LCD_ShowString(1, 1, "Date:");
	LCD_ShowString(1, 10, "/");
	LCD_ShowString(1, 13, "/");
	
	LCD_ShowString(2, 1, "Clock:");
	LCD_ShowString(2, 9, ":");
	LCD_ShowString(2, 12, ":");
	
	
	
	
	while(1)
	{
		LCD_ShowNum(1, 6, Year, 4);
		LCD_ShowNum(1, 11, Mouth, 2);
		LCD_ShowNum(1, 14, Day, 2);
		
		LCD_ShowNum(2, 7, Hours, 2);
		LCD_ShowNum(2, 10, Minutes, 2);
		LCD_ShowNum(2, 13, Second, 2);
	}
}

void Timer0_Rountine() interrupt 1
{
	static unsigned int T0count;
	TL0 = 0x66;
	TH0 = 0xFC;
	T0count++;
	
	if(T0count >= 1000)
	{
		T0count = 0;
		
		Second++;
		if(Second >= 60)
		{
			Second = 0;
			Minutes++;
			if(Minutes >= 60)
			{
				Minutes = 0;
				Hours++;
				if(Hours >= 24)
				{
					Hours =0;
					Day++;
					if(Day >= 30)
					{
						Day = 1;
						Mouth++;
						if(Mouth >= 12)
						{
							Mouth = 1;
							Year++;
						}
					}
				}
			}
		}
	}
}