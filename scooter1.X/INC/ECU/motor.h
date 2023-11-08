/* 
 * File:   DC_motor.h
 * Author: Lenovo
 *
 * 
 */

#ifndef DC_MOTOR_H
#define	DC_MOTOR_H

/*Section :Includes */
#include "../MCAL/GPIO.h"
/*Section :Data type Declarations */
typedef struct {
    uint8 port_name :4;
       uint8 pin :3;
         uint8 DC_motor_Pin_status :1;
    
}DC_motor_pin_t;

typedef struct {
    DC_motor_pin_t Motor_pins[2];
}DC_motor_t;
/*Section :Functions Declarations  */
Std_ReturnType DC_motor_initialize(const DC_motor_t *motor);
Std_ReturnType DC_motor_MOve_clock_Wise(const DC_motor_t *motor);
Std_ReturnType DC_motor_MOve_Anti_clock_Wise(const DC_motor_t *motor);
Std_ReturnType DC_motor_Stop(const DC_motor_t *motor);
#endif	/* DC_MOTOR_H */

