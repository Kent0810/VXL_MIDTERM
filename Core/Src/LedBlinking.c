/*
 * fsm_run2.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */

#include <LedBlinking.h>
void LedBlinking(){
	if(timer1_flag == 1){
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		setTimer1(1000);
	}
}
