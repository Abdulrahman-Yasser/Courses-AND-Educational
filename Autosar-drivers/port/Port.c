/******************************************************************************
 *
 * Module: PORT
 *
 * File Name: port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Abdulrahman Yasser
 *
 ******************************************************************************/


#include "Port.h"
#include "Port_Regs.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)
#include "resources/Det.h"
/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif
#endif

/********************************************************************
 Private functions prototype
********************************************************************/

void set_mode_DIO(volatile uint32* port, uint8 pin);
void set_DIO_direction(volatile uint32* port, uint8 pin, Port_PinDirectionType direction);
void set_DIO_level(volatile uint32* port, uint8 pin, Port_PinInitValueType level);
void set_DIO_register(volatile uint32* port, uint8 pin, Port_PinResistorType pull_register);
void set_mode_ADC(volatile uint32* port, uint8 pin);
void set_mode(volatile uint32* port, uint8 pin, uint8 ctl_reg_value);
void unlock_pin(volatile uint32* port, uint8 pin);
volatile uint32 *get_pin_port(Port_PortType Port_id);

/********************************************************************
 Private variables
********************************************************************/

const Port_PinType LOCKED_PINS[PORT_LOCKER_PINS_NUM] = {PC0, PC1, PC2, PC3, PD7, PF0};

STATIC const Port_ConfigStruct*  module_configuration = NULL_PTR;
STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;


/********************************************************************
 Private function definition
********************************************************************/

/* Unlocking pin to allow us to use it */
void unlock_pin(volatile uint32* port, uint8 pin){
    *(volatile uint32 *)((volatile uint8 *)port + PORT_LOCK_REG_OFFSET) = PORT_UNLOCKING_VALUE;
    SET_BIT(*(volatile uint32 *)((volatile uint8 *)port + PORT_COMMIT_REG_OFFSET) , pin);
}

/* Setting pin's mode */
void set_mode_DIO(volatile uint32* port, uint8 pin){
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)port + PORT_ANALOG_MODE_SEL_REG_OFFSET) , pin);
    *(volatile uint32 *)((volatile uint8 *)port + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (pin * 4));
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)port + PORT_ALT_FUNC_REG_OFFSET) , pin);
    SET_BIT(*(volatile uint32 *)((volatile uint8 *)port + PORT_DIGITAL_ENABLE_REG_OFFSET) , pin);
}

/* Setting pin's direction */
void set_DIO_direction(volatile uint32* port, uint8 pin, Port_PinDirectionType direction){
    if(direction == PORT_PIN_OUT){
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)port + PORT_DIR_REG_OFFSET) , pin);
    }else if(direction == PORT_PIN_IN){
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)port + PORT_DIR_REG_OFFSET) , pin);
    }else{

    }
}

/* Setting pin's output value */
void set_DIO_level(volatile uint32* port, uint8 pin, Port_PinInitValueType level){
    if(level == PORT_PIN_LEVEL_HIGH){
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)port + PORT_DATA_REG_OFFSET) , pin);
    }else if(level == PORT_PIN_LEVEL_LOW){
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)port + PORT_DATA_REG_OFFSET) , pin);
    }else{

    }
}

/* Setting pin's input mode */
void set_DIO_register(volatile uint32* port, uint8 pin, Port_PinResistorType pull_register){
    if(pull_register == PULL_DOWN){
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)port + PORT_PULL_UP_REG_OFFSET) , pin);
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)port + PORT_PULL_DOWN_REG_OFFSET) , pin);
    }else if(pull_register == PULL_UP){
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)port + PORT_PULL_DOWN_REG_OFFSET) , pin);
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)port + PORT_PULL_UP_REG_OFFSET) , pin);
    }else{

    }
}

/* Setting pin as analog input/output */
void set_mode_ADC(volatile uint32* port, uint8 pin){
    SET_BIT(*(volatile uint32 *)((volatile uint8 *)port + PORT_ANALOG_MODE_SEL_REG_OFFSET) , pin);
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)port + PORT_ALT_FUNC_REG_OFFSET) , pin);
    *(volatile uint32 *)((volatile uint8 *)port + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (pin * 4));
}

