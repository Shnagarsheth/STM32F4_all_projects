#include "stm32f4xx_hal.h"
#include <stdbool.h>
#include <string.h>


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

