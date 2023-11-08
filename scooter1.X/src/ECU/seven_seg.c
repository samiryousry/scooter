#include "seven_seg.h"

Std_ReturnType segment_intilaize( segment_t *seg)
{
    Std_ReturnType ret=E_OK;
    if (!(seg))
    {ret=E_NOT_OK;}
    else {
        seg->Segment_Pins[0].direction =OUTPUT;
        seg->Segment_Pins[1].direction =OUTPUT;
        seg->Segment_Pins[2].direction =OUTPUT;
        seg->Segment_Pins[3].direction =OUTPUT;
        if ((seg->segment_type)==COMMON_CATHODE)
        {seg->Segment_Pins[0].logic=0 ;
                seg->Segment_Pins[1].logic=0;
                seg->Segment_Pins[2].logic=0;
                seg->Segment_Pins[3].logic=0;
        }
        else if ((seg->segment_type)==COMMON_ANODE)
        { seg->Segment_Pins[0].logic=1;
                seg->Segment_Pins[1].logic=1;
                seg->Segment_Pins[2].logic=1;
                seg->Segment_Pins[3].logic=1;}
            gpio_pin_intilaize(&(seg->Segment_Pins[0]));
            gpio_pin_intilaize(&(seg->Segment_Pins[1]));
            gpio_pin_intilaize(&(seg->Segment_Pins[2]));
            gpio_pin_intilaize(&(seg->Segment_Pins[3]));
    }
    return ret;
}
Std_ReturnType segment_write(const segment_t *seg,uint8 data)
{
    Std_ReturnType ret=E_OK;
    if (!(seg)||(data>9))
    {ret=E_NOT_OK;}
    else {
        gpio_pin_write_logic(&(seg->Segment_Pins[0]),(data&0b00000001));
         gpio_pin_write_logic(&(seg->Segment_Pins[1]),(data&0b00000010)>>1);
          gpio_pin_write_logic(&(seg->Segment_Pins[2]),(data&0b00000100)>>2);
              gpio_pin_write_logic(&(seg->Segment_Pins[3]),(data&0b00001000)>>3);
        
    }
    return ret;
}

