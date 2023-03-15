/*
 * HC.h
 *
 *  Created on: Feb 17, 2023
 *      Author: rerom
 */

#ifndef HAL_HC_H_
#define HAL_HC_H_

#include <util/delay.h>
#include "../MCAL/DIO.h"
#include "../MCAL/INT.h"
#include "../MCAL/Timer.h"

#include"../LIB/BitMath.h"
#include"../LIB/TypeDef.h"


#define TriggerPulsePin PIN0
#define EchoPulsePin    PIN6
#define HcPortEcho       GD
#define HcPortTrigger    GC
#define FOSC  16

void HCInit();
void HCTrigger();
float HCCalcDistance();

#endif /* HAL_HC_H_ */
