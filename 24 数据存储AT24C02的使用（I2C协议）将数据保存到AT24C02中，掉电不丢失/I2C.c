#include <REGX52.H>

sbit I2C_SCL = P2^1;
sbit I2C_SDA = P2^0;

void I2C_Start(void)
{
	I2C_SCL = 1;
	I2C_SDA = 1;
	
	I2C_SDA = 0;
	I2C_SCL = 0;
}

void I2C_Stop(void)
{
	I2C_SDA = 0;
	
	I2C_SCL = 1;
	I2C_SDA = 1;
}

void SendByte(unsigned char Data)
{
	unsigned char i;
	//I2C_SCL = 0;
	
	for(i = 0; i <= 7; i++)
	{
		I2C_SDA = Data & (0x80 >> i);
		I2C_SCL = 1;
		//Delay();
		I2C_SCL = 0;
	}
}

unsigned char ReceiveByte(void)
{
	unsigned char Data = 0x00;
	unsigned char i;
	//I2C_SCL = 0;
	I2C_SDA = 1;//主机释放SDA
	
	for(i = 0; i <= 7; i++)
	{
		I2C_SCL = 1;
		
		if(I2C_SDA)
		{
			Data = Data | (0x80 >> i);
		}
		I2C_SCL = 0;
	}
	return Data;
}

void SendAck(unsigned char SDA_Bit) 
{
	
	//I2C_SCL = 0;
	
	I2C_SDA = SDA_Bit;
	I2C_SCL = 1;
	I2C_SCL = 0;
}

unsigned char ReceiveAck(void)
{
	unsigned char SDA_Bit;
	//I2C_SCL = 0;
	I2C_SDA = 1;//主机释放SDA
	
	I2C_SCL = 1;
	SDA_Bit = I2C_SDA;
	I2C_SCL = 0;
	
	return SDA_Bit;
}