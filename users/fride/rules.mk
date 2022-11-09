AUTO_SHIFT_ENABLE = yes
COMBO_ENABLE = yes
MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = no

# Easy definition of combos
VPATH +=  keyboards/gboards/

APPLY_USERSPACE			= yes

# Extra features that are nice but takes space
WPM_ENABLE = no
EXTRAKEY_ENABLE = no        # For volume keys and similar
LEADER_ENABLE = no
TAP_DANCE_ENABLE = no
RGBLIGHT_ENABLE = no        # Keyboard RGB underglow
RGB_MATRIX_ENABLE = no      # Disable RGB, not used on Kyria

# Saves a bunch of memory
EXTRAFLAGS += -flto
CONSOLE_ENABLE = no
VERBOSE = no
DEBUG_MATRIX_SCAN_RATE  = no
DEBUG_MATRIX = no
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no

SRC += features/layermodes.c
SRC += features/casemodes.c
SRC += features/repeat.c
SRC += features/swapper.c
SRC += fride.c
SRC += features/nshot_mod.c
SRC += features/leader.c
SRC += features/utils.c
SRC += features/tap_hold.c
