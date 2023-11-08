/* ----------------- Includes -----------------*/
#ifndef BUTTON_H
#define	BUTTON_H
#include "../MCAL/GPIO.h"
/* ----------------- Data Type Declarations -----------------*/
typedef enum 
{
    BUTTON_PRESSED  ,
    BUTTON_RELEASED
           
}button_state_t;

typedef enum{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW
}button_active_t;
typedef struct{
    pin_config_t button_pin;
    button_state_t button_state;
    button_active_t button_connection;
}button_t;
/* ----------------- Software Interfaces Declarations -----------------*/

Std_ReturnType button_initialize(const button_t *btn);
Std_ReturnType button_read_state(const button_t *btn, button_state_t *btn_state);
#endif	/* BUTTON_H */

