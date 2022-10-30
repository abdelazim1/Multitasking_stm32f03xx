/*
 * STD_TYPE.h
 *
 *  Created on: Oct 15, 2022
 *      Author: a_a
 */

#ifndef STD_TYPE_H_
#define STD_TYPE_H_

typedef unsigned char			u8;
typedef unsigned short int		u16;
typedef unsigned long int		u32;
typedef signed char				s8;
typedef signed short int		s16;
typedef signed long	int			s32;

#define private					static
#define __vo					volatile
#define Naked					__attribute__((naked))

#endif /* STD_TYPE_H_ */
