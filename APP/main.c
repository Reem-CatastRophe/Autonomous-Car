/*
 * main.c
 *
 *  Created on: Jan 28, 2023
 *      Author: rerom
 */

#include"../AutomatedCar/Car.h"

int main(){

CarInit();

while(1){

	U8 distance=CarCheckDistance();

	if(distance > 10){
		CarForwardDir();
	}else{
		CarBrake();
		if(distance < 5){
			CarStop();
			CarCheckRight();
			if(distance > 5){
				CarRotateRight();
			}else{
				CarCheckLeft();
				if(distance > 5){
					CarRotateLeft();
				}else{
					CarReverseDir();
					CarStop();
					CarCheckRight();
					if(distance > 5){
						CarRotateRight();
					}else{
						CarCheckLeft();
						if(distance > 5){
							CarRotateLeft();
						}else{
							CarStop();
						}
					}
				}
			}
		}
	}
}

	return 0;
}
