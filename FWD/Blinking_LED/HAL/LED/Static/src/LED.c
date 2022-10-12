/*
 * LED.c
 *
 *  Created on: Aug 23, 2022
 *      Author: Abdu
 */
#include "../inc/LED.h"
#include "../inc/LED_Types.h"
#include "../../Dynamic/inc/LED_Cfg.h"

#include "../../../../Mcal/PORT/Static/inc/PORT.h"
#include "../../../../Mcal/PORT/Dynamic/inc/PORT_Cfg.h"

#include "../../../../Mcal/SysTick/Static/inc/SysTick.h"
#include "../../../../Mcal/SysTick/Dynamic/inc/SysTick_Cfg.h"

#include "../../../../Mcal/DIO/Static/inc/DIO.h"
#include "../../../../Mcal/DIO/Dynamic/inc/DIO_Cfg.h"

#include "../../../../Mcal/IntCtrl/Static/inc/IntCtrl.h"
#include "../../../../Mcal/IntCtrl/Dynamic/inc/IntCtrl_Cfg.h"

#include "../../../../Mcal/WDT/Static/inc/WDT.h"
#include "../../../../Mcal/WDT/Dynamic/inc/WDT_Cfg.h"

#include "../../../../Mcal/GPT/Static/inc/GPT.h"
#include "../../../../Mcal/GPT/Dynamic/inc/GPT_Cfg.h"

void Led_Init(void){
    Port_Init(&ConfigPtr);
    IntCtrl_Init(&Initialized_Interrupt_Container);
    Gpt_Init(&Gpt_ConfigPtr);
    Gpt_EnableNotification(LED1_TIMER_CHANNEL);
    Gpt_StartTimer(LED1_TIMER_CHANNEL, 1000);
}

void Led_Blink_On(void){
    Dio_WriteChannel(LED1_PIN_NUMBER, LED_FLASH);
}

void Led_Blink_Off(void){
    Dio_WriteChannel(LED1_PIN_NUMBER, LED_STOP);
}

void Led_Toggle(void){
    Dio_FlipChannel(LED1_PIN_NUMBER);
}

void Led_TimeValue(uint32 value){
    Gpt_StartTimer(LED1_TIMER_CHANNEL, value);
}
