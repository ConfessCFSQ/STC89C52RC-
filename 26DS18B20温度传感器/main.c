#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "DS18B02.h"

float Temp;
void main()
{
	LCD_Init();
	DS18B02_ConvertT();

	while(1)
	{
		DS18B02_ConvertT();
		Temp = DS18B02_ReadRegister();
		
		if(Temp < 0)
		{
			LCD_ShowChar(2, 1, '-');
			Temp = -Temp;
		}
		else
		{
			LCD_ShowChar(2, 1, '+');
		}
		LCD_ShowNum(2, 2, Temp, 3);
		LCD_ShowChar(2, 5, '.');
		LCD_ShowNum(2, 6, (unsigned long)(Temp * 10000) % 10000, 4);
	}
}