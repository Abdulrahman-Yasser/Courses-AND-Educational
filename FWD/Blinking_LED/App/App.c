#include "App.h"

#include "../Common/Std_Types.h"

#include "../HAL/LED/Static/inc/LED.h"
#include "../HAL/LED/Dynamic/inc/LED_Cfg.h"



void Init_App(void){
    Enable_Interrupts();
    Led_Init();
}

void App_Function(void){
//    Led_Toggle();
    static uint8 my_bool = 0;
    if(my_bool){
        Led_Blink_On();
        Led_TimeValue(On_Period);
        my_bool = 0;
    }else{
        Led_Blink_Off();
        Led_TimeValue(Off_Period);
        my_bool = 1;
    }
}
