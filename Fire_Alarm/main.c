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
#include "TIM0_interface.h"
u16 AdcRead=0 ,OldAdcRead=1 ;
u8  AdcStr[2],CountStr[2];
u8	THR_COUNT=0, Old_THR_COUNT=1 , THR_FLAG=0;
u8  ADC= 1 ;
void Write_LCD(void) ;

void main (void)
{

//   AdcRead=0 ;
  OldAdcRead=1 ;
//   THR_COUNT= 0 ;

u32 TimeRead=0;

	DIO_voidInit();
	ADC_voidInit();
	TIM0_voidInit();
	CLC_voidInit();
	ADC_voidEnable();
	CLCD_u8WriteComand(CLC_u8CLRDISP);
while(1)
	{

		TSEN_u8ReadTSensr(0,&AdcRead);
		TimeRead=TIM0_u8ReadOF();

	    if( AdcRead > (TSEN_u8THRSHOLD - TSEN_u8TOLERANCE) && THR_FLAG==0  )
	    {

	    	THR_COUNT++;
	    	THR_FLAG=1 ;

	    	if(THR_COUNT>100)
	    		THR_COUNT=0 ;
	    }

	   else if( AdcRead < ((TSEN_u8THRSHOLD - TSEN_u8TOLERANCE)-4)  )
	    {
	    	BUZ_voidBuzOff();
	    	THR_FLAG=0 ;

	    }

	    if(OldAdcRead-AdcRead>2)
	    	ADC= AdcRead ;

	    if(THR_FLAG==1)
	    {
	    	BUZ_voidBuzOn();
	    }

	    if(TimeRead>1000 )
	    {
	    	 Write_LCD();
	    	 OldAdcRead=AdcRead;
	    	TIM0_voiResetTimer();
	    }
	}
}

void Write_LCD(void)
{

	CLCD_u8WriteComand(CLC_u8STL);

	if(AdcRead<10)
	{
		itoa(ADC,AdcStr,10) ;
		CLCD_u8WriteDataStr("TEMP: ");
		CLCD_u8WriteDataStr("0");
	    CLCD_u8WriteDataStr(AdcStr) ;

	}
	else
	{
		itoa(ADC,AdcStr,10) ;
		CLCD_u8WriteDataStr("TEMP: ");
		CLCD_u8WriteDataStr(AdcStr) ;
	}


	CLCD_u8WriteComand(CLC_u8NEWL );

	itoa(THR_COUNT,CountStr,10);
	CLCD_u8WriteDataStr("COUNT: ");
	CLCD_u8WriteDataStr(CountStr);

}
