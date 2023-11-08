    #include "E:\diploma embeded\scooter1.X\INC\MCAL\CCP.h"

static Std_ReturnType CCP_Capture_Mode_Config(const ccp_t *_ccp_obj);
static Std_ReturnType CCP_Compare_Mode_Config(const ccp_t *_ccp_obj);
static void CCP_Mode_Timer_Select(const ccp_t *_ccp_obj);
static void CCP_Mode_interrupt(const ccp_t *_ccp_obj);
Std_ReturnType CCP_Init(const ccp_t *_ccp_obj)
{ Std_ReturnType ret =E_OK;
    if(!(_ccp_obj))
{ret=E_NOT_OK ;
}
else
{ gpio_pin_intilaize(&(_ccp_obj->ccp_pin));
if(_ccp_obj->ccp_inst==CCP1_INST){
  CCP1_SET_MODE(CCP_disable);}
 else if(_ccp_obj->ccp_inst==CCP2_INST){
   CCP2_SET_MODE(CCP_disable);
    }
  
    
   
        #if(CCP1_CFG_SELECTED_MODE==CCP_CFG_CAPTURE_MODE_SELECTED) 
 if(CCP_CAPTURE_MODE_SELECTED==_ccp_obj->ccp1_mode){
      CCP_Capture_Mode_Config(_ccp_obj);
 }
#endif
  #if(CCP1_CFG_SELECTED_MODE==CCP_CFG_COMPARE_MODE_SELECTED) 
 if(CCP_COMPARE_MODE_SELECTED==_ccp_obj->ccp1_mode)
{CCP_Compare_Mode_Config(_ccp_obj);
    
}
#endif
 #if(CCP1_CFG_SELECTED_MODE==CCP_CFG_PWM_MODE_SELECTED)       
 if(CCP_PWM_MODE_SELECTED==_ccp_obj->ccp1_mode)
{
    if(_ccp_obj->ccp_inst==CCP1_INST){
  CCP1_SET_MODE(CCP_PWM_MODE);
    }
    else if(_ccp_obj->ccp_inst==CCP2_INST){
  CCP2_SET_MODE(CCP_PWM_MODE);
    }
    PR2=(_XTAL_FREQ/4/_ccp_obj->pwm_frequncy/_ccp_obj->timer2_postscaler_value/_ccp_obj->timer2_prescaler_value-1);
//
    PIR1bits.TMR2IF=0;
    T2CONbits.T2CKPS=4;
    T2CONbits.TMR2ON=1;
}
     #endif

}
return ret ;
}
    

Std_ReturnType CCP_DeInit(const ccp_t *_ccp_obj)
{
    Std_ReturnType ret =E_OK;
    if(!(_ccp_obj))
{ret=E_NOT_OK ;
}
else
{ if(_ccp_obj->ccp_inst==CCP1_INST){
 CCP1_SET_MODE(CCP_disable);

    }
    else if(_ccp_obj->ccp_inst==CCP2_INST){
   CCP2_SET_MODE(CCP_disable);

    }


}
return ret ;
}


