#pragma once

#include "quantum/keycodes.h"

// macOS shortcuts
#define Z_UND G(KC_Z)
#define Z_CUT G(KC_X)
#define Z_CPY G(KC_C)
#define Z_PST G(KC_V)
#define Z_SAVE G(KC_S)
#define Z_FND G(KC_F)
#define Z_RLD G(KC_R)

// Shortcuts that will be picked up by a tool like BetterTouchTool
// to set Ploopy Nano Trackball leds and toggle scroll mode or reset
#define PLP_SCR HYPR(KC_S) // Scroll
#define PLP_RST HYPR(KC_R) // Reset

// Alias DRGSCRL and PLP_SCR if not on Charybdis
#if !defined(KEYBOARD_bastardkb_charybdis_3x5)
#    undef DRGSCRL
#    define DRGSCRL PLP_SCR
#    define S_D_MOD XXXXXXX
#    define DPI_MOD XXXXXXX
#    define SNIPING XXXXXXX
#endif

// Charybdis specific
#if defined(KEYBOARD_bastardkb_charybdis_3x5)

#    ifndef POINTING_DEVICE_ENABLE
#        define DRGSCRL KC_NO
#        define DPI_MOD KC_NO
#        define S_D_MOD KC_NO
#        define SNIPING KC_NO
#    endif // POINTING_DEVICE_ENABLE

// Automatically enable sniping-mode on the pointer layer.
#    define CHARYBDIS_AUTO_SNIPING_ON_LAYER PNT

#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#        ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#            define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#        endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#        ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#            define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#        endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#    endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#endif

// Tap hold macros
#define TH_QE LT(0, KC_Q)
#define TH_PC LT(0, KC_P)
#define TH_QC LT(0, KC_QUOT)
#define TH_DU LT(0, KC_DOT)
#define TH_CM LT(0, KC_COMM)
#define TH_SE LT(0, KC_SLSH)
#define TH_SC LT(0, KC_SCLN)

// Home row mod-tap macros
#define HRML(k1, k2, k3, k4) LSFT_T(k1), LCTL_T(k2), LGUI_T(k3), LALT_T(k4)
#define HRMR(k1, k2, k3, k4) RALT_T(k1), RGUI_T(k2), RCTL_T(k3), RSFT_T(k4)

// One shot mods
#ifdef NO_ACTION_ONESHOT
#    define OSM_SFT KC_LSFT
#else
#    define OSM_SFT OSM(MOD_LSFT)
#endif

// Layers
#ifdef BKB_LAYOUT
enum common_layers { BSE, CMK, FNC, NAV, MED, NUM, PNT, SYM };
#else
enum common_layers { BSE, CMK, SYM, NUM, FNC, PNT };
#endif

// Convenience row shorthands
#define _______________DEAD_HALF_ROW_______________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______________HOME_ROW_SCGA_L______________ KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX
#define ______________HOME_ROW_SCGA_R______________ XXXXXXX, KC_RALT, KC_RGUI, KC_RCTL, KC_RSFT
#define ____________HOME_ROW_SCGA_R_ENT____________ XXXXXXX, KC_RALT, KC_RGUI, KC_RCTL, RSFT_T(KC_ENT)

// Layer shorthands
#define SPC_NAV LT(NAV, KC_SPC)
#define TAB_FUN LT(FNC, KC_TAB)
#define ENT_SYM LT(SYM, KC_ENT)
#define BSP_NUM LT(NUM, KC_BSPC)
#define _L_PTR(KC) LT(PNT, KC)
#ifdef BKB_LAYOUT
  #define ESC_MED LT(MED, KC_ESC)
  #define _L_MED(KC) LT(MED, KC)
#endif

// clang-format off
// Default 3x5_2 split layout

#ifdef BKB_LAYOUT
#define _BASE                                                                                       \
       TH_QE,   KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,       \
       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,       \
       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,       \
                               SPC_NAV, TAB_FUN, ENT_SYM, BSP_NUM
