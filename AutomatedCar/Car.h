/*
 * Car.h
 *
 *  Created on: Feb 20, 2023
 *      Author: rerom
 */

#ifndef AUTOMATEDCAR_CAR_H_
#define AUTOMATEDCAR_CAR_H_

#include"../MCAL/DIO.h"
#include"../MCAL/Timer2.h"
#include"../HAL/HC.h"
#include"../HAL/Motor.h"
#include"../HAL/Servo.h"
#include"../HAL/TCRT5000.h"
#include <util/delay.h>

#define MidPosition              0
#define LeftPosition             1
#define RightPosition            2
#define MidAngle                 90
#define LeftAngle                160
#define RightAngle               35
#define ObstacleMode             1
#define IRMode             		 0

#define StraightSpeed 	50
#define RotateSpeed 	45
#define DriftSpeed		35

void CarInit();
U8 CarDetectObstacle();
void CarForwardDir();
void CarRotateLeft(U8 Choice);
void CarRotateRight(U8 Choice);
void CarReverseDir();
void CarBrake();
void CarStop();
void CarCheckRight();
void CarCheckLeft();
void CarDriftLeft();
void CarDriftRight();
void CarRotateServo(U8 CurrentPosition, U8 NextPosition);
void CarDelay(U32);







#endif /* AUTOMATEDCAR_CAR_H_ */