/* Setting pin's mode */
void set_mode(volatile uint32* port, uint8 pin, uint8 ctl_reg_value){
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)port + PORT_ANALOG_MODE_SEL_REG_OFFSET) , pin);
    SET_BIT(*(volatile uint32 *)((volatile uint8 *)port + PORT_DIGITAL_ENABLE_REG_OFFSET) , pin);
    SET_BIT(*(volatile uint32 *)((volatile uint8 *)port + PORT_ALT_FUNC_REG_OFFSET) , pin);
    *(volatile uint32 *)((volatile uint8 *)port + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (pin * 4));
    *(volatile uint32 *)((volatile uint8 *)port + PORT_CTL_REG_OFFSET) |= (ctl_reg_value << (pin * 4));
}

/* Return the port address */
volatile uint32 *get_pin_port(Port_PortType Port_id){
    volatile uint32 *port_ptr = NULL_PTR;
    switch(Port_id){
    case PORT_A:
        port_ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS;
        break;
    case PORT_B:
        port_ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS;
        break;
    case PORT_C:
        port_ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS;
        break;
    case PORT_D:
        port_ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS;
        break;
    case PORT_E:
        port_ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS;
        break;
    case PORT_F:
        port_ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS;
        break;
    case NOT_USED:
        port_ptr = NULL_PTR;
        break;
    }
    return port_ptr;
}

/* Return the mode's value for the port control register according to the datasheet */
uint8 get_mode_value(Port_PinModeType mode){
    uint8 value = 0;
    switch(mode){
    case PORT_PIN_MODE_UARTn:
        value = PORT_PIN_MODE_UARTn_CTL_VALUE;
        break;
    case PORT_PIN_MODE_SSIn:
        value = PORT_PIN_MODE_ADC_CTL_VALUE;
        break;
    case PORT_PIN_MODE_SSI3:
        value = PORT_PIN_MODE_SSI3_CTL_VALUE;
        break;
    case PORT_PIN_MODE_I2Cn:
        value = PORT_PIN_MODE_I2Cn_CTL_VALUE;
        break;
    case PORT_PIN_MODE_M0PWMn:
        value = PORT_PIN_MODE_M0PWMn_CTL_VALUE;
        break;
    case PORT_PIN_MODE_M1PWMn:
        value = PORT_PIN_MODE_M1PWMn_CTL_VALUE;
        break;
    case PORT_PIN_MODE_IDXn_Phpn:
        value = PORT_PIN_MODE_IDXn_Phpn_CTL_VALUE;
        break;
    case PORT_PIN_MODE_TnCCPn_WTnCCPn:
        value = PORT_PIN_MODE_TnCCPn_WTnCCPn_CTL_VALUE;
        break;
    case PORT_PIN_MODE_CANn:
        value = PORT_PIN_MODE_CANn_CTL_VALUE;
        break;
    case PORT_PIN_MODE_CAN0_F:
        value = PORT_PIN_MODE_CAN0_F_CTL_VALUE;
        break;
    case PORT_PIN_MODE_USBn:
        value = PORT_PIN_MODE_USBn_CTL_VALUE;
        break;
    case PORT_PIN_MODE_NMI:
        value = PORT_PIN_MODE_NMI_CTL_VALUE;
        break;
    case PORT_PIN_MODE_ANALOG_COMPARATOR:
        value = PORT_PIN_MODE_ANALOG_COMPARATOR_CTL_VALUE;
        break;
    case PORT_PIN_MODE_TRD:
        value = PORT_PIN_MODE_TRD_CTL_VALUE;
        break;
    case PORT_PIN_MODE_USB0_DM_DP:
        value = PORT_PIN_MODE_USB0_DM_DP_CTL_VALUE;
        break;
    case PORT_PIN_MODE_UART1_RTS_CTS:
        value = PORT_PIN_MODE_UART1_RTS_CTS_CTL_VALUE;
        break;
    default:
        value = 0;
        break;
    }
    return value;
}

/********************************************************************
 Public function definition
********************************************************************/

/********************************************************************
 * Service Name     :   Port_Init
 * Service ID       :   0x00
 * Sync/Async       :   Synchronous
 * Reentrancy       :   Non Reentrant
 * Parameters(in)   :   (port_ConfigType) ConfigPtr
 * Parameters(inout):   None
 * Parameters(out)  :   None
 * Return Value     :   None
 * Description      :   Initializes the Port Driver module.
********************************************************************/

void Port_Init(const port_ConfigType *ConfigPtr){
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    boolean error = FALSE;
    if(NULL_PTR == ConfigPtr)
    {
       Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                       PORT_INIT_SID, PORT_E_PARAM_CONFIG);
       error = TRUE;
    }else{

    }
    if(error == TRUE){
        return;
    }else
