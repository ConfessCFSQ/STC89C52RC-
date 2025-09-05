#include <REGX52.H>
#include "Delay.h"
#include "NixieTube.h"
#include "Key.h"
#include "Buzzer.h"

unsigned char KeyNum;
void main()
{
	NixieTube(1, 0);
	while(1)
	{
		KeyNum = KeyNumber();
		if(KeyNum)
		{
			
			NixieTube(1, KeyNum);
			Buzzer(100);
			
		}
		
	}
}