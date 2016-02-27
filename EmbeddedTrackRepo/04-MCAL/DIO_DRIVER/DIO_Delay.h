/*
 * DIO_delay.h
 *
 *  Created on: Feb 2, 2016
 *      Author: seif
 */

#ifndef DIO_DELAY_H_
#define DIO_DELAY_H_
#include "DIO_delayConfig.h"


/* Comment!: delay function */
#define DELAY_MS(x) do{for(u32 Local_u8DelayCount = (DELAY_u32SYSCLK*125UL*x); Local_u8DelayCount >0; Local_u8DelayCount--){__asm("NOP");}}while(0)

#endif /* DIO_DELAY_H_ */
