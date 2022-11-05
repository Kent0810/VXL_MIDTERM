/*
 * Button2.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */

#ifndef INC_BUTTON2_H_
#define INC_BUTTON2_H_
#include "global.h"

#define NORMAL_STATE 	GPIO_PIN_SET //-> 0 Nhan
#define PRESSED_STATE 	GPIO_PIN_RESET // -> Nhan

extern int isButton2Clicked;
extern int isButton2LongClicked;

//function prototype
void KeyInputHandler2();
void getKeyInput2();
void LongKeyInputHandler2();

#endif /* INC_BUTTON2_H_ */