#else
#define _BASE                                                                                       \
	    TH_QE,   KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,    TH_PC,      \
	    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,    \
	    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,    KC_M,    TH_CM,   TH_DU,   TH_SE,      \
	                             KC_SPC,  KC_TAB,   KC_ENT,  TO(SYM)
/* ╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮
   │  Q/ESC │  W     │  E     │  R     │  T     │   │  Y     │  U     │  I     │  O     │  P/:   │
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │  A/SFT │  S/CTL │  D/CMD │  F/ALT │  G     │   │  H     │  J/ALT │  K/CMD │  L/CTL │ ' "/SFT│
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │    Z   │   X    │    C   │   V    │  B     │   │  N     │  M     │ , </-  │ . >/_  │ / ?/!  │
   ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯
                              │   SPC  │  TAB   │   │  ENT   │  SYM   │
                              ╰────────┴────────╯   ╰────────┴────────╯*/
#endif

#ifdef BKB_LAYOUT
#define _COLE                                                                                       \
       TH_QE,   KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,       \
       KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,       \
       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,       \
                               SPC_NAV, TAB_FUN, ENT_SYM, BSP_NUM
#else
#define _COLE \
	TH_QE,   KC_W,    KC_F,    TH_PC, KC_G,         KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,    \
	KC_A,    KC_R,    KC_S,    KC_T,    KC_D,       KC_H,    KC_N,    KC_E,    KC_I,    KC_O,       \
	KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    \
	                           KC_SPC,  KC_TAB,     KC_ENT,  TO(SYM)
/* ╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮
   │  Q/ESC │  W     │  F     │   P/:  │  G     │   │  J     │  L     │  U     │  Y     │    "   │
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │  A/SFT │  R/CTL │  S/CMD │  T/ALT │  D     │   │  H     │  N/ALT │  E/CMD │  I/CTL │  O/SFT │
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │    Z   │   X    │   C    │  V     │  B     │   │  N     │  M     │  , <   │  . >   │  / ?   │
   ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯
                              │  SPC   │  TAB   │   │  ENT   │  SYM   │
                              ╰────────┴────────╯   ╰────────┴────────╯*/
#endif

#ifdef BKB_LAYOUT
#define _COLE_DH                                                                                    \
       TH_QE,   KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,       \
       KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,       \
       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,       \
                               SPC_NAV, TAB_FUN, ENT_SYM, BSP_NUM
#else
#define _COLE_DH \
	TH_QE,   KC_W,    KC_F,    TH_PC,   KC_B,       KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,    \
	KC_A,    KC_R,    KC_S,    KC_T,    KC_G,       KC_M,    KC_N,    KC_E,    KC_I,    KC_O,       \
	KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H,    TH_CM,  TH_DU,    TH_SE, \
	                           KC_SPC,  KC_TAB,     KC_ENT,  TO(SYM)

/* ╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮
   │  Q/ESC │  W     │  F     │   P/:  │  B     │   │  J     │  L     │  U     │  Y     │    "   │
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │  A/SFT │  R/CTL │  S/CMD │  T/ALT │  G     │   │  M     │  N/ALT │  E/CMD │  I/CTL │  O/SFT │
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │   Z    │   X    │   C    │   D    │  V     │   │  K     │  H     │  , <   │  . >   │  / ?   │
   ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯
                              │  SPC   │  TAB   │   │  ENT   │  SYM   │
                              ╰────────┴────────╯   ╰────────┴────────╯*/
#endif

#ifdef BKB_LAYOUT
#define _SYMB                                                                                     \
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,    _______________DEAD_HALF_ROW_______________,  \
    KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,    ______________HOME_ROW_SCGA_R______________,  \
    KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,    _______________DEAD_HALF_ROW_______________,  \
                               KC_RPRN, KC_UNDS,    _______, XXXXXXX
