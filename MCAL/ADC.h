/*
 * ADC.h
 *
 *  Created on: Feb 12, 2023
 *      Author: omarM
 */

#ifndef MCAL_ADC_H_
#define MCAL_ADC_H_

#define ADCChannel0					0
#define ADCChannel1					1
#define ADCChannel2					2
#define ADCChannel3					3
#define ADCChannel4					4
#define ADCChannel5					5
#define ADCChannel6					6
#define ADCChannel7					7

// ADMUX Bits
#define REFS1	7
#define REFS0	6
#define ADLAR	5
#define MUX4	4
#define MUX3	3
#define MUX2	2
#define MUX1	1
#define MUX0	0

#define ADMUXMask	0xE0


//ADCSRA Bits
#define ADEN		7
#define ADSC		6
#define ADATE		5
#define ADIF		4

#define ADSP2		2
#define ADSP1		1
#define ADSP0		0

#define ADCVREF AVCC
#define ADCPrescalerDiv	128 // 128 or 64
#define ADCConvFinished		1

#define AVCC			0
#define AREF		    1
#define _2V56			2

#include"../LIB/BitMath.h"
#include"../LIB/MemoMap.h"
#include"../LIB/TypeDef.h"

void ADCInit();
U16 ADCRead(U8);

#endif /* MCAL_ADC_H_ */
