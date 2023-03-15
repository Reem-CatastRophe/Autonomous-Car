/*
 * Servo.h
 *
 *  Created on: Feb 16, 2023
 *      Author: rerom
 */

#ifndef HAL_SERVO_H_
#define HAL_SERVO_H_


#include "../MCAL/DIO.h"
#include "../MCAL/Timer.h"
#include <avr/io.h>

void ServoInit();
void ServoSetAngle(U8);


#endif /* HAL_SERVO_H_ */
