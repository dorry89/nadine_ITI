/*
 * ADCprog.c
 *
 *  Created on: Mar 8, 2016
 *      Author: m.mamdooh
 */
#include "type.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "DIO_utilites.h"

static const u8 CHKERR[2]={error,ok};
extern void ADC_voidInit(void)
{
	ADC_ADMUX = ADC_ADMUX_VAL;
	ADC_ADCSRA= ADC_ADCSRA_VAL ;
	ADC_ADCH=ADC_ADCH_VAL;
	ADC_ADCL=ADC_ADCL_VAL;
	ADC_SFIOR|=ADC_SFIOR_VAL  ;

}

extern void ADC_voidEnable(void)
{
	ADC_ADCSRA|=(1<<ADEN);
}

extern void ADC_voidDisable(void)
{
	ADC_ADCSRA&=~(1<<ADEN);
}

extern u8 ADC_u8ReadCh_SSht(u8 Copy_ChIdx , u16 * Copy_PtrToVal)
{

	*Copy_PtrToVal=0 ;

	ADC_ADMUX|=(0x1F & Copy_ChIdx) ;
	ADC_ADCSRA|=(1<<ADSC);

	while(ADC_ADCSRA&(1<<ADSC)) ;

switch 	(ADC_RES)
{
case ADC_LOWRES :
		if(ADC_ADLAR_INITVAL==0)
		{
		* Copy_PtrToVal = ADC_ADCL  ;
		* Copy_PtrToVal >>=2  ;
		* Copy_PtrToVal |=(ADC_ADCH<<6) ;
		}
		else
		{
			* Copy_PtrToVal = ADC_ADCH  ;
		}
	break ;
case ADC_HIGHRES :
		if(ADC_ADLAR_INITVAL==0)
		{
			* Copy_PtrToVal = ADC_ADCL  ;
			* Copy_PtrToVal |= ( ADC_ADCH<<8) ;
		}
		else
		{
			* Copy_PtrToVal = ADC_ADCL ;
			* Copy_PtrToVal>>=6 ;
			* Copy_PtrToVal |= (ADC_ADCH<<2) ;
		}
	break ;

default :
	break ;
}
return CHKERR[Copy_ChIdx < 8];
}

extern u8 ADC_u8ReadCh_MSht(u8 Copy_ChIdx , u16 * Copy_PtrToVal)
{

	u8 local_u8ount=0;
	u16 local_u16avg=0 ;
	u16 local_u16sum=0 ;
	 * Copy_PtrToVal=0;
	 ADC_ADMUX|=(0x1F & Copy_ChIdx) ;
for(local_u8ount=0 ;local_u8ount<8;local_u8ount++)
{

	ADC_ADCSRA|=(1<<ADSC);

	while(ADC_ADCSRA&(1<<ADSC)) ;


switch 	(ADC_RES)
{
case ADC_LOWRES :
		if(ADC_ADLAR_INITVAL==0)
		{
			local_u16avg = ADC_ADCL  ;
			local_u16avg >>=2  ;
			local_u16avg |=(ADC_ADCH<<6) ;
		}
		else
		{
			local_u16avg = ADC_ADCH  ;
		}
	break ;
case ADC_HIGHRES :
		if(ADC_ADLAR_INITVAL==0)
		{
			local_u16avg = ADC_ADCL ;
			local_u16avg|= ( ADC_ADCH <<8) ;

		}
		else
		{
			local_u16avg = ADC_ADCL ;
			local_u16avg>>=6 ;
			local_u16avg= (ADC_ADCH<<2) ;
		}
	break ;

default :
	break ;
}
	local_u16sum+=local_u16avg ;

}
* Copy_PtrToVal =  local_u16sum /8 ;
return CHKERR[Copy_ChIdx < 8];
}

extern u8 ADC_u8ReadGp( u8 * Copy_IdxArr, u16 * Copy_PtrToVal)
{
	u8 local_u8count ;
	 * Copy_PtrToVal=0;

for(local_u8count=0;local_u8count<4;local_u8count++)
{
		ADC_ADMUX|=(0x1F & Copy_IdxArr[local_u8count]) ;
		ADC_ADCSRA|=(1<<ADSC);

		while(ADC_ADCSRA&(1<<ADSC)) ;


	switch 	(ADC_RES)
	{
	case ADC_LOWRES :
			if(ADC_ADLAR_INITVAL==0)
			{
				* Copy_PtrToVal = ADC_ADCL  ;
				* Copy_PtrToVal >>=2  ;
				* Copy_PtrToVal |=(ADC_ADCH<<6) ;
			}
			else
			{
				* Copy_PtrToVal = ADC_ADCH  ;
			}
		break ;
	case ADC_HIGHRES :
			if(ADC_ADLAR_INITVAL==0)
			{
				* Copy_PtrToVal = ADC_ADCL ;
				* Copy_PtrToVal |= ( ADC_ADCH<<8) ;
			}
			else
			{
				* Copy_PtrToVal = ADC_ADCL ;
				* Copy_PtrToVal>>=6 ;
				* Copy_PtrToVal |= (ADC_ADCH<<2) ;
			}
		break ;

	default :
		break ;
	}
}
	return CHKERR[Copy_IdxArr[0] < 8 && Copy_IdxArr[1] < 8 && Copy_IdxArr[2] < 8 && Copy_IdxArr[3] < 8 ];
}
