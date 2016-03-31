/*
 * ADC_interface.h
 *
 *  Created on: Mar 8, 2016
 *      Author: m.mamdooh
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "type.h"
////////////////////////////////////////////////////////////
///////////////// MACROS //////////////////////////////////
//////////////////////////////////////////////////////////
//comment!: ADMUX register

#define REFS1    7
#define REFS0    6
#define ADLAR    5
#define MUX4     4
#define MUX3     3
#define MUX2     2
#define MUX1     1
#define MUX0     0

//comment!: ADCSRA register

#define ADEN      7
#define ADSC      6
#define ADATE     5
#define ADIF      4
#define ADIE      3
#define ADPS2     2
#define ADPS1     1
#define ADPS0     0

//comment!: ADC Data register

#define ADC9      9
#define ADC8      8
#define ADC7      7
#define ADC6      6
#define ADC5      5
#define ADC4      4
#define ADC3      3
#define ADC2      2
#define ADC1      1
#define ADC0      0

//comment!: SFIOR register

#define ADTS2      7
#define ADTS1      6
#define ADTS0      5

//comment !: ADC RESOLUTION
#define ADC_LOWRES 8
#define ADC_HIGHRES 10

/////////////////////////////////////////////////////////////
///////////////////// API's ////////////////////////////////
////////////////////////////////////////////////////////////
extern u8 ADC_u8ReadCh_SSht(u8 Copy_ChIdx , u16 * Copy_PtrToVal);
extern u8 ADC_u8ReadCh_MSht(u8 Copy_ChIdx , u16 * Copy_PtrToVal);
extern u8 ADC_u8ReadGp( u8 * Copy_IdxArr, u16 * Copy_PtrToVal);
extern void ADC_voidInit(void);
extern void ADC_voidEnable(void);
extern void ADC_voidDisable(void);

#endif /* ADC_INTERFACE_H_ */
