/*
 * INT.h
 *
 *  Created on: Feb 12, 2023
 *      Author: omarM
 */

#ifndef MCAL_INT_H_
#define MCAL_INT_H_


#define INT0ControlMode RisingEdge
#define INT1ControlMode RisingEdge

#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define GIE 7

#define INT0 6
#define INT1 5
#define INT2 7


#define FallingEdge 0
#define RisingEdge 1
#define LowLevel 2
#define LogicalChange 3

#define INT0Channel 0
#define INT1Channel 1
#define INT2Channel 2

#include"../LIB/BitMath.h"
#include"../LIB/MemoMap.h"
#include"../LIB/TypeDef.h"
#include<avr/interrupt.h>

void IntInit(U8);
void SetCallBack(void(*)(void),U8);
void GlobalInterruptEnable();
void GlobalInterruptDisable();
#endif /* MCAL_INT_H_ */
