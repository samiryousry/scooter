
#include "timer3.h"
static inline void prescaler_set_timer3(timer3_t *Timer_obj);
static inline void read_mode(timer3_t *Timer_obj);
static inline void mode_set_timer3(timer3_t *Timer_obj);
static void(*Handler)(void) =NULL;
uint16 preloaded_val=0;
Std_ReturnType timer3_init(timer3_t *Timer_obj)
{Std_ReturnType ret =E_OK;
    if(!(Timer_obj))
    {ret=E_NOT_OK;}
    else
    {
    TIMER3_DISABLE();
    prescaler_set_timer3(Timer_obj);
    mode_set_timer3(Timer_obj);
    #if TIMER3_INTERRUPTS==INTERRUPT_ENABLE
TIMER3_INT_ENABLE();
GLOBAL_INTERRPT_ENABLE();
GLOBAL_Peripheral_INTERRPT_ENABLE();
TIMER3_INT_FLAG_CLEAR();

#endif

    
TMR0H = ((Timer_obj->Preloaded_Value)>>8); 
TMR0L = (uint8)(Timer_obj->Preloaded_Value);     
Handler=(Timer_obj->timer_handler );
preloaded_val=(Timer_obj->Preloaded_Value);
read_mode( Timer_obj);
TIMER3_ENABLE();
    }
return ret;
    
}
Std_ReturnType timer3_DE_init(timer3_t *Timer_obj)
{
     Std_ReturnType ret =E_OK;
    if(!(Timer_obj))
    {ret=E_NOT_OK;}
    else
    {TIMER3_DISABLE();
    
    }return ret;
}
Std_ReturnType timer3_write_value(timer3_t *Timer_obj,uint16 value){
 Std_ReturnType ret =E_OK;
    if(!(Timer_obj))
    {ret=E_NOT_OK;}
    else
    { TMR3H = ((value)>>8); 
TMR3L = (uint8)(value); 
    }return ret;}
Std_ReturnType timer3_read_value(timer3_t *Timer_obj,uint16 *value){
     Std_ReturnType ret =E_OK;  
    uint8 low_val=0;  uint8 high_val=0; 
    if(!(Timer_obj))
    {ret=E_NOT_OK;}
    else
    {low_val=TMR3L ;
   high_val =TMR3H ;
   *value =(uint16)(low_val+(high_val<<8)) ;   
}return ret;
}

static inline void prescaler_set_timer3(timer3_t *Timer_obj)
{ TIMER3_PRESCALAR=(Timer_obj->prescaler_value);
}
static inline void mode_set_timer3(timer3_t *Timer_obj)
{
 switch(Timer_obj->timer3_mode)  {
         case COUNTER_MODE: TIMER3_COUNTER_MODE() ; TIMER3_NO_SYINCHORNIZE_COUNTER()   ; break;
         case TIMER_MODE:   TIMER3_TIMER_MODE();   break;
 }}
 void timer_interrupt_handler_timer3(void)
{TIMER3_INT_FLAG_CLEAR();
TMR3H = ((preloaded_val)>>8); 
TMR3L = (uint8)(preloaded_val);     
if(Handler){
Handler();
}
 }
  static inline void read_mode(timer3_t *Timer_obj){
 if((Timer_obj->reg_write_mode)==READ_16BIT)
{TIMER3_16_bit_Read_Write_Mode_Enable()    ;}
else if((Timer_obj->reg_write_mode)==READ_8BIT)
{TIMER3_16_bit_Read_Write_Mode_disable()  ;}
  }