#endif
    {
        uint8 i, my_mode;
        volatile uint32 *port_ptr, *old_port = NULL_PTR;
        volatile uint32 delay;
        Port_Status = PORT_INITIALIZED;
        module_configuration = ConfigPtr->port;
        //  Unlocking used pins
        port_ptr = NULL_PTR;
        // Loop through all locked ports/pins
        for(i = 0; i < PORT_LOCKER_PINS_NUM; i++){
            port_ptr = get_pin_port(module_configuration[LOCKED_PINS[i]].Port_id);
            if(port_ptr != NULL_PTR){
                SYSCTL_REGCGC2_REG |= (1<<module_configuration[LOCKED_PINS[i]].Port_id);
                delay = SYSCTL_REGCGC2_REG;
                unlock_pin(port_ptr, module_configuration[LOCKED_PINS[i]].pin_offset);
                set_mode(port_ptr, module_configuration[LOCKED_PINS[i]].pin_offset, 0x00);
            }else{
            }
        }
        // Loop through all ports/pins
        for(i = 0; i < PORT_CONFIGURED_PINS; i++){
            port_ptr = get_pin_port(module_configuration[i].Port_id);
            if(port_ptr == NULL_PTR){
                continue;
            }else if(port_ptr != old_port){
                // Enable clock signal for the port
                SYSCTL_REGCGC2_REG |= (1<<module_configuration[i].Port_id);
                delay = SYSCTL_REGCGC2_REG;
                old_port = port_ptr;
            }else{
            }
            switch(module_configuration[i].pin_mode){
            case PORT_PIN_MODE_DIO:
                /*pin i is Digital input/output pin*/
                set_mode_DIO(port_ptr, module_configuration[i].pin_offset);
                set_DIO_direction(port_ptr, module_configuration[i].pin_offset, module_configuration[i].pin_direction);
                if(module_configuration[i].pin_direction == PORT_PIN_IN){
                    set_DIO_register(port_ptr, module_configuration[i].pin_offset, module_configuration[i].pin_resistor);
                }else if(module_configuration[i].pin_direction == PORT_PIN_OUT){
                    set_DIO_level(port_ptr, module_configuration[i].pin_offset, module_configuration[i].pin_initial_value);
                }else{
                }
                break;
            case PORT_PIN_MODE_ADC:
                /*pin i is Digital Analog pin*/
                set_mode_ADC(port_ptr, module_configuration[i].pin_offset);
                set_DIO_direction(port_ptr, module_configuration[i].pin_offset, module_configuration[i].pin_direction);
                if(module_configuration[i].pin_direction == PORT_PIN_IN){
                    set_DIO_register(port_ptr, module_configuration[i].pin_offset, module_configuration[i].pin_resistor);
                }else if(module_configuration[i].pin_direction == PORT_PIN_OUT){
                    set_DIO_level(port_ptr, module_configuration[i].pin_offset, module_configuration[i].pin_initial_value);
                }else{
                }
                break;
            default:
                /* Set the pin mode according to it's mode*/
                my_mode = get_mode_value(module_configuration[i].pin_mode);
                set_mode(port_ptr, module_configuration[i].pin_offset, my_mode);
                set_DIO_direction(port_ptr, module_configuration[i].pin_offset, module_configuration[i].pin_direction);
                if(module_configuration[i].pin_direction == PORT_PIN_IN){
                    set_DIO_register(port_ptr, module_configuration[i].pin_offset, module_configuration[i].pin_resistor);
                }else if(module_configuration[i].pin_direction == PORT_PIN_OUT){
                    set_DIO_level(port_ptr, module_configuration[i].pin_offset, module_configuration[i].pin_initial_value);
                }else{
                }
            }
        }
    }
}





