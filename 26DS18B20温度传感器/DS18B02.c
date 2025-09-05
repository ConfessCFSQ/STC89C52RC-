#include "OneWire.h"

void DS18B02_ConvertT(void)
{
	unsigned char Ask;
	Ask = OneWire_Init();//初始化单总线
	OneWire_SendByte(0xCC);//发送跳过ROM指令
	OneWire_SendByte(0x44);//发送开始温度变换指令
}

float DS18B02_ReadRegister(void)
{
	unsigned char Ask;
	unsigned char TLSB, TMSB;
	int Temp;
	float T;
	
	Ask = OneWire_Init();//初始化单总线
	OneWire_SendByte(0xCC);//发送跳过ROM指令
	OneWire_SendByte(0xBE);//发送开始温度变换指令
	TLSB = OneWire_ReceiveByte();//接收温度的低八位
	TMSB = OneWire_ReceiveByte();//接收温度的高八位
	Temp = (TMSB << 8) | TLSB;//将高八位和低八位合并
	T = Temp / 16.0;//将补码转换为原码，并保留小数部分
	
	return T;
}