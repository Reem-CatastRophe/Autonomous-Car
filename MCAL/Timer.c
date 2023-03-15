/*
 * Timer.c
 *
 *  Created on: Feb 15, 2023
 *      Author: Mn3m
 */

#include"Timer.h"
#include<avr/io.h>

void (*TimerCallBack)(void);

U32 CompareMatchNumber = 0;
U32 OverflowNumber = 0;
U8 RemainderTicks = 0;

void Timer1Init(U8 Mode){

	if(Mode == NormalMode){

		TCCR1A = (1<<FOC1A);
		/* put initial value of timer1 in TCNT1 */
		TCNT1 = 0;

		/* Insert first two bits of Timer1_Mode in first two bits in TCCR1A */
		ClrBit(TCCR1A,WGM10);
		ClrBit(TCCR1A,WGM11);
		/*Insert bit-3 and bit-2 of Timer1_Mode in bit-4 and bit-3 bit in TCCR1B */
		ClrBit(TCCR1B,WGM12);
		ClrBit(TCCR1B,WGM13);

		/*Insert timer1_prescalar value in first three bits of TCCR1A */
		SetBit(TCCR1B,CS10);
		SetBit(TCCR1B,CS11);
		ClrBit(TCCR1B,CS12);

	}
	else if(Mode == FastPWMMode){
		TCNT1 = 0;
		DioSetPinDir(GD,OCR1APin,Output);
		ClrBit(TCCR1A,WGM10);
		SetBit(TCCR1A,WGM11);
		SetBit(TCCR1B,WGM12);
		SetBit(TCCR1B,WGM13);

		ClrBit(TCCR1A,COM1A0);
		SetBit(TCCR1A,COM1A1);

		ICR1 = 4999;
	}
	else{

	}

}

void TimerInit(){

#if Timer0Mode == NormalMode
	ClrBit(TCCR0,WGM00);
	ClrBit(TCCR0,WGM01);
	SetBit(TIMSK,TOIE0);
#elif Timer0Mode == CTCMode
	ClrBit(TCCR0,WGM00);
	SetBit(TCCR0,WGM01);
	SetBit(TIMSK,OCIE0);
#endif

#if Timer2Mode == NormalMode
	ClrBit(TCCR2,WGM20);
	ClrBit(TCCR2,WGM21);
//	SetBit(TIMSK,TOIE2);
#elif Timer2Mode == CTCMode
	ClrBit(TCCR2,WGM20);
	SetBit(TCCR2,WGM21);
	SetBit(TIMSK,OCIE2);
#endif
}

void TimerSetCallBack(void(*FunctionPtr)(void)){
	TimerCallBack = FunctionPtr;
}

void TimerStart(U8 TimerChannel){
	switch(TimerChannel){
	case Timer0Channel:
#if Timer0PrescalerValue == 1024
		SetBit(TCCR0,CS00);
		ClrBit(TCCR0,CS01);
		SetBit(TCCR0,CS02);
#elif Timer0PrescalerValue == 256
		ClrBit(TCCR0,CS00);
		ClrBit(TCCR0,CS01);
		SetBit(TCCR0,CS02);
#elif Timer0PrescalerValue == 64
		SetBit(TCCR0,CS00);
		SetBit(TCCR0,CS01);
		ClrBit(TCCR0,CS02);
#elif Timer0PrescalerValue == 8
		ClrBit(TCCR0,CS00);
		SetBit(TCCR0,CS01);
		ClrBit(TCCR0,CS02);
#elif Timer0PrescalerValue == 1
		SetBit(TCCR0,CS00);
		ClrBit(TCCR0,CS01);
		ClrBit(TCCR0,CS02);
#endif
		break;
	case Timer1Channel:
#if Timer1PrescalerValue == 1024
		SetBit(TCCR1B,CS10);
		ClrBit(TCCR1B,CS11);
		SetBit(TCCR1B,CS12);
#elif Timer1PrescalerValue == 256
		ClrBit(TCCR1B,CS10);
		ClrBit(TCCR1B,CS11);
		SetBit(TCCR1B,CS12);
#elif Timer1PrescalerValue == 64
		SetBit(TCCR1B,CS10);
		SetBit(TCCR1B,CS11);
		ClrBit(TCCR1B,CS12);
#elif Timer1PrescalerValue == 8
		ClrBit(TCCR1B,CS10);
		SetBit(TCCR1B,CS11);
		ClrBit(TCCR1B,CS12);
#elif Timer1PrescalerValue == 1
		SetBit(TCCR1B,CS10);
		ClrBit(TCCR1B,CS11);
		ClrBit(TCCR1B,CS12);
#endif
		break;
	case Timer2Channel:
#if Timer2PrescalerValue == 1024
		SetBit(TCCR2,CS20);
		SetBit(TCCR2,CS21);
		SetBit(TCCR2,CS22);
#elif Timer2PrescalerValue == 256
		ClrBit(TCCR2,CS20);
		SetBit(TCCR2,CS21);
		SetBit(TCCR2,CS22);
#elif Timer2PrescalerValue == 128
		SetBit(TCCR2,CS20);
		ClrBit(TCCR2,CS21);
		ClrBit(TCCR2,CS22);
#elif Timer2PrescalerValue == 64
		ClrBit(TCCR2,CS20);
		ClrBit(TCCR2,CS21);
		SetBit(TCCR2,CS22);
#elif Timer2PrescalerValue == 8
		ClrBit(TCCR2,CS20);
		SetBit(TCCR2,CS21);
		ClrBit(TCCR2,CS22);
#elif Timer2PrescalerValue == 1
		SetBit(TCCR2,CS20);
		ClrBit(TCCR2,CS21);
		ClrBit(TCCR2,CS22);
#endif
		break;
	default: break;
	}
}


