/*
 * FreeRTOS Kernel V10.2.0
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/* 
	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used.
*/


/*
 * Creates all the demo application tasks, then starts the scheduler.  The WEB
 * documentation provides more details of the demo application tasks.
 * 
 * Main.c also creates a task called "Check".  This only executes every three 
 * seconds but has the highest priority so is guaranteed to get processor time.  
 * Its main function is to check that all the other tasks are still operational.
 * Each task (other than the "flash" tasks) maintains a unique count that is 
 * incremented each time the task successfully completes its function.  Should 
 * any error occur within such a task the count is permanently halted.  The 
 * check task inspects the count of each task to ensure it has changed since
 * the last time the check task executed.  If all the count variables have 
 * changed all the tasks are still executing error free, and the check task
 * toggles the onboard LED.  Should any task contain an error at any time 
 * the LED toggle rate will change from 3 seconds to 500ms.
 *
 */

/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "lpc21xx.h"
#include "event_groups.h"
#include "queue.h"

/* Peripheral includes. */
#include "serial.h"
#include "GPIO.h"


/*-----------------------------------------------------------*/

/* Constants to setup I/O and processor. */
#define mainBUS_CLK_FULL	( ( unsigned char ) 0x01 )

/* Constants for the ComTest demo application tasks. */
#define mainCOM_TEST_BAUD_RATE	( ( unsigned long ) 115200  )

/*--------------------------------*/


#define Button_1_Monitor_PERIOD 		50		//task 1 Period
#define Button_2_Monitor_PERIOD 		50		//task 2 Period
#define Periodic_Transmitter_PERIOD 100			//task 3 Period
#define Uart_Receiver_PERIOD 				20			//task 4 Period
#define Load_1_Simulation_PERIOD 		10			//task 5 Period
#define Load_2_Simulation_PERIOD 		100			//task 6 Period


/*
 * Configure the processor for use with the Keil demo board.  This is very
 * minimal as most of the setup is managed by the settings in the project
 * file.
 */
static void prvSetupHardware( void );
void Button_1_Monitor(void *pvParameters);
void Button_2_Monitor(void *pvParameters);
void Periodic_Transmitter(void *pvParameters);
void Uart_Receiver(void *pvParameters);
void Load_1_Simulation(void *pvParameters);
void Load_2_Simulation(void *pvParameters);


/*-----------------------------------------------------------*/

TaskHandle_t Button_1_Monitor_Handler = NULL;
TaskHandle_t Button_2_Monitor_Handler = NULL;
TaskHandle_t Periodic_Transmitter_Handler = NULL;
TaskHandle_t Uart_Receiver_Handler = NULL;
TaskHandle_t Load_1_Simulation_Handler = NULL;
TaskHandle_t Load_2_Simulation_Handler = NULL;

/*-----------------------------------------------------------*/
QueueSetHandle_t UART_Queue = NULL;

int task_1_in_time = 0, task_1_out_time = 0, task_1_total_time;
int task_2_in_time = 0, task_2_out_time = 0, task_2_total_time;
int task_3_in_time = 0, task_3_out_time = 0, task_3_total_time;
int task_4_in_time = 0, task_4_out_time = 0, task_4_total_time;
int task_5_in_time = 0, task_5_out_time = 0, task_5_total_time;
int task_6_in_time = 0, task_6_out_time = 0, task_6_total_time;
int system_time = 0;
int cpu_load = 0;


volatile int misses = 0;
char runTimeStatsBuff[280];


/*
 * Application entry point:
 * Starts all the other tasks, then starts the scheduler. 
 */
