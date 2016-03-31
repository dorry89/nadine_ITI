/*
 * Delay.h
 *
 *  Created on: Feb 2, 2016
 *      Author: m.mamdooh
 */

#include "Delay_config.h"
#ifndef DELAY_H_
#define DELAY_H_
#define DELAY(Copy_u8DelayVal)  do{ \
							u32 Local_u32Duration;\
							for(Local_u32Duration=0UL;Local_u32Duration<((Copy_u8DelayVal*DELAY_u32SYSCLOCK)/8000UL);Local_u32Duration ++)\
							{__asm__("NOP");}} while(0)
#endif /* DELAY_H_ */
