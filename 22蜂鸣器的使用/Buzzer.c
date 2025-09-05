#include <REGX52.H>
#include <INTRINS.H>

sbit BuzzerIO = P2^5;

void Buzzer_Delay500us(void)	//@11.0592MHz
{
	unsigned char data i;

	_nop_();
	i = 227;
	while (--i);
}


void Buzzer(unsigned char ms)
{
	unsigned int i;
	for(i = 0; i < ms * 2; i++)
	{
		BuzzerIO = ~BuzzerIO;
		Buzzer_Delay500us();
	}
	
}