/********************************************************************
 * Service Name     :   Port_SetPinDirection
 * Service ID       :   0x01
 * Sync/Async       :   Synchronous
 * Reentrancy       :   Reentrant
 * Parameters(in)   :   (Port_PinType) Pin
 *                      (Port_PinDirectionType) Direction
 * Parameters(inout):   None
 * Parameters(out)  :   None
 * Return Value     :   None
 * Description      :   Set the pin Direction for the port
********************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection( Port_PinType pin, Port_PinDirectionType Direction ){
    volatile uint32* port_ptr;
    port_ptr = get_pin_port(module_configuration[pin].Port_id);

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    boolean error = FALSE;
    if(Port_Status == PORT_NOT_INITIALIZED)
    {
       Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                       PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
       error = TRUE;
    }else{
    }
    if(module_configuration[pin].pin_direction_changeable == STD_OFF){
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        PORT_SET_PIN_DIRECTION_SID, PORT_E_DIRECTION_UNCHANGEABLE);
        error = TRUE;
    }else{
    }
    if(module_configuration[pin].pin_offset < PINS_BASE){
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
        error = TRUE;
    }else{
    }
    if(error == TRUE){
        return;
    }
#endif

    if(module_configuration[pin].pin_direction_changeable == STD_ON){
        set_DIO_direction(port_ptr,module_configuration[pin].pin_offset, Direction);
    }else{
    }
}
#endif





/********************************************************************
 * Service Name     :   Port_RefreshPortDirection
 * Service ID       :   0x02
 * Sync/Async       :   Synchronous
 * Reentrancy       :   Non Reentrant
 * Parameters(in)   :   None
 * Parameters(inout):   None
 * Parameters(out)  :   None
 * Return Value     :   None
 * Description      :   Refreshes port direction.
********************************************************************/
void Port_RefreshPortDirection( void ){
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    boolean error = FALSE;
    if(Port_Status == PORT_NOT_INITIALIZED)
    {
       Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                       PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
       error = TRUE;
    }else{
    }
    if(error == TRUE){
        return;
    }else
#endif

    {
        uint8 i ;
        volatile uint32* port_ptr;
        for(i = 0; i < PORT_CONFIGURED_PINS; i++){
            if(module_configuration[i].pin_direction_changeable == STD_OFF){
                port_ptr = get_pin_port(module_configuration[i].Port_id);
                set_DIO_level(port_ptr, module_configuration[i].pin_offset, module_configuration[i].pin_initial_value);
            }else{
            }
        }
    }
}






/********************************************************************
 * Service Name     :   Port_GetVersionInfo
 * Service ID       :   0x03
 * Sync/Async       :   Synchronous
 * Reentrancy       :   Non Reentrant
 * Parameters(in)   :   None
 * Parameters(inout):   None
 * Parameters(out)  :   (Std_VersionInfoType) versioninfo
 * Return Value     :   None
 * Description      :   Returns the version information of this module.
********************************************************************/
#if( PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo ){
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    boolean error = FALSE;
    if(Port_Status == PORT_NOT_INITIALIZED)
    {
       Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                       PORT_GET_VERSION_INFO_SID, PORT_E_UNINIT);
       error = TRUE;
    }else{
    }
    if(NULL_PTR == versioninfo)
    {
       Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                       PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
       error = TRUE;
    }else{
    }
    if(error == TRUE){
        return;
    }else
#endif
    {
        versioninfo->vendorID = (uint16)PORT_VERSION_ID;
        versioninfo->moduleID = (uint16)PORT_MODULE_ID;
        versioninfo->sw_major_version = (uint16)PORT_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint16)PORT_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint16)PORT_SW_PATCH_VERSION;
    }
}
#endif












/********************************************************************
 * Service Name     :   Port_SetPinMode
 * Service ID       :   0x04
 * Sync/Async       :   Synchronous
 * Reentrancy       :   Reentrant
 * Parameters(in)   :   (Port_PinType) Pin
 *                      (Port_PinModeType) Mode
 * Parameters(inout):   None
 * Parameters(out)  :   None
 * Return Value     :   None
 * Description      :   Sets the port pin mode.
********************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode( Port_PinType pin, Port_PinModeType Mode ){
    uint8 mode_value;
    volatile uint32* port_ptr;
    port_ptr = get_pin_port(module_configuration[pin].Port_id);

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    boolean error = FALSE;
    if(Port_Status == PORT_NOT_INITIALIZED)
    {
       Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                       PORT_SET_PIN_MODE_SID, PORT_E_UNINIT);
       error = TRUE;
    }else{
    }
    // Check the pin unchangeable state
    if(module_configuration[pin].pin_mode_changeable == STD_OFF)
    {
       Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                       PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
       error = TRUE;
    }else{
    }
    // Check the mode
    if(Mode > PORT_CONFIGURED_MODES)
    {
       Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                       PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
       error = TRUE;
    }else{
    }
    if(error == TRUE){
        return;
    }else
#endif
    {
        if(module_configuration[pin].pin_mode_changeable == STD_ON)
        {
            mode_value = get_mode_value(Mode);
            set_mode(port_ptr, module_configuration[pin].pin_offset, mode_value);
        }
    }
}
#endif
