#include "lvgl/lvgl.h"

/*******************************************************************************
 * Size: 8 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifndef PRESSSTART2P_8P
#define PRESSSTART2P_8P 1
#endif

#if PRESSSTART2P_8P

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t gylph_bitmap[] = {
    /* U+20 " " */
    0x0,

    /* U+21 "!" */
    0xff, 0xec, 0x30,

    /* U+22 "\"" */
    0xde, 0xf6,

    /* U+23 "#" */
    0x6d, 0xfd, 0xb3, 0x66, 0xdf, 0xdb, 0x0,

    /* U+24 "$" */
    0x10, 0xfb, 0x43, 0xe1, 0x7f, 0x84, 0x0,

    /* U+25 "%" */
    0x63, 0x4b, 0x20, 0x82, 0x69, 0x63, 0x0,

    /* U+26 "&" */
    0x71, 0xb3, 0x63, 0x8d, 0xb9, 0x9f, 0x80,

    /* U+27 "'" */
    0xfc,

    /* U+28 "(" */
    0x36, 0xcc, 0xc6, 0x30,

    /* U+29 ")" */
    0xc6, 0x33, 0x36, 0xc0,

    /* U+2A "*" */
    0x6c, 0x73, 0xf9, 0xc6, 0xc0,

    /* U+2B "+" */
    0x30, 0xcf, 0xcc, 0x30,

    /* U+2C "," */
    0x6f, 0x0,

    /* U+2D "-" */
    0xfc,

    /* U+2E "." */
    0xf0,

    /* U+2F "/" */
    0x2, 0x8, 0x20, 0x82, 0x8, 0x20, 0x0,

    /* U+30 "0" */
    0x38, 0x9b, 0x1e, 0x3c, 0x6c, 0x8e, 0x0,

    /* U+31 "1" */
    0x31, 0xc3, 0xc, 0x30, 0xcf, 0xc0,

    /* U+32 "2" */
    0x7d, 0x8c, 0x39, 0xe7, 0x9c, 0x3f, 0x80,

    /* U+33 "3" */
    0x7e, 0x18, 0x61, 0xe0, 0x78, 0xdf, 0x0,

    /* U+34 "4" */
    0x1c, 0x79, 0xb6, 0x6f, 0xe1, 0x83, 0x0,

    /* U+35 "5" */
    0xfd, 0x83, 0xf0, 0x30, 0x78, 0xdf, 0x0,

    /* U+36 "6" */
    0x3c, 0xc3, 0x7, 0xec, 0x78, 0xdf, 0x0,

    /* U+37 "7" */
    0xff, 0x8c, 0x30, 0xc3, 0x6, 0xc, 0x0,

    /* U+38 "8" */
    0x79, 0x8b, 0x93, 0xc9, 0xf0, 0xdf, 0x0,

    /* U+39 "9" */
    0x7d, 0x8f, 0x1b, 0xf0, 0x61, 0x9e, 0x0,

    /* U+3A ":" */
    0xf3, 0xc0,

    /* U+3B ";" */
    0x6c, 0x37, 0x80,

    /* U+3C "<" */
    0x19, 0x99, 0x86, 0x18, 0x60,

    /* U+3D "=" */
    0xfe, 0x3, 0xf8,

    /* U+3E ">" */
    0xc3, 0xc, 0x33, 0x33, 0x0,

    /* U+3F "?" */
    0x7d, 0xff, 0x18, 0x63, 0x80, 0xe, 0x0,

    /* U+40 "@" */
    0x7d, 0x6, 0xed, 0x5b, 0xf0, 0x1f, 0x0,

    /* U+41 "A" */
    0x38, 0xdb, 0x1e, 0x3f, 0xf8, 0xf1, 0x80,

    /* U+42 "B" */
    0xfd, 0x8f, 0x1f, 0xec, 0x78, 0xff, 0x0,

    /* U+43 "C" */
    0x3c, 0xcf, 0x6, 0xc, 0xc, 0xcf, 0x0,

    /* U+44 "D" */
    0xf9, 0x9b, 0x1e, 0x3c, 0x79, 0xbe, 0x0,

    /* U+45 "E" */
    0xff, 0x83, 0x7, 0xec, 0x18, 0x3f, 0x80,

    /* U+46 "F" */
    0xff, 0x83, 0x7, 0xec, 0x18, 0x30, 0x0,

    /* U+47 "G" */
    0x3e, 0xc3, 0x6, 0x7c, 0x6c, 0xcf, 0x80,

    /* U+48 "H" */
    0xc7, 0x8f, 0x1f, 0xfc, 0x78, 0xf1, 0x80,

    /* U+49 "I" */
    0xfc, 0xc3, 0xc, 0x30, 0xcf, 0xc0,

    /* U+4A "J" */
    0x6, 0xc, 0x18, 0x30, 0x78, 0xdf, 0x0,

    /* U+4B "K" */
    0xc7, 0x9b, 0x67, 0x8f, 0x9b, 0xb3, 0x80,

    /* U+4C "L" */
    0xc3, 0xc, 0x30, 0xc3, 0xf, 0xc0,

    /* U+4D "M" */
    0xc7, 0xdf, 0xfe, 0xbd, 0x78, 0xf1, 0x80,

    /* U+4E "N" */
    0xc7, 0xcf, 0xde, 0xfc, 0xf8, 0xf1, 0x80,

    /* U+4F "O" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x78, 0xdf, 0x0,

    /* U+50 "P" */
    0xfd, 0x8f, 0x1e, 0x3f, 0xd8, 0x30, 0x0,

    /* U+51 "Q" */
    0x7d, 0x8f, 0x1e, 0x3d, 0xf9, 0x9e, 0x80,

    /* U+52 "R" */
    0xfd, 0x8f, 0x1e, 0x7f, 0x9b, 0xb3, 0x80,

    /* U+53 "S" */
    0x7d, 0x8f, 0x3, 0xe0, 0x78, 0xdf, 0x0,

    /* U+54 "T" */
    0xfc, 0xc3, 0xc, 0x30, 0xc3, 0x0,

    /* U+55 "U" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xdf, 0x0,

    /* U+56 "V" */
    0xc7, 0x8f, 0x1f, 0x77, 0xc7, 0x4, 0x0,

    /* U+57 "W" */
    0xd7, 0xaf, 0x5e, 0xbf, 0xfd, 0xd1, 0x0,

    /* U+58 "X" */
    0xc7, 0x8d, 0xb1, 0xc6, 0xd8, 0xf1, 0x80,

    /* U+59 "Y" */
    0xcf, 0x3c, 0xde, 0x30, 0xc3, 0x0,

    /* U+5A "Z" */
    0xfe, 0x1c, 0x71, 0xc7, 0x1c, 0x3f, 0x80,

    /* U+5B "[" */
    0xfc, 0xcc, 0xcc, 0xf0,

    /* U+5C "\\" */
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,

    /* U+5D "]" */
    0xf3, 0x33, 0x33, 0xf0,

    /* U+5E "^" */
    0x76, 0xc0,

    /* U+5F "_" */
    0xfe,

    /* U+60 "`" */
    0x90,

    /* U+61 "a" */
    0x7c, 0xd, 0xfe, 0x37, 0xe0,

    /* U+62 "b" */
    0xc1, 0x83, 0xf6, 0x3c, 0x78, 0xdf, 0x0,

    /* U+63 "c" */
    0x7f, 0x83, 0x6, 0x7, 0xe0,

    /* U+64 "d" */
    0x6, 0xd, 0xfe, 0x3c, 0x78, 0xdf, 0x80,

    /* U+65 "e" */
    0x7d, 0x8f, 0xfe, 0x7, 0xc0,

    /* U+66 "f" */
    0x1c, 0xcf, 0xcc, 0x30, 0xc3, 0x0,

    /* U+67 "g" */
    0x7f, 0x8f, 0x1b, 0xf0, 0x6f, 0x80,

    /* U+68 "h" */
    0xc1, 0x83, 0xf6, 0x3c, 0x78, 0xf1, 0x80,

    /* U+69 "i" */
    0x30, 0x7, 0xc, 0x30, 0xcf, 0xc0,

    /* U+6A "j" */
    0x18, 0xe, 0x31, 0x8c, 0x7e,

    /* U+6B "k" */
    0xc1, 0x83, 0x1e, 0x6f, 0x99, 0xb1, 0x80,

    /* U+6C "l" */
    0x70, 0xc3, 0xc, 0x30, 0xcf, 0xc0,

    /* U+6D "m" */
    0xfd, 0x6e, 0xdd, 0xbb, 0x60,

    /* U+6E "n" */
    0xfd, 0x8f, 0x1e, 0x3c, 0x60,

    /* U+6F "o" */
    0x7d, 0x8f, 0x1e, 0x37, 0xc0,

    /* U+70 "p" */
    0xfd, 0x8f, 0x1f, 0xec, 0x18, 0x0,

    /* U+71 "q" */
    0x7f, 0x8f, 0x1b, 0xf0, 0x60, 0xc0,

    /* U+72 "r" */
    0xdf, 0x8c, 0x30, 0xc0,

    /* U+73 "s" */
    0x7d, 0x81, 0xf0, 0x3f, 0xc0,

    /* U+74 "t" */
    0x30, 0xcf, 0xcc, 0x30, 0xc3, 0x0,

    /* U+75 "u" */
    0xc7, 0x8f, 0x1e, 0x37, 0xe0,

    /* U+76 "v" */
    0xcf, 0x3c, 0xde, 0x30,

    /* U+77 "w" */
    0xd7, 0xaf, 0x5e, 0xb6, 0xc0,

    /* U+78 "x" */
    0xc6, 0xd8, 0xe3, 0x6c, 0x60,

    /* U+79 "y" */
    0xc7, 0x8f, 0x1b, 0xf0, 0x6f, 0x80,

    /* U+7A "z" */
    0xfe, 0x38, 0xe3, 0x8f, 0xe0,

    /* U+7B "{" */
    0x36, 0x6c, 0x66, 0x30,

    /* U+7C "|" */
    0xff, 0xfc,

    /* U+7D "}" */
    0xc6, 0x63, 0x66, 0xc0,

    /* U+7E "~" */
    0x71, 0x74, 0x70,

    /* U+7F "" */
    0xde, 0xc0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 128, .box_w = 3, .box_h = 7, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 4, .adv_w = 128, .box_w = 5, .box_h = 3, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 6, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 13, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 20, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 27, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 34, .adv_w = 128, .box_w = 2, .box_h = 3, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 35, .adv_w = 128, .box_w = 4, .box_h = 7, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 39, .adv_w = 128, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 43, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 48, .adv_w = 128, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 52, .adv_w = 128, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 54, .adv_w = 128, .box_w = 6, .box_h = 1, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 55, .adv_w = 128, .box_w = 2, .box_h = 2, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 56, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 63, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 70, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 76, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 83, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 90, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 97, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 104, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 111, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 118, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 125, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 132, .adv_w = 128, .box_w = 2, .box_h = 5, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 134, .adv_w = 128, .box_w = 3, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 137, .adv_w = 128, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 142, .adv_w = 128, .box_w = 7, .box_h = 3, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 145, .adv_w = 128, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 150, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 157, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 164, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 171, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 178, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 185, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 192, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 199, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 206, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 213, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 220, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 226, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 233, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 240, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 246, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 253, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 260, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 267, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 274, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 281, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 288, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 295, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 301, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 308, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 315, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 322, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 329, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 335, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 342, .adv_w = 128, .box_w = 4, .box_h = 7, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 346, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 353, .adv_w = 128, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 357, .adv_w = 128, .box_w = 5, .box_h = 2, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 359, .adv_w = 128, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 360, .adv_w = 128, .box_w = 2, .box_h = 2, .ofs_x = 3, .ofs_y = 6},
    {.bitmap_index = 361, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 366, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 373, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 378, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 385, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 390, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 396, .adv_w = 128, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 402, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 409, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 415, .adv_w = 128, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 420, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 427, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 433, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 438, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 443, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 448, .adv_w = 128, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 454, .adv_w = 128, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 460, .adv_w = 128, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 464, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 469, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 475, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 480, .adv_w = 128, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 484, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 489, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 494, .adv_w = 128, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 500, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 505, .adv_w = 128, .box_w = 4, .box_h = 7, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 509, .adv_w = 128, .box_w = 2, .box_h = 7, .ofs_x = 3, .ofs_y = 1},
    {.bitmap_index = 511, .adv_w = 128, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 515, .adv_w = 128, .box_w = 7, .box_h = 3, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 518, .adv_w = 128, .box_w = 5, .box_h = 2, .ofs_x = 1, .ofs_y = 1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 96, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

/*Store all the custom data of the font*/
static lv_font_fmt_txt_dsc_t font_dsc = {
    .glyph_bitmap = gylph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
lv_font_t PressStart2p_8p = {
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 8,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0)
    .underline_position = -1,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if PRESSSTART2P_8P*/

