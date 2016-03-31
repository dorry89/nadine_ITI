/*
 * ADC_private.h
 *
 *  Created on: Mar 8, 2016
 *      Author: m.mamdooh
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

////////////////////////////////////////////////////////////
///////////////// MACROS //////////////////////////////////
//////////////////////////////////////////////////////////

// comment : intitializations
#define conc(x0,x1,x2,x3,x4,x5,x6,x7)     conchelper(x0,x1,x2,x3,x4,x5,x6,x7)
#define conchelper(x0,x1,x2,x3,x4,x5,x6,x7) 0b##x7##x6##x5##x4##x3##x2##x1##x0

#define ADC_ADMUX_VAL   conc(ADC_MUX0_INITVAL,ADC_MUX1_INITVAL,ADC_MUX2_INITVAL,ADC_MUX3_INITVAL,ADC_MUX4_INTITVAL,ADC_ADLAR_INITVAL,ADC_REFS0_INITVAL,ADC_REFS1_INITVAL)
#define ADC_ADCSRA_VAL  conc(ADC_ADPS0_INITVAL,ADC_ADPS1_INITVAL,ADC_ADPS2_INITVAL,ADC_ADIE_INITVAL,ADC_ADIF_INITVAL,ADC_ADATE_INITVAL,ADC_ADSC_INITVAL,ADC_ADEN_INITVAL)
#define ADC_SFIOR_VAL   conc(0,0,0,0,0,ADC_ADTS0_INITVAL ,ADC_ADTS1_INITVAL ,ADC_ADTS2_INITVAL )
#define ADC_ADCH_VAL    conc(0,0,0,0,0,0,0,0)
#define ADC_ADCL_VAL    conc(0,0,0,0,0,0,0,0)

//comment!: register addresses
#define ADC_ADMUX *((volatile u8*)(0x27))
#define ADC_ADCSRA *((volatile u8*)(0x26))
#define ADC_ADCH *((volatile u8*)(0x25))
#define ADC_ADCL *((volatile u8*)(0x24))
#define ADC_SFIOR *((volatile u8*)(0x50))

// omment : statuse
#define ADC_HIGH 1
#define ADC_LOW  0
#endif /* ADC_PRIVATE_H_ */


