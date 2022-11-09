/*
    copied from
   https://github.com/possumvibes/qmk_firmware/blob/possumdev/users/possumvibes/features/nshot_mod.c
*/
#include "nshot_mod.h"
#include "keycodes.h"

nshot_state_t nshot_states[] = {{OS_LSFT, KC_LSFT, 1, os_up_unqueued, 0},
                                {OS_LCTL, KC_LCTL, 1, os_up_unqueued, 0},
                                {OS_LALT, KC_LALT, 1, os_up_unqueued, 0},
                                {OS_LGUI, KC_LGUI, 1, os_up_unqueued, 0},
                                {TS_LCTL, KC_LCTL, 2, os_up_unqueued, 0}};
uint8_t NUM_NSHOT_STATES = sizeof(nshot_states) / sizeof(nshot_state_t);

void cancel_nshots() {
  nshot_state_t *curr_state = NULL;
  for (int i = 0; i < NUM_NSHOT_STATES; ++i) {
    curr_state = &nshot_states[i];
    curr_state->state = os_up_unqueued;
    curr_state->count = 0;
    unregister_code(curr_state->mod);
  }
}
void tigger_nshot(uint16_t trigger) {
  nshot_state_t *curr_state = NULL;
  cancel_nshots();
  for (int i = 0; i < NUM_NSHOT_STATES; ++i) {
    curr_state = &nshot_states[i];
    if (trigger == curr_state->trigger) {
      // Trigger keydown
      if (curr_state->state == os_up_unqueued) {
        register_code(curr_state->mod);
      }
      curr_state->state = os_up_queued;
      curr_state->count = 0;
      break;
    }
  }
}

void process_nshot_state_pre(uint16_t keycode, keyrecord_t *record) {
  nshot_state_t *curr_state = NULL;

  for (int i = 0; i < NUM_NSHOT_STATES; ++i) {
    curr_state = &nshot_states[i];

    if (keycode == curr_state->trigger) {
      if (record->event.pressed) {
        // Trigger keydown
        if (curr_state->state == os_up_unqueued) {
          register_code(curr_state->mod);
        }
        curr_state->state = os_down_unused;
        curr_state->count = 0;
      } else {
        // Trigger keyup
        switch (curr_state->state) {
        case os_down_unused:
          // If we didn't use the mod while trigger was held, queue it.
          curr_state->state = os_up_queued;
          break;
        case os_down_used:
          // If we did use the mod while trigger was held, unregister it.
          curr_state->state = os_up_unqueued;
          unregister_code(curr_state->mod);
          break;
        default:
          break;
        }
      }
    }
  }
}
void process_nshot_state_post(uint16_t keycode, keyrecord_t *record) {
  nshot_state_t *curr_state = NULL;

  for (int i = 0; i < NUM_NSHOT_STATES; ++i) {
    curr_state = &nshot_states[i];
    if (keycode != curr_state->trigger) {
      if (record->event.pressed) {
        if (is_nshot_cancel_key(keycode) &&
            curr_state->state != os_up_unqueued) {
          // Cancel oneshot on designated cancel keydown.
          curr_state->state = os_up_unqueued;
          curr_state->count = 0;
          unregister_code(curr_state->mod);
        }
      } else {
        if (!is_nshot_ignored_key(keycode, record)) {
          // On non-ignored keyup, consider the oneshot used.
          switch (curr_state->state) {
          case os_down_unused:
            // The mod key is being held as a normal mod.
            curr_state->state = os_down_used;
            break;
          case os_up_queued:
            // The mod key is being used as an n-shot.
            // Increment the keys-used count.
            curr_state->count = curr_state->count + 1;

            // If the n-shot max has been reached, complete the n-shot.
            if (curr_state->count == curr_state->max_count) {
              curr_state->state = os_up_unqueued;
              curr_state->count = 0;
              unregister_code(curr_state->mod);
            }
            break;
          default:
            break;
          }
        }
      }
    }
  }
}

bool is_nshot_cancel_key(uint16_t keycode) {
  switch (keycode) {
  case CANCEL:
  case CLEAR:
    return true;
  default:
    return false;
  }
}

bool is_nshot_ignored_key(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case OS_LSFT:  // OS Mods
  case OS_LCTL:  // OS Mods
  case OS_LALT:  // OS Mods
  case OS_LGUI:  // OS Mods
  case QUOT_MOD: // Two-shot ctrl
    return true;
  case NAV_SPC: // TODO -> check if this is a keyup after layer switch or after
                // ....
    if (layer_state_is(_NAV)) {
      return true;
    }
    return false;
  default:
    return false;
  }
}
