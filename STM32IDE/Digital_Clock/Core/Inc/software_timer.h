/*
 * _SOFTWARE_TIMER_.h
 *
 *  Created on: Sep 24, 2022
 *      Author: pc
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_
extern int timer0_flag;
extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;
extern int timer4_flag;
extern int timer5_flag;
extern int timer6_flag;

void clearTimer0();
void clearTimer1();
void clearTimer2();
void clearTimer3();
void clearTimer4();
void clearTimer5();
void clearTimer6();

void setTimer0(int duration);
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);
void setTimer5(int duration);
void setTimer6(int duration);

int isTimerFlag0();
int isTimerFlag1();
int isTimerFlag2();
int isTimerFlag3();
int isTimerFlag4();
int isTimerFlag5();
int isTimerFlag6();
//void clearTimer1();

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
