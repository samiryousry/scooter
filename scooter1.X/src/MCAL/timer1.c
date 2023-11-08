#include "timer1.h"
static inline void prescaler_set_timer1(timer1_t *Timer_obj);
static inline void read_mode(timer1_t *Timer_obj);
static inline void mode_set_timer1(timer1_t *Timer_obj);
static void(*Handler)(void) =NULL;
uint16 preloaded_val=0;
Std_ReturnType timer1_init(timer1_t *Timer_obj)
{Std_ReturnType ret =E_OK;
    if(!(Timer_obj))
    {ret=E_NOT_OK;}
    else
    {
    TIMER1_DISABLE();
    prescaler_set_timer1(Timer_obj);
    mode_set_timer1(Timer_obj);
    #if TIMER1_INTERRUPTS==INTERRUPT_ENABLE
TIMER1_INT_ENABLE();
GLOBAL_INTERRPT_ENABLE();
GLOBAL_Peripheral_INTERRPT_ENABLE();
TIMER1_INT_FLAG_CLEAR();

#endif

    
TMR0H = ((Timer_obj->Preloaded_Value)>>8); 
TMR0L = (uint8)(Timer_obj->Preloaded_Value);     
Handler=(Timer_obj->timer_handler );
preloaded_val=(Timer_obj->Preloaded_Value);
read_mode( Timer_obj);
TIMER1_ENABLE();
    }
return ret;
    
}
Std_ReturnType timer1_DE_init(timer1_t *Timer_obj)
{
     Std_ReturnType ret =E_OK;
    if(!(Timer_obj))
    {ret=E_NOT_OK;}
    else
    {TIMER1_DISABLE();
    
    }return ret;
}
Std_ReturnType timer1_write_value(timer1_t *Timer_obj,uint16 value){
 Std_ReturnType ret =E_OK;
    if(!(Timer_obj))
    {ret=E_NOT_OK;}
    else
    { TMR1H = ((value)>>8); 
TMR1L = (uint8)(value); 
    }return ret;}
Std_ReturnType timer1_read_value(timer1_t *Timer_obj,uint16 *value){
     Std_ReturnType ret =E_OK;  
    uint8 low_val=0;  uint8 high_val=0; 
    if(!(Timer_obj))
    {ret=E_NOT_OK;}
    else
    {low_val=TMR1L ;
   high_val =TMR1H ;
   *value =(uint16)(low_val+(high_val<<8)) ;   
}return ret;
}

void timer_ISR_1(void)
{
    TIMER0_INT_FLAG_CLEAR();
    if(Handler){
Handler();
    }}
static inline void prescaler_set_timer1(timer1_t *Timer_obj)
{ TIMER1_PRESCALAR=(Timer_obj->prescaler_value);
}
static inline void mode_set_timer1(timer1_t *Timer_obj)
{
 switch(Timer_obj->timer1_mode)  {
         case COUNTER_MODE: TIMER1_COUNTER_MODE() ; TIMER1_NO_SYINCHORNIZE_COUNTER()   ; break;
         case TIMER_MODE:   TIMER1_TIMER_MODE();   break;
 }}
 void timer_interrupt_handler_timer1(void)
{TIMER1_INT_FLAG_CLEAR();
TMR1H = ((preloaded_val)>>8); 
TMR1L = (uint8)(preloaded_val);     
if(Handler){
Handler();
}
 }
  static inline void read_mode(timer1_t *Timer_obj){
 if((Timer_obj->reg_write_mode)==READ_16BIT)
{TIMER1_16_bit_Read_Write_Mode_Enable()    ;}
else if((Timer_obj->reg_write_mode)==READ_8BIT)
{TIMER1_16_bit_Read_Write_Mode_disable()  ;}
  }