int main( void )
{
	/* Setup the hardware for use with the Keil demo board. */
	prvSetupHardware();

	
  /* Create Tasks here */
  /* Create the task, storing the handle. */
  xTaskPeriodicCreate(
                    Button_1_Monitor,       /* Function that implements the task. */
                    "First Task",          /* Text name for the task. */
                    100,      /* Stack size in words, not bytes. */
                    ( void * )0,    /* Parameter passed into the task. */
                    0,/* Priority at which the task is created. */
                    &Button_1_Monitor_Handler,
										Button_1_Monitor_PERIOD);      /* Used to pass out the created task's handle. */

  xTaskPeriodicCreate(
                    Button_2_Monitor,       /* Function that implements the task. */
                    "Second Task",          /* Text name for the task. */
                    100,      /* Stack size in words, not bytes. */
                    ( void * )0,    /* Parameter passed into the task. */
                    0,/* Priority at which the task is created. */
                    &Button_2_Monitor_Handler ,
										Button_2_Monitor_PERIOD);      /* Used to pass out the created task's handle. */

	xTaskPeriodicCreate(
                    Periodic_Transmitter,       /* Function that implements the task. */
                    "Third Task",          /* Text name for the task. */
                    100,      /* Stack size in words, not bytes. */
                    ( void * )0,    /* Parameter passed into the task. */
                    0,/* Priority at which the task is created. */
                    &Periodic_Transmitter_Handler ,
										Periodic_Transmitter_PERIOD);      /* Used to pass out the created task's handle. */

	xTaskPeriodicCreate(
                    Uart_Receiver,       /* Function that implements the task. */
                    "Forth Task",          /* Text name for the task. */
                    100,      /* Stack size in words, not bytes. */
                    ( void * )0,    /* Parameter passed into the task. */
                    0,/* Priority at which the task is created. */
                    &Uart_Receiver_Handler ,
										Uart_Receiver_PERIOD);      /* Used to pass out the created task's handle. */
										
	xTaskPeriodicCreate(
                    Load_1_Simulation,       /* Function that implements the task. */
                    "Fifth Task",          /* Text name for the task. */
                    100,      /* Stack size in words, not bytes. */
                    ( void * )0,    /* Parameter passed into the task. */
                    0,/* Priority at which the task is created. */
                    &Load_1_Simulation_Handler ,
										Load_1_Simulation_PERIOD);      /* Used to pass out the created task's handle. */

	xTaskPeriodicCreate(
                    Load_2_Simulation,       /* Function that implements the task. */
                    "Sixth Task",          /* Text name for the task. */
                    100,      /* Stack size in words, not bytes. */
                    ( void * )0,    /* Parameter passed into the task. */
                    0,/* Priority at which the task is created. */
                    &Load_2_Simulation_Handler ,
										Load_2_Simulation_PERIOD);      /* Used to pass out the created task's handle. */
										
										
/* Now all the tasks have been started - start the scheduler.

	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used here. */
	vTaskStartScheduler();

	/* Should never reach here!  If you do then there was not enough heap
	available for the idle task to be created. */
	for( ;; );
}
/*-----------------------------------------------------------*/

/* Function to reset timer 1 */
void timer1Reset(void)
{
	T1TCR |= 0x2;
	T1TCR &= ~0x2;
}

/* Function to initialize and start timer 1 */
static void configTimer1(void)
{
	T1PR = 1000;
	T1TCR |= 0x1;
}

static void prvSetupHardware( void )
{
	/* Perform the hardware setup required.  This is minimal as most of the
	setup is managed by the settings in the project file. */

	/* Configure UART */
	xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);

	/* Configure GPIO */
	GPIO_init();
	
	/* Config trace timer 1 and read T1TC to get current tick */
	configTimer1();

	/* Setup the peripheral bus to be the same as the PLL output. */
	VPBDIV = mainBUS_CLK_FULL;
}
/*-----------------------------------------------------------*/

/*
		Second task : Button_1_Monitor 
		periodic: 50ms, execution : 13.3Us
		the task sends a Button state every 50ms through an Event with hanler Button_1_Events
*/
void Button_1_Monitor(void *pvParameters){
	int counter = 0;
	pinState_t state;
	int xLastWakeTime = xTaskGetTickCount();
	EventGroupHandle_t Button_1_Events = xEventGroupCreate();
	vTaskSetApplicationTaskTag(NULL, (void*) 1);
	for(;;){
		state = GPIO_read(PORT_0, PIN9);
		if(state == PIN_IS_HIGH && counter < 3){
			counter++;
			if(counter == 3){
				// send the event of rising
				xEventGroupSetBits(Button_1_Events, 0);
			}
		}else if(state == PIN_IS_LOW && counter > 1){
			counter--;
			if(counter == 0){
				// send the event of falling
				xEventGroupSetBits(Button_1_Events, 1);
				
			}
		}
		vTaskDelayUntil(&xLastWakeTime, Button_1_Monitor_PERIOD);
	}
}

