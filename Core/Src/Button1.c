/*
 * button1.c
 *
 *  Created on: Nov 3, 2022
 *      Author: Admin
 */

#include "Button1.h"


static int KeyReg0 = NORMAL_STATE;
static int KeyReg1 = NORMAL_STATE;
static int KeyReg2 = NORMAL_STATE;

static int KeyReg3 = NORMAL_STATE; //previous
static int TimerForKeyPress = 200;
int isButton1Clicked = 0;

void KeyInputHandler1(){
	isButton1Clicked = 1;
}
void LongKeyInputHandler1(){
	return;
}

void getKeyInput1(){
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin);
	if((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
		if(KeyReg3 != KeyReg2){
			KeyReg3 = KeyReg2;
			if(KeyReg2 == PRESSED_STATE){
				KeyInputHandler1();
				TimerForKeyPress = 300;
			}
		}
		else {
			TimerForKeyPress--;
			if(TimerForKeyPress == 0){
				if(KeyReg2 == PRESSED_STATE){
					LongKeyInputHandler1();
				}
				TimerForKeyPress = 300;
			}
		}
	}
}
