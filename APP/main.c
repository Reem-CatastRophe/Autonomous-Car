/*
 * main.c
 *
 *  Created on: Jan 28, 2023
 *      Author: rerom
 */

#include"../AutomatedCar/Car.h"
#include<avr/io.h>
#define BlackLine        1
#define WhiteLine        0
#define MinimumDistance  15
#define MaxTrials        3
#define CarStopDelay     250
#define InstructionDelay  25
#define ServoDelay        30


void DelayFunc(volatile U32 i){
	volatile U32 j;
	for(j=0;j<i;j++){

	}
}

int main(){
	CarInit();
	DioSetPinDir(GD,PIN3,Output);
	U8 MiddleIRdigitalVal, RightIRdigitalVal, LeftIRdigitalVal;

	while(1)
	{

		while(!CarDetectObstacle()){

			TCRT5000GetVal(&MiddleIRdigitalVal, &RightIRdigitalVal, &LeftIRdigitalVal);

			/* follow black line forward as long as there is no curvature */
			if (MiddleIRdigitalVal == BlackLine && RightIRdigitalVal== WhiteLine && LeftIRdigitalVal == WhiteLine)
			{
				CarForwardDir();
			}
			else
			{
				CarBrake();

				/*follow black line right with no sharp curvature */
				if (RightIRdigitalVal== BlackLine && MiddleIRdigitalVal== WhiteLine )
				{
					CarRotateRight(IRMode);
					TCRT5000GetVal(&MiddleIRdigitalVal, &RightIRdigitalVal, &LeftIRdigitalVal);
					if(MiddleIRdigitalVal== WhiteLine && LeftIRdigitalVal==WhiteLine && RightIRdigitalVal== WhiteLine)
						CarRotateLeft(IRMode);
				}

				/*follow black line left with no sharp curvature */
				else if (LeftIRdigitalVal == BlackLine && MiddleIRdigitalVal== WhiteLine)
				{
					CarRotateLeft(IRMode);
					TCRT5000GetVal(&MiddleIRdigitalVal, &RightIRdigitalVal, &LeftIRdigitalVal);

					if(MiddleIRdigitalVal== WhiteLine && LeftIRdigitalVal==WhiteLine && RightIRdigitalVal== WhiteLine)
						CarRotateRight(IRMode);
				}

				/*sharp turn to the right*/
				else if (MiddleIRdigitalVal == BlackLine && RightIRdigitalVal== BlackLine)
				{
					CarDriftRight();
					CarDelay(20);
				}

				/*sharp turn to the left */
				else if (MiddleIRdigitalVal == BlackLine && LeftIRdigitalVal== BlackLine)
				{
					CarDriftLeft();
					CarDelay(20);

				}
				else if(MiddleIRdigitalVal== WhiteLine && LeftIRdigitalVal==WhiteLine && RightIRdigitalVal== WhiteLine)
				{
					CarBrake();

				}else{
					CarStop();
				}
			}
		}

		CarDelay(60);
		ServoSetAngle(MidAngle);
		CarForwardDir();
		while(CarDetectObstacle()){
			CarStop();
			CarDelay(60);
			CarRotateServo(MidPosition, RightPosition);
			CarDelay(350);

			if(CarDetectObstacle()){
				CarRotateServo(RightPosition, LeftPosition);
				CarDelay(250);
				if(CarDetectObstacle()){
					CarRotateServo(LeftPosition, MidPosition);
					CarDelay(250);
					CarReverseDir();
					CarDelay(125);
					CarStop();
					CarDelay(250);
				}
				else{
					ServoSetAngle(MidAngle);
					CarDelay(60);
					CarRotateLeft(IRMode);
					CarDelay(145);
					//CarStop();
					//CarDelay(CarStopDelay);
					CarForwardDir();
					CarDelay(150);
					//CarStop();
					//CarDelay(CarStopDelay);
					CarRotateRight(IRMode);
					CarDelay(105);
					//CarStop();
					//CarDelay(CarStopDelay);
					CarForwardDir();
					CarDelay(165);
					//CarStop();
					//CarDelay(CarStopDelay);
					CarRotateRight(IRMode);
					CarDelay(110);
					//CarStop();
					//CarDelay(CarStopDelay);
					CarForwardDir();
					TCRT5000GetVal(&MiddleIRdigitalVal, &RightIRdigitalVal, &LeftIRdigitalVal);
					while( MiddleIRdigitalVal!=BlackLine)
					{

						TCRT5000GetVal(&MiddleIRdigitalVal, &RightIRdigitalVal, &LeftIRdigitalVal);
					}
					//CarStop();
					//CarDelay(CarStopDelay);

				}
			}
			else{
				ServoSetAngle(MidAngle);
				CarDelay(60);
				CarRotateRight(IRMode);
				CarDelay(145);
				//CarStop();
				//CarDelay(CarStopDelay);
				CarForwardDir();
				CarDelay(150);
				//CarStop();
				//CarDelay(CarStopDelay);
				CarRotateLeft(IRMode);
				CarDelay(105);
				//CarStop();
				//CarDelay(CarStopDelay);
				CarForwardDir();
				CarDelay(165);
				//CarStop();
				//CarDelay(CarStopDelay);
				CarRotateLeft(IRMode);
				CarDelay(110);
				//CarStop();
				//CarDelay(CarStopDelay);
				CarForwardDir();
				TCRT5000GetVal(&MiddleIRdigitalVal, &RightIRdigitalVal, &LeftIRdigitalVal);
				while( MiddleIRdigitalVal!=BlackLine)
				{

					TCRT5000GetVal(&MiddleIRdigitalVal, &RightIRdigitalVal, &LeftIRdigitalVal);
				}
				//CarStop();
				//CarDelay(CarStopDelay);

			}
		}
	}

	return 0;
}

