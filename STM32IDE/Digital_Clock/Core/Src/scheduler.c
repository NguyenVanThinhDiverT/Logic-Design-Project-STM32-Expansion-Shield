/*
 * scheduler.c
 *
 *  Created on: Dec 8, 2022
 *      Author: pc
 */
#include "scheduler.h"
sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;

void SCH_Init(void){
	current_index_task = 0;
}

//int Tick = 10; // 10ms

void SCH_Add_Task ( void (*pFunction)() , uint32_t DELAY, uint32_t PERIOD){
	if(current_index_task < SCH_MAX_TASKS){

		SCH_tasks_G[current_index_task].pTask = pFunction;
		SCH_tasks_G[current_index_task].Delay = DELAY/TICK;
		SCH_tasks_G[current_index_task].Period =  PERIOD/TICK;
		SCH_tasks_G[current_index_task].RunMe = 0;

		SCH_tasks_G[current_index_task].TaskID = current_index_task;


		current_index_task++;
	}
}

void SCH_Update(void){
	for (int i = 0 ; i < current_index_task; i++){
		if (SCH_tasks_G[i].Delay > 0 ){
			SCH_tasks_G[i].Delay--;
		}else{
			SCH_tasks_G[i].Delay =SCH_tasks_G[i].Period;
			SCH_tasks_G[i].RunMe += 1;
		}
	}
}

void SCH_Dispatch_Tasks(void){
	for (int i = 0 ; i < current_index_task; i++){
		if (SCH_tasks_G[i].RunMe > 0 ){
			SCH_tasks_G[i].RunMe--;
			(*SCH_tasks_G[i].pTask)(); // Run the task
			if (SCH_tasks_G[i].Period == 0 ){ // one shot task
				SCH_Delete_Task(i);
			}
		}
	}
}


void SCH_Delete_Task(int index){
	if (index >= current_index_task ){ //

		return;
	}else {
		for (int i = index; i <current_index_task - 1; i++){
			SCH_tasks_G[i].pTask = SCH_tasks_G[i+1].pTask;
			SCH_tasks_G[i].Period = SCH_tasks_G[i+1].Period;
			SCH_tasks_G[i].RunMe = SCH_tasks_G[i+1].RunMe;
			SCH_tasks_G[i].Delay = SCH_tasks_G[i+1].Delay;
		}
		current_index_task--;
	}
}

