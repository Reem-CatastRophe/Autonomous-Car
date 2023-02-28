/*
 * LCD.h
 *
 *  Created on: Jan 29, 2023
 *      Author: rerom
 */

#ifndef HAL_LCD_H_
#define HAL_LCD_H_

#include "../MCAL/DIO.h"

#define RS PIN1
#define RW PIN2
#define EN PIN3

#define LcdCmdPort GB
#define LcdDataPort GA

void LcdTrigger();
void LcdWriteCmd(U8);
void LcdInit();
void LcdWriteData(U8);
void LcdWriteString(U8*);
void LcdWriteNum(U32);
//void LcdClr();






#endif /* HAL_LCD_H_ */
