/*
 * CLCD_interface.h
 *
 *  Created on: Mar 9, 2016
 *      Author: m.mamdooh
 */

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_


/////////////////////////////////////////////
///////////////MACROS///////////////////////
///////////////////////////////////////////
#define CLC_u8ENABLE  1
#define CLC_u8DISABLE  0

//comments !: commands

//comments !: clr display
#define CLC_u8CLRDISP    0x01
//comments !: move the cursor home
#define CLC_CURHOME      0x02
//comments !:  entry mode
#define CLC_u8ENTERMOD   0x06
//comments !:  display on off and cursor blink
#define CLC_u8DISPON     0x0C
#define CLC_u8DISPOFF    0x08
#define CLC_u8CURBLNK    0x0F
//comment shift data or cursor
#define CLC_u8SHFTCURL   0x10
#define CLC_u8SHFTCURR   0x14
#define CLC_u8SHFTDTAL   0x18
#define CLC_u8SHFTDTAR   0x1C
//jump on the second line of the disp
#define CLC_u8NEWL       0xC0
//jump on the first line of the disp
#define CLC_u8STL       0x80

#define CLC_u8JMPCGRAM       0x40

/////////////////////////////////////////////
///////////////APIS///////////////////////
///////////////////////////////////////////
extern u8 CLCD_u8WriteComand(u8 Copy_u8command) ;
extern u8 CLCD_u8WriteDataStr(u8 *Copy_u8Data) ;
extern u8 CLCD_u8WriteDataChar(u8 Copy_u8command) ;
void CLC_voidInit(void);
extern u8 CLCD_u8ReadBF(u8 *Copy_u8BF);
extern u8 CLCD_u8WriteOnCGRam(u8 *Copy_u8Ptrn,u8 Copy_location);

#endif /* CLCD_INTERFACE_H_ */
