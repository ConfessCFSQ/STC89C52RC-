#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "AT24C02.h"
#include "Key.h"

unsigned char KeyNum;
unsigned char Num;

void main()
{
	LCD_Init();
	
	LCD_ShowNum(1, 1, Num, 5);
	while(1)
	{
		KeyNum = KeyNumber();
		if(KeyNum == 1)
		{
			Num--;
			LCD_ShowNum(1, 1, Num, 5);
		}
		if(KeyNum == 2)
		{
			Num++;
			LCD_ShowNum(1, 1, Num, 5);
		}
		if(KeyNum == 3)
		{
			AT24C02_SendByte(0, Num);
			LCD_ShowString(2, 1, "SaveNumber  OK");
			Delay(250);
			Delay(250);
			Delay(250);
			Delay(250);
			LCD_ShowString(2, 1, "              ");
		}
		if(KeyNum == 4)
		{
			Num = AT24C02_ReceiveByte(0);
			LCD_ShowNum(2, 1, Num, 5);
		}
	}
}