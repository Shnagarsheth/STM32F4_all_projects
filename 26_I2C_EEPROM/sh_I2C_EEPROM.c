/*
Written by: Shaival Nagarsheth

Description: This is a header file for I2C Communication with ST M24C16-RP (EEPROM) through 
STM32 MCUs based on HAL libraries. It provides 4 specific functions for byte by byte write/read 
and page by page write/read.

References: (1) https://www.st.com/resource/en/datasheet/m24c16-f.pdf
			(2) https://www.jameco.com/Jameco/Products/ProdDS/697901-DS01.pdf  (detailed datasheet)
			(3) Youtube Channel by "Mohammad Yaqoob" for some greater start on STM32. 
*/

#include "main.h"
#include "sh_I2C_EEPROM.h"

extern I2C_HandleTypeDef hi2c1;

void I2C_EEPROM_READY(uint8_t eeprom_dev_address)
{
	while(HAL_I2C_IsDeviceReady(&hi2c1, eeprom_dev_address, 5, 10) != HAL_OK);
}


void EEPROM_BYTE_WRITE(uint8_t eeprom_dev_add_wr, uint8_t emem_add, uint8_t Txbuf[], uint16_t Nbytes)
{
	uint16_t e=0; 
	uint8_t a=0;

	while(Nbytes !=0)
	{
		if(a==255)
		{
			a=0;
			eeprom_dev_add_wr+=0x02;
		}
		if (HAL_I2C_IsDeviceReady(&hi2c1, eeprom_dev_add_wr, 5, 10) == HAL_OK)
		{
			if(HAL_I2C_Mem_Write(&hi2c1,eeprom_dev_add_wr,emem_add,I2C_MEMADD_SIZE_8BIT,&Txbuf[e],1,100)!=HAL_OK)
			{
				Error_Handler();
			}		
			emem_add++;
			e++;
			a++;
			Nbytes--;
		}	
		else
		{
			Error_Handler();
		}
	}
}

void EEPROM_BYTE_READ(uint8_t eeprom_dev_add_wr, uint8_t emem_add, uint8_t Rxbuf[], uint16_t Nbytes)
{
	uint8_t a=0;
	uint16_t e=0; 
	while(Nbytes !=0)
	{
	if(a==255)
		{
			a=0;
			eeprom_dev_add_wr+=0x02;
		}
		if (HAL_I2C_IsDeviceReady(&hi2c1, eeprom_dev_add_wr, 5, 10) == HAL_OK)
		{
		
			if(HAL_I2C_Mem_Read(&hi2c1,eeprom_dev_add_wr,emem_add,I2C_MEMADD_SIZE_8BIT,&Rxbuf[e],1,100)!=HAL_OK)
			{
				Error_Handler();
			}		
			emem_add++;
			e++;
			a++;
			Nbytes--;
		}
		else
		{
			Error_Handler();
		}		
	}
}	

void EEPROM_PAGE_WRITE(uint8_t eeprom_dev_add_wr, uint8_t emem_add, uint8_t Txbuf[], uint8_t Npages)
{
	uint8_t a=0;
	uint16_t e=0; 

	while(Npages !=0)
	{
	if(a==16)
		{
			a=0;
			eeprom_dev_add_wr+=0x02;
		}
		if (HAL_I2C_IsDeviceReady(&hi2c1, eeprom_dev_add_wr, 5, 10) == HAL_OK)
		{
			if(HAL_I2C_Mem_Write(&hi2c1,eeprom_dev_add_wr,emem_add,I2C_MEMADD_SIZE_8BIT,&Txbuf[e],16,100)!=HAL_OK)
			{
				Error_Handler();
			}		
			emem_add+=16;
			e+=16;
			a++;
			Npages--;
		}
		else
		{
			Error_Handler();
		}		
	}
}	
	
void EEPROM_PAGE_READ(uint8_t eeprom_dev_add_wr, uint8_t emem_add, uint8_t Txbuf[], uint8_t Npages)
{
	uint8_t  a=0;
	uint16_t e=0; 

	while(Npages !=0)
	{
	if(a==16)
		{
			a=0;
			eeprom_dev_add_wr+=0x02;
		}
		if (HAL_I2C_IsDeviceReady(&hi2c1, eeprom_dev_add_wr, 5, 10) == HAL_OK)
		{
			if(HAL_I2C_Mem_Read(&hi2c1,eeprom_dev_add_wr,emem_add,I2C_MEMADD_SIZE_8BIT,&Txbuf[e],16,100)!=HAL_OK)
			{
				Error_Handler();
			}		
			emem_add+=16;
			e+=16;
			a++;
			Npages--;
		}
		else
		{
			Error_Handler();
		}		
	}
}	