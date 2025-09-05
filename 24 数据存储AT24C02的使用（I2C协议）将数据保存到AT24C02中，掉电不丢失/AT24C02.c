#include <REGX52.H>
#include "I2C.h"

void AT24C02_SendByte(unsigned char WordAdd, unsigned char Data)
{
	unsigned char Ack;
	
	I2C_Start();//开始条件
	SendByte(0xA0);//发送从机地址1010 XXX(000)和写操作
	Ack = ReceiveAck();//接收应答
	//if(Ack){};//非应答操作
	SendByte(WordAdd);//发送要写入字节的地址
	Ack = ReceiveAck();//接收应答
	//if(Ack){};//非应答操作
	SendByte(Data);//发送要写入的数据
	Ack = ReceiveAck();//接收应答
	//if(Ack){};//非应答操作
	I2C_Stop();//停止条件
}

unsigned char AT24C02_ReceiveByte(unsigned char WordAdd)
{
	unsigned char Ack;
	unsigned char Data;
	
	I2C_Start();//开始条件
	SendByte(0xA0);//发送从机地址1010 XXX(000)和写操作
	Ack = ReceiveAck();//接收应答
	//if(Ack){};//非应答操作
	SendByte(WordAdd);//发送要接收字节的地址
	Ack = ReceiveAck();//接收应答
	//if(Ack){};//非应答操作
	
	I2C_Start();//开始条件
	SendByte(0xA1);//发送从机地址1010 XXX(000)和读操作
	Ack = ReceiveAck();//接收应答
	//if(Ack){};//非应答操作
	Data = ReceiveByte();//变量接收数据
	SendAck(1);//发送非应答
	I2C_Stop();//停止条件
	
	return Data;
}