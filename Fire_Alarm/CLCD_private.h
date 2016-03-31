/*
 * CLCD_private.h
 *
 *  Created on: Mar 10, 2016
 *      Author: m.mamdooh
 */

#ifndef CLCD_PRIVATE_H_
#define CLCD_PRIVATE_H_

#define conc(x0,x1,x2,x3,x4,x5,x6,x7)     conchelper(x0,x1,x2,x3,x4,x5,x6,x7)
#define conchelper(x0,x1,x2,x3,x4,x5,x6,x7) 0b##x7##x6##x5##x4##x3##x2##x1##x0

#define CLC_u8FUNCSET conc(0,0,CLC_u8DotsLNUM,CLC_u8DISPLNUM,CLC_u8DLNUM,1,0,0)

#endif /* CLCD_PRIVATE_H_ */
