/*
 * Timer.h
 *
 *  Created on: Feb 15, 2023
 *      Author: omarM
 */

#ifndef MCAL_TIMER_H_
#define MCAL_TIMER_H_

#include"../LIB/BitMath.h"
#include"../LIB/MemoMap.h"
#include"../LIB/TypeDef.h"
#include"./DIO.h"

#define WGM00 6
#define WGM01 3
#define COM00 4
#define COM01 5

#define CS00 0
#define CS01 1
#define CS02 2

#define TOIE0 0
#define OCIE0 1

#define TOIE2 6
#define OCIE2 7

#define WGM11  1
#define WGM10  0
#define COM1A0 6
#define COM1A1 7

#define WGM13 4
#define WGM12 3
#define CS10 0
#define CS11 1
#define CS12 2

#define WGM20 6
#define WGM21 3
#define CS20 0
#define CS21 1
#define CS22 2
#define COM20 4
#define COM21 5


#define OC0   PIN3
#define OCR1APin PIN5

#define NormalMode 0
#define CTCMode 1
#define FastPWMMode 2
#define PhaseCorrectPWMMode 4

#define Inverted 0
#define NonInverted 1

#define Timer0Mode FastPWMMode
#define Timer0PWMMode NonInverted
#define Timer0PrescalerValue 64

#define Timer1Mode FastPWMMode
#define Timer1PWMMode NonInverted
#define Timer1PrescalerValue 64

#define Timer2Mode NormalMode
#define Timer2PWMMode NonInverted
#define Timer2PrescalerValue 256
#define FOSC 16 // in MHz

#define Timer0Channel 0
#define Timer1Channel 1
#define Timer2Channel 2

void TimerInit();
void TimerSetTime(U32);
void TimerStart(U8);
void TimerStop(U8);
U32  TimerGetTime();

void PWMInit(U8);
void PWMSetDutyCycle(U8,U8);
void PWMStart(U8);
void PWMStop(U8);

void TimerSetCallBack(void(*)(void));

#endif /* MCAL_TIMER_H_ */
