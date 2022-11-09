/*
Copyright 2018 Mattia Dal Ben <matthewdibi@gmail.com>

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

/* Use I2C or Serial, not both */
#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 14
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD
// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// Immediately turn on layer if key is pressed quickly
// this cancels IGNORE_MOD_TAP_INTERRUPT.
// #define HOLD_ON_OTHER_KEY_PRESS

#define TAPPING_TOGGLE 1

// Combos
#undef COMBO_TERM
#define COMBO_TERM 20
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_TERM_PER_COMBO
// All combos are specified from the base layer, saves space and keeps me sane
#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_VARIABLE_LEN

// does nothing :D
#define COMBO_ALLOW_ACTION_KEYS

#define DEFAULT_XCASE_SEPARATOR KC_MINS
#define XCASE_DELIMITER_KEY KC_UNDS

// Not supported without flto
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#define TAPPING_TERM 240

// Autoshift! I'm to slow with the pinkies!
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_auto_shift.md
#define AUTO_SHIFT_TIMEOUT_PER_KEY
