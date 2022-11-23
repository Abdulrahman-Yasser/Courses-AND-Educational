 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Abdulrahman yasser
 ******************************************************************************/

#ifndef PORT_H_
#define PORT_H_

/* Id for the company in the AUTOSAR*/
#define PORT_VERSION_ID          (1000U)


/* PORT Module Id*/
#define PORT_MODULE_ID           (124U)

/* PORT Instance Id */
#define PORT_INSTANCE_ID         (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION    (1U)
#define PORT_SW_MINOR_VERSION    (0U)
#define PORT_SW_PATCH_VERSION    (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION    (4U)
#define PORT_AR_RELEASE_MINOR_VERSION    (0U)
#define PORT_AR_RELEASE_PATCH_VERSION    (3U)

/*
 * Macros for PORT Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)


/* Standard AUTOSAR types */
#include "resources/Std_Types.h"
/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* PORT Pre-Compiled Configuration Header file*/
#include "Port_cfg.h"


/* AUTOSAR Version checking between PORT_cfg.h and PORT.h files */
#if ( (PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
  ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
  ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
    #error "The AR version of PORT_cfg.h does not match the expected version"
#endif

#if ( (PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
  ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
  ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
#error "The SW version of PORT_cfg.h does not match the expected version"
#endif


/*Registers for ports*/
#include "Port_Regs.h"

/* Non AUTOSAR files */
#include "resources/Common_Macros.h"


/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/

/* Service ID for PORT Initialization API*/
#define PORT_INIT_SID                       0x00

/* Service ID for SetPinDirection API*/
#define PORT_SET_PIN_DIRECTION_SID          0x01

/* Service ID for PortRefreshPortDirection API*/
#define PORT_REFRESH_PORT_DIRECTION_SID     0x02

/* Service ID for Port_GetVersionInfo API*/
#define PORT_GET_VERSION_INFO_SID           0x03

/* Service ID for Port_SetPinMode API*/
#define PORT_SET_PIN_MODE_SID               0x04


/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN                                0x0A

/* Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE                   0x0B

/* API Port_Init service called with wrong parameter. */
#define PORT_E_PARAM_CONFIG                             0x0C

/* API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_PARAM_INVALID_MODE                       0x0D

/* API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_MODE_UNCHANGEABLE                        0x0E

/* API service called without module initialization */
#define PORT_E_UNINIT                                   0x0F

/* APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER                            0x10



/*
 * Mode Definitions
 */
#define PORT_PIN_MODE_DIO_CTL_VALUE             0x00
#define PORT_PIN_MODE_ADC_CTL_VALUE             0x00
#define PORT_PIN_MODE_UARTn_CTL_VALUE           0x01
#define PORT_PIN_MODE_SSIn_CTL_VALUE            0x02
#define PORT_PIN_MODE_SSI3_CTL_VALUE            0x01
#define PORT_PIN_MODE_I2Cn_CTL_VALUE            0x03
#define PORT_PIN_MODE_M0PWMn_CTL_VALUE          0x04
#define PORT_PIN_MODE_M1PWMn_CTL_VALUE          0x05
#define PORT_PIN_MODE_IDXn_Phpn_CTL_VALUE       0x06
#define PORT_PIN_MODE_TnCCPn_WTnCCPn_CTL_VALUE  0x07
#define PORT_PIN_MODE_CANn_CTL_VALUE            0x08
#define PORT_PIN_MODE_CAN0_F_CTL_VALUE          0x03
#define PORT_PIN_MODE_USBn_CTL_VALUE            0x08
#define PORT_PIN_MODE_NMI_CTL_VALUE             0x08
#define PORT_PIN_MODE_ANALOG_COMPARATOR_CTL_VALUE       0x09
#define PORT_PIN_MODE_TRD_CTL_VALUE             0x0E
#define PORT_PIN_MODE_USB0_DM_DP_CTL_VALUE      0x00
#define PORT_PIN_MODE_UART1_RTS_CTS_CTL_VALUE   0x08

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/




/* Possible direction of a port pin.*/
typedef enum{
    PORT_PIN_IN, PORT_PIN_OUT
}Port_PinDirectionType;


/* Possible value of an input port pin's register.*/
typedef enum{
    NOT_INPUT, PULL_DOWN, PULL_UP, OPEN_DRAIN
}Port_PinResistorType;

/* Possible value of an output port pin.*/
typedef enum{NOT_OUTPUT, PORT_PIN_LEVEL_HIGH, PORT_PIN_LEVEL_LOW
}Port_PinInitValueType;

/* Different port pin modes. */
typedef enum{
    PORT_PIN_MODE_DIO,
    PORT_PIN_MODE_ADC,
    PORT_PIN_MODE_UARTn,
    PORT_PIN_MODE_SSIn,
    PORT_PIN_MODE_SSI3,
    PORT_PIN_MODE_I2Cn,
    PORT_PIN_MODE_M0PWMn,
    PORT_PIN_MODE_M1PWMn,
    PORT_PIN_MODE_IDXn_Phpn,
    PORT_PIN_MODE_TnCCPn_WTnCCPn,
    PORT_PIN_MODE_CANn,
    PORT_PIN_MODE_CAN0_F,
    PORT_PIN_MODE_USBn,
    PORT_PIN_MODE_NMI,
    PORT_PIN_MODE_ANALOG_COMPARATOR,
    PORT_PIN_MODE_TRD,
    PORT_PIN_MODE_USB0_DM_DP,
    PORT_PIN_MODE_UART1_RTS_CTS
}Port_PinModeType;


/* Data type for the symbolic name of a port . */
typedef enum{
    PORT_A,
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_E,
    PORT_F,
    NOT_USED
}Port_PortType;

/* Data type for the symbolic name of a port pin. */
typedef enum{
    PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7,
    PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7,
    PC0, PC1, PC2, PC3, PC4, PC5, PC6, PC7,
    PD0, PD1, PD2, PD3, PD4, PD5, PD6, PD7,
    PE0, PE1, PE2, PE3, PE4, PE5,
    PF0, PF1, PF2, PF3, PF4
}Port_PinType;

/* Data type for the symbolic name of port pin's index. */
typedef uint8 port_pinOffsetType;

typedef struct{
    Port_PortType Port_id;
    Port_PinType Pin_id;
    port_pinOffsetType pin_offset;
    Port_PinModeType pin_mode;
    Port_PinDirectionType pin_direction;
    Port_PinInitValueType pin_initial_value;
    Port_PinResistorType pin_resistor;
    boolean pin_direction_changeable;
    boolean pin_mode_changeable;
}Port_ConfigStruct;


typedef struct{
    Port_ConfigStruct port[PORT_CONFIGURED_PINS];
}port_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Initializes the Port Driver module.*/
void Port_Init(const port_ConfigType *ConfigPtr);



#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/* Sets the port pin direction.*/
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
#endif


/* Refreshes port direction.*/
void Port_RefreshPortDirection( void );


#if( PORT_VERSION_INFO_API == STD_ON)
/* Returns the version information of this module.*/
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo );
#endif


#if (PORT_SET_PIN_MODE_API == STD_ON)
/* Sets the port pin mode.*/
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );
#endif


/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

extern const port_ConfigType port_Configuration;


#endif /* PORT_H_ */