#if (CCP1_CFG_SELECTED_MODE==CCP_CFG_CAPTURE_MODE_SELECTED)
static Std_ReturnType CCP_Capture_Mode_Config(const ccp_t *_ccp_obj){
    Std_ReturnType ret =E_OK;
  if((_ccp_obj->ccp_inst)==CCP1_INST){
        switch(_ccp_obj->ccp_mode_varient)
   {case Capture_mode_every_falling_edge :CCP1_SET_MODE(Capture_mode_every_falling_edge); break;
    case Capture_mode_every_rising_edge :CCP1_SET_MODE(Capture_mode_every_rising_edge);break;
    case Capture_mode_every_4_th_rising_edge :CCP1_SET_MODE(Capture_mode_every_4_th_rising_edge);break;
    case Capture_mode_every_16_th_rising_edge :CCP1_SET_MODE(Capture_mode_every_16_th_rising_edge);break;
       default:ret=E_NOT_OK ;
   }
      
    }
else if(_ccp_obj->ccp_inst==CCP2_INST){
      switch(_ccp_obj->ccp_mode_varient)
   {case Capture_mode_every_falling_edge :CCP2_SET_MODE(Capture_mode_every_falling_edge);break;
    case Capture_mode_every_rising_edge :CCP2_SET_MODE(Capture_mode_every_rising_edge);break;
    case Capture_mode_every_4_th_rising_edge :CCP2_SET_MODE(Capture_mode_every_4_th_rising_edge);break;
    case Capture_mode_every_16_th_rising_edge :CCP2_SET_MODE(Capture_mode_every_16_th_rising_edge);break;
       default:ret=E_NOT_OK ;
   }
     }   
    CCP_Mode_Timer_Select(_ccp_obj);
}
Std_ReturnType CCP1_IsCapturedDataReady(uint8 *_capture_status)
{ Std_ReturnType ret =E_OK;
    if(!(_capture_status))
{ret=E_NOT_OK ;
}
else
{ 
    if(1==PIR1bits.CCP1IF)
    {*_capture_status =CCP1_CAPTURE_READY;
        CCP1_INT_FLAG_CLEAR();
    }else if(0==PIR1bits.CCP1IF)
    {*_capture_status =CCP1_CAPTURE_NOT_READY;
        
    }
}return ret ;
}
Std_ReturnType CCP1_Capture_Mode_Read_Value(uint16 *capture_value)
{Std_ReturnType ret =E_OK;
    if(!(capture_value))
{ret=E_NOT_OK ;
}
else
{ CCP_REG_T temp_val={.ccpr1_16bit=0};
 temp_val.ccpr1_low= CCPR1L ;
 temp_val.ccpr1_high= CCPR1H ;
 *capture_value=temp_val.ccpr1_16bit;
}return ret ;
}
#endif

#if (CCP1_CFG_SELECTED_MODE==CCP_CFG_COMPARE_MODE_SELECTED)||(CCP2_CFG_SELECTED_MODE==CCP_CFG_COMPARE_MODE_SELECTED)
Std_ReturnType CCP_IsCompareComplete(uint8 *_compare_status)
{Std_ReturnType ret =E_OK;
    if(!(_compare_status))
{ret=E_NOT_OK ;
}
else
{ 
    if(1==PIR1bits.CCP1IF)
    {*_compare_status =CCP1_COMPARE_READY;
       
    }else if(0==PIR1bits.CCP1IF)
    {*_compare_status =CCP1_COMPARE_NOT_READY;
        
    }
}return ret ;
    
}
Std_ReturnType CCP_Compare_Mode_Set_Value(const ccp_t *_ccp_obj, uint16 compare_value){
  Std_ReturnType ret =E_OK;
  CCP_REG_T temp_val={.ccpr1_16bit=0};
  temp_val.ccpr1_16bit= compare_value ;
  if((_ccp_obj->ccp_inst)==CCP1_INST){
  
  CCPR1L =temp_val.ccpr1_low  ;
  CCPR1H=temp_val.ccpr1_high ;}
  else if((_ccp_obj->ccp_inst)==CCP2_INST)
  {
     
  CCPR2L =temp_val.ccpr1_low  ;
  CCPR2H=temp_val.ccpr1_high ; 
  }
  return ret ;
}
#endif

