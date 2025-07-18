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
  L_BASE,  // dvorak on qwerty codes
  L_SYMB,  // I like symbols
  L_NATV,  // native dvorak
  L_FUNC,  // function keys
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT(
        KC_NO,    DV_1,    DV_2,    DV_3,    DV_4,    DV_5,    KC_BRIU,          KC_VOLU,   DV_6,    DV_7,    DV_8,    DV_9,    DV_0,     KC_NO,
        DV_GRV,   DV_QUOT, DV_COMM, DV_DOT,  DV_P,    DV_Y,    KC_BRID,          KC_VOLD,   DV_F,    DV_G,    DV_C,    DV_R,    DV_L,     DV_SLSH,
        // ^ tmux prefix
        KC_CAPS,  DV_A,    DV_O,    DV_E,    DV_U,    DV_I,    DV_BSLS,          DV_EQL,    DV_D,    DV_H,    DV_T,    DV_N,    DV_S,     LT(L_SYMB,DV_MINS),
        // ^ assume that os mapping sees this as an escape
        KC_LSFT,  MT(MOD_LCTL,DV_SCLN),
                           DV_Q,    DV_J,    DV_K,    DV_X,                                 DV_B,    DV_M,    DV_W,    DV_V,    MT(MOD_RCTL,DV_Z),
                                                                                                                                          KC_RSFT,
        KC_NO,    KC_LSFT, KC_LCTL, MT(MOD_LALT,KC_DOWN),
                                             MT(MOD_LGUI,KC_UP),
                                                               KC_NO,            KC_NO,              MT(MOD_RGUI,KC_LEFT),
                                                                                                              MT(MOD_RALT,KC_RIGHT),
                                                                                                                       KC_RCTL, KC_RSFT,  DF(L_NATV),
                                             KC_SPC,  KC_TAB,  OSL(L_FUNC),      OSL(L_FUNC),
                                                                                            KC_ENT, KC_BSPC
    ),

    [L_SYMB] = LAYOUT(
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, DV_LCBR, DV_RCBR, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, DV_LPRN, DV_RPRN, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, DV_LBRC, DV_RBRC, _______,                             _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,          _______,          _______,           _______, _______, _______, _______, _______,
                                             _______, _______, _______,          _______,  _______, _______
    ),

    [L_NATV] = LAYOUT(
        _______,  _______, _______, _______, _______, _______, KC_LBRC,          _______,  _______, _______, _______, _______, _______, _______,
        KC_GRV,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_RBRC,          _______,  KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
        KC_ESC,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_BSLS,          KC_EQL,   KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
        // ^ assume that we don't have os mapping for this layer                                                                        ^ too lazy to
        //                                                                                                                                add another layer
        _______,  MT(MOD_LCTL,KC_SCLN),
                           KC_Q,    KC_J,    KC_K,    KC_X,                                KC_B,    KC_M,    KC_W,    KC_V,    MT(MOD_RCTL,KC_Z),
                                                                                                                                        _______,
        _______,  _______, _______, _______, _______,          _______,          _______,           _______, _______, _______, _______, DF(L_BASE),
                                             _______, _______, OSL(L_FUNC),      OSL(L_FUNC),
                                                                                           _______, _______
    ),

    [L_FUNC] = LAYOUT(
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, DB_TOGG,
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,          _______,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
        _______,  _______, _______, _______, _______, KC_F6,   _______,          _______,  KC_F7,   KC_MEDIA_PREV_TRACK,
                                                                                                             KC_MEDIA_PLAY_PAUSE,
                                                                                                                      KC_MEDIA_NEXT_TRACK,
                                                                                                                               _______, _______,
        _______,  _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,          _______,          _______,           _______, _______, _______, _______, _______,
                                             _______, _______, _______,          _______,  _______, _______
    ),


};
// clang-format on

// clang-format off
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        '*',  '*', '*', '*', '*', '*', '*',          '*',  '*', '*', '*', '*', '*', '*',
        '*',  '*', '*', '*', '*', '*', '*',          '*',  '*', '*', '*', '*', '*', '*',
        '*',  '*', '*', '*', '*', '*', '*',          '*',  '*', '*', '*', '*', '*', '*',
        '*',  'l', '*', '*', '*', '*',                     '*', '*', '*', '*', '*', '*',
        '*',  '*', '*', '*', '*',      '*',          '*',       '*', '*', '*', '*', '*',
                             'l', '*', '*',          '*',  '*', '*'
                           // ^ I would roll the space, hack chordal hold to disambiguate
    );
// clang-format off

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
  set_color_row_col(5, 2, 168, 16, 255);
  set_color_row_col(11, 4, 168, 16, 255);
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

void set_natv_colors(void)
{
  // Let color pass through

  // Go back
  set_color_row_col(10, 6, 168, 16, 255);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode) {
  case MT(MOD_LCTL, DV_SCLN):
    // Wait for a long time if shift is held
    // This would effecitvely allow `:` to be triggered correctly
    if (get_mods() & MOD_MASK_SHIFT) {
      return TAPPING_TERM + 500;
    }
    return TAPPING_TERM;

  default:
    return TAPPING_TERM;
  }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode) {
  case MT(MOD_LCTL, DV_SCLN):
    // Interrupt as soon as another key is hit
    // When we get shifted semicolon it's always :
    // I can't think of a case where I would want the next key to be with control held down
    if (get_mods() & MOD_MASK_SHIFT) {
      return false;
    }
    return true;

  case LT(L_SYMB, DV_MINS):
    // Interrupt if shift is held down
    if (get_mods() & MOD_MASK_SHIFT) {
      return false;
    }
    return true;

  case MT(MOD_RCTL, DV_Z):
    return false;

  default:
    return true;
  }
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t prev_keycode)
{
  if (!is_flow_tap_key(keycode) || !is_flow_tap_key(prev_keycode)) {
    return 0;
  }

  switch (keycode) {
  // turn this off, high error rate
  case MT(MOD_LCTL, DV_SCLN):
    return 0;

  // on word boundary use default hold logic
  case MT(MOD_RCTL, DV_Z):
    switch (prev_keycode) {
    case DV_RPRN:
    case KC_ENTER:
    case KC_SPACE:
      return 0;

    default:
      return FLOW_TAP_TERM;
    }

  default:
    return FLOW_TAP_TERM;
  }
}

bool rgb_matrix_indicators_user(void)
{
  switch (get_highest_layer(default_layer_state | layer_state)) {
  case L_FUNC:
    set_fn_colors();
    break;
  case L_SYMB:
    set_symb_colors();
    break;
  case L_NATV:
    set_natv_colors();
    break;
  }
  return true;
}


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
