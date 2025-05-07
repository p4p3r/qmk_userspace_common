#include "layout.h"
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "rgb.h"

// clang-format off
#if defined(KEYBOARD_splitkb_aurora_sweep_rev1)
led_config_t g_led_config = {{
    /* Key Matrix to LED index. */
    // Left split.
    {   10,    9,      8,      7,      6       },
    {   15,    14,     13,     12,     11      },
    {   20,    19,     18,     17,     16      },
    {   22,    21,     NO_LED, NO_LED, NO_LED  },
    // Right split.
    {   29,     30,     31,     32,     33      },
    {   34,     35,     36,     37,     38      },
    {   39,     40,     41,     42,     43      },
    {   44,     45,     NO_LED, NO_LED, NO_LED  },
}, {
    /* LED index to physical position. */
    // Left split.
    // Underglow
    {71, 15}, {51, 8}, {10, 13}, {10, 42}, {41, 45}, {76, 50},
    // Key matrix
    {0, 15},    {20, 5},    {41, 0},    {61, 4},    {81, 7},
    {0, 31},    {20, 21},   {41, 16},   {61, 20},   {81, 23},
    {0, 47},    {20, 37},   {41, 32},   {61, 36},   {81, 39},
    // Thumb cluster
    {71, 60},   {92, 64},
    // Right split.
    // Underglow
    {150, 15},  {190, 8},   {210, 13},  {220, 42},  {183, 45}, {155, 50},
    // Key matrix
    {143, 7},   {163, 20},  {183, 0},   {204, 5},   {224, 15},
    {143, 23},  {163, 20},  {183, 16},  {204, 21},  {224, 31},
    {143, 39},  {163, 36},  {183, 32},  {204, 37},  {224, 47},
    // Thumb cluster
    {132, 64}, {153, 60}
}, {
    /* LED index to flag. */
    // Left split.
    // Underglow
    2, 2, 2, 2, 2, 2,
    // Per-key
    4, 4, 4, 4, LED_FLAG_KEYLIGHT | CAP_FLAG,
    4, 4, 4, 4, LED_FLAG_KEYLIGHT | CAP_FLAG,
    4, 4, 4, 4, LED_FLAG_KEYLIGHT | CAP_FLAG,
    // Thumb
    LED_FLAG_KEYLIGHT | CAP_FLAG,
    LED_FLAG_KEYLIGHT | CAP_FLAG,
    // Right split.
    // Underglow
    2, 2, 2, 2, 2, 2,
    // Per-key
    LED_FLAG_KEYLIGHT | CAP_FLAG, 4, 4, 4, 4,
    LED_FLAG_KEYLIGHT | CAP_FLAG, 4, 4, 4, 4,
    LED_FLAG_KEYLIGHT | CAP_FLAG, 4, 4, 4, 4,
    // Thumb
    LED_FLAG_KEYLIGHT | CAP_FLAG,
    LED_FLAG_KEYLIGHT | CAP_FLAG
} };
#endif
// clang-format on

#if defined(KEYBOARD_bastardkb_charybdis_3x5)
extern led_config_t g_led_config;
#endif

