/* 
 * File:   GPIO.h
 * Author: Lenovo
 *
 * Created on November 5, 2023, 9:47 PM
 */
/* 
 
 */
#ifndef HAL_GPIO_H
#define	HAL_GPIO_H


    /*Section :Includes */
#include "../device_config.h"
#include "pic18f4620.h"
#include "../std_types.h"

/*Section :Macro Declarations */
    #define  BIT_MASK                   0X01   
  #define  PORTC_MASK                   0XFF  
#define PORT_PIN_MAX_NUMBER  8
#define PORT_MAX_NUMBER      5
/*Section :Macro Functions Declarations */
#define  HWREG8(_X)         (*((volatile uint8 *)_X))
#define SET_BIT(REG,BIT)     (REG|=(BIT_MASK<<BIT))
#define TOGGLE_BIT(REG,BIT)     (REG^=(BIT_MASK<<BIT))
#define CLEAR_BIT(REG,BIT)     (REG&=~(BIT_MASK<<BIT))
#define READ_BIT(REG,BIT)     ((REG>>BIT)&BIT_MASK)
    /*Section :Data type Declarations */
typedef enum {
   LOW =0,
   HIGH
}logic_t;
typedef enum {
   OUTPUT =0,
   INPUT
}direction_t;
typedef enum {
   PIN0 =0,
   PIN1,
   PIN2,
   PIN3,
   PIN4,
   PIN5,
   PIN6,
   PIN7
           
}pin_index_t;
typedef enum {
  PORTA_INDEX=0,
   PORTB_INDEX,
   PORTC_INDEX,
  PORTD_INDEX,
   PORTE_INDEX
   
           
}port_index_t;
typedef struct {
    uint8 pin :3 ;
    uint8 port :3 ;
    uint8 direction :1;
    uint8 logic :1 ;
}pin_config_t;  
/*Section :Functions Declarations  */
Std_ReturnType gpio_pin_intilaize(const pin_config_t *pin);
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *pin ,direction_t *status);
Std_ReturnType gpio_pin_write_logic(const pin_config_t *pin ,logic_t logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t *pin ,logic_t *status);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *pin );
Std_ReturnType gpio_port_direction_intialize(port_index_t port, uint8 direction);

Std_ReturnType gpio_port_write_logic(port_index_t port ,logic_t logic);
Std_ReturnType gpio_port_read_logic(port_index_t port ,logic_t *logic);
Std_ReturnType gpio_port_toggle_logic(port_index_t port );
#endif	/* HAL_GPIO_H */


