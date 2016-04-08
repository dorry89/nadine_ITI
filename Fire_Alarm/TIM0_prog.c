/*
 * TIM_prog.c
 *
 *  Created on: Mar 29, 2016
 *      Author: m.mamdooh
 */
#include "type.h"
#include "TIM0_config.h"
#include "TIM0_interface.h"
#include "TIM0_private.h"
#include "DIO_utilites.h"

u32 TIM0_OFCOUNT=0 ;
u32 TIM0_u8TIME_OVFLW = ((256*TIM0_u8PRESCLER)/FCPU) ;
void TIM0_voidInit(void)
{
	TCCR0|=TIM0_u8TCCR0INIT;
}

u8 TIM0_u8ReadTimer(void)
{
	return ((TCNT0*TIM0_u8PRESCLER)/FCPU) ;
}
u32 TIM0_u8ReadOF(void)
{

   if(get_bit(TIFR,TOV0))
   {
	   set_bit(TIFR,TOV0);
	   TIM0_OFCOUNT++ ;
   }

   	//DELAY(100);

return (TIM0_OFCOUNT *TIM0_u8TIME_OVFLW ) ;

}
void TIM0_voiResetTimer(void)
{
	TIM0_OFCOUNT=0 ;
}
