#include <REGX52.H>
#include "Delay.h"

#define MatrixLED_Row	P0

sbit SER = P3^4;
sbit SRCLK = P3^6;
sbit RCK = P3^5; //RCLK




void MartixLED_74HC595_(unsigned char Row_Byte)
{
	unsigned char i;
	for(i = 0; i < 8; i++)
	{
		SER = Row_Byte & (0x80 >> i);//1000 0000
		SRCLK = 1;
		SRCLK = 0;
	}
	RCK = 1;
	RCK = 0;

}

//Column行 Row列
void MatrixLED_Show(unsigned char Column, Row)
{
	MartixLED_74HC595_(Row);
//	if(Column == 0){P0_7 = 0;}
//	if(Column == 1){P0_6 = 0;}
//	if(Column == 2){P0_5 = 0;}
//	if(Column == 3){P0_4 = 0;}
//	if(Column == 4){P0_3 = 0;}
//	if(Column == 5){P0_2 = 0;}
//	if(Column == 6){P0_1 = 0;}
//	if(Column == 7){P0_0 = 0;}
	MatrixLED_Row = ~(0x80 >> Column);//1000 0000
	
	//消影
	Delay(1);
	MatrixLED_Row = 0xFF;
}

void MatrixLED_Init()
{
	SRCLK = 0;
	RCK = 0;
}