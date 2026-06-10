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

#define DELAY_BATTERY_MEASURE	1000
#define	DELAY_SET_BRGT			100
#define DELAY_SLEEP				100
#define DELAY_DIMMER_TIM		50

void Task_Battery_Measeru(){
	Battery_Measeru();
}
void Task_Set_Brightness(void){
	Set_Brightness();
}
void Task_Sleep(){
	Sleep();
}
void Task_DIMMER_TIM(){
	DIMMER_TIM();
}

Task regular[] = {
		{DELAY_BATTERY_MEASURE, 0, Task_Battery_Measeru, 1},	//***0***
		{DELAY_SET_BRGT, 0, Task_Set_Brightness, 1},			//***1***
		{DELAY_SLEEP, 0, Task_Sleep, 1},						//***2***
		{DELAY_DIMMER_TIM, 0, Task_DIMMER_TIM, 0}				//***3***
	};

//#define TASK_COUNT 		(sizeof(regular)/sizeof(regular[0]))
const uint8_t TASK_COUNT = (sizeof(regular) / sizeof(regular[0]));
