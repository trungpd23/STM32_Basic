#ifndef LCD_H_
#define LCD_H_

#include <stdint.h>
#include "stm32f1xx_hal.h"

#define MCMD 0x00
#define MDATA 0x01

//RS, RW, E -> PORT_CF
//D0-D7 -> PORT_DATA
typedef struct {
	GPIO_TypeDef *PORT_CF;
	GPIO_TypeDef *PORT_DATA;
	uint16_t D0, D1, D2, D3, D4, D5, D6, D7;
	uint16_t RS, RW, E;
} LCD;

extern LCD myLCD;

void LCD_Init();
void LCD_Write_Byte(uint8_t data, uint8_t mode);
void LCD_Write_Data(uint8_t data);
void LCD_Write_Cmd(uint8_t cmd);
void LCD_Print(char *str);

#endif