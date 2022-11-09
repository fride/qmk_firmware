#pragma once

#include QMK_KEYBOARD_H

enum layers { _BASE, _NAV, _NUM,_SYM, _MODS, _FUN};

enum custom_keycodes {
  QUOTE = SAFE_RANGE,
  REPEAT,
  LEADER,

  CIRC,
  GRV,
  TILD,

  // Smart caps lock and layers that turn off on certain keys
  CAPSWORD,
  NUMWORD,
  SENTENCE,

  // Layer management
  CANCEL, // Cancel SYMWORD and NUMWORD
  CLEAR,  // Clear all WORD, one-shots and reset to BASE

  // N-Shot Mods
  OS_LSFT, // OS Mods
  OS_LCTL, // OS Mods
  OS_LALT, // OS Mods
  OS_LGUI, // OS Mods
  TS_LCTL, // Two-shot ctrl

  SPAZE, // try this to handle the one time mods with space.

  ARROW_L,
  ARROW_R,
  ANFZCH, // TODO remove this?
  SZ,
  QU,

  COPY_PASTE,
  SP_MOD, // oneshot modifier and tap, nav layer on hold. See 'NAV_MOD'
  SP_SFT,
  CPYPASTE,

  NUM_G,
  VIM_COLON,
  VIM_SAFE,

  SW_APP,
  SW_WIN,
  MOUSE_TGL,

  // to override shifted stuff!
  SLASH,
  LPAREN,
  RPAREN,
  BRACE, // TODO NEEDED?
  UNDER,
  SNAKE,
  KEBAB

};

#define NAV_SPC LT(_NAV, KC_SPC)

// Semantic Keys
#define FWD G(KC_RBRC)
#define BACK G(KC_LBRC)
#define TAB_L G(S(KC_LBRC))
#define TAB_R G(S(KC_RBRC))
#define SPACE_L A(G(KC_LEFT))
#define SPACE_R A(G(KC_RGHT))

// combos for layers.:
#define CLN_SYM LT(_SYM, KC_COLON)
#define QUOT_MOD LT(1, KC_QUOTE)
#define SCLN_FUN LT(3, KC_SCLN)
#define ESC_SYM LT(_SYM, KC_ESC)
#define TAB_MODS LT(_MODS, KC_TAB)
