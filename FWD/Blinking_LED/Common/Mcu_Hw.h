 #ifndef MCU_HW_H
 #define MCU_HW_H

/*****************************************************************************
Nasted Vector Interrupt Controller (NVIC)
*****************************************************************************/
#define       NVIC_STCTRL                             (*((volatile uint32 *)0xE000E010))
#define       NVIC_BASE                               (*((volatile uint32 *)0xE000E000))
#define       NVIC_EN0                                (*((volatile uint32 *)0xE000E100))
#define       NVIC_EN1                                (*((volatile uint32 *)0xE000E104))
#define       NVIC_EN2                                (*((volatile uint32 *)0xE000E108))
#define       NVIC_EN3                                (*((volatile uint32 *)0xE000E10C))
#define       NVIC_EN4                                (*((volatile uint32 *)0xE000E110))
#define       NVIC_DIS0                               (*((volatile uint32 *)0xE000E180))
#define       NVIC_DIS1                               (*((volatile uint32 *)0xE000E184))
#define       NVIC_DIS2                               (*((volatile uint32 *)0xE000E188))
#define       NVIC_DIS3                               (*((volatile uint32 *)0xE000E18C))
#define       NVIC_DIS4                               (*((volatile uint32 *)0xE000E190))
#define       NVIC_PEND0                              (*((volatile uint32 *)0xE000E200))
#define       NVIC_PEND1                              (*((volatile uint32 *)0xE000E204))
#define       NVIC_PEND2                              (*((volatile uint32 *)0xE000E208))
#define       NVIC_PEND3                              (*((volatile uint32 *)0xE000E20C))
#define       NVIC_PEND4                              (*((volatile uint32 *)0xE000E210))
#define       NVIC_UNPEND0                            (*((volatile uint32 *)0xE000E280))
#define       NVIC_UNPEND1                            (*((volatile uint32 *)0xE000E284))
#define       NVIC_UNPEND2                            (*((volatile uint32 *)0xE000E288))
#define       NVIC_UNPEND3                            (*((volatile uint32 *)0xE000E28C))
#define       NVIC_UNPEND4                            (*((volatile uint32 *)0xE000E290))
#define       NVIC_ACTIVE0                            (*((volatile uint32 *)0xE000E300))
#define       NVIC_ACTIVE1                            (*((volatile uint32 *)0xE000E304))
#define       NVIC_ACTIVE2                            (*((volatile uint32 *)0xE000E308))
#define       NVIC_ACTIVE3                            (*((volatile uint32 *)0xE000E30C))
#define       NVIC_ACTIVE4                            (*((volatile uint32 *)0xE000E310))
#define       NVIC_PRI0                               (*((volatile uint32 *)0xE000E400))
#define       NVIC_PRI0_ADDRESS                       0xE000E400
#define       NVIC_SWTRIG                             (*((volatile uint32 *)0xE000EF00))
#define       NVIC_INTCTRL                            (*((volatile uint32 *)0xE000ED04))
#define       NVIC_VTABLE                             (*((volatile uint32 *)0xE000ED08))
#define       NVIC_APINT                              (*((volatile uint32 *)0xE000ED0C))
#define       NVIC_SYSPRI1                            (*((volatile uint32 *)0xE000ED18))
#define       NVIC_SYSPRI2                            (*((volatile uint32 *)0xE000ED1C))
#define       NVIC_SYSPRI3                            (*((volatile uint32 *)0xE000ED20))
#define       NVIC_SYSHNDCTRL                         (*((volatile uint32 *)0xE000ED24))
#define       NVIC_FAULTSTAT                          (*((volatile uint32 *)0xE000ED28))
#define       NVIC_HFAULTSTAT                         (*((volatile uint32 *)0xE000ED2C))




/* Base Addresses For GPIO PORTS */
#define GPIO_PORTA_BASE_ADDRESS           0x40004000
#define GPIO_PORTB_BASE_ADDRESS           0x40005000
#define GPIO_PORTC_BASE_ADDRESS           0x40006000
#define GPIO_PORTD_BASE_ADDRESS           0x40007000
#define GPIO_PORTE_BASE_ADDRESS           0x40024000
#define GPIO_PORTF_BASE_ADDRESS           0x40025000

