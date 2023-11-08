

#include "usart.h"
void(*UART_RX_ISR1)(void)=NULL ;
static void baud_rate(USART_t* uart_obj);
static void uart_config_pins(void);
static void interrupt_config(void);
Std_ReturnType USART_init(USART_t* uart_obj){
    baud_rate( uart_obj);
    uart_config_pins();
    interrupt_config();
    TXSTAbits.TX9=uart_obj->ninth_bit_state;
    UART_RX_ISR1=uart_obj->UART_RX_ISR ;
    TXSTAbits.SYNC=0;
   TXSTAbits.TXEN=1;
   RCSTAbits.SPEN=1;
   RCSTAbits.CREN=1;
}
Std_ReturnType USART_send_data(uint16 data)
{DATA_t all_data;
all_data.all_data=data;
TXREG=all_data.data_reg.data_bits;
TXSTAbits.TX9D=all_data.data_reg.ninth_bit;
       
    
}
Std_ReturnType USART_recieve_data(uint16 *data)
{DATA_t all_data;
all_data.data_reg.data_bits=RCREG;
  *data =all_data.all_data;
    
}
static void baud_rate(USART_t* uart_obj)
{ 
    BAUDCONbits.BRG16=1;
    baud_rate_t baudrate_reg_calc;
    baudrate_reg_calc.baud_rate_16bits =((_XTAL_FREQ/(64*(uart_obj->BAUD_RATE)))-1);
    
    SPBRGH=baudrate_reg_calc.baud_rate.lower_bits;   
     SPBRG=   baudrate_reg_calc.baud_rate.higher_bits;   
}
static void uart_config_pins(void)
{
    TRISCbits.RC6=1;
    TRISCbits.RC7=1;
}
static void interrupt_config(void)
{GLOBAL_INTERRPT_ENABLE();
 EUSART_RX_INT_FLAG_CLEAR();
  EUSART_TX_INT_FLAG_CLEAR();
GLOBAL_Peripheral_INTERRPT_ENABLE();
EUSART_RX_INT_ENABLE();
EUSART_TX_INT_DSABLE();

}
 void eusart_RX_ISR(void){
    EUSART_RX_INT_FLAG_CLEAR();
    if(UART_RX_ISR1){
    UART_RX_ISR1();
    }
 }