/*
 * App.h
 *
 *  Created on: Aug 26, 2022
 *      Author: Abdu
 */

#ifndef APP_APP_H_
#define APP_APP_H_

#include "App_Cfg.h"
#include "../Common/Std_Types.h"

/* Enable IRQ Interrupts ... This Macro enables IRQ interrupts by clearing the I-bit in the PRIMASK. */
#define Enable_Interrupts()    __asm("  CPSIE I")

/* Disable IRQ Interrupts ... This Macro disables IRQ interrupts by setting the I-bit in the PRIMASK. */
#define Disable_Interrupts()   __asm("  CPSID I")

/* With Frequency 15U in timer's configuration */
#define On_Period       (uint32)65000
#define Off_Period       (uint32)65000

void Init_App(void);

void App_Function(void);

#endif /* APP_APP_H_ */
