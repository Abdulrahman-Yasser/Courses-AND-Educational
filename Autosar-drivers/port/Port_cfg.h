 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Abdulrahman yasser
 ******************************************************************************/

#ifndef PORT_CFG_H_
#define PORT_CFG_H_


/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)


/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT               (STD_OFF)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API               (STD_ON)

/* Is it allowed to change the PIN direction in the runtime or not*/
#define PORT_SET_PIN_DIRECTION_API          (STD_ON)

/* Is it allowed to change the PIN mode in the runtime or not*/
#define PORT_SET_PIN_MODE_API               (STD_ON)


/* Number of PINS */
#define PORT_CONFIGURED_PINS                (43U)

/* Number of PORTS */
#define PORT_CONFIGURED_PORTS               (6U)

/* The number of the biggest port's pins*/
#define PINS_BASE                           (8U)

/* Number of MODES */
#define PORT_CONFIGURED_MODES               (12U)


/* Indexes for all the pins on the board */
#define PORTA_PIN0_ID_INDEX       (uint8)0
#define PORTA_PIN1_ID_INDEX       (uint8)1
#define PORTA_PIN2_ID_INDEX       (uint8)2
#define PORTA_PIN3_ID_INDEX       (uint8)3
#define PORTA_PIN4_ID_INDEX       (uint8)4
#define PORTA_PIN5_ID_INDEX       (uint8)5
#define PORTA_PIN6_ID_INDEX       (uint8)6
#define PORTA_PIN7_ID_INDEX       (uint8)7

#define PORTB_PIN0_ID_INDEX       (uint8)0
#define PORTB_PIN1_ID_INDEX       (uint8)1
#define PORTB_PIN2_ID_INDEX       (uint8)2
#define PORTB_PIN3_ID_INDEX       (uint8)3
#define PORTB_PIN4_ID_INDEX       (uint8)4
#define PORTB_PIN5_ID_INDEX       (uint8)5
#define PORTB_PIN6_ID_INDEX       (uint8)6
#define PORTB_PIN7_ID_INDEX       (uint8)7

#define PORTC_PIN0_ID_INDEX       (uint8)0
#define PORTC_PIN1_ID_INDEX       (uint8)1
#define PORTC_PIN2_ID_INDEX       (uint8)2
#define PORTC_PIN3_ID_INDEX       (uint8)3
#define PORTC_PIN4_ID_INDEX       (uint8)4
#define PORTC_PIN5_ID_INDEX       (uint8)5
#define PORTC_PIN6_ID_INDEX       (uint8)6
#define PORTC_PIN7_ID_INDEX       (uint8)7

#define PORTD_PIN0_ID_INDEX       (uint8)0
#define PORTD_PIN1_ID_INDEX       (uint8)1
#define PORTD_PIN2_ID_INDEX       (uint8)2
#define PORTD_PIN3_ID_INDEX       (uint8)3
#define PORTD_PIN4_ID_INDEX       (uint8)4
#define PORTD_PIN5_ID_INDEX       (uint8)5
#define PORTD_PIN6_ID_INDEX       (uint8)6
#define PORTD_PIN7_ID_INDEX       (uint8)7

#define PORTE_PIN0_ID_INDEX       (uint8)0
#define PORTE_PIN1_ID_INDEX       (uint8)1
#define PORTE_PIN2_ID_INDEX       (uint8)2
#define PORTE_PIN3_ID_INDEX       (uint8)3
#define PORTE_PIN4_ID_INDEX       (uint8)4
#define PORTE_PIN5_ID_INDEX       (uint8)5

#define PORTF_PIN0_ID_INDEX       (uint8)0
#define PORTF_PIN1_ID_INDEX       (uint8)1
#define PORTF_PIN2_ID_INDEX       (uint8)2
#define PORTF_PIN3_ID_INDEX       (uint8)3
#define PORTF_PIN4_ID_INDEX       (uint8)4

#define PORT_LOCKER_PINS_NUM      (uint8)6



#endif /* PORT_CFG_H_ */
