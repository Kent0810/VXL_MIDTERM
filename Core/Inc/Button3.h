/*
 * Button3.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */

#ifndef INC_BUTTON3_H_
#define INC_BUTTON3_H_

#include "global.h"
#define NORMAL_STATE 	GPIO_PIN_SET //-> 0 Nhan
#define PRESSED_STATE 	GPIO_PIN_RESET // -> Nhan

extern int isButton3Clicked;
extern int isButton3LongClicked;
//function prototype
void KeyInputHandler3();
void getKeyInput3();
void LongKeyInputHandler3();


#endif /* INC_BUTTON3_H_ */
