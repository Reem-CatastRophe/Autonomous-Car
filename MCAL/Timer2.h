/*
 * Timer2.h
 *
 *  Created on: Mar 9, 2023
 *      Author: rerom
 */

#ifndef MCAL_TIMER2_H_
#define MCAL_TIMER2_H_


#include"../LIB/BitMath.h"
#include"../LIB/MemoMap.h"
#include"../LIB/TypeDef.h"
#include"./DIO.h"
#include <avr/io.h>
#include <avr/interrupt.h>
void Timer2Init();
void Timer2Stop();




#endif /* MCAL_TIMER2_H_ */
