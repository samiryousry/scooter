#include "hal_gpio.h"
#include "GPIO_CONFIG.h"
 volatile uint8 *tris_register[]={&TRISA,&TRISB, &TRISC ,&TRISD ,&TRISE};
 volatile uint8 *lat_register[]={&LATA,&LATB, &LATC ,&LATD ,&LATE};
 volatile uint8 *port_register[]={&PORTA,&PORTB, &PORTC ,&PORTD ,&PORTE};
#if GPIO_PORT_PIN_CONFIGURATIONS ==CONFIG_ENABLE
Std_ReturnType gpio_pin_intilaize(const pin_config_t *pin){
    Std_ReturnType ret=E_OK;
   if (!(pin)||((pin->pin)>(PORT_PIN_MAX_NUMBER-1)))
    { ret=E_NOT_OK;
        
    }
    else
    {  switch(pin->direction)
    { case INPUT:
        SET_BIT(*(tris_register[pin->port]),pin->pin);
        break ;
  case OUTPUT:
    CLEAR_BIT(*(tris_register[pin->port]),pin->pin);
      break ;
        default : ret=E_NOT_OK;
    }}
return ret ;}
#endif
#if GPIO_PORT_PIN_CONFIGURATIONS ==CONFIG_ENABLE
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *pin ,direction_t *status){
    Std_ReturnType ret=E_OK;
     if (!(pin))
          { ret=E_NOT_OK;
        
    }else {*status =READ_BIT(*tris_register[pin->port],(pin->pin));
   
    } return ret ;}
#endif
#if GPIO_PORT_PIN_CONFIGURATIONS ==CONFIG_ENABLE
Std_ReturnType gpio_pin_write_logic(const pin_config_t *pin ,logic_t logic){
        Std_ReturnType ret=E_OK;
     if (!(pin))
          { ret=E_NOT_OK;
        
    }else {
         switch(logic)
         {
             case HIGH :SET_BIT(*lat_register[pin->port],pin->pin);
             break;
         case LOW :CLEAR_BIT(*lat_register[pin->port],pin->pin);  
         break;
             default :ret=E_NOT_OK;
         }
    } return ret ;
}
#endif
#if GPIO_PORT_PIN_CONFIGURATIONS ==CONFIG_ENABLE
Std_ReturnType gpio_pin_read_logic(const pin_config_t *pin ,logic_t *status){
        Std_ReturnType ret=E_OK;
     if (!(pin))
          { ret=E_NOT_OK;
        
    }else {*status =READ_BIT(*port_register[pin->port],(pin->pin));
   
    } return ret ;
}
#endif
#if GPIO_PORT_PIN_CONFIGURATIONS ==CONFIG_ENABLE
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *pin ){
        Std_ReturnType ret=E_OK;
     if (!(pin))
          { ret=E_NOT_OK;
        
    }else {
     TOGGLE_BIT(*lat_register[pin->port],pin->pin);
    } return ret ;
}
#endif
Std_ReturnType gpio_port_direction_intialize(port_index_t port, uint8 direction){
    Std_ReturnType ret=E_OK;
    if (port>(PORT_MAX_NUMBER-1))
    { ret=E_NOT_OK;
        
    }
    else
    {
    *tris_register[port]=direction;
      
    }
return ret ;}

Std_ReturnType gpio_port_write_logic(port_index_t port ,logic_t logic){
    Std_ReturnType ret=E_OK;
    if (port>(PORT_MAX_NUMBER-1))
    { ret=E_NOT_OK;
        
    }
    else
    {
    *lat_register[port]=logic;
      
    }
return ret ;}
Std_ReturnType gpio_port_read_logic(port_index_t port ,logic_t *logic){
Std_ReturnType ret=E_OK;
    if(!logic)
    {ret=E_NOT_OK;}
    else 
    {
   *logic=*port_register[port];
    }
return ret ;
}

Std_ReturnType gpio_port_toggle_logic(port_index_t port ){
Std_ReturnType ret=E_OK;
    if (port>(PORT_MAX_NUMBER-1))
    { ret=E_NOT_OK;
        
    }
    else
    {
    *lat_register[port]^=PORTC_MASK;
      
    }
return ret ;}
