/*
 * HC.c
 *
 *  Created on: Feb 17, 2023
 *      Author: rerom
 */


#include "HC.h"



void HCInit(){
	GlobalInterruptEnable();
	DioSetPinDir(HcPort,TriggerPulsePin, Output);
	DioSetPinDir(HcPort,EchoPulsePin, Input);

	TimerInit();
}

void HCTrigger() {
	DioSetPinVal(HcPort,TriggerPulsePin, High);
	 _delay_us(10);
	 DioSetPinVal(HcPort,TriggerPulsePin, Low);
}


float HCCalcDistance() {

	float ElapsedTime;

	HCTrigger();
	U32 Cnt = 0;


	while(DioGetPinVal(HcPort,EchoPulsePin) == 0 && ++Cnt < 2000);



	TimerStart(Timer2Channel);
	Cnt = 0;
	while(DioGetPinVal(HcPort,EchoPulsePin) != 0);

	ElapsedTime = TimerGetTime();
	TimerStop(Timer2Channel);


	return (ElapsedTime*34300)/(2*1000000);
}