/* GPIO Registers offset addresses */
#define PORT_DATA_REG_OFFSET              0x3FC
#define PORT_DIR_REG_OFFSET               0x400
#define PORT_ALT_FUNC_REG_OFFSET          0x420
#define PORT_2_MA_DRIVE_REG_OFFSET        0X500
#define PORT_4_MA_DRIVE_REG_OFFSET        0X504
#define PORT_8_MA_DRIVE_REG_OFFSET        0X508
#define PORT_OPEN_DRAIN_REG_OFFSET        0x50C
#define PORT_PULL_UP_REG_OFFSET           0x510
#define PORT_PULL_DOWN_REG_OFFSET         0x514
#define PORT_DIGITAL_ENABLE_REG_OFFSET    0x51C
#define PORT_LOCK_REG_OFFSET              0x520
#define PORT_COMMIT_REG_OFFSET            0x524
#define PORT_ANALOG_MODE_SEL_REG_OFFSET   0x528
#define PORT_CTL_REG_OFFSET               0x52C
#define PORT_ADC_CONTROL_REG_OFFSET       0x530



/*****************************************************************************
GPIO BASES (PORT)
*****************************************************************************/
#define GPIO_PORTA_DATA_ADDRESS       0x40004000
#define GPIO_PORTB_DATA_ADDRESS       0x40005000
#define GPIO_PORTC_DATA_ADDRESS       0x40006000
#define GPIO_PORTD_DATA_ADDRESS       0x40007000
#define GPIO_PORTE_DATA_ADDRESS       0x40024000
#define GPIO_PORTF_DATA_ADDRESS       0x40025000

/*****************************************************************************
GPIO registers (PORTA)
*****************************************************************************/
#define GPIO_PORTA_DATA_REG       (*((volatile uint32 *)0x400043FC))
#define GPIO_PORTA_DIR_REG        (*((volatile uint32 *)0x40004400))
#define GPIO_PORTA_AFSEL_REG      (*((volatile uint32 *)0x40004420))
#define GPIO_PORTA_PUR_REG        (*((volatile uint32 *)0x40004510))
#define GPIO_PORTA_PDR_REG        (*((volatile uint32 *)0x40004514))
#define GPIO_PORTA_DEN_REG        (*((volatile uint32 *)0x4000451C))
#define GPIO_PORTA_LOCK_REG       (*((volatile uint32 *)0x40004520))
#define GPIO_PORTA_CR_REG         (*((volatile uint32 *)0x40004524))
#define GPIO_PORTA_AMSEL_REG      (*((volatile uint32 *)0x40004528))
#define GPIO_PORTA_PCTL_REG       (*((volatile uint32 *)0x4000452C))

/* PORTA External Interrupts Registers */
#define GPIO_PORTA_IS_REG         (*((volatile uint32 *)0x40004404))
#define GPIO_PORTA_IBE_REG        (*((volatile uint32 *)0x40004408))
#define GPIO_PORTA_IEV_REG        (*((volatile uint32 *)0x4000440C))
#define GPIO_PORTA_IM_REG         (*((volatile uint32 *)0x40004410))
#define GPIO_PORTA_RIS_REG        (*((volatile uint32 *)0x40004414))
#define GPIO_PORTA_ICR_REG        (*((volatile uint32 *)0x4000441C))

/*****************************************************************************
GPIO registers (PORTB)
*****************************************************************************/
#define GPIO_PORTB_DATA_REG       (*((volatile uint32 *)0x400053FC))
#define GPIO_PORTB_DIR_REG        (*((volatile uint32 *)0x40005400))
#define GPIO_PORTB_AFSEL_REG      (*((volatile uint32 *)0x40005420))
#define GPIO_PORTB_PUR_REG        (*((volatile uint32 *)0x40005510))
#define GPIO_PORTB_PDR_REG        (*((volatile uint32 *)0x40005514))
#define GPIO_PORTB_DEN_REG        (*((volatile uint32 *)0x4000551C))
#define GPIO_PORTB_LOCK_REG       (*((volatile uint32 *)0x40005520))
#define GPIO_PORTB_CR_REG         (*((volatile uint32 *)0x40005524))
#define GPIO_PORTB_AMSEL_REG      (*((volatile uint32 *)0x40005528))
#define GPIO_PORTB_PCTL_REG       (*((volatile uint32 *)0x4000552C))

