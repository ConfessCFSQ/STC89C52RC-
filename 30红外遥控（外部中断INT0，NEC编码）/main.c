#include <REGX52.H>
#include "LCD1602.h"
#include "IR.h"

unsigned char Num;
unsigned char Address;
unsigned char Command;


void main()
{
	LCD_Init();
	IR_Init();
	
	LCD_ShowNum(1, 1, 0x09, 3);
	while(1)
	{
		if(IR_GetDataFlag())
		{
			Address = IR_GetAddress();
			Command = IR_GetCommand();
			
			LCD_ShowHexNum(2, 1, Address, 2);
			LCD_ShowHexNum(2, 5, Command, 2);
		}
	}
}
