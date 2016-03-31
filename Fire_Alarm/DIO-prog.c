/*
 * DIO-prog.c
 *
 *  Created on: Jan 27, 2016
 *      Author: m.mamdooh
 */
#include "type.h"
#include"DIO-config.h"
#include"DIO-private.h"
#include"DIO-interface.h"
#include "DIO_utilites.h"

static  u8 *const  DIO_u8Ports[]={DIO_u8PORTA ,DIO_u8PORTB, DIO_u8PORTC , DIO_u8PORTD} ;
static  u8 * const DIO_u8Ddrs[]={DIO_u8DDRA ,DIO_u8DDRB, DIO_u8DDRC , DIO_u8DDRD} ;
static  u8 *const DIO_u8Pins[]={DIO_u8PINA ,DIO_u8PINB, DIO_u8PINC , DIO_u8PIND} ;


extern void DIO_voidInit(void)
{

/*Comment!:initializing Ports Directions */
*DIO_u8Ddrs[DIO_u8PORT0]=DIO_u8PORTA_DIR;
*DIO_u8Ddrs[DIO_u8PORT1]=DIO_u8PORTB_DIR;
*DIO_u8Ddrs[DIO_u8PORT2]=DIO_u8PORTC_DIR;
*DIO_u8Ddrs[DIO_u8PORT3]=DIO_u8PORTD_DIR;

/*Comment!:initializing Ports Value  */
*DIO_u8Ports[DIO_u8PORT0] =(DIO_u8PORTA_DIR & DIO_u8PORTA_VAL) | ((~DIO_u8PORTA_DIR)&*DIO_u8Ports[DIO_u8PORT0] );
*DIO_u8Ports[DIO_u8PORT1] =(DIO_u8PORTB_DIR & DIO_u8PORTB_VAL)| ((~DIO_u8PORTB_DIR)&*DIO_u8Ports[DIO_u8PORT1] );
*DIO_u8Ports[DIO_u8PORT2] =(DIO_u8PORTC_DIR & DIO_u8PORTC_VAL)| ((~DIO_u8PORTC_DIR)&*DIO_u8Ports[DIO_u8PORT2] );
*DIO_u8Ports[DIO_u8PORT3] =(DIO_u8PORTD_DIR & DIO_u8PORTD_VAL)| ((~DIO_u8PORTD_DIR)&*DIO_u8Ports[DIO_u8PORT3] );

}


extern u8 DIO_u8ReadPinVal(u8 Copy_u8PinIdx,u8* Copy_u8PtrToval)
{

	 u8 Local_u8CheckPinState=ok ;
	if(Copy_u8PinIdx<DIO_u8PINMAXIDX)
	    {

		u8 local_u8CheckPinPlace=Copy_u8PinIdx/PINNUMS ;
		u8 local_u8MapPin=Copy_u8PinIdx%PINNUMS ;

		* Copy_u8PtrToval=get_bit(*DIO_u8Pins[local_u8CheckPinPlace],local_u8MapPin);

    }
    else
    {

    }
return    Local_u8CheckPinState=ok ;
}

extern u8 DIO_u8WritePinVal(u8 Copy_u8PinIdx,u8 Copy_u8Pinval)
{
	 u8 Local_u8CheckPinState=ok ;

	    if(Copy_u8PinIdx>DIO_u8PINMAXIDX)
	    {
	    	 Local_u8CheckPinState=error ;
	    }
	    else
	    {
	    	 u8 local_u8CheckPinPlace=Copy_u8PinIdx/PINNUMS ;
	    		 u8 local_u8MapPin=Copy_u8PinIdx%PINNUMS ;
	    	     u8 local_u8PinDir;
	    	     local_u8PinDir=get_bit(*DIO_u8Ddrs[local_u8CheckPinPlace],local_u8MapPin);
	    	if(local_u8PinDir==1)
	    	{
	    	assign_bit(*DIO_u8Ports[local_u8CheckPinPlace],local_u8MapPin,Copy_u8Pinval);
	    	}
	    	else
	    	{

	    	}
	    }

     return  Local_u8CheckPinState ;
}


