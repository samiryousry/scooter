#include "I2C_MASTER.h"
/*--------------------------------------------STATIC Functions Declration-------------------------------------------------*/
static void i2c_config_pins(void);
static void i2_c_master_config_clock(I2C_t* );
static void i2_c_slave_config_id(I2C_t* );
static void SET_MODE(I2C_t* );
static void slave_genral_call_state_CONFIG(I2C_t* );
static void interrupt_settings(void);
/*--------------------------------------------Functions Defintions-------------------------------------------------*/
Std_ReturnType I2C_init(const I2C_t*I2C_obj)
{ Std_ReturnType ret=E_OK;
    interrupt_settings();
if(I2C_obj){
        i2c_config_pins();
        if(I2C_obj->device_mode==MASTER)
        {i2_c_master_config_clock(I2C_obj);
        }
        else if(I2C_obj->device_mode==SLAVE){
            i2_c_slave_config_id(I2C_obj);
            slave_genral_call_state_CONFIG(I2C_obj);
        }
        
        else{/*do noting*/}
        SET_MODE(I2C_obj);
    I2C_INIT();}
else
{
        ret=E_NOT_OK;
}
return ret;
}
Std_ReturnType I2C_DEinit(const I2C_t*I2C_obj)
{Std_ReturnType ret=E_OK;
    if(I2C_obj){
    I2C_deINIT();}
   else
{
        ret=E_NOT_OK;
}
return ret;
}
Std_ReturnType I2C_Send_Data(uint8 data,uint8 slave_id){
   
    Std_ReturnType ret=E_OK;
    MASTER_SEND_START_BIT();
    __delay_ms(1);
    SSPBUF=slave_id;
    __delay_ms(1);
    while(SSPSTATbits.BF);
    __delay_ms(1);
    if(SLAVE_ACK_STATE==1){
        
          MASTER_SEND_STOP_BIT();
        return  ret=E_NOT_OK;
    }
    __delay_ms(1);
    SSPBUF=data;
    __delay_ms(1);
    MASTER_SEND_STOP_BIT();
    __delay_ms(1);
      return  ret;
    }
 

Std_ReturnType I2C_recieve_Data(uint32 *data){
    
}
/*--------------------------------------------STATICFunctions Defintions-------------------------------------------------*/
static void i2c_config_pins(void)
{ CLOCK_PIN_DIRECTION=INPUT; /*clock pin*/
DATA_PIN_DIRECTION=INPUT;   /*data pin*/
}
static void i2_c_master_config_clock(I2C_t* I2C_obj)
{  SSPADD=(uint8)((_XTAL_FREQ/(4.0*I2C_obj->sck))-1);
}
static void i2_c_slave_config_id(I2C_t* I2C_obj)
{  SSPADD=I2C_obj->slave_ID;
}
static void SET_MODE(I2C_t* I2C_obj)
{  if(I2C_obj->device_mode==MASTER)
{SSPCON1bits.SSPM=MASTER_MODE;
    
}
else if(I2C_obj->device_mode==SLAVE)
{SSPCON1bits.SSPM=SLAVE_7BIT_ADDRESS;
    
}
}
static void slave_genral_call_state_CONFIG(I2C_t* I2C_obj){
    if(I2C_obj->general_call==genral_call_respond)
    {
        SLAVE_genral_call_respond();
    }
    else if(I2C_obj->general_call==genral_call_ignore)
    {
        SLAVE_genral_call_ignore();
    }
}

  /*SSPADD used for baud rate */
static void interrupt_settings(void)
{
    GLOBAL_INTERRPT_ENABLE();
    GLOBAL_Peripheral_INTERRPT_ENABLE();
    MSSP_I2C_INT_ENABLE();
   
}