#include "../../INC/MCAL/timer0/timer0.h"
static void (*Handler)(void)=NULL ;
static inline void mode_set(timer0_t *Timer_obj);
static inline void bit_mode_set(timer0_t *Timer_obj);
static inline void prescaler_set(timer0_t *Timer_obj);
 void timer_interrupt_handler(void);
 static uint16 preloaded_val=0;
Std_ReturnType timer0_init(timer0_t *Timer_obj)
{Std_ReturnType ret =E_OK;
    if(!(Timer_obj))
    {ret=E_NOT_OK;}
    else
    {
    TIMER0_DISABLE();
    prescaler_set(Timer_obj);
    bit_mode_set(Timer_obj);
    mode_set(Timer_obj);
    #if TIMER0_INTERRUPTS==INTERRUPT_ENABLE
TIMER0_INT_ENABLE();
GLOBAL_INTERRPT_ENABLE();
GLOBAL_Peripheral_INTERRPT_ENABLE();
TIMER0_INT_FLAG_CLEAR();

#endif
TMR0H = ((Timer_obj->Preloaded_Value)>>8); 
TMR0L = (uint8)(Timer_obj->Preloaded_Value);     
Handler=(Timer_obj->timer_handler );
preloaded_val=(Timer_obj->Preloaded_Value);
TIMER0_ENABLE();
    }
return ret;}
Std_ReturnType timer0_DE_init(timer0_t *Timer_obj)
{   Std_ReturnType ret =E_OK;
    if(!(Timer_obj))
    {ret=E_NOT_OK;}
    else
    {TIMER0_DISABLE();
    
    }return ret;}
Std_ReturnType timer0_write_value(timer0_t *Timer_obj,uint16 value){
    Std_ReturnType ret =E_OK;
    if(!(Timer_obj))
    {ret=E_NOT_OK;}
    else
    { TMR0H = ((value)>>8); 
TMR0L = (uint8)(value); 
    }return ret;
}
Std_ReturnType timer0_read_value(timer0_t *Timer_obj,uint16 *value){
    Std_ReturnType ret =E_OK;  
    uint8 low_val=0;  uint8 high_val=0; 
    if(!(Timer_obj))
    {ret=E_NOT_OK;}
    else
    {low_val=TMR0L ;
   high_val =TMR0H ;
   *value =(uint16)(low_val+(high_val<<8)) ;   
}return ret;}
static inline void bit_mode_set(timer0_t *Timer_obj)
{ if((Timer_obj->timer0_register_size)==TIMER0_16bit_MODE)
{
TIMER0_16_BIT();
}
else if((Timer_obj->timer0_register_size)==TIMER0_8bit_MODE)
{
TIMER0_8_BIT();
}
else{//do nothing}
}}
void timer_ISR(void)
{
    TIMER0_INT_FLAG_CLEAR();
    if(Handler){
Handler();
    }}
static inline void prescaler_set(timer0_t *Timer_obj)
{ if(Timer_obj->prescaler_enable==PRESCALAR_ENABLE)
{
TIMER0_PRESCALAR_VALUE=(Timer_obj->prescaler_value);
    TIMER0_PRESCALAR_ENABLE();} 
else if(Timer_obj->prescaler_enable==PRESCALAR_DISABLE)
{TIMER0_PRESCALAR_DISABLE();
}
else{//do no thing
}}
static inline void mode_set(timer0_t *Timer_obj)
{
    if((Timer_obj->timer0_mode)==COUNTER_MODE)
{
    TIMER0_COUNTER_MODE();
    if(Timer_obj->timer0_counter_edge==RISING_EDGE)
    {
        TIMER0_COUNTER_MODE_RISING_EGDE();
    }
    else if(Timer_obj->timer0_counter_edge==FALLING_EDGE)
    {
        TIMER0_COUNTER_MODE_FALLING_EGDE();
    }
}
else if((Timer_obj->timer0_mode)==TIMER_MODE)
{
    TIMER0_TIMER_MODE();
}   
}
 void timer_interrupt_handler(void)
{TIMER0_INT_FLAG_CLEAR();
TMR0H = ((preloaded_val)>>8); 
TMR0L = (uint8)(preloaded_val);     
if(Handler){
Handler();
}
 }