/* PORTB External Interrupts Registers */
#define GPIO_PORTB_IS_REG         (*((volatile uint32 *)0x40005404))
#define GPIO_PORTB_IBE_REG        (*((volatile uint32 *)0x40005408))
#define GPIO_PORTB_IEV_REG        (*((volatile uint32 *)0x4000540C))
#define GPIO_PORTB_IM_REG         (*((volatile uint32 *)0x40005410))
#define GPIO_PORTB_RIS_REG        (*((volatile uint32 *)0x40005414))
#define GPIO_PORTB_ICR_REG        (*((volatile uint32 *)0x4000541C))

/*****************************************************************************
GPIO registers (PORTC)
*****************************************************************************/
#define GPIO_PORTC_DATA_REG       (*((volatile uint32 *)0x400063FC))
#define GPIO_PORTC_DIR_REG        (*((volatile uint32 *)0x40006400))
#define GPIO_PORTC_AFSEL_REG      (*((volatile uint32 *)0x40006420))
#define GPIO_PORTC_PUR_REG        (*((volatile uint32 *)0x40006510))
#define GPIO_PORTC_PDR_REG        (*((volatile uint32 *)0x40006514))
#define GPIO_PORTC_DEN_REG        (*((volatile uint32 *)0x4000651C))
#define GPIO_PORTC_LOCK_REG       (*((volatile uint32 *)0x40006520))
#define GPIO_PORTC_CR_REG         (*((volatile uint32 *)0x40006524))
#define GPIO_PORTC_AMSEL_REG      (*((volatile uint32 *)0x40006528))
#define GPIO_PORTC_PCTL_REG       (*((volatile uint32 *)0x4000652C))

/* PORTC External Interrupts Registers */
#define GPIO_PORTC_IS_REG         (*((volatile uint32 *)0x40006404))
#define GPIO_PORTC_IBE_REG        (*((volatile uint32 *)0x40006408))
#define GPIO_PORTC_IEV_REG        (*((volatile uint32 *)0x4000640C))
#define GPIO_PORTC_IM_REG         (*((volatile uint32 *)0x40006410))
#define GPIO_PORTC_RIS_REG        (*((volatile uint32 *)0x40006414))
#define GPIO_PORTC_ICR_REG        (*((volatile uint32 *)0x4000641C))

/*****************************************************************************
GPIO registers (PORTD)
*****************************************************************************/
#define GPIO_PORTD_DATA_REG       (*((volatile uint32 *)0x400073FC))
#define GPIO_PORTD_DIR_REG        (*((volatile uint32 *)0x40007400))
#define GPIO_PORTD_AFSEL_REG      (*((volatile uint32 *)0x40007420))
#define GPIO_PORTD_PUR_REG        (*((volatile uint32 *)0x40007510))
#define GPIO_PORTD_PDR_REG        (*((volatile uint32 *)0x40007514))
#define GPIO_PORTD_DEN_REG        (*((volatile uint32 *)0x4000751C))
#define GPIO_PORTD_LOCK_REG       (*((volatile uint32 *)0x40007520))
#define GPIO_PORTD_CR_REG         (*((volatile uint32 *)0x40007524))
#define GPIO_PORTD_AMSEL_REG      (*((volatile uint32 *)0x40007528))
#define GPIO_PORTD_PCTL_REG       (*((volatile uint32 *)0x4000752C))

/* PORTD External Interrupts Registers */
#define GPIO_PORTD_IS_REG         (*((volatile uint32 *)0x40007404))
#define GPIO_PORTD_IBE_REG        (*((volatile uint32 *)0x40007408))
#define GPIO_PORTD_IEV_REG        (*((volatile uint32 *)0x4000740C))
#define GPIO_PORTD_IM_REG         (*((volatile uint32 *)0x40007410))
#define GPIO_PORTD_RIS_REG        (*((volatile uint32 *)0x40007414))
#define GPIO_PORTD_ICR_REG        (*((volatile uint32 *)0x4000741C))

