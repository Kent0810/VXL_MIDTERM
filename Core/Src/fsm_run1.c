/*
 * fsm_run1.c
 *
 *  Created on: Nov 5, 2722
 *      Author: Admin
 */
#include "fsm_run1.h"
#include "Button1.h"
#include "Button2.h"
#include "Button3.h"

void display7SegLed(int number){
	switch (number){
		case 0:
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
			HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
			HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
			HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
			HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
			HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, SET);
			HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, SET);
			HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, SET);
			HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, SET);
			HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
			HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
			HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, SET);
			HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
			HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
			HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, SET);
			HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, SET);
			HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, SET);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
			HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, SET);
			HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, SET);
			HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
			HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, SET);
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
			HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
			HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, SET);
			HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
			HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, SET);
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
			HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
			HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
			HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
			HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
			HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, SET);
			HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, SET);
			HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, SET);
			HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, SET);
			break;
		case 8:
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
			HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
			HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, RESET);
			HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
			HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, RESET);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, RESET);
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, RESET);
			HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, RESET);
			HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, SET);
			HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, RESET);
			HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, RESET);
			break;
		default:
			break;
		}
}

void fsm_run1(){
	display7SegLed(counter);
	switch (status1){
	case INIT:
		status1 = WAIT;
		setTimer2(10000);//COUNT DOWN
		setTimer3(1000); //COUNT DOWN SPEED
		break;
	case WAIT:
		if(isButton1Clicked == 1){
			status1 = RES;
			isButton1Clicked = 0;
		}
		if(isButton2Clicked == 1){
			status1 = INC;
			isButton2Clicked = 0;
		}
		if(isButton3Clicked == 1){
			status1 = DEC;
			isButton3Clicked = 0;
		}
		if(isButton2LongClicked == 1){
			status1 = LONG_INC;
			isButton2LongClicked = 0;
		}
		if(isButton3LongClicked == 1){
			status1 = LONG_DEC;
			isButton3LongClicked = 0;
		}
		if(timer2_flag == 1){
			timer2_flag = 0;
			status1 = COUNT_DOWN;
		}
		break;
	case RES:
		setTimer2(10000);
		counter = 0;
		status1 = WAIT;
		break;
	case INC:
		setTimer2(10000);
		counter++;
		if(counter > 9){
			counter = 0;
		}
		status1 = WAIT;
		break;
	case DEC:
		setTimer2(10000);
		counter--;
		if(counter < 0){
			counter = 9;
		}

		status1 = WAIT;
		break;
	case LONG_INC:
		setTimer2(10000);
		counter++;
		if(counter > 9){
			counter = 0;
		}
		status1 = WAIT;
		break;
	case LONG_DEC:
		setTimer2(10000);
		counter--;
		if(counter < 0){
			counter = 9;
		}
		status1 = WAIT;
		break;
	case COUNT_DOWN:
		if(isButton1Clicked == 1){
					status1 = RES;
					isButton1Clicked = 0;
				}
				if(isButton2Clicked == 1){
					status1 = INC;
					isButton2Clicked = 0;
				}
				if(isButton3Clicked == 1){
					status1 = DEC;
					isButton3Clicked = 0;
				}
				if(isButton2LongClicked == 1){
					status1 = LONG_INC;
					isButton2LongClicked = 0;
				}
				if(isButton3LongClicked == 1){
					status1 = LONG_DEC;
					isButton3LongClicked = 0;
				}
		if(timer3_flag == 1){
			setTimer3(1000);
			counter--;
			display7SegLed(counter);
		}
		if(counter == 0){
			status1 = WAIT;
			break;
		}
		break;
	default:
		break;
	}
}