extern u8 DIO_u8ReadPortVal(u8 Copy_u8PortIdx,u8* Copy_u8PtrToval)
{
	u8 Local_u8CheckPortR=ok ;

	if(Copy_u8PortIdx<=DIO_u8PORTMAXIDX)
	{

	* Copy_u8PtrToval=*DIO_u8Pins[Copy_u8PortIdx] ;
	}
	else
	{
		Local_u8CheckPortR=error ;
	}

	return Local_u8CheckPortR ;
}

extern u8 DIO_u8WritePortVal(u8 Copy_u8PortIdx,u8 Copy_u8Portval)
{
     	u8 Local_u8CheckPortR=ok ;
        u8 local_u8PortDir;
		if(Copy_u8PortIdx<=DIO_u8PORTMAXIDX)
		{
				local_u8PortDir=*DIO_u8Ddrs[Copy_u8PortIdx] ;
			  if(local_u8PortDir==0xff)
			  {
		        *DIO_u8Ports[Copy_u8PortIdx]= Copy_u8Portval;
			  }
			  else
			  {

			  }
		}
		else
		{
			Local_u8CheckPortR=error ;
		}

		return Local_u8CheckPortR ;
}

extern u8 DIO_u8WritePinDir(u8 Copy_u8PinIdx,u8 Copy_u8PinDir)
{
	     u8 Local_u8CheckPinState=ok ;

		    if(Copy_u8PinIdx>DIO_u8PINMAXIDX)
		    {
		    	 Local_u8CheckPinState=error ;
		    }
		    else
		    {
		    	u8 local_u8CheckPinPlace=Copy_u8PinIdx/PINNUMS ;
		    	u8 local_u8MapPin=Copy_u8PinIdx%PINNUMS ;
		    	assign_bit(* DIO_u8Ddrs[local_u8CheckPinPlace],local_u8MapPin,Copy_u8PinDir);
		    }

	     return  Local_u8CheckPinState ;
}

extern u8 DIO_u8WritePortDir(u8 Copy_u8PortIdx,u8 Copy_u8PortDir)
{

	u8 Local_u8CheckPortR=ok ;

			if(Copy_u8PortIdx<=DIO_u8PORTMAXIDX)
			{

			*DIO_u8Ddrs[Copy_u8PortIdx]= Copy_u8PortDir;
			}
			else
			{
				Local_u8CheckPortR=error ;
			}

			return Local_u8CheckPortR ;
}

extern u8 DIO_u8ReadPinDir(u8 Copy_u8PinIdx,u8 * Copy_u8PtrToDir)
{
	 u8 Local_u8CheckPinState=ok ;


	    if(Copy_u8PinIdx>DIO_u8PINMAXIDX)
	    {
	    	 Local_u8CheckPinState=error ;
	    }
	    else
	    {
	    	u8 local_u8CheckPinPlace=Copy_u8PinIdx/PINNUMS;
	    		 u8 local_u8MapPin=Copy_u8PinIdx%PINNUMS ;
	    	* Copy_u8PtrToDir=get_bit(*DIO_u8Ddrs[local_u8CheckPinPlace],local_u8MapPin);
	    }
	return  Local_u8CheckPinState ;
}

extern u8 DIO_u8ReadPortDir(u8 Copy_u8PortIdx,u8 *Copy_u8PtrToDir)
{
	u8 Local_u8CheckPortR=ok ;

		if(Copy_u8PortIdx<=DIO_u8PORTMAXIDX)
		{

		* Copy_u8PtrToDir=*DIO_u8Pins[Copy_u8PortIdx] ;
		}
		else
		{
			Local_u8CheckPortR=error ;
		}

		return Local_u8CheckPortR ;
}
