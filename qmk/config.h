/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

// #define MASTER_LEFT
#define MASTER_RIGHT
// #define EE_HANDS

#define _QWERTY 0
#define _NUM 1
#define _SYM 2
#define _FN 3

#define TAPPING_TOGGLE 2
#define TAPPING_FORCE_HOLD_PER_KEY
#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM 200

#undef PERMISSIVE_HOLD
// #define TAPPING_FORCE_HOLD
#define ONESHOT_TAP_TOGGLE 2

#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
    #define RGB_MATRIX_LED_FLUSH_LIMIT 16
    #define RGB_MATRIX_HUE_STEP 8
    #define RGB_MATRIX_SAT_STEP 8
    #define RGB_MATRIX_VAL_STEP 5
    #define RGB_MATRIX_SPD_STEP 10
    // effects
    #define ENABLE_RGB_MATRIX_MULTISPLASH
    #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT
#endif

// #define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
