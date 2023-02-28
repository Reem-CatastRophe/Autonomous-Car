/*
 * Car.c
 *
 *  Created on: Feb 20, 2023
 *      Author: rerom
 */
#include"Car.h"

void CarInit(){
	HCInit();
	MotorInit();
	ServoInit();
	ServoSetAngle(90);
}

int CarCheckDistance(int space){
	int* dist;
	int Cnt = 0;

	DioSetPinVal(GD,PIN3,Low);
	for(int i = 0;i < 6;i++){
		dist[i] = HCCalcDistance();
	}

	for(int i = 0;i < 6;i++){
		if(dist[i] > space) Cnt++;
	}


	return Cnt > 2 ? 1 : 0;
}

void CarForwardDir(){
	MotorStop();
	MotorSetDirection(Forward);
	MotorSetSpeed(99);
	MotorStart();
}

void CarReverseDir(){
	ServoSetAngle(90);
	MotorStart();
	MotorSetDirection(Reverse);
	MotorSetSpeed(99);

}

void CarRotateRight(){
	MotorStart();
	MotorStartRight();
	MotorStopLeft();
}

void CarRotateLeft(){
	MotorStart();
	MotorStartLeft();
	MotorStopRight();
}
void CarBrake(){
	MotorSetSpeed(40);

}
void CarStop(){
	MotorStop();
}
void CarCheckRight(){
	ServoSetAngle(10);
}
void CarCheckLeft(){
	ServoSetAngle(170);
}
