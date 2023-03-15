/*
 * Servo.c
 *
 *  Created on: Feb 16, 2023
 *      Author: rerom
 */

#include"Servo.h"



void ServoInit(){
	Timer1Init(FastPWMMode);
	PWMStart(Timer1Channel);
}

void ServoSetAngle(U8 ServoAngle){
	ServoInit();
	PWMSetDutyCycle(Timer1Channel,3+ServoAngle*(1.0/18));
//	TimerStop(Timer1Channel);
}

