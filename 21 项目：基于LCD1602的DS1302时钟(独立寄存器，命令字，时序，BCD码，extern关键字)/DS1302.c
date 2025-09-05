#include <REGX52.H>

sbit DS1302_SCLK = P3^6;
sbit DS1302_IO = P3^4;
sbit DS1302_CE = P3^5;

#define DS1302_SECOND	0x80
#define DS1302_MINUTE	0x82
#define DS1302_HOUR		0x84
#define DS1302_DATE		0x86
#define DS1302_MONTH	0x88
#define DS1302_DAY		0x8A
#define DS1302_YEAR		0x8C
#define DS1302_WP		0x8E

unsigned char DS1302_Time[] = {25, 9, 1, 2, 59, 55, 1};

void DS1302_Init(void)
{
	DS1302_CE = 0;
	DS1302_SCLK = 0;
}

unsigned char DS1302_ReadByte(unsigned char Byte)
{
	unsigned char i, Data = 0x00;
	Byte |= 0x01;
	DS1302_CE = 1;
	
	
	for(i = 0; i <= 7; i++)
	{
		DS1302_IO = Byte & (0x01 << i);
		DS1302_SCLK = 0;
	//	Delay();
		DS1302_SCLK = 1;
	}
	
	for(i = 0; i <= 7; i++)
	{
		DS1302_SCLK = 1;
//		Delay();
		DS1302_SCLK = 0;
		if(DS1302_IO){Data = Data | (0x01 << i);}
	}
	//Data = (Data / 16 * 10) + (Data % 16);
	
	DS1302_CE = 0;
	DS1302_IO = 0;
	return Data;
}

void DS1302_WriteByte(unsigned char Byte, unsigned char Data)
{
	
	unsigned char i;
	DS1302_CE = 1;
	
	
	for(i = 0; i <= 7; i++)
	{
		DS1302_IO = Byte & (0x01 << i);
		DS1302_SCLK = 1;
//		Delay();
		DS1302_SCLK = 0;
	}
	
	
	for(i = 0; i <= 7; i++)
	{
		DS1302_IO = Data & (0x01 << i);
		DS1302_SCLK = 1;
//		Delay();
		DS1302_SCLK = 0;
	}
	
	DS1302_CE = 0;
}

void DS1302_SetTime(void)
{
	DS1302_WriteByte(DS1302_WP, 0x00);//关闭写入保护
	DS1302_WriteByte(DS1302_YEAR, DS1302_Time[0] / 10 * 16 + DS1302_Time[0] % 10);//写入年
	DS1302_WriteByte(DS1302_MONTH, DS1302_Time[1] / 10 * 16 + DS1302_Time[1] % 10);//写入月
	DS1302_WriteByte(DS1302_DATE, DS1302_Time[2] / 10 * 16 + DS1302_Time[2] % 10);//写入日
	DS1302_WriteByte(DS1302_HOUR, DS1302_Time[3] / 10 * 16 + DS1302_Time[3] % 10);//写入时
	DS1302_WriteByte(DS1302_MINUTE, DS1302_Time[4] / 10 * 16 + DS1302_Time[4] % 10);//写入分
	DS1302_WriteByte(DS1302_SECOND, DS1302_Time[5] / 10 * 16 + DS1302_Time[5] % 10);//写入秒
	DS1302_WriteByte(DS1302_DAY, DS1302_Time[6] / 10 * 16 + DS1302_Time[6] % 10);//写入星期
	DS1302_WriteByte(DS1302_WP, 0x80);//打开写入保护
}


void DS1302_ReadTime(void)
{
	unsigned char Temp;
	Temp = DS1302_ReadByte(DS1302_YEAR);//读取年
	DS1302_Time[0] = Temp / 16 * 10 + Temp % 16;//设置数组
	
	Temp = DS1302_ReadByte(DS1302_MONTH);//读取月
	DS1302_Time[1] = Temp / 16 * 10 + Temp % 16;
	
	Temp = DS1302_ReadByte(DS1302_DATE);//读取日
	DS1302_Time[2] = Temp / 16 * 10 + Temp % 16;
	
	Temp = DS1302_ReadByte(DS1302_HOUR);//读取时
	DS1302_Time[3] = Temp / 16 * 10 + Temp % 16;
	
	Temp = DS1302_ReadByte(DS1302_MINUTE);//读取分
	DS1302_Time[4] = Temp / 16 * 10 + Temp % 16;
	
	Temp = DS1302_ReadByte(DS1302_SECOND);//读取秒
	DS1302_Time[5] = Temp / 16 * 10 + Temp % 16;
	
	Temp = DS1302_ReadByte(DS1302_DAY);//读取星期
	DS1302_Time[6] = Temp / 16 * 10 + Temp % 16;
	
}
	