/*
		Second task : Button_2_Monitor 
		periodic: 50ms, execution : 13.3Us
		the task sends a Button state every 50ms through an Event with hanler Button_2_Events
*/
void Button_2_Monitor(void *pvParameters){
	int counter = 0;
	pinState_t state;
	int xLastWakeTime = xTaskGetTickCount();
	EventGroupHandle_t Button_2_Events = xEventGroupCreate();
	vTaskSetApplicationTaskTag(NULL, (void*) 2);
	for(;;){
		state = GPIO_read(PORT_0, PIN8);
		if(state == PIN_IS_HIGH && counter < 3){
			counter++;
			if(counter == 3){
				// send the event of rising
				xEventGroupSetBits(Button_2_Events, 0);
			}
		}else if(state == PIN_IS_LOW && counter > 0){
			counter--;
			if(counter == 0){
				// send the event of falling
				xEventGroupSetBits(Button_2_Events, 1);
			}
		}
		vTaskDelayUntil(&xLastWakeTime, Button_2_Monitor_PERIOD);
	}
}

/*
		Third task : Periodic_Transmitter 
		periodic: 100ms, execution : 20.3Us
		the task sends a string every 100ms through a queue with hanler UART_Queue
*/
void Periodic_Transmitter(void *pvParameters){
	BaseType_t state;
	/* My Message that will be send periodically */
	char *msg = "Mohammed Salah";
	int xLastWakeTime = xTaskGetTickCount();
	vTaskSetApplicationTaskTag(NULL, (void*) 3);
	/* Creating a queue */
	UART_Queue = xQueueCreate((UBaseType_t) 1, sizeof(&msg));
	for(;;){
		/* Sending my messsage */
		if(uxQueueSpacesAvailable(UART_Queue) > 0){
			state = xQueueSend(UART_Queue, ( void * )&msg, 10);
		}
		vTaskDelayUntil(&xLastWakeTime, Periodic_Transmitter_PERIOD);
	}
}


/*
		Forth task : Uart_Receiver 
		periodic: 20ms, 
		execution : 15.5Us 
								26Us in case the Queue is full
		the task has a character holder for strings (msg), receive in it what task 3 
		send through a queue with handler UART_Queue
*/
void Uart_Receiver(void *pvParameters){
	/* My Message holder */
	char *msg_2 = "No Data";
	int i = 0;
	int xLastWakeTime = xTaskGetTickCount();
	BaseType_t state;
	vTaskSetApplicationTaskTag(NULL, (void*) 4);
	for(;;){
	/* Receiving the message through my queue */
		if(UART_Queue != NULL){
			if(uxQueueMessagesWaiting(UART_Queue) > 0){
				state = xQueueReceive(UART_Queue, &(msg_2), 30);
			}
		}
		if(state == pdPASS ){
			xSerialPutChar('\n');
			vSerialPutString(msg_2, 14);
			state = pdFAIL;
		}
		/* Sending the received message through the queue */
		vTaskDelayUntil(&xLastWakeTime, Uart_Receiver_PERIOD);
	}
}

/*
		Fifth task : Load_1_Simulation 
		periodic: 10ms, execution : 5ms
		The task is just for load purpose
*/
void Load_1_Simulation(void *pvParameters){
 	int i = 0, j = 0;
	/* My Message holder */
	int xLastWakeTime = xTaskGetTickCount();
	vTaskSetApplicationTaskTag(NULL, (void*) 5);
	for(;;){
		for(i = 0; i < 7648; i++){
			for( j = 0; j < 5; j++){
			}
		}
		vTaskDelayUntil(&xLastWakeTime, Load_1_Simulation_PERIOD);
	}
}

/*
		sixth task : Load_2_Simulation 
		periodic: 100ms, execution : 12ms
		The task is just for load purpose
*/
void Load_2_Simulation(void *pvParameters){
 	int i = 0, j = 0, q = 0;
	portBASE_TYPE uart_state;
	int xLastWakeTime = xTaskGetTickCount();
	vTaskSetApplicationTaskTag(NULL, (void*) 6);
	for(;;){
		for(i = 0; i < 12128; i++){
			for( j = 0; j < 9; j++){
			}
		}
//		xSerialPutChar('\n');
		vTaskGetRunTimeStats(runTimeStatsBuff);
/*			vSerialPutString(runTimeStatsBuff, 280);*/
/*		for(q = 0; q < 14; q++){
			vSerialPutString(&runTimeStatsBuff[q*20], 20);
			vTaskDelay(10);
		}*/
		vTaskDelayUntil(&xLastWakeTime, Load_2_Simulation_PERIOD);
	}
}


void vApplicationTickHook(void){
		GPIO_write(PORT_0, PIN0, PIN_IS_HIGH);
		GPIO_write(PORT_0, PIN0, PIN_IS_LOW);
}

void vApplicationIdleHook(void){
		GPIO_write(PORT_0, PIN1, PIN_IS_HIGH);
}