#else
#define _SYMB                                                                                     \
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,  \
    KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,    ____________HOME_ROW_SCGA_R_ENT____________,  \
    KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,    XXXXXXX, XXXXXXX, XXXXXXX,  KC_ENT, TO(FNC),  \
                               TO(BSE), KC_RPRN,    KC_MINS, TO(NUM)

/* ╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮
   |   {    │   &    │   *    │   (    │   }    │   │        │        │        │        │  BSPC  │
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │  TAB   │   $    │   %    │   ^    │   +    │   │        │  ALT   │  CMD   │  CTL   │  SFT   │
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │   ~    │   !    │   @    │   #    |   |    │   │        │        │        │  ENT   │  FNC   │
   ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯
                              │  BSE   │   )    │   │   -    │  NUM   │
                              ╰────────┴────────╯   ╰────────┴────────╯*/
#endif

#ifdef BKB_LAYOUT
#define _NUMB                                                                                     \
    KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,    _______________DEAD_HALF_ROW_______________,  \
    KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,    ______________HOME_ROW_SCGA_R______________,  \
     KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,    _______________DEAD_HALF_ROW_______________,  \
                                  KC_0, KC_MINS,    KC_DOT, _______
#else
#define _NUMB                                                                                     \
    KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,  \
    KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,    ____________HOME_ROW_SCGA_R_ENT____________,  \
     KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,    XXXXXXX, XXXXXXX, XXXXXXX,  KC_ENT, TO(FNC),  \
                               TO(BSE),    KC_0,    KC_DOT, TO(SYM)

/* ╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮
   │   [    │   7    │   8    │   9    │   ]    │   │        │        │        │        │  BSPC  │
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │   ;    │   4    │   5    │   6    │   =    │   │        │  ALT   │  CMD   │  CTL   │  SFT   │
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │   `    │   1    │   2    │   3    │   \    │   │        │        │        │  ENT   │  FNC   │
   ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯
                              │  BSE   │   0    │   │   .    │  SYM   │
                              ╰────────┴────────╯   ╰────────┴────────╯*/
#endif

#ifdef BKB_LAYOUT
#define _FUNC                                                                                    \
    _______________DEAD_HALF_ROW_______________,    KC_PSCR,   KC_F7,   KC_F8,   KC_F9,  KC_F12, \
    ______________HOME_ROW_SCGA_L______________,    KC_SCRL,   KC_F4,   KC_F5,   KC_F6,  KC_F11, \
    _______________DEAD_HALF_ROW_______________,    KC_PAUS,   KC_F1,   KC_F2,   KC_F3,  KC_F10, \
                               XXXXXXX, _______,    DF(BSE), DF(CMK)
#else
#define _FUNC                                                                                    \
    XXXXXXX,RGB_RMOD, RGB_TOG, RGB_MOD, XXXXXXX,    DF(BSE), DF(CMK),   Z_UND, XXXXXXX, XXXXXXX, \
    KC_MPRV, KC_VOLD, KC_MUTE, KC_VOLU, KC_MNXT,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_CAPS, \
      Z_CUT,   Z_CPY,   Z_PST,  EE_CLR, QK_BOOT,    KC_INS,  KC_HOME, KC_PGDN, KC_PGUP,  KC_END, \
                               TO(BSE), KC_MPLY,    KC_MSTP, TO(SYM)

/* ╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮
   │        │RGB_RMOD│ RGB_TOG│ RGB_MOD│        │   |  BSE   │  CMK   │  UND   │        │        │
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │ M_PREV │ VOL_DN │  MUTE  │ VOL_UP │ M_NEXT │   │ MS LFT │ MS DN  │ MS UP  │ MS RHT |  CAPS  │
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │  Z_CUT │  Z_CPY │  Z_PST │ EE_CLR │ QK_BOOT│   │  INS   │  HOME  │ PG DN  │ PG UP  │  END   │
   ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯
                              │  BSE   │  MPLAY │   │ MSTOP  │  SYM   │
                              ╰────────┴────────╯   ╰────────┴────────╯ */
