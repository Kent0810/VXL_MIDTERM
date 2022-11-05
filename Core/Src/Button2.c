/*
 * button2.c
 *
 *  Created on: Nov 3, 2022
 *      Author: Admin
 */

#include "Button2.h"


static int KeyReg0 = NORMAL_STATE;
static int KeyReg1 = NORMAL_STATE;
static int KeyReg2 = NORMAL_STATE;

static int KeyReg3 = NORMAL_STATE; //previous
static int TimerForKeyPress = 300;

int isButton2Clicked = 0;
int isButton2LongClicked = 0;
void KeyInputHandler2(){
	isButton2Clicked = 1;
}
void LongKeyInputHandler2(){
	isButton2Clicked = 0;
	isButton2LongClicked = 1;
}


void getKeyInput2(){
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);
	if((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
		if(KeyReg3 != KeyReg2){
			KeyReg3 = KeyReg2;
			if(KeyReg2 == PRESSED_STATE){
				KeyInputHandler2();
				TimerForKeyPress = 300;
			}
		}
		else {
			TimerForKeyPress--;
			if(TimerForKeyPress == 0){
				if(KeyReg2 == PRESSED_STATE){
					LongKeyInputHandler2();
				}
				TimerForKeyPress = 100;
			}

		}
	}
}
