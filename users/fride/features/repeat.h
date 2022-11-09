
#pragma once

// from https://github.com/treeman/qmk_firmware/blob/master/keyboards/ferris/keymaps/treeman/repeat.h

#include QMK_KEYBOARD_H

// Register a keycode we should repeat with the repeat key
void register_key_to_repeat(uint16_t keycode);
// Last keycode
uint16_t last_key(void);
// Repeat key actions
void update_repeat_key(keyrecord_t *record);

//void update_reverse_repeat_key(keyrecord_t *record);
