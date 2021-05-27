/*
Written by: Shaival Nagarsheth

Description: This is a header file LCD 16x2 through STM32 MCUs based on HAL libraries. 
              It provides 12 different LCD write functions
              (Read operations are omitted, beacuse generally do not require a read function with LCD)

References: (1) https://www.elprocus.com/lcd-16x2-pin-configuration-and-its-working/
			(2) Youtube Channel by "Mohammad Yaqoob" for some great start on STM32. 
*/

#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include <string.h>
#include "main.h"

#ifdef LCD_H_
    void command(uint8_t temp);
    void ready(void);
    void display(uint8_t temp);
    void delay(void);
    void setCursor(uint8_t row, uint8_t col);
    void clear(void);
    void initialize_LCD(void);
    void LCD_firstline(void);
    void LCD_secondline(void);
    void LCD_print(char string[]);
    void LCD_float(double num, uint8_t d_p);
    void LCD_int(uint32_t num);
#else
    extern void command(uint8_t temp);
    extern void ready(void);
    extern void display(uint8_t temp);
    extern void delay(void);
    extern void setCursor(uint8_t row, uint8_t col);
    extern void clear(void);
    extern void initialize_LCD(void);
    extern void LCD_firstline(void);
    extern void LCD_secondline(void);
    extern void LCD_print(char string[]);
    extern void LCD_float(double num, uint8_t d_p);
    extern void LCD_int(uint32_t num);
#endif