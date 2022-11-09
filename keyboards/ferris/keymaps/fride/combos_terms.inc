uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case combo_numword:
   return COMBO_TERM + 20;
case combo_reset:
   return COMBO_TERM + 10;

case combo_canel:
   return COMBO_TERM + 10;

case combo_q:
   return COMBO_TERM + 20;

case combo_min:
   return COMBO_TERM + 10;

case combo_qu:
   return COMBO_TERM + 10;

case combo_backspace:
   return COMBO_TERM + 10;

case combo_del:
   return COMBO_TERM + 10;

case combo_eql:
   return COMBO_TERM + 10;

case combo_quote:
   return COMBO_TERM + 0;

case combo_esc_sym:
   return COMBO_TERM + 0;

case combo_tab_mod:
   return COMBO_TERM + 10;

case combo_colon_sym:
   return COMBO_TERM + 0;

case combo_enter:
   return COMBO_TERM + 10;

case combo_double_quote:
   return COMBO_TERM + 10;

case combo_gui:
   return COMBO_TERM + 5;

case combo_alt:
   return COMBO_TERM + 5;

case combo_dollar:
   return COMBO_TERM + 5;

case combo_caps:
   return COMBO_TERM + 5;

case combo_two:
   return COMBO_TERM + 10;

case combo_four:
   return COMBO_TERM + 10;

case combo_six:
   return COMBO_TERM + 10;

case combo_eight:
   return COMBO_TERM + 10;

case combo_zero:
   return COMBO_TERM + 10;

case combo_one:
   return COMBO_TERM + 10;

case combo_three:
   return COMBO_TERM + 10;

case combo_five:
   return COMBO_TERM + 10;

case combo_seven:
   return COMBO_TERM + 10;

case combo_nine:
   return COMBO_TERM + 10;

case combo_tilde:
   return COMBO_TERM + 10;

case combo_plus:
   return COMBO_TERM + 10;

case combo_past:
   return COMBO_TERM + 10;

case combo_hash:
   return COMBO_TERM + 10;

case combo_at:
   return COMBO_TERM + 10;

case combo_circ:
   return COMBO_TERM + 10;

case combo_less:
   return COMBO_TERM + 10;

case combo_pipe:
   return COMBO_TERM + 10;

case combo_mins:
   return COMBO_TERM + 10;

case combo_greater:
   return COMBO_TERM + 10;

case combo_backsl:
   return COMBO_TERM + 10;

case combo_grave:
   return COMBO_TERM + 10;

case combo_left_br:
   return COMBO_TERM + 10;

case combo_left_brc:
   return COMBO_TERM + 10;

case combo_right_brc:
   return COMBO_TERM + 10;

case combo_right_br:
   return COMBO_TERM + 10;

case combo_exclamation:
   return COMBO_TERM + 10;

case combo_percent:
   return COMBO_TERM + 10;

case combo_question_mark:
   return COMBO_TERM + 10;

case combo_ampersen:
   return COMBO_TERM + 10;

case combo_left_paren:
   return COMBO_TERM + 10;

case combo_right_paren:
   return COMBO_TERM + 10;

case combo_underscore:
   return COMBO_TERM + 10;

        default:
            return COMBO_TERM + 25;
    }
}
