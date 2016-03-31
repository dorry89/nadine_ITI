/*
 * CLCD.c
 *
 *  Created on: Mar 9, 2016
 *      Author: m.mamdooh
 */
#include "DIO-interface.h"
#include "CLCD_config.h"
#include "DELAY.h"
#include "CLCD_interface.h"
#include "DIO_utilites.h"
#include "CLCD_private.h"
const u8  CLC_u8DataArr[8]={CLC_u8D0,CLC_u8D1,CLC_u8D2,CLC_u8D3,CLC_u8D4,CLC_u8D5,CLC_u8D6,CLC_u8D7};
const u8 CHKerr[2]={error,ok};
void CLC_voidInit(void)
{

	DELAY(20);
	CLCD_u8WriteComand(0b00110000);

	DELAY(5);
	CLCD_u8WriteComand(0b00110000);

	DELAY(1);
	CLCD_u8WriteComand(0b00110000);


	CLCD_u8WriteComand(0b00111000);


	CLCD_u8WriteComand(0b00000110);

	CLCD_u8WriteComand(0b00001100);

	DELAY(1);

	CLCD_u8WriteComand(CLC_u8FUNCSET);
}

extern u8 CLCD_u8WriteComand(u8 Copy_u8Command)
{
	u8 local_loopcount ;
	for(local_loopcount=0 ; local_loopcount<8;local_loopcount++)
	{
		DIO_u8WritePinVal(CLC_u8DataArr[local_loopcount],get_bit(Copy_u8Command,local_loopcount));
	}
	DIO_u8WritePinVal(CLC_u8RS, DIO_u8LOW);
	DIO_u8WritePinVal(CLC_u8RW, DIO_u8LOW);
	DIO_u8WritePinVal(CLC_u8EN, DIO_u8HIGH);
	DELAY(1);
	DIO_u8WritePinVal(CLC_u8EN, DIO_u8LOW);

	return 0 ;
}

extern u8 CLCD_u8WriteDataChar(u8 Copy_u8Data)
{
	u8 local_loopcount ;
	for(local_loopcount=0 ; local_loopcount<8;local_loopcount++)
	{
	DIO_u8WritePinVal(CLC_u8DataArr[local_loopcount],get_bit(Copy_u8Data,local_loopcount));
	}
	DIO_u8WritePinVal(CLC_u8RS, DIO_u8HIGH);
	DIO_u8WritePinVal(CLC_u8RW, DIO_u8LOW);
	DIO_u8WritePinVal(CLC_u8EN, DIO_u8HIGH);
	DELAY(1);

	DIO_u8WritePinVal(CLC_u8EN, DIO_u8LOW);

	return 0 ;
}

extern u8 CLCD_u8WriteDataStr(u8 *Copy_u8Data)
{
	u8 local_loopcount=0 ;
while(*Copy_u8Data)
{
	for(local_loopcount=0 ; local_loopcount<8;local_loopcount++)
	{
	DIO_u8WritePinVal(CLC_u8DataArr[local_loopcount],get_bit(*Copy_u8Data,local_loopcount));
	}

	DIO_u8WritePinVal(CLC_u8RS, DIO_u8HIGH);
	DIO_u8WritePinVal(CLC_u8RW, DIO_u8LOW);
	DIO_u8WritePinVal(CLC_u8EN, DIO_u8HIGH);
	DELAY(1);
	DIO_u8WritePinVal(CLC_u8EN, DIO_u8LOW);
	Copy_u8Data++ ;
	}
	return 0 ;
}
extern u8 CLCD_u8ReadBF(u8 *Copy_u8BF)
{
	DIO_u8WritePinVal(CLC_u8RS, DIO_u8LOW);
	DIO_u8WritePinVal(CLC_u8RW, DIO_u8HIGH);
	//DIO_u8WritePinVal(CLC_u8EN, DIO_u8HIGH);
	DIO_u8WritePinDir(CLC_u8D7,DIO_u8LOW);
	DIO_u8ReadPinVal(CLC_u8D7,Copy_u8BF);
	DELAY(1);
	//DIO_u8WritePinVal(CLC_u8EN, DIO_u8LOW);
	DIO_u8WritePinDir(CLC_u8D7,DIO_u8HIGH);

	return 0 ;
}

extern u8 CLCD_u8WriteOnCGRam(u8 *Copy_u8Ptrn,u8 Copy_location)
{
	u8 local_loopcount ;
	CLCD_u8WriteComand((0x40+Copy_location*8));
	for(local_loopcount=0 ; local_loopcount<8;local_loopcount++)
	{
		CLCD_u8WriteDataChar(Copy_u8Ptrn[local_loopcount]);
	}


	return CHKerr[Copy_location<8]  ;
}


