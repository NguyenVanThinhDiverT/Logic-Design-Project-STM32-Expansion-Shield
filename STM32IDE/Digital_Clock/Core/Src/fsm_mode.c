/*
 * FSM_AUTOMATIC.c
 *
 *  Created on: Sep 30, 2022
 *      Author: pc
 */

#include <fsm_mode.h>

void fsm_mode_run(){

	switch (status_mode){
	case INIT:
		fsm_display();

		if (isButtonflag(but3) == 1){
			display_analog_clock(num_led);
			status_mode = MODE1;
			clearTimer1();
			clearTimer2();
			clearTimer3();
//
//
			setTimer2(10000);
		}
//		status_display = num_led;

		break;
	case MODE1:


		if (isButtonflag(but1) == 1){
			num_led++;
			if(num_led > 11){
				num_led = 0;
			}
			display_analog_clock(num_led);


			clearTimer1();
			clearTimer2();
//			clearTimer3();
//			status_mode = MODE2;


			setTimer2(10000);

		}
		if (isButtonflag(but2) == 1){
			num_led--;
			if(num_led < 0){
				num_led = 11;
			}
			display_analog_clock(num_led);
//			status_mode = MODE2;

			clearTimer1();
			clearTimer2();
//			clearTimer3();
			//


		    setTimer2(10000);



		}
		if(isButtonflag(but3) == 1){
			restartDisplay(num_led--);
			status_mode = INIT;
		}
		if(isTimerFlag2()== 1){
			restartDisplay(num_led);
			status_mode = INIT;
		}
//		status_display = num_led;

		break;





	default:
		clearAllClock();
		break;
	}


}


