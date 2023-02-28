/*
 * LCD.c
 *
 *  Created on: Jan 29, 2023
 *      Author: rerom
 */
#include "LCD.h"
#include <util/delay.h>


void LcdTrigger(){
	DioSetPinVal(LcdCmdPort,EN,High);
	_delay_ms(1);
	DioSetPinVal(LcdCmdPort,EN,Low);
	_delay_ms(2);
}

void LcdWriteCmd(U8 Cmd){
	DioSetPinVal(LcdCmdPort,RS,Low);
	DioSetPinVal(LcdCmdPort,RW,Low);
	DioSetPortVal(LcdDataPort,Cmd&0xF0);
	LcdTrigger();
	DioSetPortVal(LcdDataPort,Cmd<<4);
	LcdTrigger();
}
void LcdInit(){

	DioSetPortDir(LcdDataPort,Output);

	DioSetPinDir(LcdCmdPort,EN,Output);
	DioSetPinDir(LcdCmdPort,RS,Output);
	DioSetPinDir(LcdCmdPort,RW,Output);

	_delay_ms(50);

	LcdWriteCmd(0x02);
	LcdWriteCmd(0x2c);//2 Line Display + Bold Font
	LcdWriteCmd(0x0F);// Display on + Cursor on + Blink on
	LcdWriteCmd(0x01);
	LcdWriteCmd(0x06);//Increment address mode on + Shift off

}

void LcdWriteData(U8 Data){
	DioSetPinVal(LcdCmdPort,RS,High);
	DioSetPinVal(LcdCmdPort,RW,Low);
	DioSetPortVal(LcdDataPort,Data&0xF0);
	LcdTrigger();
	DioSetPortVal(LcdDataPort,Data<<4);
	LcdTrigger();
}

void LcdWriteString(U8* Str){
	int i;
	for(i=0;Str[i]!=0;i++)
		LcdWriteData(Str[i]);
}

void LcdWriteNum(U32 Num){

	U32 Remainder;
	U8 ProcessedNum[10]={0};
	S32 i=0,j;
	if(Num<0){
		LcdWriteData('-');
		Num*=-1;
	}

	while(Num!=0){
		Remainder =Num%10;
		Remainder +='0';
		ProcessedNum[i] =Remainder;
		Num/=10;
		i++;
	}

	for(j=i-1;j>=0;j--)
		LcdWriteData(ProcessedNum[j]);

}

