/*
 * DIO.c
 *
 *  Created on: Jan 28, 2023
 *      Author: omarM
 */


#include "./DIO.h"
void DioSetPinDir(U8 Port,U8 Pin,U8 Dir){
	if(Dir == Input){
		switch(Port){
			case GA:
				ClrBit(DDRA,Pin);
				break;
			case GB:
				ClrBit(DDRB,Pin);
				break;
			case GC:
				ClrBit(DDRC,Pin);
				break;
			case GD:
				ClrBit(DDRD,Pin);
				break;
		}
	}else if(Dir == Output){
		switch(Port){
			case GA:
				SetBit(DDRA,Pin);
				break;
			case GB:
				SetBit(DDRB,Pin);
				break;
			case GC:
				SetBit(DDRC,Pin);
				break;
			case GD:
				SetBit(DDRD,Pin);
				break;
		}
	}
}

void DioSetPinVal(U8 Port,U8 Pin,U8 Val){
	if(Val == Low){
		switch(Port){
			case GA:
				ClrBit(PORTA,Pin);
				break;
			case GB:
				ClrBit(PORTB,Pin);
				break;
			case GC:
				ClrBit(PORTC,Pin);
				break;
			case GD:
				ClrBit(PORTD,Pin);
				break;
		}
	}else if(Val == High){
		switch(Port){
			case GA:
				SetBit(PORTA,Pin);
				break;
			case GB:
				SetBit(PORTB,Pin);
				break;
			case GC:
				SetBit(PORTC,Pin);
				break;
			case GD:
				SetBit(PORTD,Pin);
				break;
		}
	}
}

U8 DioGetPinVal(U8 Port,U8 Pin){
	switch(Port){
		case GA:
			return GetBit(PINA,Pin);
		case GB:
			return GetBit(PINB,Pin);
		case GC:
			return GetBit(PINC,Pin);
		case GD:
			return GetBit(PIND,Pin);
	}
	return 0;
}

void DioSetPortDir(U8 Port,U8 Dir){
	if(Dir == Input){
		switch(Port){
			case GA:
				DDRA = 0x00;
				break;
			case GB:
				DDRB = 0x00;
				break;
			case GC:
				DDRC = 0x00;
				break;
			case GD:
				DDRD = 0x00;
				break;
		}
	}else if(Dir == Output){
		switch(Port){
			case GA:
				DDRA = 0xFF;
				break;
			case GB:
				DDRB = 0xFF;
				break;
			case GC:
				DDRC = 0xFF;
				break;
			case GD:
				DDRD = 0xFF;
				break;
		}
	}
}

void DioSetPortVal(U8 Port,U8 Val){
	switch(Port){
		case GA:
			PORTA = Val;
			break;
		case GB:
			PORTB = Val;
			break;
		case GC:
			PORTC = Val;
			break;
		case GD:
			PORTD = Val;
			break;
	}
}

U8 DioGetPortValue(U8 Port){
	switch(Port){
		case GA:
			return PINA;
			break;
		case GB:
			return PINB;
			break;
		case GC:
			return PINC;
			break;
		case GD:
			return PINC;
			break;
	}
	return 0;
}

void DioSetPinPullUpRes(U8 Port,U8 Pin,U8 State){
	switch(Port){
		case GA:
			switch(State){
				case Enable:
					SetBit(PORTA,Pin);
					break;
				case Disable:
					SetBit(PORTA,Pin);
					break;
			}
			break;
		case GB:
			switch(State){
				case Enable:
					SetBit(PORTB,Pin);
					break;
				case Disable:
					SetBit(PORTB,Pin);
					break;
			}
			break;
		case GC:
			switch(State){
				case Enable:
					SetBit(PORTC,Pin);
					break;
				case Disable:
					SetBit(PORTC,Pin);
					break;
			}
			break;
		case GD:
			switch(State){
				case Enable:
					SetBit(PORTD,Pin);
					break;
				case Disable:
					SetBit(PORTD,Pin);
					break;
			}
			break;
	}

}
