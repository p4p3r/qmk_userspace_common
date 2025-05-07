# Disable unused features
MAGIC_ENABLE = no
CONSOLE_ENABLE = no
UNICODE_ENABLE = no
GRAVE_ESC_ENABLE = no
SPACE_CADET_ENABLE = no
SWAP_HANDS_ENABLE = no
BOOTMAGIC_ENABLE = no
TAP_DANCE_ENABLE = no
RGB_MATRIX_ENABLE = no
RGBLIGHT_ENABLE = no
VIA_ENABLE = no
CAPS_WORD_ENABLE = no

# Enable common features
LTO_ENABLE = yes
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
COMBO_ENABLE = yes

INTROSPECTION_KEYMAP_C = p4p3r.c

# NanoBoot firmware
ifeq ($(strip $(NANOBOOT)), yes)
	BOOTLOADER = qmk-hid
	BOOTLOADER_SIZE = 512
endif

# RGB Matrix boards
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), crkbd/rev1 splitkb/aurora/sweep/rev1 1bastardkb/charybdis/3x5))
    RGB_MATRIX_ENABLE = yes
	SRC += rgb.c
endif

# RGB Underglow boards
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), crkbd/rev1 splitkb/kyria/rev1))
    RGBLIGHT_ENABLE = yes
	SRC += rgb.c
endif

# Kyria
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), splitkb/kyria/rev1))
	WPM_ENABLE=yes
endif

# Charybdis
ifeq ($(strip $(KEYBOARD)), $(filter $(KEYBOARD), splitkb/aurora/sweep/rev1 bastardkb/charybdis/3x5))
    BOOTMAGIC_ENABLE = yes
	VIA_ENABLE = yes
endif

# BKB-like layout
ifeq ($(strip $(BKB_LAYOUT)), yes)
    OPT_DEFS += -DBKB_LAYOUT
endif
