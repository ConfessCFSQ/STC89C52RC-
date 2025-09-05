#ifndef __DS1302__H__
#define __DS1302__H__

extern unsigned char DS1302_Time[];

void DS1302_Init(void);
unsigned char DS1302_ReadByte(unsigned char Byte);
void DS1302_WriteByte(unsigned char Byte, unsigned char Data);
void DS1302_SetTime(void);
void DS1302_ReadTime(void);

#endif