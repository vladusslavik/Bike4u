#pragma once

#ifndef 	SCHEDULER
#define 	SCHEDULER

#include "main.h"

#include "stdint.h"


typedef struct{
	uint32_t interval;
	uint32_t last;
	void (*callback)(void);
	uint8_t enable;
} Task;

void Scheduler_RunTask(Task *task);

extern const uint8_t TASK_COUNT;
extern Task regular[];

#endif

// Example	----------------------------------------------------------*/

//Task tasks[];

/* Schedule 		---------------------------------------------------------- */
/*
#define 	DELAY_LIST	200

void Task_List_Freq_3G3(){
	List_Freq_3G3();
}

Task tasks[] = {
	{DELAY_LIST, 0, Task_List_Freq_3G3, 1},
};

#define TASK_COUNT 		(sizeof(tasks)/sizeof(tasks[0]))

void main(){
  for (uint8_t i = 0; i < TASK_COUNT; i++)
	          Scheduler_RunTask(&tasks[i]);

}

*/
/* Schedule 		----------------------------------------------------------*/


// Example	----------------------------------------------------------*/