#endif

#ifdef BKB_LAYOUT
#define _POINT                                                                                   \
    XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, PLP_RST, \
    ______________HOME_ROW_SCGA_L______________,    ______________HOME_ROW_SCGA_R______________, \
    _______, DRGSCRL, SNIPING,  EE_CLR, QK_BOOT,    QK_BOOT, EE_CLR, SNIPING, DRGSCRL, _______, \
                               KC_BTN1, KC_BTN2,    KC_BTN3, KC_BTN1
#else
#define _POINT                                                                                   \
    XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, PLP_RST, \
    ______________HOME_ROW_SCGA_L______________,    ______________HOME_ROW_SCGA_R______________, \
    _______, DRGSCRL, SNIPING,  EE_CLR, QK_BOOT,    QK_BOOT,  EE_CLR, SNIPING, DRGSCRL, _______, \
                               KC_BTN1, KC_BTN2,    KC_BTN3, KC_BTN1

/* ╭────────┬────────┬────────┬────────┬────────╮   ╭────────┬────────┬────────┬────────┬────────╮
   │        │        │        │  DPI   │ SN_DPI │   | SN_DPI │  DPI   │        │        │ PLPRST │
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │  SFT   │  CTL   │  CMD   │  ALT   │        │   │        │  ALT   │  CMD   │  CTL   │  SFT   │
   ├────────┼────────┼────────┼────────┼────────┤   ├────────┼────────┼────────┼────────┼────────┤
   │        │  SCRL  │  SNIP  │ EE_CLR │ QK_BOOT│   │  INS   │  HOME  │  SNIP  │  SCRL  │        │
   ╰────────┴────────┴────────┼────────┼────────┤   ├────────┼────────┼────────┴────────┴────────╯
                              │  BTN1  │  BTN2  │   │  BTN3  │  BTN1  │
                              ╰────────┴────────╯   ╰────────┴────────╯ */
#endif

#ifdef BKB_LAYOUT
#define _MEDIA                                                                                \
    XXXXXXX,RGB_RMOD, RGB_TOG, RGB_MOD, XXXXXXX, XXXXXXX,RGB_RMOD, RGB_TOG, RGB_MOD, XXXXXXX, \
    KC_MPRV, KC_VOLD, KC_MUTE, KC_VOLU, KC_MNXT, KC_MPRV, KC_VOLD, KC_MUTE, KC_VOLU, KC_MNXT, \
    XXXXXXX, XXXXXXX, XXXXXXX,  EE_CLR, QK_BOOT, QK_BOOT,  EE_CLR, XXXXXXX, XXXXXXX, XXXXXXX, \
                               KC_MPLY, KC_MSTP, KC_MSTP, KC_MPLY
#endif

#ifdef BKB_LAYOUT
#define _NAVI                                                                                 \
    _______________DEAD_HALF_ROW_______________, _______________DEAD_HALF_ROW_______________, \
    ______________HOME_ROW_SCGA_L______________, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_CAPS, \
    _______________DEAD_HALF_ROW_______________,  KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, \
                               _______, XXXXXXX,  KC_ENT, KC_BSPC
#endif

// Mod-tap wrapper -> use on json layout layers
#define HR_MODTAP( \
      l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, \
      l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, \
      l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, \
                     l16, l17,   r16, r17                 \
) \
      l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05,       \
HRML(l06, l07, l08, l09), l10,   r06, HRMR(r07, r08, r09, r10), \
      l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, \
                     l16, l17,   r16, r17
#define HRM(k) HR_MODTAP(k)

