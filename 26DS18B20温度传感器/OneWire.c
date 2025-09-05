#include <REGX52.H>

sbit OneWire_DQ = P3^7;

unsigned char OneWire_Init(void)
{
	unsigned char i;
	unsigned char AckBit;
	
	OneWire_DQ = 1;//将通信线初始化置1
	
	OneWire_DQ = 0;//主机拉低：要求从机通信
	i = 247;while (--i);//延时500微秒
	
	OneWire_DQ = 1;//主机释放通信线
	i = 29;	while (--i);//延时70微秒
	
	AckBit = OneWire_DQ;//主机接收从机返回值
	i = 247;while (--i);//延时500微秒
	
	return AckBit;
}

void OneWire_SendBit(unsigned char Bit)
{
	unsigned char i;
	OneWire_DQ = 1;//将通信线初始化置1
	
	OneWire_DQ = 0;
	i = 4;while (--i);//延时15微秒
	OneWire_DQ = Bit;//主机拉低/主机拉高
	
	i = 25;	while (--i);//延时60微秒
	OneWire_DQ = 1;
	
	
}

unsigned char OneWire_ReceiveBit()
{
	unsigned char i;
	unsigned char Bit;
	
	OneWire_DQ = 1;//将通信线初始化置1
	
	OneWire_DQ = 0;
	i = 1;while (--i);//延时5微秒
	
	OneWire_DQ = 1;//主机释放通信线
	i = 1;while (--i);//延时5微秒
	
	Bit = OneWire_DQ;
	i = 29;	while (--i);//延时70微秒
	
	return Bit;
}

void OneWire_SendByte(unsigned char Byte)
{
	unsigned char i;
	
	for(i = 0; i <= 7; i++)
	{
		OneWire_SendBit(Byte & (0x01 << i));
	}
}

unsigned char OneWire_ReceiveByte(void)
{
	unsigned char Byte = 0x00;
	unsigned char Temp;
	unsigned char i;
	
	Temp = OneWire_ReceiveBit();
	for(i = 0; i <= 7; i++)
	{
		if(Temp)
		{
			Byte = Byte | (Temp << i);
		}
	}
	
	return Byte;
}