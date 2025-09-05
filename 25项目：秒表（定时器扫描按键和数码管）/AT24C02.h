#ifndef __AT24C02__H__
#define __AT24C02__H__

void AT24C02_SendByte(unsigned char WordAdd, unsigned char Data);
unsigned char AT24C02_ReceiveByte(unsigned char WordAdd);


#endif