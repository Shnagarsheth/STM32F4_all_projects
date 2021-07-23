#include "SH_LCD.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>


#define RS_Port GPIOB
#define RS_Pin GPIO_PIN_11
#define RWB_Port GPIOB
#define RWB_Pin GPIO_PIN_10
#define EN_Port GPIOB
#define EN_Pin GPIO_PIN_2
#define DATA_Port GPIOE
#define DATA_Pin GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
#define DATA_Pin_0 GPIO_PIN_0

#define LCD_2LN5X7MATRIX      0x38
#define LCD_CLEARDISPLAY      0x01
#define LCD_INCREMENTCUS      0x06
#define LCD_DIS_ON_CSBLK      0x0E
#define LCD_CSFIRSTLINE		    0x80
#define LCD_CSSECONDLINE	    0xC0


void command(uint8_t temp)
{
	ready();
	DATA_Port->ODR&=~((uint32_t)DATA_Pin);
	DATA_Port->ODR|=temp<<(DATA_Pin_0-1);
	RS_Port->BSRR=(uint16_t)RS_Pin << 16U;
	delay();
	RWB_Port->BSRR=(uint16_t)RWB_Pin << 16U;
	delay();
	EN_Port->BSRR=(uint16_t)EN_Pin;
	delay();
	EN_Port->BSRR=(uint16_t)EN_Pin << 16U;
}

void display(uint8_t temp)
{
	ready();
	DATA_Port->ODR&=~((uint32_t)DATA_Pin);
	DATA_Port->ODR|=temp<<(DATA_Pin_0-1);
	RS_Port->BSRR=(uint16_t)RS_Pin;
	delay();
	RWB_Port->BSRR=(uint16_t)RWB_Pin << 16U;
	delay();
	EN_Port->BSRR=(uint16_t)EN_Pin;
	delay();
	EN_Port->BSRR=(uint16_t)EN_Pin << 16U;
}

void ready(void)
{
	uint8_t i;
	for(i=0;i<=50;i++)
		delay();
}

void delay(void)
{
	uint16_t x;
	for(x=0;x<=1000;x++);
}


void setCursor(uint8_t row, uint8_t col)
{
	uint8_t maskData;
  	maskData = (col)&0x0F;
	if(row==1)
  	{
    	maskData |= (0x80);
    	command(maskData);
  	}
  else
  	{
    	maskData |= (0xC0);
    	command(maskData);
  	}
}

void clear(void)
{
	command(LCD_CLEARDISPLAY);
	delay();	
}


void initialize_LCD(void)
{
	EN_Port->BSRR=(uint16_t)EN_Pin << 16U;

 	for(uint8_t ii=0;ii<=200;ii++)
  	delay();

  	command(LCD_2LN5X7MATRIX);
  	command(LCD_CLEARDISPLAY);
  	command(LCD_INCREMENTCUS);
  	command(LCD_DIS_ON_CSBLK);
}

void LCD_firstline(void)
{
	command(LCD_CSFIRSTLINE);
}

void LCD_secondline(void)
{
	command(LCD_CSSECONDLINE);
}

void LCD_print(char string[])
{
	for(uint8_t i=0; i<strlen(string); i++)
		{
		display((uint8_t)string[i]);
		}
}

void LCD_float(double num, uint8_t d_p)
{
	uint8_t c=1, i=0, f=0;	
	uint32_t dv[10];
	uint32_t intpart;
	float fracpart;
	
	intpart = (uint32_t)num;
	fracpart = (float) (num-intpart);
	while(intpart!=0)
		{
			  dv[c]=(((uint32_t)(intpart))%10);
				intpart/=10;
			  c++;
		}
		f=c;
	//while(fracpart!=0)
	for (i=c;i<=(c+d_p);i++)
		{
			fracpart*=10;			 
			dv[i]=(((uint32_t)(fracpart))%10);
			f++;
		}
	for(i=c-1; i>0; i--)
		{
			display(dv[i]+0x30);
		}
		if(d_p!=0)
		{
			display('.');
		}
	for(i=c; i<f-1; i++)
		{
			display(dv[i]+0x30);
		}
}

void LCD_int(uint32_t num)
{
	uint8_t c=1, i=0;	
	uint32_t dv[10];
	while(num!=0)
		{
			  dv[c]=(uint8_t)(((uint32_t)(num))%10);
				num/=10;
			  c++;
		}
		for(i=c-1; i>0; i--)
		{
			display(dv[i]+0x30);
		}		
}
