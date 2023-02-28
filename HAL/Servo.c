/*
 * Servo.c
 *
 *  Created on: Feb 16, 2023
 *      Author: rerom
 */

#include"Servo.h"

void ServoInit(){
	PWMInit(Timer1Channel);
	PWMStart(Timer1Channel);
}

void ServoSetAngle(U8 ServoAngle){
	PWMSetDutyCycle(Timer1Channel,3+ServoAngle*(1.0/18));
}
