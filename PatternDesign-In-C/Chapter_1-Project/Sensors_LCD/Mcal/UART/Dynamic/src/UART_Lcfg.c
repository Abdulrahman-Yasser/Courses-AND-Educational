/**********************************************************************************************************************
 *  FILE DESCRIPTION
  *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  UART_Lcfg.c
  *        \brief  Digital Input Output Driver
  *
  *      \details  This file contains all the needed Linkning time configuration
  *
  *
  *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include <Mcal/UART/Dynamic/inc/UART_Cfg.h>


extern const UART_ConfigType UART_Container[UART_CONFIGURED_NUMBER] = {
                                                                       {.uart_n = UART_NUM_5,.Uart_Mode = UARTMode_Transmit_Receive,
                                                                        .Data_Size = UARTSize_EIGHT_BITS, .parity = UARTParity_NO_PARITY,
                                                                        .StopBits_Num = UARTSTOPBIT_ONE, .Uart_ISRMode = UARTMode_INTERRUPT,
                                                                        .BaudRate = 9600,.endOfTransmission = 1,
                                                                        .fifo_size_rx = UART_FIFO_1_8,.fifo_size_tx = UART_FIFO_1_8
                                                                        }
};


/**********************************************************************************************************************
 *  END OF FILE: UART_Lcfg.c
 *********************************************************************************************************************/
