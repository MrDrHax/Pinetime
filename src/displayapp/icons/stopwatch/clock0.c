#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "../lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_CLOCK0
#define LV_ATTRIBUTE_IMG_CLOCK0
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_CLOCK0 uint8_t clock0_map[] = {
  0x04, 0x00, 
  0x40, 0xa0, 
  0x24, 0xa0, 
  0x04, 0xa0, 
  0x04, 0x00, 
  0xc4, 0x60, 
  0x00, 0x00, 
  0x00, 0x00, 
  0x20, 0x80, 
  0x44, 0x40, 
  0x04, 0x00, 
};

const lv_img_dsc_t clock0 = {
  .header.always_zero = 0,
  .header.w = 11,
  .header.h = 11,
  .data_size = 22,
  .header.cf = LV_IMG_CF_ALPHA_1BIT,
  .data = clock0_map,
};