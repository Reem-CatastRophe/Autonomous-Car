/*
 * Timer2.c
 *
 *  Created on: Mar 9, 2023
 *      Author: men3em
 */
#include"Timer2.h"

volatile U32 OverflowNum=0;

void Timer2Init()
{
	TCNT2 = 0;

	ClrBit(TCCR2,WGM20);
	ClrBit(TCCR2,WGM21);
//	SetBit(TCCR2,FOC2);

	// set up timer with prescaler = 256
	TCCR2 |= (1 << CS22)|(1 << CS21);

	// initialize counter

	// enable overflow interrupt
	TIMSK |= (1 << TOIE2);

	// enable global interrupts
	sei();

}

void Timer2Stop(){
	ClrBit(TCCR2,CS20);
	ClrBit(TCCR2,CS21);
	ClrBit(TCCR2,CS22);
}

ISR(TIMER2_OVF_vect){

	OverflowNum++;

}

