/*
 * fsm_display.c
 *
 *  Created on: Jun 8, 2023
 *      Author: WELCOME
 */


#include "fsm_display.h"

/* Define -----*/
//State of 7SEG display fsm
#define INIT 0
#define EN0 1
#define EN1 2
#define EN2 3
#define EN3 4
#define EN4 5
#define EN5 6
#define EN6 7
#define EN7 8
#define EN8 9
#define EN9 10
#define EN10 11
#define EN11 12

//state for blink LED fsm
#define LED_ON 1
#define LED_OFF 2
//Time
//#define SCANNING_TIME 250
//#define BLINK_TIME 500

/* Init ------*/
//int status_display = INIT;'
//int status_display = INIT;
int status_blink = INIT;
//int num_led = 0;
/* Function -----*/
//Set restart 7SEG display
void restartDisplay(int num_led) {
  status_display = num_led;
}
//7SEG LED display
void fsm_display(void) {
  switch(status_display) {
  case INIT:
		  display_analog_clock(num_led);
		  status_display = EN0;
		  setTimer1(1000);
		  break;
  case EN0:
	  if(isTimerFlag1() == 1)
	  {

//		  display_analog_clock(0);
		  num_led++;
		  display_analog_clock(num_led);
		  setTimer1(1000);
		  status_display = EN1;
	  }

//	    status_display = EN0;

    break;
  case EN1:
	  if(isTimerFlag1() == 1)
	  {

//		  display_analog_clock(0);
//		  display_analog_clock(1);
		  num_led++;
		  display_analog_clock(num_led);
		   setTimer1(1000);
			  status_display = EN2;
	  }

//	    status_display = EN0;

    break;
  case EN2:
	  if(isTimerFlag1() == 1)
	  {
		  num_led++;
		  status_display = EN3;
		  display_analog_clock(num_led);
		   setTimer1(1000);
	  }

  case EN3:
	  if(isTimerFlag1() == 1)
	  {
		  num_led++;
		  status_display = EN4;
		  display_analog_clock(num_led);
		   setTimer1(1000);
	  }
    break;
  case EN4:
	  if(isTimerFlag1() == 1)
	  {
		  num_led++;
		  status_display = EN5;
		  display_analog_clock(num_led);
		   setTimer1(1000);
	  }
    break;
  case EN5:
	  if(isTimerFlag1() == 1)
	  {
		  num_led++;
		  status_display = EN6;
		  display_analog_clock(num_led);
		   setTimer1(1000);
	  }
    break;
  case EN6:
	  if(isTimerFlag1() == 1)
	  {
		  num_led++;
		  status_display = EN7;
		  display_analog_clock(num_led);
		   setTimer1(1000);
	  }
    break;
  case EN7:
	  if(isTimerFlag1() == 1)
	  {
		  num_led++;
		  status_display = EN8;
		  display_analog_clock(num_led);
		   setTimer1(1000);
	  }
    break;
  case EN8:
	  if(isTimerFlag1() == 1)
	  {
		  num_led++;
		  status_display = EN9;
		  display_analog_clock(num_led);
		   setTimer1(1000);
	  }
    break;
  case EN9:
	  if(isTimerFlag1() == 1)
	  {
		  num_led++;
		  status_display = EN10;
		  display_analog_clock(num_led);
		   setTimer1(1000);
	  }
    break;
  case EN10:
	  if(isTimerFlag1() == 1)
	  {
		  num_led++;
		  status_display = EN11;
		  display_analog_clock(num_led);
//		  if(num_led > 11){
//			  num_led = 0;
//		  }

		   setTimer1(1000);
	  }
    break;
  case EN11:
	  if(isTimerFlag1() == 1)
	  {
		  num_led++;
		  display_analog_clock(num_led);
		  if(num_led > 11){
			  num_led = 0;
			  restartDisplay(num_led);
		  }

//		  status_display = INIT;

		   setTimer1(1000);
	  }
    break;
  default:
//	  onAllClock();
	  break;
  }
}


