/*
 * INT.c
 *
 *  Created on: Feb 12, 2023
 *      Author: omarM
 */

#include"INT.h"

void (*INT0CallBack)(void);
void (*INT1CallBack)(void);
void (*INT2CallBack)(void);

void IntInit(U8 Channel){
	switch(Channel){
		case INT0Channel:
			#if INT0ControlMode == RisingEdge
				SetBit(MCUCR,ISC00);
				SetBit(MCUCR,ISC01);
			#elif INT0ControlMode == FallingEdge
				ClrBit(MCUCR,ISC00);
				SetBit(MCUCR,ISC01);
			#elif INT0ControlMode == LowLevel
				ClrBit(MCUCR,ISC00);
				ClrBit(MCUCR,ISC01);
			#elif INT0ControlMode == LogicalChange
				SetBit(MCUCR,ISC00);
				ClrBit(MCUCR,ISC01);
			#endif

			SetBit(GICR,INT0);
			break;
		case INT1Channel:
			#if INT1ControlMode == RisingEdge
				SetBit(MCUCR,ISC10);
				SetBit(MCUCR,ISC11);
			#elif INT1ControlMode == FallingEdge
				ClrBit(MCUCR,ISC10);
				SetBit(MCUCR,ISC11);
			#elif INT1ControlMode == LowLevel
				ClrBit(MCUCR,ISC10);
				ClrBit(MCUCR,ISC11);
			#elif INT1ControlMode == LogicalChange
				SetBit(MCUCR,ISC10);
				ClrBit(MCUCR,ISC11);
			#endif

			SetBit(GICR,INT1);
			break;

		case INT2Channel:
			SetBit(GICR,INT2);
			break;
		default: break;

	}

}

void GlobalInterruptEnable(){
	SetBit(SREG,GIE);
}

void GlobalInterruptDisable(){
	ClrBit(SREG,GIE);
}

void SetCallBack(void (*ISR)(void),U8 IntChannel){
	switch(IntChannel){
		case INT0Channel:
			INT0CallBack = ISR;
			break;
		case INT1Channel:
			INT1CallBack = ISR;
			break;
		case INT2Channel:
			INT2CallBack = ISR;
			break;
		default: break;
	}
}
void __vector_1(void)__attribute__((signal,used));
void __vector_1(void){
	INT0CallBack();
}
