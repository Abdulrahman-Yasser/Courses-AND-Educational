#include "../inc/Senosr.h"
#include "../inc/Sensor_Types.h"
#include "../../Dynamic/inc/Sensor_Cfg.h"

#include "../../../../Common/Compiler.h"
#include "../../../../Mcal/DIO/Static/inc/DIO.h"

void Sensor_Init(Sensor_Type* const me, SENSOR_READ_TYPE (*GetValueFunction)(Sensor_Type* const me));
void Sensor_Cleanup(Sensor_Type* const me) ;



/* Constructor */
void Sensor_Init(Sensor_Type* const me, SENSOR_READ_TYPE (*GetValueFunction)(Sensor_Type* const me)) {
    me->GetValue = GetValueFunction;
}

/* Destructor */
void Sensor_Cleanup(Sensor_Type* const me) {
    me->GetValue = Null_Ptr;
}

Sensor_Type * Sensor_Create(uint8 Sensor_ID, Sensor_IntrfaceType SensorInterface){
    if(SensorInterface == Sensor_Interface_Analog){
        Sensor_Init(me, GetValueFunction_Analog);
    }else if(SensorInterface == Sensor_Interface_Digital){
        Sensor_Init(me, GetValueFunction_Digital);
    }
}

void Sensor_Destroy( const Sensor_Type* const me){
    if(me != Null_Ptr){
        Sensor_Cleanup(me);
    }
    free(me);
}


SENSOR_READ_TYPE GetValueFunction_Digital(Sensor_Type* const me){
    return Dio_ReadChannel(Sensor_Digital_Config[me->Sensor_ID].Sensor_Data_Pins);
}

SENSOR_READ_TYPE GetValueFunction_Analog(Sensor_Type* const me){
    return 0;
}
