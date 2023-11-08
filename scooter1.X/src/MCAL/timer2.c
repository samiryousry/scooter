#include "timer2.h"
static inline void prescaler_set_timer2(timer2_t *Timer_obj);
static inline void postscaler_set_timer2(timer2_t *Timer_obj);
static void(*Handler_2)(void) =NULL;
static uint8 value=0 ;
Std_ReturnType timer2_init(timer2_t *Timer_obj)
{   Std_ReturnType ret =E_OK;
    if(!(Timer_obj))
    {ret=E_NOT_OK;}
    else
    {
     TIMER2_DISABLE();
    prescaler_set_timer2(Timer_obj);
   Handler_2=(Timer_obj->timer_handler);
    #if TIMER2_INTERRUPTS==INTERRUPT_ENABLE
TIMER2_INT_ENABLE();
GLOBAL_INTERRPT_ENABLE();
GLOBAL_Peripheral_INTERRPT_ENABLE();
TIMER2_INT_FLAG_CLEAR();

#endif
TMR2=(Timer_obj->Preloaded_Value);
value=(Timer_obj->Preloaded_Value);
    postscaler_set_timer2(Timer_obj);
   
    TIMER2_ENABLE();
    }
return ret;  
}
Std_ReturnType timer2_DE_init(timer2_t *Timer_obj)
{ Std_ReturnType ret =E_OK;
    if(!(Timer_obj))
    {ret=E_NOT_OK;}
    else
    {TIMER2_DISABLE();
    }
return ret; 
    
}
Std_ReturnType timer2_write_value(timer2_t *Timer_obj,uint16 valuee){
   Std_ReturnType ret =E_OK;
    if(!(Timer_obj))
    {ret=E_NOT_OK;}
    else
    {TMR2=valuee;
    }
return ret; 
    
}
Std_ReturnType timer2_read_value(timer2_t *Timer_obj,uint16 *valuee){
    Std_ReturnType ret =E_OK;
    if(!(Timer_obj))
    {ret=E_NOT_OK;}
    else
    {*valuee=TMR2;
    }
return ret; 
    
}
static inline void prescaler_set_timer2(timer2_t *Timer_obj)
{
    TIMER2_PRESCALAR=(Timer_obj->prescaler_value);
}
static inline void postscaler_set_timer2(timer2_t *Timer_obj)
{
    TIMER2_POSTSCALAR=(Timer_obj->postscaler_value);
}
void timer_interrupt_handler_timer2(void)
{TIMER2_INT_FLAG_CLEAR();  
TMR2=value;
if(Handler_2){
Handler_2();
}
 }