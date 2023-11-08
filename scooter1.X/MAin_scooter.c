/* 
 * File:   MAin_scooter.c
 * Author: Lenovo
 *
 * Created on November 3, 2023, 10:27 PM
 */


#include "main.h"
#include "src/ECU/seven_seg.h"
#include "INC/MCAL/CCP.h"
/**********************************************************Data declarations*****************************/
ccp_t motor_sp={.ccp1_mode=CCP_PWM_MODE_SELECTED,
.ccp_inst=CCP2_INST,
.ccp_pin.pin=PIN1,
.ccp_pin.port=PORTC_INDEX,
.pwm_frequncy=50,
.timer2_postscaler_value=CCP_TIMER2_POSTSCALER_DIV_BY_16,
.timer2_prescaler_value=CCP_TIMER2_PRESCALER_DIV_BY_16};
        
        
        
        
DC_motor_t motor_1={
    .Motor_pins[0].port_name=PORTD_INDEX,
    .Motor_pins[0].pin=  PIN0,
    .Motor_pins[0].DC_motor_Pin_status=LOW,
.Motor_pins[1].port_name=PORTD_INDEX,
    .Motor_pins[1].pin=PIN1,
    .Motor_pins[1].DC_motor_Pin_status=LOW};
  
DC_motor_t motor_2={
    .Motor_pins[0].port_name=PORTD_INDEX,
    .Motor_pins[0].pin=  PIN2
    ,.Motor_pins[0]. DC_motor_Pin_status=LOW,
.Motor_pins[1].port_name=PORTD_INDEX,
    .Motor_pins[1].pin=  PIN3,
    .Motor_pins[1]. DC_motor_Pin_status=LOW};
 segment_t myseg ={.Segment_Pins[0].pin=PIN0,
 .Segment_Pins[0].port=PORTC_INDEX,
 .Segment_Pins[1].pin=PIN4,
 .Segment_Pins[1].port=PORTC_INDEX,
 .Segment_Pins[2].pin=PIN2,
 .Segment_Pins[2].port=PORTC_INDEX,
 .Segment_Pins[3].pin=PIN3,
 .Segment_Pins[3].port=PORTC_INDEX,
 .segment_type=COMMON_CATHODE};  
        
        
button_t LIGHTS_btn_ON = {
    .button_pin.port = PORTB_INDEX,
    .button_pin.pin = PIN7,
    .button_pin.direction = INPUT,
    .button_pin.logic = LOW,
    .button_connection = BUTTON_ACTIVE_HIGH,
    .button_state = BUTTON_RELEASED
};
button_t MOTORS_FORWARD = {
    .button_pin.port = PORTD_INDEX,
    .button_pin.pin = PIN6,
    .button_pin.direction = INPUT,
    .button_pin.logic = LOW,
    .button_connection = BUTTON_ACTIVE_HIGH,
    .button_state = BUTTON_RELEASED
};
button_t MOTORS_BACKWARD = {
    .button_pin.port = PORTA_INDEX,
    .button_pin.pin = PIN4,
    .button_pin.direction = INPUT,
    .button_pin.logic = LOW,
    .button_connection = BUTTON_ACTIVE_HIGH,
    .button_state = BUTTON_RELEASED
};
button_t LIGHTS_btn_OFF = {
    .button_pin.port = PORTB_INDEX,
    .button_pin.pin = PIN6,
    .button_pin.direction = INPUT,
    .button_pin.logic = LOW,
    .button_connection = BUTTON_ACTIVE_HIGH,
    .button_state = BUTTON_RELEASED
};
  button_t Speed_up = {
    .button_pin.port = PORTA_INDEX,
    .button_pin.pin = PIN6,
    .button_pin.direction = INPUT,
    .button_pin.logic = LOW,
    .button_connection = BUTTON_ACTIVE_HIGH,
    .button_state = BUTTON_RELEASED
};
  button_t Speed_down = {
    .button_pin.port = PORTD_INDEX,
    .button_pin.pin = PIN4,
    .button_pin.direction = INPUT,
    .button_pin.logic = LOW,
    .button_connection = BUTTON_ACTIVE_HIGH,
    .button_state = BUTTON_RELEASED
};
led_t LIGHT_LED ={.pin=PIN5,.port_name=PORTD_INDEX};
button_active_t LIGHTS_btn_ON_activ =BUTTON_ACTIVE_LOW;
button_active_t LIGHTS_btn_OFF_activ =BUTTON_ACTIVE_LOW;
 button_active_t MOTORS_btn_FORWARD_activ =BUTTON_ACTIVE_LOW;
button_active_t MOTORS_btn_BACKWARD_activ =BUTTON_ACTIVE_LOW;
button_state_t speed_up_btn_state= BUTTON_RELEASED;
button_state_t speed_down_btn_state= BUTTON_RELEASED;
button_state_t speed_up_btn_state_final= BUTTON_RELEASED;
button_state_t speed_down_btn_state_final= BUTTON_RELEASED;
 uint32 MOTORS_FORWARD_button_high_valid =0;
  uint32 speed_up_button_high_valid =0;
   uint32 speed_down_button_high_valid =0;
  uint32 MOTORS_BACKWARD_button_high_valid =0;
  button_state_t Button_forward_state=BUTTON_RELEASED;
  button_state_t Button_Backward_state=BUTTON_RELEASED;
  uint8 data=0;
  
 /**********************************************************main program *****************************/

