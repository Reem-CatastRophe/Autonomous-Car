/*
 * ADC.c
 *
 *  Created on: Feb 12, 2023
 *      Author: omarM
 */

#include "ADC.h"

void ADCInit(void){
#if ADCVREF == AVCC
	SetBit(ADMUX, REFS0);
	ClrBit(ADMUX, REFS1);
#elif ADCVREF == AREF
	ClrBit(ADMUX, REFS0);
	ClrBit(ADMUX, REFS1);
#elif ADCVREF == _2V56
	SetBit(ADMUX, REFS0);
	SetBit(ADMUX, REFS1);
#endif
	// To select right adjust
	ClrBit(ADMUX, ADLAR);
#if	ADCPrescalarDiv == 128
	SetBit(ADCSRA,ADSP0);
	SetBit(ADCSRA,ADSP1);
	SetBit(ADCSRA,ADSP2);
#elif ADCPrescalarDiv == 64
	ClrBit(ADCSRA,ADSP0);
	SetBit(ADCSRA,ADSP1);
	SetBit(ADCSRA,ADSP2);
#endif
	// Set auto trigger mode
	SetBit(ADCSRA,ADATE);
	// Enable the circuit
	SetBit(ADCSRA,ADEN);
	// Check this later
	// To start conversion
	SetBit(ADCSRA,ADSC);
}
U16 ADCRead(U8 CopyU8ADCChannel)
{
	ADMUX = (ADMUX & ADMUXMask) | CopyU8ADCChannel;
	U32 LocalU8MaxIterations = 0;
	while(LocalU8MaxIterations < 2000000)
	{
		LocalU8MaxIterations++;
		if(GetBit(ADCSRA,ADIF) == ADCConvFinished)
			break;
	}
	/*
	 * ADSC will read as one as long as a conversion is in progress. When the conversion is
	 * complete, it returns to zero. Writing zero to this Bit has no effect
	 */

	return ADCVal;
}
