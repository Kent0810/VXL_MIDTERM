/*
 * Button3.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */

#include "Button3.h"


static int KeyReg0 = NORMAL_STATE;
static int KeyReg1 = NORMAL_STATE;
static int KeyReg2 = NORMAL_STATE;

static int KeyReg3 = NORMAL_STATE; //previous
static int TimerForKeyPress = 300;

int isButton3Clicked = 0;
int isButton3LongClicked = 0;
void KeyInputHandler3(){
	isButton3Clicked = 1;
}
void LongKeyInputHandler3(){
	isButton3Clicked = 0;
	isButton3LongClicked = 1;
}

void getKeyInput3(){
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin);
	if((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
		if(KeyReg3 != KeyReg2){
			KeyReg3 = KeyReg2;
			if(KeyReg2 == PRESSED_STATE){
				KeyInputHandler3();
				TimerForKeyPress = 300;
			}

		}
		else {
			TimerForKeyPress--;
			if(TimerForKeyPress == 0){
				if(KeyReg2 == PRESSED_STATE){
					LongKeyInputHandler3();
				}
				TimerForKeyPress = 100;
			}
		}
	}
}
