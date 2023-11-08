/* 
 * File:   CCP1.h
 * Author: Lenovo
 *
 * Created on April 2, 2023, 2:23 PM
 */

#ifndef CCP1_H
#define	CCP1_H


                                      /* Section : Includes */

#include "pic18f4620.h"
#include "../std_types.h"
#include "GPIO.h"   
#include "ccp1_cnfg.h"
/*-------------------------------------------Section :Macro declarations   -------------------------------------------*/
 #define   CCP_disable                                             ((uint8)0x00)
 #define   Compare_mode_toggle_output_on_match                     ((uint8)0x02)
 #define   Capture_mode_every_falling_edge                         ((uint8)0x04)
 #define   Capture_mode_every_rising_edge                          ((uint8)0x05)
 #define   Capture_mode_every_4_th_rising_edge                     ((uint8)0x06)
 #define   Capture_mode_every_16_th_rising_edge                    ((uint8)0x07)
 #define   CCP_COMPARE_MODE_SET_PIN_LOW                            ((uint8)0x08)
 #define   CCP_COMPARE_MODE_SET_PIN_HIGH                           ((uint8)0x09)
 #define   CCP_COMPARE_MODE_GEN_SW_INTERRUPT                       ((uint8)0x0A)
 #define   CCP_COMPARE_MODE_GEN_EVENT                              ((uint8)0x0B)
 #define   CCP_PWM_MODE                                            ((uint8)0x0C)
#define CCP_TIMER2_POSTSCALER_DIV_BY_1       1
#define CCP_TIMER2_POSTSCALER_DIV_BY_2       2
#define CCP_TIMER2_POSTSCALER_DIV_BY_3       3
#define CCP_TIMER2_POSTSCALER_DIV_BY_4       4
#define CCP_TIMER2_POSTSCALER_DIV_BY_5       5
#define CCP_TIMER2_POSTSCALER_DIV_BY_6       6
#define CCP_TIMER2_POSTSCALER_DIV_BY_7       7
#define CCP_TIMER2_POSTSCALER_DIV_BY_8       8
#define CCP_TIMER2_POSTSCALER_DIV_BY_9       9
#define CCP_TIMER2_POSTSCALER_DIV_BY_10      10
#define CCP_TIMER2_POSTSCALER_DIV_BY_11      11
#define CCP_TIMER2_POSTSCALER_DIV_BY_12      12
#define CCP_TIMER2_POSTSCALER_DIV_BY_13      13
#define CCP_TIMER2_POSTSCALER_DIV_BY_14      14
#define CCP_TIMER2_POSTSCALER_DIV_BY_15      15
#define CCP_TIMER2_POSTSCALER_DIV_BY_16      16

/* Timer2 Input Clock Pre-scaler */
#define CCP_TIMER2_PRESCALER_DIV_BY_1        1
#define CCP_TIMER2_PRESCALER_DIV_BY_4        4
#define CCP_TIMER2_PRESCALER_DIV_BY_16       16

/* CCP1 Capture Mode State  */
#define    CCP1_CAPTURE_NOT_READY              0X00
#define    CCP1_CAPTURE_READY                  0X01

/* CCP1 Compare Mode State  */
#define   CCP1_COMPARE_NOT_READY              0X00
#define   CCP1_COMPARE_READY                  0X01



/* Timer2 Input Clock Pre-scaler */
#define CCP_TIMER2_PRESCALER_DIV_BY_1        1
#define CCP_TIMER2_PRESCALER_DIV_BY_4        4
#define CCP_TIMER2_PRESCALER_DIV_BY_16       16
/* Set the CCP1 Mode Variant */
#define CCP1_SET_MODE(_CONFIG)  (CCP1CONbits.CCP1M = _CONFIG)
#define CCP2_SET_MODE(_CONFIG)  (CCP2CONbits.CCP2M = _CONFIG)
typedef enum{
    CCP_CAPTURE_MODE_SELECTED = 0, /* Select CCP1 Capture Mode */
    CCP_COMPARE_MODE_SELECTED,     /* Select CCP1 Compare Mode */
    CCP_PWM_MODE_SELECTED          /* Select CCP1 PWM Mode */
}ccp1_mode_t;
typedef enum{
    CCP1_CCP2_TIMER3 = 0,
    CCP1_TIMER1_CCP2_TIMER3,
    CCP1_CCP2_TIMER1
}ccp_capture_timer_t;
typedef enum{
    CCP1_INST = 0,
    CCP2_INST
}ccp_inst_t;
typedef struct{
    #if CCP_INTERRUPTS==INTERRUPT_ENABLE
    void (*ccp1_handler)(void) ;
#endif
    #if (CCP1_CFG_SELECTED_MODE==CCP_CFG_PWM_MODE_SELECTED) || (CCP2_CFG_SELECTED_MODE==CCP_CFG_PWM_MODE_SELECTED)
    uint32 pwm_frequncy ;
     uint8 timer2_postscaler_value ;
    uint8 timer2_prescaler_value ;
#endif
    ccp_capture_timer_t ccp_capture_timer;
    pin_config_t ccp_pin;
     ccp1_mode_t ccp1_mode;
     uint8 ccp_mode_varient ;    
    ccp_inst_t ccp_inst ;
     

}ccp_t;
typedef union{
    struct{
        uint8 ccpr1_low;
         uint8 ccpr1_high;
    };
    struct{
        uint16  ccpr1_16bit ;
    };
}CCP_REG_T;

/*-------------------------------------------Section :data types -------------------------------------- */

/*-------------------------------------------Section :Macro functions  -------------------------------------------*/

/* ----------------- Software Interfaces Declarations -----------------*/
Std_ReturnType CCP_Init(const ccp_t *_ccp_obj);
Std_ReturnType CCP_DeInit(const ccp_t *_ccp_obj);

#if(CCP1_CFG_SELECTED_MODE==CCP_CFG_CAPTURE_MODE_SELECTED)
Std_ReturnType CCP1_IsCapturedDataReady(uint8 *_capture_status);
Std_ReturnType CCP1_Capture_Mode_Read_Value(uint16 *capture_value);
#endif

#if(CCP1_CFG_SELECTED_MODE==CCP_CFG_COMPARE_MODE_SELECTED)
Std_ReturnType CCP_IsCompareComplete(uint8 *_compare_status);
Std_ReturnType CCP_Compare_Mode_Set_Value(const ccp_t *_ccp_obj, uint16 compare_value);
#endif

#if(CCP1_CFG_SELECTED_MODE==CCP_CFG_PWM_MODE_SELECTED)
Std_ReturnType CCP_PWM_Set_Duty(const ccp_t *_ccp_obj, const uint8 _duty);
Std_ReturnType CCP_PWM_Start(const ccp_t *_ccp_obj);
Std_ReturnType CCP_PWM_Stop(const ccp_t *_ccp_obj);
#endif












#endif	/* CCP1_H */

