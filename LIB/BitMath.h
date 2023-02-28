/*
 * BITMATH.h
 *
 *  Created on: Jan 28, 2023
 *      Author: omarM
 */

#ifndef LIB_BITMATH_H_
#define LIB_BITMATH_H_

#define SetBit(Reg,Bit) 	Reg |= 1<<Bit
#define ClrBit(Reg,Bit) 	Reg &= ~(1<<Bit)
#define ToggleBit(Reg,Bit) 	Reg ^= (1<<Bit)
#define GetBit(Reg,Bit) 	(Reg & (1<<Bit)) >> Bit



#endif /* LIB_BITMATH_H_ */
