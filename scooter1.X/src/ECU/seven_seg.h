/* 
 * File:   7_seg.h
 * Author: Lenovo
 *

 */

#ifndef SEVEN_SEG_H
#define	SEVEN_SEG_H

#include "../../INC/MCAL/GPIO.h"
/* ----------------- Data Type Declarations -----------------*/
typedef enum
{ COMMON_CATHODE,
        COMMON_ANODE
    
}segment_type_t;
typedef struct
{ pin_config_t Segment_Pins[4];
segment_type_t segment_type ;
    
}segment_t;
/*Section :Functions Declarations  */
Std_ReturnType segment_intilaize( segment_t *seg);
Std_ReturnType segment_write(const segment_t *seg,uint8 data);
#endif	/* SEVEN_SEG_H */

