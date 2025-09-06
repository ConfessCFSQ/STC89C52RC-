#include <REGX52.H>


void Timer0_Init()
{
	//定时器工作模式寄存器TMOD：
	TMOD = TMOD & 0xF0;//???? ???? & 1111 0000 = ???? 0000
	TMOD = TMOD | 0x01;//???? 0000 | 0000 0001 = ???? 0001
	//定时器控制寄存器TCON：
	//由于定时器0的GATE口置0，所以不用管IE0和IT0，原因看图
	TR0 = 0;//1开启计时器/0关闭计时器
	TF0 = 0;
	//低8位寄存器赋初始值TL0：
	TL0 = 0;
	//高8位寄存器赋初始值TH0:
	TH0 = 0;
}

void Timer0_SetCounter(unsigned int Value)
{
	TL0 = Value / 256;
	TH0 = Value % 256;
}

unsigned int Timer0_GetCounter()
{
	return (TH0 << 8) | TL0;
}

void Timer0_StartStop(unsigned char Flag)
{
	TR0 = Flag;
}
