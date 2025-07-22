#include "lcd.h"

LCD myLCD;

void LCD_Write_Byte(uint8_t data, uint8_t mode) {
	if(mode == MCMD) {
		HAL_GPIO_WritePin(myLCD.PORT_CF, myLCD.RS, 0); //RS = 0
	}
	else if(mode == MDATA) {
		HAL_GPIO_WritePin(myLCD.PORT_CF, myLCD.RS, 1); //RS = 1
	}
	
	HAL_GPIO_WritePin(myLCD.PORT_DATA, myLCD.D0, (data & 0x01) ? 1 : 0);
	HAL_GPIO_WritePin(myLCD.PORT_DATA, myLCD.D1, (data & 0x02) ? 1 : 0);
	HAL_GPIO_WritePin(myLCD.PORT_DATA, myLCD.D2, (data & 0x04) ? 1 : 0);
	HAL_GPIO_WritePin(myLCD.PORT_DATA, myLCD.D3, (data & 0x08) ? 1 : 0);
	HAL_GPIO_WritePin(myLCD.PORT_DATA, myLCD.D4, (data & 0x10) ? 1 : 0);
	HAL_GPIO_WritePin(myLCD.PORT_DATA, myLCD.D5, (data & 0x20) ? 1 : 0);
	HAL_GPIO_WritePin(myLCD.PORT_DATA, myLCD.D6, (data & 0x40) ? 1 : 0);
	HAL_GPIO_WritePin(myLCD.PORT_DATA, myLCD.D7, (data & 0x80) ? 1 : 0);
	
	HAL_GPIO_WritePin(myLCD.PORT_CF, myLCD.E, 0);
	HAL_Delay(1);
	HAL_GPIO_WritePin(myLCD.PORT_CF, myLCD.E, 1);
	HAL_Delay(1);
	HAL_GPIO_WritePin(myLCD.PORT_CF, myLCD.E, 0);
	HAL_Delay(1);
}


void LCD_Write_Data(uint8_t data) {
	LCD_Write_Byte(data, MDATA);
}
void LCD_Write_Cmd(uint8_t cmd) {
	LCD_Write_Byte(cmd, MCMD);
}

void LCD_Init() {
	HAL_GPIO_WritePin(myLCD.PORT_CF, myLCD.RW, 0);
	HAL_Delay(50);
	LCD_Write_Cmd(0x38);
	HAL_Delay(5);
	LCD_Write_Cmd(0x0C);
	HAL_Delay(5);
	LCD_Write_Cmd(0x06);
	HAL_Delay(5);
	LCD_Write_Cmd(0x01);
	HAL_Delay(5);
}

void LCD_Print(char *str) {
	while(*str) {
		LCD_Write_Data(*str++);
	}
}
