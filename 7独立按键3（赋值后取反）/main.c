#include <REGX52.H>

void Delay(unsigned int xms)	//@12MHz
{
	unsigned char data i, j;

	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
	
	
}


void main()
{
	unsigned char LEDNum = 0;
	while(1)
	{
		if(P3_1 == 0)
		{
			Delay(20);
			while(P3_1 == 0);
			Delay(20);
			
			LEDNum++;
//			0000 0001 / 0000 0010 / 0000 0011 / ...
			P2 = ~LEDNum;
//			1111 1110 / 1111 1101 / 1111 1100 / ...
		}
	}
}