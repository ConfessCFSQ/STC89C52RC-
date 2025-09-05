#include <REGX52.H>


void Timer0_Init()
{
	//定时器工作模式寄存器TMOD：
	TMOD = TMOD & 0xF0;//???? ???? & 1111 0000 = ???? 0000
	TMOD = TMOD | 0x01;//???? 0000 | 0000 0001 = ???? 0001
	//定时器控制寄存器TCON：
	//由于定时器0的GATE口置0，所以不用管IE0和IT0，原因看图
	TR0 = 1;
	TF0 = 0;
	//低8位寄存器赋初始值TL0：
	TL0 = 0xA4;
	//高8位寄存器赋初始值TH0:
	TH0 = 0xFF;
	//中断允许寄存器IE：
	ET0 = 1;
	EA = 1;
	//中断优先级控制寄存器低IP：
	PT0 = 0;
}

// 定时器0中断服务函数
//void Timer0_Routine(void) interrupt 1
//{
//    TL0 = 0x66;  // 低8位初值
//	TH0 = 0xFC;  // 高8位初值
//    
//}