int main ()

{  
  system_init();

    while(1)
    {button_read_state(&Speed_up,&speed_up_btn_state);
    button_read_state(&Speed_down,&speed_down_btn_state);
    button_read_state(&LIGHTS_btn_OFF,&LIGHTS_btn_OFF_activ);
     button_read_state(&LIGHTS_btn_ON,&LIGHTS_btn_ON_activ);
     button_read_state(&MOTORS_BACKWARD,&MOTORS_btn_BACKWARD_activ);
     button_read_state(&MOTORS_FORWARD,&MOTORS_btn_FORWARD_activ);
     if(LIGHTS_btn_ON_activ==BUTTON_ACTIVE_HIGH)
         {
             led_turn_on(&LIGHT_LED);
         }
  if(LIGHTS_btn_OFF_activ==BUTTON_ACTIVE_HIGH)
         {
             led_turn_off(&LIGHT_LED);
         }
     if(MOTORS_btn_BACKWARD_activ==BUTTON_PRESSED)
     {MOTORS_BACKWARD_button_high_valid++;
     if(MOTORS_BACKWARD_button_high_valid>10)
     {
         Button_Backward_state=BUTTON_PRESSED;
     }
     
     else {}
    }else if(MOTORS_btn_BACKWARD_activ==BUTTON_RELEASED)
     {
         MOTORS_BACKWARD_button_high_valid=0;
         Button_Backward_state=BUTTON_RELEASED;
     }
     if(MOTORS_btn_FORWARD_activ==BUTTON_PRESSED)
     {MOTORS_FORWARD_button_high_valid++;
     if(MOTORS_FORWARD_button_high_valid>10)
     {
         Button_forward_state=BUTTON_PRESSED;
         
     }}else if(MOTORS_btn_FORWARD_activ==BUTTON_RELEASED)
     {Button_forward_state=BUTTON_RELEASED;
         MOTORS_FORWARD_button_high_valid=0;
     
     }
     if(Button_Backward_state==BUTTON_PRESSED)
     {
         scooter_forward();
     }
     if(Button_forward_state==BUTTON_PRESSED)
     {
         scooter_backward();
     }
      if((Button_Backward_state==BUTTON_RELEASED)&&(Button_forward_state==BUTTON_RELEASED))
     {
         scooter_stop();
     }
     if(speed_up_btn_state_final==BUTTON_PRESSED)
     {if(data<4){
         data++;}
     CCP_PWM_Stop(&motor_sp);
     CCP_PWM_Start(&motor_sp);
     CCP_PWM_Set_Duty(&motor_sp,data*duty);
     
     speed_up_btn_state_final=BUTTON_RELEASED;
         segment_write(&myseg,data);
     }
     if(speed_down_btn_state_final==BUTTON_PRESSED)
     {if(data>0){
         data--;}
     CCP_PWM_Stop(&motor_sp);
     CCP_PWM_Start(&motor_sp);
     CCP_PWM_Set_Duty(&motor_sp,data*duty);
     
     speed_down_btn_state_final=BUTTON_RELEASED;
         segment_write(&myseg,data);
     }
     if(speed_up_btn_state==BUTTON_PRESSED)
     {speed_up_button_high_valid++;
     if(speed_up_button_high_valid>100)
     {
         speed_up_btn_state_final=BUTTON_PRESSED;
          speed_up_button_high_valid=0;
     }
     
    }else if(speed_up_btn_state==BUTTON_RELEASED)
     {
         speed_up_button_high_valid=0;
         speed_up_btn_state_final=BUTTON_RELEASED;
     }
     if(speed_down_btn_state==BUTTON_PRESSED)
     {speed_down_button_high_valid++;
     if(speed_down_button_high_valid>100)
     {
         speed_down_btn_state_final=BUTTON_PRESSED;
         speed_down_button_high_valid=0;
     }
     
    }else if(speed_down_btn_state==BUTTON_RELEASED)
     {
         speed_down_button_high_valid=0;
         speed_down_btn_state_final=BUTTON_RELEASED;
     }
    }
  return 0;
    
    }
       
/**********************************************************functions  implementation *****************************/
void  system_init()
{   button_initialize(&LIGHTS_btn_ON);
    button_initialize(&LIGHTS_btn_OFF);
    button_initialize(&Speed_up);
    button_initialize(&Speed_down);
    button_initialize(&MOTORS_FORWARD);
    button_initialize(&MOTORS_BACKWARD);
    led_initialize(&LIGHT_LED);
    DC_motor_initialize(&motor_1);
    DC_motor_initialize(&motor_2);
    segment_intilaize(&myseg);
    CCP_Init(&motor_sp);
}
void scooter_forward(){
    DC_motor_MOve_clock_Wise(&motor_1);
     DC_motor_MOve_clock_Wise(&motor_2);
}
void scooter_backward(){
    DC_motor_MOve_Anti_clock_Wise(&motor_1);
     DC_motor_MOve_Anti_clock_Wise(&motor_2);
}
void scooter_stop()
{
    DC_motor_Stop(&motor_2);
      DC_motor_Stop(&motor_1);
}