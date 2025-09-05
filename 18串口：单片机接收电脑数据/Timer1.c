#include <REGX52.H>


void Timer1_Init()
{
	//定时器工作模式寄存器TMOD：
	TMOD = TMOD & 0x0F;//xxxx xxxx & 0000 1111 = 0000 xxxx
	TMOD = TMOD | 0x20;//0000 xxxx | 0010 0000 = 0010 xxxx
	//定时器控制寄存器TCON：
	TF1 = 0;//软件置0，允许开始计数
	TR1 = 1;//允许定时器1启用
	//低4位寄存器赋初始值TL0：
	TL1 = 0xFD;
	//高4位寄存器赋初始值TH0:
	TH1 = 0xFD;
}

