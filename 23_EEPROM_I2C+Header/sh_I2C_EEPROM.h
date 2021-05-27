/*
Written by: Shaival Nagarsheth

Description: This is a header file for I2C Communication with ST M24C16-RP (EEPROM) through 
STM32 MCUs based on HAL libraries. It provides 4 specific functions for byte by byte write/read 
and page by page write/read.

References: (1) https://www.st.com/resource/en/datasheet/m24c16-f.pdf
			(2) https://www.jameco.com/Jameco/Products/ProdDS/697901-DS01.pdf  (detailed datasheet)
			(3) Youtube Channel by "Mohammad Yaqoob" for some great start on STM32. 
*/

#include "stm32f4xx_hal.h"
#include "main.h"

/* Device addresses for EEPROM ST M24C16-RP */

/* Device Addresses for Writing */

#define EEPROM_DEV_ADD_WR1 0xA0
#define EEPROM_DEV_ADD_WR2 0xA2
#define EEPROM_DEV_ADD_WR3 0xA4
#define EEPROM_DEV_ADD_WR4 0xA6
#define EEPROM_DEV_ADD_WR5 0xA8
#define EEPROM_DEV_ADD_WR6 0xAA
#define EEPROM_DEV_ADD_WR7 0xAC
#define EEPROM_DEV_ADD_WR8 0xAE

/* Device Addresses for Reading */

#define EEPROM_DEV_ADD_RD1 0xA1
#define EEPROM_DEV_ADD_RD2 0xA3
#define EEPROM_DEV_ADD_RD3 0xA5
#define EEPROM_DEV_ADD_RD4 0xA7
#define EEPROM_DEV_ADD_RD5 0xA9
#define EEPROM_DEV_ADD_RD6 0xAB
#define EEPROM_DEV_ADD_RD7 0xAD
#define EEPROM_DEV_ADD_RD8 0xAF

#ifdef EEPROM_H_
	void I2C_EEPROM_READY(uint8_t eeprom_dev_address);
	void EEPROM_BYTE_WRITE(uint8_t eeprom_dev_add_wr, uint8_t emem_add, uint8_t Txbuf[], uint16_t Nbytes);
	void EEPROM_BYTE_READ(uint8_t eeprom_dev_add_rd, uint8_t emem_add, uint8_t Rxbuf[], uint16_t Nbytes);
	void EEPROM_PAGE_WRITE(uint8_t eeprom_dev_add_wr, uint8_t emem_add, uint8_t Txbuf[], uint8_t Npages);
	void EEPROM_PAGE_READ(uint8_t eeprom_dev_add_rd, uint8_t emem_add, uint8_t Rxbuf[], uint8_t Npages);
#else 
  	extern void I2C_EEPROM_READY(uint8_t eeprom_dev_address);
	extern void EEPROM_BYTE_WRITE(uint8_t eeprom_dev_add_wr, uint8_t emem_add, uint8_t Txbuf[], uint16_t Nbytes);
	extern void EEPROM_BYTE_READ(uint8_t eeprom_dev_add_rd, uint8_t emem_add, uint8_t Rxbuf[], uint16_t Nbytes);
	extern void EEPROM_PAGE_WRITE(uint8_t eeprom_dev_add_wr, uint8_t emem_add, uint8_t Txbuf[], uint8_t Npages);
	extern void EEPROM_PAGE_READ(uint8_t eeprom_dev_add_rd, uint8_t emem_add, uint8_t Rxbuf[], uint8_t Npages);
#endif