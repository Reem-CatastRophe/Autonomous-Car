/*
 * Motor.h
 *
 *  Created on: Feb 16, 2023
 *      Author: rerom
 */

#ifndef HAL_MOTOR_H_
#define HAL_MOTOR_H_



#include "../MCAL/DIO.h"
#include "../MCAL/Timer.h"

#define Forward 0
#define Reverse 1

#define HA1  PIN3
#define HA2  PIN4
#define HA3  PIN5
#define HA4  PIN6


void MotorInit();
void MotorSetDirection(U8);
void MotorSetSpeed(U8);
void MotorStart();
void MotorStartRight();
void MotorStartLeft();

void MotorStop();
void MotorStopRight();
void MotorStopLeft();



#endif /* HAL_MOTOR_H_ */
