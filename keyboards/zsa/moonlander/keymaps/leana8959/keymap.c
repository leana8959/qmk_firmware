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
        KC_CAPS,
        //  ^ assume that os mapping sees this as an escape
                  DV_A,    DV_O,    DV_E,    DV_U,    DV_I,    KC_NO,            KC_NO,     DV_D,    DV_H,    DV_T,    DV_N,    DV_S,     OSL(SYMBOL),
        KC_LSFT,  DV_SCLN, DV_Q,    DV_J,    DV_K,    DV_X,                                 DV_B,    DV_M,    DV_W,    DV_V,    DV_Z,     KC_RSFT,
        _______,  KC_LSFT, KC_LCTL, LALT_T(KC_DOWN),
                                             LGUI_T(KC_UP),    KC_RALT,          KC_RALT,            RGUI_T(KC_LEFT),
                                                                                                            LALT_T(KC_RIGHT),
                                                                                                                       KC_RCTL, KC_RSFT,  _______,
                                             KC_SPC,  KC_TAB,  _______,          _______,   KC_ENTER,KC_BSPC
    ),

    [SYMBOL] = LAYOUT(
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, DV_LCBR, DV_RCBR, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, DV_LPRN, DV_RPRN, _______, _______,          _______,  _______, DV_EQL,  DV_MINS, DV_BSLS, _______, _______,
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

bool rgb_matrix_indicators_user(void)
{
  layer_state_t highest_layer = get_highest_layer(layer_state);
  if (highest_layer > BASE) {
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
      for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
        uint8_t index = g_led_config.matrix_co[row][col];
        switch (keymaps[highest_layer][row][col]) {
        case KC_TRANSPARENT:
          if (IS_QK_ONE_SHOT_LAYER(keymaps[BASE][row][col])) {
            rgb_matrix_set_color(index, MY_RGB_PURPLE);
          } else {
            rgb_matrix_set_color(index, RGB_OFF);
          }
          break;
        case KC_MEDIA_NEXT_TRACK ... KC_MEDIA_PLAY_PAUSE:
          rgb_matrix_set_color(index, RGB_WHITE);
          break;
        case DB_TOGG:
        case QK_DYNAMIC_TAPPING_TERM_PRINT ... QK_DYNAMIC_TAPPING_TERM_DOWN:
          rgb_matrix_set_color(index, MY_RGB_PURPLE);
          break;
        default:  // assume the rest are symbols
          rgb_matrix_set_color(index, MY_RGB_CYAN);
        }
      }
    }
  }
  return false;
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
