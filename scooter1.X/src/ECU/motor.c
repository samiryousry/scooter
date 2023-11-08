#include "E:\diploma embeded\scooter1.X\INC\ECU\motor.h"
Std_ReturnType DC_motor_initialize(const DC_motor_t *motor)
{Std_ReturnType ret=E_OK ;
if(!motor)
{ret =E_NOT_OK;
}else{
    pin_config_t pin_obj_1 ;
pin_config_t pin_obj_2 ;
  pin_obj_1.port= motor->Motor_pins[0].port_name;
    pin_obj_1.pin = motor->Motor_pins[0].pin;
    pin_obj_2.port= motor->Motor_pins[1].port_name;
   pin_obj_2.pin=  motor->Motor_pins[1].pin;
          pin_obj_1.direction =OUTPUT ;
  pin_obj_1.logic=motor->Motor_pins[0].DC_motor_Pin_status ;
  pin_obj_2.direction =OUTPUT ;
  pin_obj_2.logic=motor->Motor_pins[1].DC_motor_Pin_status ;
  gpio_pin_intilaize(&pin_obj_1);
          gpio_pin_intilaize(&pin_obj_2);}

          return ret ;
}
Std_ReturnType DC_motor_MOve_clock_Wise(const DC_motor_t *motor)
{Std_ReturnType ret=E_OK ;
if(!motor)
{ret =E_NOT_OK;
}else{
    pin_config_t pin_obj_1 ;
pin_config_t pin_obj_2 ;
  pin_obj_1.port= motor->Motor_pins[0].port_name;
    pin_obj_1.pin = motor->Motor_pins[0].pin;
    pin_obj_2.port= motor->Motor_pins[1].port_name;
   pin_obj_2.pin=  motor->Motor_pins[1].pin;
          pin_obj_1.direction =OUTPUT ;
  pin_obj_1.logic=motor->Motor_pins[0].DC_motor_Pin_status ;
  pin_obj_2.direction =OUTPUT ;
  pin_obj_2.logic=motor->Motor_pins[1].DC_motor_Pin_status ;
    gpio_pin_write_logic(&pin_obj_1,HIGH) ;
  gpio_pin_write_logic(&pin_obj_2,LOW) ;}
  return ret ;
    
}
Std_ReturnType DC_motor_MOve_Anti_clock_Wise(const DC_motor_t *motor){
    Std_ReturnType ret=E_OK ;
if(!motor)
{ret =E_NOT_OK;
}else{
    pin_config_t pin_obj_1 ;
pin_config_t pin_obj_2 ;
  pin_obj_1.port= motor->Motor_pins[0].port_name;
    pin_obj_1.pin = motor->Motor_pins[0].pin;
    pin_obj_2.port= motor->Motor_pins[1].port_name;
   pin_obj_2.pin=  motor->Motor_pins[1].pin;
          pin_obj_1.direction =OUTPUT ;
  pin_obj_1.logic=motor->Motor_pins[0].DC_motor_Pin_status ;
  pin_obj_2.direction =OUTPUT ;
  pin_obj_2.logic=motor->Motor_pins[1].DC_motor_Pin_status ;
    gpio_pin_write_logic(&pin_obj_1,LOW) ;
  gpio_pin_write_logic(&pin_obj_2,HIGH) ;}
  return ret ;
    
}
Std_ReturnType DC_motor_Stop(const DC_motor_t *motor){
        Std_ReturnType ret=E_OK ;
if(!motor)
{ret =E_NOT_OK;
}else{
    pin_config_t pin_obj_1 ;
pin_config_t pin_obj_2 ;
  pin_obj_1.port= motor->Motor_pins[0].port_name;
    pin_obj_1.pin = motor->Motor_pins[0].pin;
    pin_obj_2.port= motor->Motor_pins[1].port_name;
   pin_obj_2.pin=  motor->Motor_pins[1].pin;
          pin_obj_1.direction =OUTPUT ;
  pin_obj_1.logic=motor->Motor_pins[0].DC_motor_Pin_status ;
  pin_obj_2.direction =OUTPUT ;
  pin_obj_2.logic=motor->Motor_pins[1].DC_motor_Pin_status ;
    gpio_pin_write_logic(&pin_obj_1,LOW) ;
  gpio_pin_write_logic(&pin_obj_2,LOW) ;}
  return ret ;
}
