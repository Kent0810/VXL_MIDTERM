/*
 * global.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <LedBlinking.h>
#include "main.h"
#include "software_timer.h"
#include "fsm_run1.h"
extern int status1;
extern int counter;
#define INIT 		0
#define WAIT		1
#define RES			2
#define INC			3
#define DEC			4
#define LONG_INC	5
#define	LONG_DEC	6
#define COUNT_DOWN	7
#endif /* INC_GLOBAL_H_ */