void TimerStop(U8 TimerChannel){
	switch(TimerChannel){
	case Timer0Channel:
		ClrBit(TCCR0,CS00);
		ClrBit(TCCR0,CS01);
		ClrBit(TCCR0,CS02);
		break;
	case Timer1Channel:
		ClrBit(TCCR1B,CS00);
		ClrBit(TCCR1B,CS01);
		ClrBit(TCCR1B,CS02);
		break;
	case Timer2Channel:
		ClrBit(TCCR2,CS20);
		ClrBit(TCCR2,CS21);
		ClrBit(TCCR2,CS22);

		break;
	default: break;
	}
}

void TimerSetTime(U32 ReqTime){
	U32 TickTime = Timer0PrescalerValue/FOSC;
	U32 TotalTicks = ReqTime * 1000 / TickTime;

#if Timer0Mode == NormalMode
	OverflowNumber = TotalTicks / 256;
	RemainderTicks = OverflowNumber % 256;
	if(RemainderTicks){
		TCNT0 = 256 - RemainderTicks;
		OverflowNumber++;
	}
#elif Timer0Mode == CTCMode
	U8 TimerDivVal = 255;

	while(ReqTime % TimerDivVal)
		TimerDivVal--;

	OCR0 = TimerDivVal - 1;
#endif


}

U32 TimerGetTime(){
	U32 TickTime = Timer2PrescalerValue/FOSC;
	U32 OverflowTime = TickTime * 256;
	U32 TotalTime = OverflowNumber * OverflowTime;

	TotalTime += TCNT1 * TickTime;
	TCNT1 = 0;
	OverflowNumber = 0;
	return TotalTime;
}

void PWMInit(U8 TimerChannel){
	switch(TimerChannel){
	case Timer0Channel:
		DioSetPinDir(GB,OC0,Output);
#if Timer0Mode == FastPWMMode
		SetBit(TCCR0,WGM00);
		SetBit(TCCR0,WGM01);
#elif Timer0Mode == PhaseCorrectPWMMode
		SetBit(TCCR0,WGM00);
		ClrBit(TCCR0,WGM01);
#endif

#if Timer0PWMMode == Inverted
		SetBit(TCCR0,COM00);
		SetBit(TCCR0,COM01);
#elif Timer0PWMMode == NonInverted
		ClrBit(TCCR0,COM00);
		SetBit(TCCR0,COM01);
#endif
		break;
	case Timer1Channel:
		DioSetPinDir(GD,OCR1APin,Output);
		ClrBit(TCCR1A,WGM10);
		SetBit(TCCR1A,WGM11);
		SetBit(TCCR1B,WGM12);
		SetBit(TCCR1B,WGM13);

		ClrBit(TCCR1A,COM1A0);
		SetBit(TCCR1A,COM1A1);

		ICR1 = 4999;
		break;

	default: break;
	}
}

void PWMSetDutyCycle(U8 TimerChannel,U8 DutyCycle){
	switch(TimerChannel){
	case Timer0Channel:
#if Timer0Mode == FastPWMMode
		OCR0 = ((DutyCycle * 256) / 100) - 1;
#elif Timer0Mode == PhaseCorrectPWMMode
		OCR0 = ((DutyCycle * 255) / 100);
#endif
		break;
	case Timer1Channel:
		OCR1A = ( (DutyCycle * ICR1) / 100 ) - 1;
		break;
	default: break;
	}
}

void PWMStart(U8 TimerChannel){
	TimerStart(TimerChannel);
}

void PWMStop(U8 TimerChannel){
	TimerStop(TimerChannel);
}

#if Timer0Mode == CTCMode
void __vector_11(void)__attribute__((signal,used));
void __vector_11(void){
	static U32 Counter = 0;

	if(++Counter == CompareMatchNumber){
		TimerCallBack();
		Counter = 0;
	}
}
#endif
