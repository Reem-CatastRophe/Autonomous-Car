/*
 * HC.c
 *
 *  Created on: Feb 17, 2023
 *      Author: rerom
 */


#include "HC.h"



void HCInit(){
	GlobalInterruptEnable();
	DioSetPinDir(HcPortTrigger,TriggerPulsePin, Output);
	DioSetPinDir(HcPortEcho,EchoPulsePin, Input);

	Timer1Init(NormalMode);
}

void HCTrigger() {
	DioSetPinVal(HcPortTrigger,TriggerPulsePin, High);
	 _delay_us(10);
	 DioSetPinVal(HcPortTrigger,TriggerPulsePin, Low);
}

float HCCalcDistance() {
	float ElapsedTime;
	HCInit();
	DioSetPinDir(GC,PIN7,Output);
	DioSetPinVal(GC,PIN7,High);

	HCTrigger();
	DioSetPinVal(GC,PIN7,Low);

	U32 Cnt = 0;
	while(DioGetPinVal(HcPortEcho,EchoPulsePin) == 0 && Cnt < 1000)
	{
		Cnt++;
	}
	Cnt = 0;

	TimerStart(Timer1Channel);

	U32 StartTime = TimerGetTime();
	while(DioGetPinVal(HcPortEcho,EchoPulsePin) > 0 && Cnt < 1000)
	{
		Cnt++;
	}
	U32 EndTime = TimerGetTime();
	TimerStop(Timer1Channel);
	ElapsedTime = EndTime-StartTime;


	return (ElapsedTime*34300)/(2*1000000);
}


