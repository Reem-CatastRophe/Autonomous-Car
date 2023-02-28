/*
 * DIO.h
 *
 *  Created on: Jan 28, 2023
 *      Author: omarM
 */

#ifndef MCAL_DIO_H_
#define MCAL_DIO_H_

#define GA 0
#define GB 1
#define GC 2
#define GD 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define Input 0
#define Output 1

#define Disable 0
#define Enable 1

#define Low 0
#define High 1

#include"../LIB/BitMath.h"
#include"../LIB/MemoMap.h"
#include"../LIB/TypeDef.h"


void DioSetPinDir(U8,U8,U8);
void DioSetPinVal(U8,U8,U8);
void DioSetPinPullUpRes(U8,U8,U8);
U8 DioGetPinVal(U8,U8);

void DioSetPortDir(U8,U8);
void DioSetPortVal(U8,U8);
U8 DioGetPortVal(U8);

#endif /* MCAL_DIO_H_ */
