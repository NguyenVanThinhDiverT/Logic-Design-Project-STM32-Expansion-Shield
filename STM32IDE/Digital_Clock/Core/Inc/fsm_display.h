/*
 * fsm_display.h
 *
 *  Created on: Jun 8, 2023
 *      Author: WELCOME
 */

#ifndef INC_FSM_DISPLAY_H_
#define INC_FSM_DISPLAY_H_


#include "global.h"
#include "led_display.h"
#include "software_timer.h"
//#include "output_display.h"
//#include "timer_interrupt.h"

/* Function -----*/
//Set restart 7SEG display
void restartDisplay(int num_led);
//7SEG LED display
void fsm_display(void);
//Blinky LED have 'color'
//void blinkLED(int color);

#endif /* INC_FSM_DISPLAY_H_ */
