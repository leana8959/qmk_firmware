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

#include "keycodes.h"
#include QMK_KEYBOARD_H
#include "keymap_dvorak.h"

enum layers {
  BASE,  // dvorak on qwerty codes
  SYMBOL,

  BROWSER,

  XMONAD_FOCUS_RESIZE,
  XMONAD_MOVE,
  XMONAD_SWAP,

  FUNCTION_KEYS,  // function keys
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        OSL(FUNCTION_KEYS),
                  DV_1,    DV_2,    DV_3,    DV_4,    DV_5,    KC_BRIU,          KC_VOLU,   DV_6,    DV_7,    DV_8,    DV_9,    DV_0,     KC_BSPC,
        DV_GRV,   DV_QUOT, DV_COMM, DV_DOT,  DV_P,    DV_Y,    KC_BRID,          KC_VOLD,   DV_F,    DV_G,    DV_C,    DV_R,    DV_L,     DV_SLSH,
        KC_CAPS,  DV_A,    DV_O,    DV_E,    DV_U,    DV_I,    KC_TAB,           _______,   DV_D,    DV_H,    DV_T,    DV_N,    DV_S,     KC_ENTER,
        KC_LSFT,  DV_SCLN, DV_Q,    DV_J,    DV_K,    DV_X,                                 DV_B,    DV_M,    DV_W,    DV_V,    DV_Z,     KC_RSFT,
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
                                             KC_SPC,  OSM(MOD_LCTL),
                                                               XXXXXXX,          XXXXXXX,   OSM(MOD_RCTL), TO(SYMBOL)
    ),

    [SYMBOL] = LAYOUT(
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  DV_EXLM, DV_AT,   DV_HASH, DV_DLR,  DV_PERC, _______,          _______,  DV_CIRC, DV_AMPR, DV_ASTR, _______, _______, _______,
        _______,  _______, DV_EQL,  DV_TILD, DV_GRV,  _______, _______,          _______,  DV_BSLS, DV_LPRN, DV_RPRN, DV_MINS, _______, _______,
        _______,  _______, _______, _______, _______, _______,                             DV_LBRC, DV_LCBR, DV_RCBR, DV_RBRC, _______, _______,
        _______,  _______, _______, _______, _______,          _______,          _______,           _______, _______, _______, _______, _______,
                                             TO(BASE),KC_RALT, _______,          _______,  _______, TO(XMONAD_FOCUS_RESIZE)
    ),

    [XMONAD_FOCUS_RESIZE] = LAYOUT(
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, LGUI(DV_COMM), LGUI(DV_DOT),
                                             _______, _______, _______,          _______,  _______, LGUI(DV_O), LGUI(DV_C), LGUI(DV_P), _______, _______,
        _______,  _______, LSG(DV_COMM), LSG(DV_COMM),
                                             _______, _______, _______,          _______,  _______, LGUI(DV_H), LGUI(DV_T), LGUI(DV_N), LGUI(DV_S), _______,
        _______,  _______, _______, LGUI(DV_J), LGUI(DV_K),
                                                      _______,                             _______, LGUI(DV_M), LGUI(DV_W), LGUI(DV_V), LGUI(DV_Z), _______,
        _______,  _______, _______, _______, _______,          _______,          _______,           _______, _______, _______, _______, _______,
                                             TO(BASE),_______, _______,          _______,  _______, TO(XMONAD_MOVE)
    ),

    [XMONAD_MOVE] = LAYOUT(
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, LAG(DV_H), LAG(DV_T), LAG(DV_N), LAG(DV_S), _______,
        _______,  _______, _______, LSG(DV_J), LSG(DV_K),
                                                      _______,                             _______, LAG(DV_M), LAG(DV_W), LAG(DV_V), LAG(DV_Z), _______,
        _______,  _______, _______, _______, _______,          _______,          _______,           _______, _______, _______, _______, _______,
                                             TO(BASE),_______, _______,          _______,  _______, TO(XMONAD_SWAP)
    ),

    [XMONAD_SWAP] = LAYOUT(
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, LCG(DV_H), LCG(DV_T), LCG(DV_N), LCG(DV_S), _______,
        _______,  _______, _______, LSG(DV_J), LSG(DV_K),
                                                      _______,                             _______, LCG(DV_M), LCG(DV_W), LCG(DV_V), LCG(DV_Z), _______,
        _______,  _______, _______, _______, _______,          _______,          _______,           _______, _______, _______, _______, _______,
                                             TO(BASE),_______, _______,          _______,  _______, TO(XMONAD_FOCUS_RESIZE)
    ),

    [BROWSER] = LAYOUT(
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, QK_MOUSE_WHEEL_LEFT,
                                                                                                             KC_WWW_BACK,
                                                                                                                      KC_WWW_FORWARD,
                                                                                                                               QK_MOUSE_WHEEL_RIGHT, _______,
        _______,  _______, _______, QK_MOUSE_WHEEL_DOWN,
                                             QK_MOUSE_WHEEL_UP,
                                                      _______,                             _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,          _______,          _______,           _______, _______, _______, _______, _______,
                                             TO(BASE),_______, _______,          _______,  _______, TO(SYMBOL)
    ),

    // More of a standalone layer
    [FUNCTION_KEYS] = LAYOUT(
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
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

const key_override_t *key_overrides[] = {
  // Shift + Backspace = Delete
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_BSPC, KC_DEL, ~0, MOD_MASK_CAG),
};

// Keep these for the moment for xmonad floats while we think of a better solution
const uint16_t PROGMEM ctrl_alt_l[] = { DV_Q, DV_E, COMBO_END };
const uint16_t PROGMEM ctrl_alt_r[] = { DV_T, DV_V, COMBO_END };

combo_t key_combos[] = {
  COMBO(ctrl_alt_l, LALT(KC_LCTL)),
  COMBO(ctrl_alt_r, LALT(KC_RCTL)),  // use LALT because ralt (altgr) is used for x11's compose key
};

void keyboard_post_init_user(void)
{
  rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
}
