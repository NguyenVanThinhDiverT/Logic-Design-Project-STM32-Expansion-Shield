/*
 * button.h
 *
 *  Created on: Dec 15, 2022
 *      Author: pc
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "global.h"
//#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

//extern int button1_flag;
//int isButton1flag();
//int isButtonflag(int index);

void getKeyInput();



#endif /* INC_BUTTON_H_ */
