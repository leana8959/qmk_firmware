/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * 2025 Leana
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_dvorak.h"
#include "print.h"

enum layers {
  BASE,
  SYMBOL,
  FUNCTION,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        OSL(FUNCTION),
                  DV_1,    DV_2,    DV_3,    DV_4,    DV_5,    KC_BRIU,          KC_VOLU,   DV_6,    DV_7,    DV_8,    DV_9,    DV_0,     KC_NO,
        DV_GRV,   DV_QUOT, DV_COMM, DV_DOT,  DV_P,    DV_Y,    KC_BRID,          KC_VOLD,   DV_F,    DV_G,    DV_C,    DV_R,    DV_L,     DV_SLSH,
        KC_CAPS,  DV_A,    DV_O,    DV_E,    DV_U,    DV_I,    DV_BSLS,          DV_EQL,    DV_D,    DV_H,    DV_T,    DV_N,    DV_S,     LT(SYMBOL,DV_MINS),
        // ^ assume that os mapping sees this as an escape
        KC_LSFT,  LCTL_T(DV_SCLN),
                           DV_Q,    DV_J,    DV_K,    DV_X,                                 DV_B,    DV_M,    DV_W,    DV_V,    RCTL_T(DV_Z),
                                                                                                                                          KC_RSFT,
        _______,  KC_NO,   KC_NO,   KC_DOWN, KC_UP,            KC_RALT,          KC_RALT,            KC_LEFT, KC_RIGHT,
                                                                                                                       KC_NO,   KC_NO,    _______,
                                             KC_SPC,  KC_TAB,  _______,          _______,   KC_ENT,  KC_BSPC
    ),

    [SYMBOL] = LAYOUT(
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, DV_LCBR, DV_RCBR, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, DV_LPRN, DV_RPRN, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, DV_LBRC, DV_RBRC, _______,                             _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,          _______,          _______,           _______, _______, _______, _______, _______,
                                             _______, _______, _______,          _______,  _______, _______
    ),

    [FUNCTION] = LAYOUT(
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, DB_TOGG,
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,          _______,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
        _______,  _______, _______, _______, _______, KC_F6,   _______,          _______,  KC_F7,   KC_MEDIA_PREV_TRACK,
                                                                                                             KC_MEDIA_PLAY_PAUSE,
                                                                                                                      KC_MEDIA_NEXT_TRACK,
                                                                                                                               _______, _______,
        _______,  _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,          _______,          _______,           _______, _______, _______, _______, _______,
                                             _______, _______, _______,          DT_PRNT,  DT_DOWN, DT_UP
    ),
};
// clang-format on

const key_override_t *key_overrides[] = {
  // Shift + Backspace = Delete
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_BSPC, KC_DEL, ~0, MOD_MASK_CAG),
};

void set_fn_colors(void)
{
  // Disable pass through
  for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    rgb_matrix_set_color(i, 0, 0, 0);
  }

  // Function keys
  set_color_row_col(1, 1, 15, 208, 255);
  set_color_row_col(1, 2, 15, 208, 255);
  set_color_row_col(1, 3, 15, 208, 255);
  set_color_row_col(1, 4, 15, 208, 255);
  set_color_row_col(1, 5, 15, 208, 255);
  set_color_row_col(2, 5, 15, 208, 255);

  set_color_row_col(8, 1, 15, 208, 255);
  set_color_row_col(7, 1, 15, 208, 255);
  set_color_row_col(7, 2, 15, 208, 255);
  set_color_row_col(7, 3, 15, 208, 255);
  set_color_row_col(7, 4, 15, 208, 255);
  set_color_row_col(7, 5, 15, 208, 255);

  // Music keys
  set_color_row_col(8, 2, 255, 255, 255);
  set_color_row_col(8, 3, 255, 255, 255);
  set_color_row_col(8, 4, 255, 255, 255);

  // Go back
  set_color_row_col(0, 0, 168, 16, 255);
}

void set_symb_colors(void)
{
  // Disable pass through
  for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    rgb_matrix_set_color(i, 0, 0, 0);
  }

  // Symbols
  set_color_row_col(1, 3, 15, 208, 255);
  set_color_row_col(1, 4, 15, 208, 255);
  set_color_row_col(2, 3, 15, 208, 255);
  set_color_row_col(2, 4, 15, 208, 255);
  set_color_row_col(3, 3, 15, 208, 255);
  set_color_row_col(3, 4, 15, 208, 255);

  // Go back
  set_color_row_col(8, 6, 168, 16, 255);
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode) {
  case LT(SYMBOL, DV_MINS):
  case MT(MOD_LCTL, DV_SCLN):
    if (get_mods() & MOD_MASK_SHIFT) {
      return false;
    }
    return true;

  case MT(MOD_RCTL, DV_Z):
    return true;

  default:
    return true;
  }
}

bool rgb_matrix_indicators_user(void)
{
  switch (get_highest_layer(default_layer_state | layer_state)) {
  case FUNCTION:
    set_fn_colors();
    break;
  case SYMBOL:
    set_symb_colors();
    break;
  }
  return true;
}

const uint16_t PROGMEM super_l[] = { DV_E, DV_K, COMBO_END };
const uint16_t PROGMEM ctrl_alt_l[] = { DV_Q, DV_E, COMBO_END };
const uint16_t PROGMEM ctrl_shft_l[] = { DV_E, LCTL_T(DV_SCLN), COMBO_END };
const uint16_t PROGMEM shift_super_l[] = { LCTL_T(DV_SCLN), DV_K, COMBO_END };
const uint16_t PROGMEM alt_super_l[] = { DV_O, DV_K, COMBO_END };

const uint16_t PROGMEM super_r[] = { DV_M, DV_T, COMBO_END };
const uint16_t PROGMEM ctrl_alt_r[] = { DV_T, DV_V, COMBO_END };
const uint16_t PROGMEM ctrl_shft_r[] = { DV_T, RCTL_T(DV_Z), COMBO_END };
const uint16_t PROGMEM shift_super_r[] = { DV_M, RCTL_T(DV_Z), COMBO_END };

combo_t key_combos[] = {
  COMBO(super_l, OS_LGUI),      COMBO(ctrl_alt_l, OS_LCA),    COMBO(ctrl_shft_l, OS_LCS),
  COMBO(shift_super_l, OS_LSG), COMBO(alt_super_l, OS_LAG),

  COMBO(super_r, OS_RGUI),      COMBO(ctrl_alt_r, OS_LCA),  // For some reason RCA doesn't work 🤔
  COMBO(ctrl_shft_r, OS_RCS),   COMBO(shift_super_r, OS_RSG),
};

void keyboard_post_init_user(void)
{
  rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
#ifdef CONSOLE_ENABLE
  if (debug_enable)
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n",
            keycode, record->event.key.col, record->event.key.row, record->event.pressed,
            record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}