void set_led_config(void) {
#if defined(KEYBOARD_bastardkb_charybdis_3x5)
    g_led_config.flags[0]  = LED_FLAG_KEYLIGHT | CAP_FLAG;
    g_led_config.flags[1]  = LED_FLAG_KEYLIGHT;
    g_led_config.flags[2]  = LED_FLAG_KEYLIGHT;
    g_led_config.flags[3]  = LED_FLAG_KEYLIGHT;
    g_led_config.flags[4]  = LED_FLAG_KEYLIGHT;
    g_led_config.flags[5]  = LED_FLAG_KEYLIGHT | CAP_FLAG;
    g_led_config.flags[6]  = LED_FLAG_KEYLIGHT | CAP_FLAG;
    g_led_config.flags[7]  = LED_FLAG_KEYLIGHT;
    g_led_config.flags[8]  = LED_FLAG_KEYLIGHT;
    g_led_config.flags[9]  = LED_FLAG_KEYLIGHT;
    g_led_config.flags[10] = LED_FLAG_KEYLIGHT;
    g_led_config.flags[11] = LED_FLAG_KEYLIGHT | CAP_FLAG;
    g_led_config.flags[12] = LED_FLAG_KEYLIGHT | CAP_FLAG;
    g_led_config.flags[13] = LED_FLAG_KEYLIGHT | CAP_FLAG;
    g_led_config.flags[14] = LED_FLAG_KEYLIGHT | CAP_FLAG;
    g_led_config.flags[15] = LED_FLAG_KEYLIGHT | MOD_FLAG;
    g_led_config.flags[16] = LED_FLAG_KEYLIGHT | MOD_FLAG;
    g_led_config.flags[17] = LED_FLAG_KEYLIGHT | MOD_FLAG;
    g_led_config.flags[18] = LED_FLAG_KEYLIGHT | CAP_FLAG;
    g_led_config.flags[19] = LED_FLAG_KEYLIGHT;
    g_led_config.flags[20] = LED_FLAG_KEYLIGHT;
    g_led_config.flags[21] = LED_FLAG_KEYLIGHT;
    g_led_config.flags[22] = LED_FLAG_KEYLIGHT;
    g_led_config.flags[23] = LED_FLAG_KEYLIGHT | CAP_FLAG;
    g_led_config.flags[24] = LED_FLAG_KEYLIGHT | CAP_FLAG;
    g_led_config.flags[25] = LED_FLAG_KEYLIGHT;
    g_led_config.flags[26] = LED_FLAG_KEYLIGHT;
    g_led_config.flags[27] = LED_FLAG_KEYLIGHT;
    g_led_config.flags[28] = LED_FLAG_KEYLIGHT;
    g_led_config.flags[29] = LED_FLAG_KEYLIGHT | CAP_FLAG;
    g_led_config.flags[30] = LED_FLAG_KEYLIGHT | CAP_FLAG;
    g_led_config.flags[31] = LED_FLAG_KEYLIGHT | CAP_FLAG;
    g_led_config.flags[32] = LED_FLAG_KEYLIGHT | CAP_FLAG;
    g_led_config.flags[33] = LED_FLAG_KEYLIGHT | MOD_FLAG;
    g_led_config.flags[34] = LED_FLAG_KEYLIGHT | MOD_FLAG;
    g_led_config.flags[35] = LED_FLAG_KEYLIGHT | MOD_FLAG;
#endif
}

// TODO: this should be moved to p4p3r.c and export here just handlers
// for the rgb-specific pieces
layer_state_t layer_state_set_user(layer_state_t const state) {
    rgb_matrix_mode_noeeprom(layer_state_is(CMK) ? CMK_MODE : DEF_MODE);

#if defined(KEYBOARD_bastardkb_charybdis_3x5)
#    ifdef POINTING_DEVICE_ENABLE
#        ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
#        endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#    endif     // POINTING_DEVICE_ENABLE
#endif

    return state;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Modifier keys indicator
    if (get_mods() & MOD_MASK_CSAG) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            if (HAS_FLAGS(g_led_config.flags[i], MOD_FLAG)) {
                rgb_matrix_set_color(i, RGB_MODS);
            }
        }
    }
    // Layer keys indicator, variation on the examples from the doc:
    // https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgb_matrix.md#examples-idindicator-examples
    uint8_t layer = get_highest_layer(layer_state);
    if (layer > CMK) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            if (HAS_FLAGS(g_led_config.flags[i], CAP_FLAG)) {
                switch (layer) {
                    case SYM:
                        rgb_matrix_set_color(i, RGB_SYM);
                        break;
                    case NUM:
                        rgb_matrix_set_color(i, RGB_NUM);
                        break;
                    case FNC:
                        rgb_matrix_set_color(i, RGB_FNC);
                        break;
                    case PNT:
                        rgb_matrix_set_color(i, RGB_PNT);
                        break;
                    case NAV:
                        rgb_matrix_set_color(i, RGB_NAV);
                        break;
                    case MED:
                        rgb_matrix_set_color(i, RGB_MED);
                        break;
                }
            }
        }
    }

    return false;
}
