/* 
 * File:   led.h
 * Author: Lenovo
 *
 * Created on November 5, 2023, 9:58 PM
 */

#ifndef LED_H
#define	LED_H


/*Section :Includes */
#include "../MCAL/GPIO.h"
/*Section :Macro Declarations */

/*Section :Macro Functions Declarations */

/*Section :Data type Declarations */
typedef struct {
    uint8 port_name :4;
       uint8 pin :3;
         uint8 led_status :1;
    
}led_t;

/*Section :Functions Declarations  */
Std_ReturnType led_initialize(const led_t *led);
Std_ReturnType led_turn_on(const led_t *led);
Std_ReturnType led_turn_off(const led_t *led);
Std_ReturnType led_turn_toggle(const led_t *led);
#endif	/* LED_H */

