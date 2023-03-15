/*
 * TCRT5000.c
 *
 *  Created on: Feb 24, 2023
 *      Author: rerom
 */

#include"TCRT5000.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void TCRT5000Init(){
	DioSetPinDir(IRPort,LeftSensor,Input);
	DioSetPinDir(IRPort,RightSensor,Input);
	DioSetPinDir(IRPort,MidSensor,Input);
}
void TCRT5000GetVal(U8* MiddleSensorPin, U8*RightSensorPin, U8* LeftSensorPin){

	*LeftSensorPin=  DioGetPinVal(IRPort,LeftSensor);

	*RightSensorPin= DioGetPinVal(IRPort,RightSensor);

	*MiddleSensorPin=  DioGetPinVal(IRPort,MidSensor);

}

