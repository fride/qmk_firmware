#pragma once

#include QMK_KEYBOARD_H

bool tap_undead_key(bool key_down, uint16_t code);
void tap_space_shift(uint16_t key, bool key_down);
void double_tap(uint16_t keycode);
void double_tap_space(uint16_t keycode);
void double_parens_left(uint16_t left, uint16_t right);
