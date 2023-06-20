/*
 * scheduler.h
 *
 *  Created on: Dec 8, 2022
 *      Author: pc
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>


//typedef struct {
//    // Pointer to the task (must be a 'void (void)' function)
//	void ( * pTask)(void);
//	// Delay (ticks) until the function will (next) be run
//	uint32_t Delay;
//	// Interval (ticks) between subsequent runs.
//	uint32_t Period;
//	// Incremented (by scheduler) when task is due to execute
//	uint8_t RunMe;
//	//This is a hint to solve the question below.
//	uint32_t TaskID;
//} sTask;
//
//// MUST BE ADJUSTED FOR EACH NEW PROJECT
//#define SCH_MAX_TASKS 			40
//#define	NO_TASK_ID				0
//sTask SCH_tasks_G[SCH_MAX_TASKS];
//#define RETURN_ERROR	0;
//#define RETURN_NORMAL 	1;
//void SCH_Init(void);
//
//unsigned char SCH_Add_Task(void (* pFunction)(), unsigned int DELAY, unsigned int PERIOD);
//
//void SCH_Update(void);
//
//void SCH_Dispatch_Tasks(void);
//
//unsigned char SCH_Delete_Task(const uint8_t TASK_INDEX);
//
//void SCH_Go_To_Sleep();
//
//void SCH_Report_Status(void);
//


typedef struct{
	void (*pTask)(void);
	uint32_t 	Delay;
	uint32_t 	Period;
	uint8_t 	RunMe;

	uint32_t 	TaskID;
}sTasks;

#define SCH_MAX_TASKS 40
#define TICK 			10

void SCH_Init(void);

void SCH_Add_Task ( void (*pFunction)() ,
					uint32_t DELAY,
					uint32_t PERIOD);

void SCH_Update(void);

void SCH_Dispatch_Tasks(void);

void SCH_Delete_Task(int index);

#endif /* INC_SCHEDULER_H_ */
