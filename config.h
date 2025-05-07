#pragma once

// Space saving options
#define LAYER_STATE_8BIT

// Tap-hold settings
#define TAPPING_TERM 180
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM TAPPING_TERM / 2
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#ifdef SPLIT_KEYBOARD
#    if defined(OLED_ENABLE) || defined(RGB_MATRIX_ENABLE)
#        define SPLIT_OLED_ENABLE
#        define SPLIT_MODS_ENABLE
#        define SPLIT_LED_STATE_ENABLE
#        define SPLIT_LAYER_STATE_ENABLE
#    endif
#endif

/* Charybdis-specific features. */

#ifdef POINTING_DEVICE_ENABLE
// Automatically enable the pointer layer when moving the trackball.  See also:
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS`
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD`
//  define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
//  undef CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif // POINTING_DEVICE_ENABLE

#ifdef VIA_ENABLE
#    define DYNAMIC_KEYMAP_LAYER_COUNT 8
#endif // VIA_ENABLE

#if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
#    include "rgb.h"
#endif // RGB_MATRIX_ENABLE

// Layout macros
#ifndef __ASSEMBLER__
#    include "layout.h"
#endif // __ASSEMBLER__
