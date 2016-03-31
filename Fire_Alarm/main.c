/*
 * main.c
 *
 *  Created on: Mar 27, 2016
 *      Author: m.mamdooh
 */
#include "type.h"
#include "DIO-interface.h"
#include "ADC_interface.h"
#include "CLCD_interface.h"
#include "BUZ_interface.h"
#include "TSEN_interface.h"
#include "App_config.h"

u16 AdcRead ,OldAdcRead ;
u8  AdcStr[2],CountStr[2];
u8	THR_COUNT, Old_THR_COUNT , THR_FLAG=0;

void Write_LCD(void) ;

void main (void)
{

   AdcRead=0 ;
   OldAdcRead=1 ;
   THR_COUNT= 0 ;
   Old_THR_COUNT= 1 ;


	DIO_voidInit();
	ADC_voidInit();
	CLC_voidInit();
	ADC_voidEnable();
while(1)
	{

		TSEN_u8ReadTSensr(0,&AdcRead);

	    if( AdcRead > (TSEN_u8THRSHOLD - TSEN_u8TOLERANCE) && THR_FLAG==0  )
	    {
	    	BUZ_voidBuzOn();
	    	THR_COUNT++;
	    	THR_FLAG=1 ;

	    	if(THR_COUNT>100)
	    		THR_COUNT=0 ;
	    }
	    else if( AdcRead < (TSEN_u8THRSHOLD - TSEN_u8TOLERANCE)  )
	    {
	    	BUZ_voidBuzOff();
	    	THR_FLAG=0;
	    }



	    if(THR_COUNT != Old_THR_COUNT || AdcRead != OldAdcRead)
	    {
	    	 Write_LCD();
	    }
	}
}

void Write_LCD(void)
{
	//CLCD_u8WriteComand( CLC_u8CLRDISP);
	CLCD_u8WriteComand(CLC_u8STL);

	if(AdcRead<10)
	{
		itoa(AdcRead,AdcStr,10) ;
		CLCD_u8WriteDataStr("TEMP: ");
		CLCD_u8WriteDataStr("0");
	    CLCD_u8WriteDataStr(AdcStr) ;

	}
	else
	{
		itoa(AdcRead,AdcStr,10) ;
		CLCD_u8WriteDataStr("TEMP: ");
		    CLCD_u8WriteDataStr(AdcStr) ;
	}


	CLCD_u8WriteComand(CLC_u8NEWL );

	itoa(THR_COUNT,CountStr,10);
	CLCD_u8WriteDataStr("COUNT: ");
	CLCD_u8WriteDataStr(CountStr);


	OldAdcRead = AdcRead ;
	Old_THR_COUNT=THR_COUNT ;
}
//if(local_u8AdcRead<10)
//{
//	itoa(local_u8AdcRead,local_u8AdcStr,10) ;
//	CLCD_u8WriteDataStr("0");
//    CLCD_u8WriteDataStr(local_u8AdcStr) ;
//
//}
//else
//{
//	itoa(local_u8AdcRead,local_u8AdcStr,10) ;
//	    CLCD_u8WriteDataStr(local_u8AdcStr) ;
//}
