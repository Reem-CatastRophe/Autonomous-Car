/*
 * TCRT5000.h
 *
 *  Created on: Feb 24, 2023
 *      Author: rerom
 */

#ifndef HAL_TCRT5000_H_
#define HAL_TCRT5000_H_

#include "../MCAL/DIO.h"
#include "util/delay.h"

#define IRPort      GA
#define LeftSensor	PIN5
#define MidSensor 	PIN6
#define RightSensor PIN7

void TCRT5000Init();
void TCRT5000GetVal(U8* MiddleSensorPin, U8*RightSensorPin, U8* LeftSensorPin);


#endif /* HAL_TCRT5000_H_ */