/*****************************************************************************
GPIO registers (PORTE)
*****************************************************************************/
#define GPIO_PORTE_DATA_REG       (*((volatile uint32 *)0x400243FC))
#define GPIO_PORTE_DIR_REG        (*((volatile uint32 *)0x40024400))
#define GPIO_PORTE_AFSEL_REG      (*((volatile uint32 *)0x40024420))
#define GPIO_PORTE_PUR_REG        (*((volatile uint32 *)0x40024510))
#define GPIO_PORTE_PDR_REG        (*((volatile uint32 *)0x40024514))
#define GPIO_PORTE_DEN_REG        (*((volatile uint32 *)0x4002451C))
#define GPIO_PORTE_LOCK_REG       (*((volatile uint32 *)0x40024520))
#define GPIO_PORTE_CR_REG         (*((volatile uint32 *)0x40024524))
#define GPIO_PORTE_AMSEL_REG      (*((volatile uint32 *)0x40024528))
#define GPIO_PORTE_PCTL_REG       (*((volatile uint32 *)0x4002452C))

/* PORTE External Interrupts Registers */
#define GPIO_PORTE_IS_REG         (*((volatile uint32 *)0x40024404))
#define GPIO_PORTE_IBE_REG        (*((volatile uint32 *)0x40024408))
#define GPIO_PORTE_IEV_REG        (*((volatile uint32 *)0x4002440C))
#define GPIO_PORTE_IM_REG         (*((volatile uint32 *)0x40024410))
#define GPIO_PORTE_RIS_REG        (*((volatile uint32 *)0x40024414))
#define GPIO_PORTE_ICR_REG        (*((volatile uint32 *)0x4002441C))

/*****************************************************************************
GPIO registers (PORTF)
*****************************************************************************/
#define GPIO_PORTF_DATA_REG       (*((volatile uint32 *)0x400253FC))
#define GPIO_PORTF_DIR_REG        (*((volatile uint32 *)0x40025400))
#define GPIO_PORTF_AFSEL_REG      (*((volatile uint32 *)0x40025420))
#define GPIO_PORTF_PUR_REG        (*((volatile uint32 *)0x40025510))
#define GPIO_PORTF_PDR_REG        (*((volatile uint32 *)0x40025514))
#define GPIO_PORTF_DEN_REG        (*((volatile uint32 *)0x4002551C))
#define GPIO_PORTF_LOCK_REG       (*((volatile uint32 *)0x40025520))
#define GPIO_PORTF_CR_REG         (*((volatile uint32 *)0x40025524))
#define GPIO_PORTF_AMSEL_REG      (*((volatile uint32 *)0x40025528))
#define GPIO_PORTF_PCTL_REG       (*((volatile uint32 *)0x4002552C))

/* PORTF External Interrupts Registers */
#define GPIO_PORTF_IS_REG         (*((volatile uint32 *)0x40025404))
#define GPIO_PORTF_IBE_REG        (*((volatile uint32 *)0x40025408))
#define GPIO_PORTF_IEV_REG        (*((volatile uint32 *)0x4002540C))
#define GPIO_PORTF_IM_REG         (*((volatile uint32 *)0x40025410))
#define GPIO_PORTF_RIS_REG        (*((volatile uint32 *)0x40025414))
#define GPIO_PORTF_ICR_REG        (*((volatile uint32 *)0x4002541C))



/*****************************************************************************
SysCtrl Registers
*****************************************************************************/
#define SYSCTL_REGCGC2_REG        (*((volatile uint32 *)0x400FE108))
#define SYSCTL_RCGCTIMER_REG      (*((volatile uint32 *)0x400FE604))


/*****************************************************************************
Systick Timer Registers
*****************************************************************************/
#define SYSTICK_CTRL_REG          (*((volatile uint32 *)0xE000E010))
#define SYSTICK_RELOAD_REG        (*((volatile uint32 *)0xE000E014))
#define SYSTICK_CURRENT_REG       (*((volatile uint32 *)0xE000E018))

/*****************************************************************************
WatchDog Timer Registers
*****************************************************************************/
#define WDT0_LOAD_REG             (*((volatile uint32 *)0x40000000))
#define WDT0_VALUE_REG            (*((volatile uint32 *)0x40000004))
#define WDT0_CTL_REG              (*((volatile uint32 *)0x40000008))
#define WDT0_ICR_REG              (*((volatile uint32 *)0x4000000C))
#define WDT0_RIS_REG              (*((volatile uint32 *)0x40000010))
#define WDT0_MIS_REG              (*((volatile uint32 *)0x40000014))
#define WDT0_TEST_REG             (*((volatile uint32 *)0x40000418))
#define WDT0_LOCK_REG             (*((volatile uint32 *)0x40000C00))

