#include <REGX52.H>


void Int0_Init(void)
{
	IT0 = 1;//下降沿触发
	IE0 = 0;//边沿触发时，由硬件置1和清0;
	EX0 = 1;//开启外部中断0
	EA = 1;//开启中断
	PX0 = 1;//给予高优先级
}

/*
void Int0_Routine(void) interrupt 0
{
	
}
*/