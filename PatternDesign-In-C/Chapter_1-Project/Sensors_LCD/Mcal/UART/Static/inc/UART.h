/**********************************************************************************************************************

 *  FILE DESCRIPTIO
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  UART.h
 *       Module:  UART
 *
 *  Description:  The file got all the global function we will use in the driver
 *
 *********************************************************************************************************************/
#ifndef UART_H
#define UART_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include <Mcal/UART/Dynamic/inc/UART_Cfg.h>
#include <Mcal/UART/Static/inc/UART_Types.h>
#include "../../../../Common/Std_Types.h"



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void uart_init(UART_ConfigType *config);
void uart5_fun(void );
void uart_transmit(uint32 base, char x);
char uart_receive(uint32 base);
extern void uart5_handler(void);

uint8 queue_push(uint32 *arr, uint8 *front_pointer, uint8 *rear_pointer, uint8 z);
uint8 queue_pop(uint32 *arr, uint8 *front_pointer, uint8 *rear_pointer);


#endif    /* UART_H */

/**********************************************************************************************************************
 *  END OF FILE: UART.h
 *********************************************************************************************************************/

