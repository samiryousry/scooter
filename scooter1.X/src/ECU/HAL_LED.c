
/* 
 * File:   led.c
 * Author: Tyrex
 *
 * Created on February 12, 2023, 8:34 AM
 */

#include "E:\diploma embeded\scooter1.X\INC\ECU\HAL_LED.H"

Std_ReturnType led_initialize(const led_t *led)
{ Std_ReturnType ret=E_OK;
    if (!(led))
    { ret=E_NOT_OK;
        
    }
    else
    {
    pin_config_t pin_obj ;
    pin_obj.direction =OUTPUT ;
     pin_obj.pin =led->pin ;
     pin_obj.port=led->port_name;
     pin_obj.logic=led->led_status;
     ret=gpio_pin_intilaize(&pin_obj);
    }
return ret;
}
Std_ReturnType led_turn_on(const led_t *led)
{
    Std_ReturnType ret=E_OK;
    if (!(led))
    { ret=E_NOT_OK;
        
    }
    else
    {
    pin_config_t pin_obj ;
    pin_obj.direction =OUTPUT ;
     pin_obj.pin =led->pin ;
     pin_obj.port=led->port_name;
     pin_obj.logic=led->led_status;
       ret=gpio_pin_write_logic(&pin_obj,HIGH);
    }
}
Std_ReturnType led_turn_off(const led_t *led)
{  Std_ReturnType ret=E_OK;
    if (!(led))
    { ret=E_NOT_OK;
        
    }
    else
    {
    pin_config_t pin_obj ;
    pin_obj.direction =OUTPUT ;
     pin_obj.pin =led->pin ;
     pin_obj.port=led->port_name;
     pin_obj.logic=led->led_status;
       ret=gpio_pin_write_logic(&pin_obj,LOW);
    }
    
}
Std_ReturnType led_turn_toggle(const led_t *led){
     Std_ReturnType ret=E_OK;
    if (!(led))
    { ret=E_NOT_OK;
        
    }
    else
    {
    pin_config_t pin_obj ;
    pin_obj.direction =OUTPUT ;
     pin_obj.pin =led->pin ;
     pin_obj.port=led->port_name;
     pin_obj.logic=led->led_status;
       ret=gpio_pin_toggle_logic(&pin_obj);
    }
    
}
