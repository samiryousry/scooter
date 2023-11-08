/* 
 * File:   main.h
 * Author: Lenovo
 *
 * Created on November 8, 2023, 8:24 PM
 */

#ifndef MAIN_H
#define	MAIN_H
#include "INC/ECU/button.h"
#include "INC/ECU/HAL_LED.h"
#include "INC/ECU/motor.h"
#include <stdio.h>
#include <stdlib.h>
void scooter_forward();
 void scooter_backward();
void  system_init();
void scooter_stop();
#define duty 25
#endif	/* MAIN_H */