#if (CCP1_CFG_SELECTED_MODE==CCP_CFG_PWM_MODE_SELECTED)
Std_ReturnType CCP_PWM_Set_Duty(const ccp_t *_ccp_obj, const uint8 _duty){
     Std_ReturnType ret =E_OK;
     uint16 l_duty_temp = 0;
     if(!(_ccp_obj))
{ret=E_NOT_OK ;

}
else
{  l_duty_temp=((_duty*4*(PR2+1)/100.0));
         if(_ccp_obj->ccp_inst==CCP1_INST){
        
CCP1CONbits.DC1B=(uint8)(l_duty_temp&3);
CCPR1L=(uint8)(l_duty_temp>>2);}
else if(_ccp_obj->ccp_inst==CCP2_INST)
{
CCP2CONbits.DC2B=(uint8)(l_duty_temp&3);
CCPR2L=(uint8)(l_duty_temp>>2);}



}
     return ret ;
}
Std_ReturnType CCP_PWM_Start(const ccp_t *_ccp_obj){
       Std_ReturnType ret =E_OK;
     if(!(_ccp_obj))
{ret=E_NOT_OK ;
}
else
{ if(_ccp_obj->ccp_inst==CCP1_INST){
         (CCP1CONbits.CCP1M)=CCP_PWM_MODE;}
else if(_ccp_obj->ccp_inst==CCP2_INST)
{
(CCP2CONbits.CCP2M)=CCP_PWM_MODE;
if(PIR1bits.TMR2IF==1)
TRISCbits.RC1=0;
}}
 return ret ;      
}
Std_ReturnType CCP_PWM_Stop(const ccp_t *_ccp_obj){
 Std_ReturnType ret =E_OK;
 if(!(_ccp_obj))
{ret=E_NOT_OK ;
}
else
{ if(_ccp_obj->ccp_inst==CCP1_INST){
     (CCP1CONbits.CCP1M)=CCP_disable ;}
else if(_ccp_obj->ccp_inst==CCP2_INST){
     (CCP2CONbits.CCP2M)=CCP_disable ;}
} 
 return ret ;
}
#endif
/*
static void CCP_Mode_Timer_Select(const ccp_t *_ccp_obj)
{
 if(!(_ccp_obj))
{
}
else{
     switch(_ccp_obj->ccp_capture_timer)
     {
     case CCP1_CCP2_TIMER3:    (T3CONbits.T3CCP1=1);      (T3CONbits.T3CCP2=1);             break;
     case CCP1_TIMER1_CCP2_TIMER3:  (T3CONbits.T3CCP1=1);      (T3CONbits.T3CCP2=0);                  break;
     case CCP1_CCP2_TIMER1:    (T3CONbits.T3CCP1=0);      (T3CONbits.T3CCP2=0);                  break;
     
     }
    } 

}

static Std_ReturnType CCP_Compare_Mode_Config(const ccp_t *_ccp_obj){
    Std_ReturnType ret=E_OK;
     if(!(_ccp_obj))
{ ret=E_NOT_OK ;
}
else {
         if(_ccp_obj->ccp_inst==CCP1_INST){
switch(_ccp_obj->ccp_mode_varient)
   {case Compare_mode_toggle_output_on_match :CCP1_SET_MODE(Compare_mode_toggle_output_on_match); break;
    case CCP_COMPARE_MODE_SET_PIN_LOW :CCP1_SET_MODE(CCP_COMPARE_MODE_SET_PIN_LOW);break;
    case CCP_COMPARE_MODE_SET_PIN_HIGH :CCP1_SET_MODE(CCP_COMPARE_MODE_SET_PIN_HIGH);break;
    case CCP_COMPARE_MODE_GEN_SW_INTERRUPT :CCP1_SET_MODE(CCP_COMPARE_MODE_GEN_SW_INTERRUPT);break;
    case CCP_COMPARE_MODE_GEN_EVENT :CCP1_SET_MODE(CCP_COMPARE_MODE_GEN_EVENT);break;
        default:ret=E_NOT_OK ;}
      
         }
    else  if(_ccp_obj->ccp_inst==CCP2_INST){
        
        switch(_ccp_obj->ccp_mode_varient)
   {case Compare_mode_toggle_output_on_match :CCP2_SET_MODE(Compare_mode_toggle_output_on_match); break;
    case CCP_COMPARE_MODE_SET_PIN_LOW :CCP2_SET_MODE(CCP_COMPARE_MODE_SET_PIN_LOW);break;
    case CCP_COMPARE_MODE_SET_PIN_HIGH :CCP2_SET_MODE(CCP_COMPARE_MODE_SET_PIN_HIGH);break;
    case CCP_COMPARE_MODE_GEN_SW_INTERRUPT :CCP2_SET_MODE(CCP_COMPARE_MODE_GEN_SW_INTERRUPT);break;
    case CCP_COMPARE_MODE_GEN_EVENT :CCP2_SET_MODE(CCP_COMPARE_MODE_GEN_EVENT);break;
        default:ret=E_NOT_OK ;}
     
    }   CCP_Mode_Timer_Select(_ccp_obj);}
return ret;}
*/