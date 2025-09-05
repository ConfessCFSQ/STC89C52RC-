#include <REGX52.H>
#include "MatrixKey.h"
#include "LCD1602.h"
#include "Delay.h"

unsigned char KeyNum;//接收按键参数
unsigned int PassWord;//密码参数
unsigned int count;//按键次数参数
unsigned int Bang;//锁定次数参数

void main()
{
	LCD_Init();//初始化LCD1602
	LCD_ShowString(1, 1, "Password:");//LCD默认展示
	LCD_ShowString(2, 1, "Status:");//LCD默认展示
	count = 0;//设置按键次数默认值
	Bang = 0;//设置锁定次数默认值
	
	while(1)
	{
		KeyNum = MatrixKey();//接收扫描矩阵按键的函数返回值
		
		if(KeyNum)//如果按键有值进入
		{
			if(KeyNum <= 11)//设置按键在S1-S12
			{
				if(KeyNum <= 10)//设置数字键在S1-S10
				{
					if(count < 4)//设置按键次数小于4次
					{
						PassWord = PassWord * 10;//未定义的Password左移一位
						PassWord = PassWord + (KeyNum % 10);//将密码数字加在PassWord后面（KeyNum%10可以将S10变为0）
						if(count == 3)//按键次数为3次时,直接判断密码正误
						{
							if(PassWord == 1234)//密码输入正确
							{
								LCD_ShowString(2, 8, "OK!");//LCD显示OK！
								Bang = 0;//锁定清零
							}
							else//密码输入错误
							{
								LCD_ShowString(2, 8, "NO!");//LCD显示NO！
								Bang++;//锁定次数加1
							}
						}
						count++;//按键次数加1
					}
					
				}
				else if(KeyNum == 11)//设置清零键在S11
				{
					PassWord = 0;//清零后密码重置为0
					count = 0;//清零后按键次数重置为0
					LCD_ShowString(2, 8, "                 ");//LCD显示重置
				}
				LCD_ShowNum(1, 10, PassWord, 4);//展示输入的密码
			}
			
		}
		if(Bang >= 3)//如果错误次数大于3次,锁定屏幕进入无限循环
		{
			while(1)
			{
				LCD_ShowString(1, 1, "BANG BANGBANG!!!");
				LCD_ShowString(2, 1, "BANG BANGBANG!!!");
				Delay(1000);
				LCD_ShowString(1, 1, "                ");
				LCD_ShowString(2, 1, "                ");
				Delay(1000);
			}
		}
	}
}