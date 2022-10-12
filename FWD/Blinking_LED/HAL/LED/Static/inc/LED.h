/*
 * LED.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Abdu
 */

#ifndef LED_H
#define LED_H

#include "../../../../Mcal/DIO/Static/inc/DIO_Types.h"
#include "../../../../Mcal/PORT/Static/inc/PORT_Types.h"



void Led_Init(void);

void Led_Blink_On(void);

void Led_Blink_Off(void);

void Led_Toggle(void);

void Led_TimeValue(uint32 value);

#endif /* HAL_LED_LED_H_ */
