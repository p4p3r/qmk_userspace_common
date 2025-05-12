# Disable unused features
CAPS_WORD_ENABLE = no
CONSOLE_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
SWAP_HANDS_ENABLE = no
UNICODE_ENABLE = no
TAP_DANCE_ENABLE = no

# Enable common features
BOOTMAGIC_ENABLE = yes
COMBO_ENABLE = yes
EXTRAKEY_ENABLE = yes
LTO_ENABLE = yes
MOUSEKEY_ENABLE = yes
VIA_ENABLE = yes
WPM_ENABLE=yes

INTROSPECTION_KEYMAP_C = p4p3r.c

# NanoBoot firmware
ifeq ($(strip $(NANOBOOT)), yes)
	BOOTLOADER = qmk-hid
	BOOTLOADER_SIZE = 512

	# Preserve space
	BOOTMAGIC_ENABLE = no
	VIA_ENABLE = no
	WPM_ENABLE=no
endif

# RGB Matrix/Underglow boards
ifneq ($(filter yes,$(RGB_MATRIX_ENABLE) $(RGBLIGHT_ENABLE)),)
	SRC += rgb.c
endif

# TODO: reverse behavior
OPT_DEFS += -DBKB_LAYOUT
