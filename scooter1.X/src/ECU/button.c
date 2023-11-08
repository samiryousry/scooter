#include "../../INC/ECU/button.h"
Std_ReturnType button_initialize(const button_t *btn)
{Std_ReturnType ret=E_OK;
    if (!(btn))
    { ret=E_NOT_OK;
        
    }
    else
    { 
    
        gpio_pin_intilaize(&(btn->button_pin));
       }
return ret;
}
Std_ReturnType button_read_state(const button_t *btn, button_state_t *btn_state)
{Std_ReturnType ret=E_OK;
logic_t Pin_logic =0;
    if ((!(btn))||(!(btn_state)))
    { ret=E_NOT_OK;
        
    }
    else
    {gpio_pin_read_logic(&(btn->button_pin),&Pin_logic);
    if(Pin_logic==HIGH){
        if((btn->button_connection)== BUTTON_ACTIVE_HIGH)
        {*btn_state=BUTTON_PRESSED;}
        else if((btn->button_connection)== BUTTON_ACTIVE_LOW)
        {
                *btn_state=BUTTON_RELEASED;
        }
    }
    else   if(Pin_logic==LOW){
        if((btn->button_connection)== BUTTON_ACTIVE_LOW)
        {*btn_state=BUTTON_PRESSED;}
        else if((btn->button_connection)== BUTTON_ACTIVE_HIGH)
        {
                *btn_state=BUTTON_RELEASED;
        }
    }
return ret; 
    }}