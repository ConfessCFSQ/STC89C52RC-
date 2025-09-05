#include <REGX52.H>

void Delay(unsigned char xms)	//@12.000MHz
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


unsigned char NixieNumber[] = {0x3F , 0x06 , 0x5B , 0x4F , 0x66 , 0x6D , 0x7D , 0x07 , 0x7F , 0x6F};//0011 1111 , 0000 0110 , 0101 1011 , 0100 1111 , 0110 0110 , 0110 1101 , 0111 1101 , 0000 0111 , 0111 1111 , 0110 1111

void NixieTube(unsigned char Location ,unsigned char Number)
{
	switch(Location)
	{
		case 1:P2_4 = 1; P2_3 = 1; P2_2 = 1;
		break;
		case 2:P2_4 = 1; P2_3 = 1; P2_2 = 0;
		break;
		case 3:P2_4 = 1; P2_3 = 0; P2_2 = 1;
		break;
		case 4:P2_4 = 1; P2_3 = 0; P2_2 = 0;
		break;
		case 5:P2_4 = 0; P2_3 = 1; P2_2 = 1;
		break;
		case 6:P2_4 = 0; P2_3 = 1; P2_2 = 0;
		break;
		case 7:P2_4 = 0; P2_3 = 0; P2_2 = 1;
		break;
		case 8:P2_4 = 0; P2_3 = 0; P2_2 = 0;
		break;
	}
	
	P0 = NixieNumber[Number];
	
	Delay(1);
	P0 = 0x00;
}

void main()
{
	while(1)
	{
		NixieTube(1, 5);

		NixieTube(2, 2);

		NixieTube(3, 0);

		NixieTube(4, 1);

		NixieTube(5, 3);

		NixieTube(6, 1);

		NixieTube(7, 4);

		
	}
}