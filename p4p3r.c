#include "p4p3r.h"

#if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
// Forward-declare this helper function since it is defined in rgb.c.
void set_led_config(void);
#endif

static uint16_t    next_keycode;
static keyrecord_t next_record;

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // Cache the next input for mod-tap decisions
        next_keycode = keycode;
        next_record  = *record;
    }
    return true;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    // Hold Control and Shift with a nested key tap on the opposite hand
    return IS_BILATERAL_TAP(record, next_record) && IS_MOD_TAP_CS(keycode);
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    // Activate layer with another key press
    if (IS_QK_LAYER_TAP(keycode) && QK_LAYER_TAP_GET_LAYER(keycode)) {
        return true;
    }
    // When a mod-tap key overlaps with another non-Shift key on the same
    // hand without any other modifiers active, send its base keycode
    if (IS_UNILATERAL_TAP(record, next_record) && !IS_MOD_TAP_SHIFT(next_keycode) && !get_mods()) {
        record->keycode = keycode & 0xff;
        process_record(record);
        record->event.pressed = false;
        process_record(record);
    }
    return false;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    // Decrease tapping term for the home row Shift
    return IS_HOMEROW(record) && IS_MOD_TAP_SHIFT(keycode) ? TAPPING_TERM - 50 : TAPPING_TERM;
}

// Turn off caps lock at the end of a word
static inline bool process_caps_unlock(uint16_t keycode, keyrecord_t *record) {
    bool const    caps = host_keyboard_led_state().caps_lock;
    uint8_t const mods = get_mods();

    // Ignore inactive caps lock status and shifted keys
    if (!caps || mods == MOD_BIT_LSHIFT || mods == MOD_BIT_RSHIFT) return true;

    // Filter mod-tap and layer-tap keys
    if (IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode)) {
        if (record->tap.count == 0) return true;
        keycode &= 0xff;
    }

    // Identify caps lock retention key codes
    switch (keycode) {
        case KC_A ... KC_0:
        case KC_BSPC:
        case KC_MINS:
        case KC_UNDS:
        case KC_CAPS:
        case TO(BSE):
        case TO(NUM):
        case TO(SYM):
            if (!mods) return true;
        default:
            tap_code(KC_CAPS);
    }

    return true;
}

// Send custom hold keycode
static inline bool process_tap_hold(uint16_t keycode, keyrecord_t *record) {
    if (record->tap.count) return true;
    tap_code16(keycode);
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_caps_unlock(keycode, record)) return false;

    if (record->event.pressed) {
        if (keycode == TH_QE)
            return process_tap_hold(KC_ESC, record);
        else if (keycode == TH_QC)
            return process_tap_hold(KC_COLN, record);
        else if (keycode == TH_PC)
            return process_tap_hold(KC_COLN, record);
        else if (keycode == TH_DU)
            return process_tap_hold(KC_UNDS, record);
        else if (keycode == TH_CM)
            return process_tap_hold(KC_MINUS, record);
        else if (keycode == TH_SE)
            return process_tap_hold(KC_EXLM, record);
        else if (keycode == TH_SC)
            return process_tap_hold(KC_COLN, record);
    }

    return true;
}

// #if defined(KEYBOARD_bastardkb_charybdis_3x5)
// #    ifdef POINTING_DEVICE_ENABLE
// #        ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
// #            include "timer.h
// static uint16_t auto_pointer_layer_timer = 0;

// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
//     if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
//         if (auto_pointer_layer_timer == 0) {
//             layer_on(PNT);
//             // TODO: This should be handled in rgb-matrix.c instead, or through
//             // a handler exported by rgb-matrix.c.
// #            ifdef RGB_MATRIX_ENABLE
//             rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
//             rgb_matrix_sethsv_noeeprom(HSV_PNT);
// #            endif // RGB_MATRIX_ENABLE
//         }
//         auto_pointer_layer_timer = timer_read();
//     }
//     return mouse_report;
// }

// void matrix_scan_user(void) {
//     if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
//         auto_pointer_layer_timer = 0;
//         layer_off(PNT);
//         // #                   ifdef RGB_MATRIX_ENABLE
//         //                         rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
//         // #                   endif // RGB_MATRIX_ENABLE
//     }
// }
// #        endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
// #    endif     // POINTING_DEVICE_ENABLE
// #endif

void keyboard_post_init_user(void) {
    set_led_config();
}