#define WDT1_LOAD_REG             (*((volatile uint32 *)0x40001000))
#define WDT1_VALUE_REG            (*((volatile uint32 *)0x40001004))
#define WDT1_CTL_REG              (*((volatile uint32 *)0x40001008))
#define WDT1_ICR_REG              (*((volatile uint32 *)0x4000100C))
#define WDT1_RIS_REG              (*((volatile uint32 *)0x40001010))
#define WDT1_MIS_REG              (*((volatile uint32 *)0x40001014))
#define WDT1_TEST_REG             (*((volatile uint32 *)0x40001418))
#define WDT1_LOCK_REG             (*((volatile uint32 *)0x40001C00))

#define GPTM_0_16_32_REG          (*((volatile uint32 *)0x40030000))
#define GPTM_1_16_32_REG          (*((volatile uint32 *)0x40031000))
#define GPTM_2_16_32_REG          (*((volatile uint32 *)0x40032000))
#define GPTM_3_16_32_REG          (*((volatile uint32 *)0x40033000))
#define GPTM_4_16_32_REG          (*((volatile uint32 *)0x40034000))
#define GPTM_5_16_32_REG          (*((volatile uint32 *)0x40035000))

#define GPTM_0_32_64_REG          (*((volatile uint32 *)0x40036000))
#define GPTM_1_32_64_REG          (*((volatile uint32 *)0x40037000))
#define GPTM_2_32_64_REG          (*((volatile uint32 *)0x4004C000))
#define GPTM_3_32_64_REG          (*((volatile uint32 *)0x4004D000))
#define GPTM_4_32_64_REG          (*((volatile uint32 *)0x4004E000))
#define GPTM_5_32_64_REG          (*((volatile uint32 *)0x4004F000))


#define GPTM_0_16_32_ADDRESS 0x40030000
#define GPTM_1_16_32_ADDRESS 0x40031000
#define GPTM_2_16_32_ADDRESS 0x40032000
#define GPTM_3_16_32_ADDRESS 0x40033000
#define GPTM_4_16_32_ADDRESS 0x40034000
#define GPTM_5_16_32_ADDRESS 0x40035000

#define GPTM_0_32_64_ADDRESS 0x40036000
#define GPTM_1_32_64_ADDRESS 0x40037000
#define GPTM_2_32_64_ADDRESS 0x4004C000
#define GPTM_3_32_64_ADDRESS 0x4004D000
#define GPTM_4_32_64_ADDRESS 0x4004E000
#define GPTM_5_32_64_ADDRESS 0x4004F000

#define GPTM_CFG_REG_OFFSET     0x000
#define GPTM_TAMR_REG_OFFSET    0x004
#define GPTM_TBMR_REG_OFFSET    0x008
#define GPTM_CTL_REG_OFFSET     0x00C
#define GPTM_SYNC_REG_OFFSET    0x010
#define GPTM_IMR_REG_OFFSET     0x018
#define GPTM_RIS_REG_OFFSET     0x01C
#define GPTM_MIS_REG_OFFSET     0x020
#define GPTM_ICR_REG_OFFSET     0x024
#define GPTM_TAILR_REG_OFFSET   0x028
#define GPTM_TBILR_REG_OFFSET   0x02C
#define GPTM_TAMATCHR_REG_OFFSET 0x030
#define GPTM_TBMATCHR_REG_OFFSET 0x034
#define GPTM_TAPR_REG_OFFSET    0x038
#define GPTM_TBPR_REG_OFFSET    0x03C
#define GPTM_TAPMR_REG_OFFSET   0x040
#define GPTM_TBPMR_REG_OFFSET   0x044
#define GPTM_TAR_REG_OFFSET     0x048
#define GPTM_TBR_REG_OFFSET     0x04C
#define GPTM_TAV_REG_OFFSET     0x050
#define GPTM_TBV_REG_OFFSET     0x054
#define GPTM_RTCPD_REG_OFFSET   0x058
#define GPTM_TAPS_REG_OFFSET    0x05C
#define GPTM_TBPS_REG_OFFSET    0x060
#define GPTM_TAPV_REG_OFFSET    0x064
#define GPTM_TBPV_REG_OFFSET    0x068
#define GPTM_PP_REG_OFFSET      0xFC0


 #endif
