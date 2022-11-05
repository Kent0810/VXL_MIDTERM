/*
 * button1.h
 *
 *  Created on: Nov 3, 2022
 *      Author: Admin
 */

#ifndef INC_BUTTON1_H_
#define INC_BUTTON1_H_
#include "global.h"

#define NORMAL_STATE 	GPIO_PIN_SET //-> 0 Nhan
#define PRESSED_STATE 	GPIO_PIN_RESET // -> Nhan

extern int isButton1Clicked;

//function prototype
void KeyInputHandler1();
void getKeyInput1();
void LongKeyInputHandler1();

#endif /* INC_BUTTON1_H_ */
