/*
 * button.c
 *
 *  Created on: Sep 24, 2022
 *      Author: pc
 */

#include "button.h"

#define NUMBER_OF_BUTTON 	3
int KeyReg0[NUMBER_OF_BUTTON] = {NORMAL_STATE};
int KeyReg1[NUMBER_OF_BUTTON] = {NORMAL_STATE};
int KeyReg2[NUMBER_OF_BUTTON] = {NORMAL_STATE};

int KeyReg3[NUMBER_OF_BUTTON] ={NORMAL_STATE};

int TimeOutForKeyPress[NUMBER_OF_BUTTON] = {100};

int button_flag[NUMBER_OF_BUTTON] = {0};

//int isButton1flag(){
//
//	if (button1_flag == 1){
//		button1_flag = 0;
//		return 1;
//	}
//	return 0;
//}

//int isButtonflag(int index){
//	if (button_flag[index] == 1){
//		button_flag[index] = 0;
//		return 1;
//	}
//	return 0;
//}


//void subKeyProcess(){
//	//if(KeyReg3 == PRESSED_STATE){
//		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//		//button1_flag = 1
//}

void getKeyInput(){
	for (int i = 0; i < NUMBER_OF_BUTTON; i++){
		  KeyReg2[i] = KeyReg1[i];
		  KeyReg1[i] = KeyReg0[i];
		  switch (i){
		  case 0: // read data from Button 1
			  KeyReg0[i] = HAL_GPIO_ReadPin(UP_GPIO_Port, UP_Pin);
			  break;
		  case 1: // read data from Button 2
			  KeyReg0[i] = HAL_GPIO_ReadPin(DOWN_GPIO_Port, DOWN_Pin);
			  break;
		  case 2: // read data from Button 3
			  KeyReg0[i] = HAL_GPIO_ReadPin(MODE_GPIO_Port, MODE_Pin);
//		  case 3: // read data from Button 4
//			  KeyReg0[i] = HAL_GPIO_ReadPin(BUTTON_P_GPIO_Port, BUTTON_P_Pin);
//			  break;
		  default:
			  KeyReg0[i] = NORMAL_STATE;
			  break;
		  }

		  if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg2[i] != KeyReg3[i]){// nhan tha
			  KeyReg3[i] = KeyReg2[i];
			  if (KeyReg3[i] == PRESSED_STATE){
				TimeOutForKeyPress[i] = 5000;
				//subKeyProcess();
				button_flag[i] = 1;
			  }
			}else{ // nhan de
			   TimeOutForKeyPress[i]--;
				if (TimeOutForKeyPress[i] == 0){
				  KeyReg3[i] = NORMAL_STATE;
				}
			}
		  }
	}
}
