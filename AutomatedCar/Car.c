/*
 * Car.c
 *
 *  Created on: Feb 20, 2023
 *      Author: rerom
 */
#include"Car.h"

extern U32 OverflowNum;


void CarInit(){
	MotorInit();
	ServoSetAngle(MidAngle);
	TCRT5000Init();
}

U8 CarDetectObstacle(){
	float distance[7];
	int i,counter=0;
	for(i=0;i<7;i++){
		distance[i]=HCCalcDistance();
		if(distance[i]<40 && distance[i]!=0)
			counter++;
	}
	if(counter == 7)
	{
		DioSetPinVal(GD,PIN3,High);
	}
	else{
		DioSetPinVal(GD,PIN3,Low);
	}
	return (counter == 7);
}

void CarForwardDir(){
	MotorStart();
	MotorSetDirection(Forward);
	MotorSetSpeed(StraightSpeed);
}

void CarReverseDir(){
	ServoSetAngle(90);
	MotorStart();
	MotorSetDirection(Reverse);
	MotorSetSpeed(StraightSpeed);

}

void CarRotateRight(U8 Choice){
	MotorStart();
	MotorSetSpeed(RotateSpeed);
	MotorStartLeft();
	MotorStopRight();

	if(Choice==ObstacleMode)
		_delay_ms(600);
}

void CarRotateLeft(U8 Choice){
	MotorStart();
	MotorSetSpeed(RotateSpeed);

	MotorStartRight();
	MotorStopLeft();
	if(Choice==ObstacleMode)
		_delay_ms(500);
}
void CarBrake(){
	MotorSetSpeed(35);
}
void CarStop(){
	MotorStop();
}



void CarDriftLeft(){
	MotorStart();
	MotorSetSpeed(DriftSpeed);
	RightMotorForward();
	LeftMotorReverse();

	for(int i = 0;i <30000;i++){
	}
}
void CarDriftRight(){
	MotorStart();
	MotorSetSpeed(DriftSpeed);
	RightMotorReverse();
	LeftMotorForward();

	for(int i = 0;i < 30000;i++){
	}
}

void CarRotateServo(U8 CurrentPosition, U8 NextPosition)
{
	U8 i;
	if(CurrentPosition == MidPosition && NextPosition == RightPosition)
	{
		for(i=MidAngle ; i>RightAngle; i-=5)
		{
			ServoSetAngle(i);
		}
	} else if (CurrentPosition == RightPosition && NextPosition == MidPosition)
	{
		for(i=RightAngle ; i<MidAngle; i+=5)
		{
			ServoSetAngle(i);
		}
	}else if (CurrentPosition == RightPosition && NextPosition == LeftPosition)
	{
		for(i=RightAngle ; i<LeftAngle; i+=5)
		{
			ServoSetAngle(i);
		}
	}else
	{
		for(i=LeftAngle; i>MidAngle; i-=5)
		{
			ServoSetAngle(i);
		}
	}
}

void CarDelay(U32 DelayTime){
	DioSetPinDir(GC,PIN2,Output);
	Timer2Init();
	while(OverflowNum < DelayTime){
		DioSetPinVal(GC,PIN2,High);
	}

	OverflowNum=0;
	DioSetPinVal(GC,PIN2,Low);

	Timer2Stop();

}




