#ifndef __I2C__H__
#define __I2C__H__

void I2C_Start(void);
void I2C_Stop(void);
void SendByte(unsigned char Data);
unsigned char ReceiveByte(void);
void SendAck(unsigned char SDA_Bit);
unsigned char ReceiveAck(void);

#endif