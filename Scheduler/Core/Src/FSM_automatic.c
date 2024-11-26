/*
 * FSM_automatic.c
 *
 *  Created on: Nov 27, 2024
 *      Author: dangq
 */

#include "fsm_automatic.h"


void fsm_automatic(){
	if(mode == MODE1){
		switch (status){
			case NO_LED:
				status = RED_GREEN;
				break;
			case RED_GREEN:
		//		display7SEG_TFL();
				displayTFL();
				counter++;
				if(counter >= GREEN_TIME){
					status = RED_YELLOW;
					counter =0;
				}
				break;
			case RED_YELLOW:
		//		display7SEG_TFL();
				displayTFL();
				counter++;
				if(counter >= YELLOW_TIME){
					status = GREEN_RED;
					counter =0;
				}
				break;
			case GREEN_RED:
		//		display7SEG_TFL();
				displayTFL();
				counter++;
				if(counter >= GREEN_TIME){
					status = YELLOW_RED;
					counter =0;
				}
				break;
			case YELLOW_RED:
		//		display7SEG_TFL();
				displayTFL();
				counter++;
				if(counter >= YELLOW_TIME){
					status = RED_GREEN;
					counter =0;
				}
				break;
			default:
				break;

			}
	}

}

