/*
 * ADC_config.h
 *
 *  Created on: Mar 8, 2016
 *      Author: m.mamdooh
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

////////////////////////////////////////////////////////////
///////////////// MACROS //////////////////////////////////
//////////////////////////////////////////////////////////
//comment!: ADMUX register

#define ADC_REFS1_INITVAL     ADC_LOW
#define ADC_REFS0_INITVAL     ADC_HIGH
#define ADC_ADLAR_INITVAL     ADC_LOW
#define ADC_MUX4_INTITVAL     ADC_LOW
#define ADC_MUX3_INITVAL      ADC_LOW
#define ADC_MUX2_INITVAL      ADC_LOW
#define ADC_MUX1_INITVAL      ADC_LOW
#define ADC_MUX0_INITVAL      ADC_LOW

//comment!: ADCSRA register

#define ADC_ADEN_INITVAL       ADC_LOW
#define ADC_ADSC_INITVAL       ADC_LOW
#define ADC_ADATE_INITVAL      ADC_LOW
#define ADC_ADIF_INITVAL       ADC_LOW
#define ADC_ADIE_INITVAL       ADC_LOW
#define ADC_ADPS2_INITVAL      ADC_HIGH
#define ADC_ADPS1_INITVAL      ADC_HIGH
#define ADC_ADPS0_INITVAL      ADC_HIGH

//comment!:  SFIOR register

#define ADC_ADTS2_INITVAL      ADC_LOW
#define ADC_ADTS1_INITVAL      ADC_LOW
#define ADC_ADTS0_INITVAL      ADC_LOW

// comment!: ADC RESP+OLUTION
// range : ADC_LOWRES  or ADC_HIGHRES
#define ADC_RES  ADC_HIGHRES

#endif /* ADC_CONFIG_H_ */
