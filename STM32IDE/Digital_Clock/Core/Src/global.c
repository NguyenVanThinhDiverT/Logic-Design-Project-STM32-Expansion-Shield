/*
 * global.c
 *
 *  Created on: Sep 30, 2022
 *      Author: pc
 */
# include "global.h"
//# include "main.h"
int status_mode = 0;
int status_ver = 0;
int status_hor = 0;
int status_led7seg = 0;
int status_pedes = 0;

int index_led = 0;
int status_display = 0;
int num_led = 0;
int but1 = 0;
int but2 = 1;
int but3 = 2;
int butp = 3;

int timered = 5;
int timegreen = 3;
int timeyellow = 2;

int led12 = 5;
int led34 = 3;

int timeTimer(int time){
	return time * 1000;
}
