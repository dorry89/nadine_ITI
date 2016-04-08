/*
 * TIM0_private.h
 *
 *  Created on: Mar 29, 2016
 *      Author: m.mamdooh
 */

#ifndef TIM0_PRIVATE_H_
#define TIM0_PRIVATE_H_

#define TCCR0  *((volatile u8*)(0x53))
#define TCNT0  *((volatile u8*)(0x52))
#define OCR0   *((volatile u8*)(0x5c))
#define TIMSK  *((volatile u8*)(0x59))
#define TIFR   *((volatile u8*)(0x58))

#define TIM0_u8LOW    0
#define TIM0_u8HIGH   1






#define TIM0_u8NOPS        1
#define TIM0_u8PS_8   	   8
#define TIM0_u8PS_64       64
#define TIM0_u8PS_256      256
#define TIM0_u8PS_1024     1024

#define TIM0_u8CLKFALEDGE  2
#define TIM0_u8CLKRISEDGE  3

#if(TIM0_u8PRESCLER == TIM0_u8NOPS)
#define TIM0_CS00INIT  TIM0_u8HIGH
#define TIM0_CS01INIT  TIM0_u8LOW
#define TIM0_CS02INIT  TIM0_u8LOW
#elif(TIM0_u8PRESCLER == TIM0_u8PS_8)
#define TIM0_CS00INIT  TIM0_u8LOW
#define TIM0_CS01INIT  TIM0_u8HIGH
#define TIM0_CS02INIT  TIM0_u8LOW
#elif(TIM0_u8PRESCLER == TIM0_u8PS_64)
#define TIM0_CS00INIT  TIM0_u8HIGH
#define TIM0_CS01INIT  TIM0_u8HIGH
#define TIM0_CS02INIT  TIM0_u8LOW
#elif(TIM0_u8PRESCLER == TIM0_u8PS_256)
#define TIM0_CS00INIT  TIM0_u8LOW
#define TIM0_CS01INIT  TIM0_u8LOW
#define TIM0_CS02INIT  TIM0_u8HIGH
#elif(TIM0_u8PRESCLER == TIM0_u8PS_1024)
#define TIM0_CS00INIT  TIM0_u8HIGH
#define TIM0_CS01INIT  TIM0_u8LOW
#define TIM0_CS02INIT  TIM0_u8HIGH
#endif


#define conc(x0,x1,x2,x3,x4,x5,x6,x7)     conchelper(x0,x1,x2,x3,x4,x5,x6,x7)
#define conchelper(x0,x1,x2,x3,x4,x5,x6,x7) 0b##x7##x6##x5##x4##x3##x2##x1##x0

#define TIM0_u8TCCR0INIT  conc(TIM0_CS00INIT,TIM0_CS01INIT,TIM0_CS02INIT,0,0,0,0,0)
#endif /* TIM0_PRIVATE_H_ */
