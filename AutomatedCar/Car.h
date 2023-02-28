/*
 * Car.h
 *
 *  Created on: Feb 20, 2023
 *      Author: rerom
 */

#ifndef AUTOMATEDCAR_CAR_H_
#define AUTOMATEDCAR_CAR_H_

#include"../MCAL/DIO.h"
#include"../HAL/HC.h"
#include"../HAL/LCD.h"
#include"../HAL/Motor.h"
#include"../HAL/Servo.h"
#include <util/delay.h>



void CarInit();
int CarCheckDistance(int);
void CarForwardDir();
void CarRotateRight();
void CarRotateLeft();
void CarReverseDir();
void CarBrake();
void CarStop();
void CarCheckRight();
void CarCheckLeft();









#endif /* AUTOMATEDCAR_CAR_H_ */
