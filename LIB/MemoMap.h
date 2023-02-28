/*
 * MEMOMAP.h
 *
 *  Created on: Jan 28, 2023
 *      Author: omarM
 */

#ifndef LIB_MEMOMAP_H_
#define LIB_MEMOMAP_H_


#define DDRA *(volatile U8*) 0x3A
#define DDRB *(volatile U8*) 0x37
#define DDRC *(volatile U8*) 0x34
#define DDRD *(volatile U8*) 0x31


#define PORTA *(volatile U8*) 0x3B
#define PORTB *(volatile U8*) 0x38
#define PORTC *(volatile U8*) 0x35
#define PORTD *(volatile U8*) 0x32


#define PINA *(volatile U8*) 0x39
#define PINB *(volatile U8*) 0x36
#define PINC *(volatile U8*) 0x33
#define PIND *(volatile U8*) 0x30

#define UCSRA * (volatile U8*) 0x2B
#define UCSRB * (volatile U8*) 0x2A
#define UDR   * (volatile U8*) 0x2C
#define UBRRL * (volatile U8*) 0x29
#define UCSRC * (volatile U8*) 0x40


#define SPDR * (volatile U8*) 0x2F
#define SPSR * (volatile U8*) 0x2E
#define SPCR * (volatile U8*) 0x2D

#define TWSR * (volatile U8*) 0x21
#define TWDR * (volatile U8*) 0x23
#define TWAR * (volatile U8*) 0x22
#define TWBR * (volatile U8*) 0x20

#define SREG  *(volatile U8*) 0x5F
#define GICR  *(volatile U8*) 0x5B
#define MCUCR *(volatile U8*) 0x55

#define ADMUX   *(volatile U8*)  0x27
#define ADCSRA  *(volatile U8*)  0x26
#define ADCH    *(volatile U8*)  0x25
#define ADCL    *(volatile U8*)  0x24
#define ADCVal  *(volatile U16*) 0x24

#define TCCR0  *(volatile U8*)  0x53
#define TCCR1H *(volatile U8*)  0x4D
#define TCCR1L *(volatile U8*)  0x4C
#define TCCR1A *(volatile U8*)  0x4F
#define TCCR1B *(volatile U8*)  0x4E
#define TCCR2  *(volatile U8*)  0x45
#define TCNT0  *(volatile U8*)  0x52
#define TCNT2  *(volatile U8*)  0x44
#define OCR0   *(volatile U8*)  0x5C
#define OCR2   *(volatile U8*)  0x43
#define OCR1A  *(volatile U16*)  0x4A
#define ICR1   *(volatile U16*)  0x46
#define TIMSK  *(volatile U8*)  0x59




#include"TypeDef.h"

#endif /* LIB_MEMOMAP_H_ */
