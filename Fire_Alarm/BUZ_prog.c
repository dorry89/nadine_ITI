/*
 * BUZ_prog.c
 *
 *  Created on: Mar 27, 2016
 *      Author: m.mamdooh
 */
#include "DIO-interface.h"
#include "BUZ_interface.h"
#include "BUZ_config.h"
void BUZ_voidBuzOn(void)
{
	DIO_u8WritePinVal(BUZZ_u8BUZZPIN,DIO_u8HIGH) ;
}
void BUZ_voidBuzOff(void)
{
	DIO_u8WritePinVal(BUZZ_u8BUZZPIN,DIO_u8LOW) ;
}
