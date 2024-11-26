/*
 * scheduler.h
 *
 *  Created on: Nov 26, 2024
 *      Author: dangq
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#define SCH_MAX_TASKS 40

#include "main.h"
#include <stdint.h>

typedef struct {
	 // Pointer to the task (must be a ’void (void) ’ function)
	 void ( * pTask)(void) ;
	 // Delay (ticks) until the function will (next) be run
	 uint32_t Delay;
	 // Interval (ticks) between subsequent runs.
	 uint32_t Period;
	 // Incremented (by scheduler) when task is due to execute
	 uint8_t RunMe;
	 //This is a hint to solve the question below.
	 uint32_t TaskID;
} sTask;


void SCH_Init(void);
void SCH_ADD_TASK(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD); //setTimer
void SCH_Update(void); //Timer_run
void SCH_Dispatch_Tasks(void);  //Timer_flag
void SCH_Delete_Task (uint32_t TASK_INDEX);

void SCH_Report_Status(void);
void SCH_Go_To_Sleep(void);
void Timer_init(void);
void Watchdog_init(void);
#endif /* INC_SCHEDULER_H_ */
