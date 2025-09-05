#include <REGX52.H>
#include <INTRINS.H>

unsigned char Time;

void Delay(unsigned int T)
{
	while (T--);
}


void main()
{
	unsigned char i;
	while(1)
	{

		for(Time = 1; Time <= 100; Time++)
		{
			for(i = 0; i <= 20; i++)
			{
				P2 = 0xF8;
				Delay(Time);
				P2 = 0xFF;
				Delay(100 - Time);
			}
			
		}
		for(Time = 100; Time > 1; Time--)
		{
			for(i = 0; i <= 20; i++)
			{
				P2 = 0xF8;
				Delay(Time);
				P2 = 0xFF;
				Delay(100 - Time);
			}
			
		}
		
	}
}