// Pointer wrapper -> use on json layout layers
#define _POINTER_MOD(                                                  \
    L00, L01, L02, L03, L04, R05, R06, R07, R08, R09,                  \
    L10, L11, L12, L13, L14, R15, R16, R17, R18, R19,                  \
    L20, L21, L22, L23, L24, R25, R26, R27, R28, R29,                  \
    ...)                                                               \
             L00,         L01,         L02,         L03,         L04,  \
             R05,         R06,         R07,         R08,         R09,  \
             L10,         L11,         L12,         L13,         L14,  \
             R15,         R16,         R17,         R18,         R19,  \
      _L_PTR(L20),        L21,         L22,         L23,         L24,  \
             R25,         R26,         R27,         R28, _L_PTR(R29),  \
      __VA_ARGS__
#define PTR(k) _POINTER_MOD(k)

// Media wrapper -> use on json layout layers
#define _MEDIA_MOD(                                                  \
    L00, L01, L02, L03, L04, R05, R06, R07, R08, R09,                  \
    L10, L11, L12, L13, L14, R15, R16, R17, R18, R19,                  \
    L20, L21, L22, L23, L24, R25, R26, R27, R28, R29,                  \
    ...)                                                               \
             L00,         L01,         L02,         L03,         L04,  \
             R05,         R06,         R07,         R08,         R09,  \
             L10,         L11,         L12,         L13,         L14,  \
             R15,         R16,         R17,         R18,         R19,  \
             L20, _L_MED(L21),         L22,         L23,         L24,  \
             R25,         R26,         R27, _L_MED(R28),         R29,  \
      __VA_ARGS__
#define MEDIA(k) _MEDIA_MOD(k)


// Layout aliases for json keymap
#define LAYOUT_34key_w(...) LAYOUT_split_3x5_2(__VA_ARGS__)
#define LAYOUT_crkbd_w(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_kyria_w(...) LAYOUT_split_3x6_5(__VA_ARGS__)
#define LAYOUT_charybdis_w(...) LAYOUT_charybdis_3x5(__VA_ARGS__)


// Convert 3x5_2 to 42-key
#define C_42(k) CONV_42(k)
#define CONV_42( \
         l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, \
         l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, \
         l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, \
                        l16, l17,   r16, r17                 \
) \
PLP_SCR, l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, Z_CUT, \
KC_BTN2, l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, Z_CPY, \
KC_BTN1, l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, Z_PST,  \
	     LSA_T(KC_ESC), l16, l17,   r16, r17, RCS_T(KC_BSPC)


// Convert 3x5_2 to Kyria
#define C_K(k) CONV_KYRIA(k)
#define CONV_KYRIA( \
	     l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, \
	     l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, \
	     l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, \
	                    l16, l17,   r16, r17                 \
) \
    PLP_SCR, l01, l02, l03, l04, l05,                                 r01, r02, r03, r04, r05, Z_CUT, \
    KC_BTN2, l06, l07, l08, l09, l10,                                 r06, r07, r08, r09, r10, Z_CPY, \
    KC_BTN1, l11, l12, l13, l14, l15, Z_CPY, Z_PST,     Z_FND, Z_RLD, r11, r12, r13, r14, r15, Z_PST, \
	KC_LBRC, KC_LPRN, LSA_T(KC_ESC),  l16,   l17,       r16,   r17,   RCS_T(KC_BSPC), KC_RPRN, KC_RBRC

// Convert 3x5_2 to Charybdis
#define C_C(k) CONV_CHARYBDIS(k)
#define CONV_CHARYBDIS( \
	     l01, l02, l03, l04, l05,   r01, r02, r03, r04, r05, \
	     l06, l07, l08, l09, l10,   r06, r07, r08, r09, r10, \
	     l11, l12, l13, l14, l15,   r11, r12, r13, r14, r15, \
	                    l16, l17,   r16, r17                 \
) \
    l01, l02, l03, l04, l05,    r01, r02, r03, r04, r05, \
    l06, l07, l08, l09, l10,    r06, r07, r08, r09, r10, \
    l11, l12, l13, l14, l15,    r11, r12, r13, r14, r15, \
	       KC_ESC, l16, l17,    r16, r17

// clang-format on
