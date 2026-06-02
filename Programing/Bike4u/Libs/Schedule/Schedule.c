#include "Schedule.h"

extern volatile uint32_t uwTick;

void Scheduler_RunTask(Task *task){

	if(!task->enable)
		return;

//	Task *prev = task - 1;
//	task->last = prev->last + task->delay_btq;

	if(uwTick - task->last >= task->interval){

		task->last = uwTick;
		task->callback();

	}

}

