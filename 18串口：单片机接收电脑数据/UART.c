#include <REGX52.H>
#include "Timer1.h"


void UART_Init()
{
	Timer1_Init();
	//串行口控制寄存器SCON
	SM0 = 0;//选择工作方式1
	SM1 = 1;//选择工作方式1
	REN = 1;//设置开启使能控制（中断）
	TI = 0;//发送中断请求标志位，必须软件复位
	RI = 0;//接收中断请求标志位，必须软件复位
	//电源控制寄存器PCON
	PCON = PCON & 0x3F;//XXXX XXXX & 0011 1111 = 00XX XXXX
	//中断允许寄存器IE
	EA = 1;//开启总中断
	ES = 1;//开启串行口1中断
	ET1 = 0;//禁止定时器1中断
	
	
	
}

void UART_SendByte(unsigned char Byte)
{
	SBUF = Byte;
	while(TI == 0);
	TI = 0;
}

/*串口中断函数
void UART_Routine() interrupt 4
{
	if(RI == 1)
	{
		
		RI = 0;
	}
}
*/
