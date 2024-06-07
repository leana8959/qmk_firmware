/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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

/*
 * Inspiration:
 * https://github.com/ThePrimeagen/keyboards
 */

#include QMK_KEYBOARD_H
#include "keymap_dvorak.h"
#include "os_detection.h"

enum layers {
  L_BASE,  // dvorak on qwerty codes
  L_NATV,  // native dvorak
  L_GAME,  // WASD and stuff
  L_FUNC   // function keys
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // TODO: macro to open iTerm on red button on the right hand
    [L_BASE] = LAYOUT(
        OSL(L_FUNC),  DV_1,    DV_2,    DV_3,    DV_4,    DV_5,    KC_BRIU,          KC_VOLU,   DV_6,    DV_7,    DV_8,    DV_9,    DV_0,     TG(L_GAME),
        KC_CAPS,  DV_QUOT, DV_COMM, DV_DOT,  DV_P,    DV_Y,    KC_BRID,          KC_VOLD,   DV_F,    DV_G,    DV_C,    DV_R,    DV_L,     DV_SLSH,
        KC_ESC,   DV_A,    DV_O,    DV_E,    DV_U,    DV_I,    DV_PLUS,          DV_EQL,    DV_D,    DV_H,    DV_T,    DV_N,    DV_S,     DV_MINS,
        KC_LSFT,  DV_SCLN, DV_Q,    DV_J,    DV_K,    DV_X,                                 DV_B,    DV_M,    DV_W,    DV_V,    DV_Z,     KC_RSFT,
        KC_APP,   KC_LSFT, KC_LCTL, MT(MOD_LALT, KC_DOWN), MT(MOD_LGUI, KC_UP),         LGUI(S(KC_4)),           DV_BSLS,            MT(MOD_RGUI, KC_LEFT), MT(MOD_RALT, KC_RIGHT), KC_RCTL, KC_RSFT, DF(L_NATV),
                                             KC_SPC,  KC_TAB, DV_DLR,            DV_GRV,    KC_ENT,  KC_BSPC
    ),

    [L_NATV] = LAYOUT(
        _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BRIU,          KC_VOLU,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     _______,
        KC_CAPS,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_BRID,          KC_VOLD,   KC_F,    KC_G,    KC_C,    KC_R,    KC_L,     KC_SLSH,
        KC_ESC,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_PLUS,          KC_EQL,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,     KC_MINS,
        KC_LSFT,  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                                 KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,     KC_RSFT,
        KC_APP,   KC_LSFT, KC_LCTL, MT(MOD_LALT, KC_DOWN), MT(MOD_LGUI, KC_UP),         XXXXXXX,           KC_BSLS,            MT(MOD_RGUI, KC_LEFT), MT(MOD_RALT, KC_RIGHT), KC_RCTL, KC_RSFT, DF(L_BASE),
                                             KC_SPC,  KC_TAB, KC_DLR,            KC_GRV,    KC_ENT,  KC_BSPC
    ),

    [L_GAME] = LAYOUT(
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, DV_W,    _______, _______, _______,          _______,  _______, _______, KC_UP,   _______, _______, _______,
        _______,  _______, DV_A,    DV_S,    DV_D,    _______, _______,          _______,  _______, KC_LEFT, KC_DOWN, KC_RIGHT,_______, _______,
        _______,  _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,          _______,          _______,           _______, _______, _______, _______, _______,
                                             KC_SPC,  _______, _______,          _______,  _______, _______
    ),

    [L_FUNC] = LAYOUT(
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,          _______,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
        _______,  _______, _______, _______, _______, KC_F6,   _______,          _______,  KC_F7,   KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, _______, _______,
        _______,  _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,          _______,          _______,           _______, _______, _______, _______, _______,
                                             _______, _______, _______,          _______,  _______, _______
    ),


};
// clang-format on

const key_override_t **key_overrides = (const key_override_t *[]){
  /***********************/
  /* Override for dvorak */
  /***********************/
  // Symbol row override
  // NOTE: mask [c]trl [a]lt [g]ui so the symbol row override doesn't affect other stuff
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DV_1, DV_EXLM, 1 << L_BASE, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DV_2, DV_LBRC, 1 << L_BASE, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DV_3, DV_LPRN, 1 << L_BASE, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DV_4, DV_LCBR, 1 << L_BASE, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DV_5, DV_PERC, 1 << L_BASE, MOD_MASK_CAG),

  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DV_6, DV_CIRC, 1 << L_BASE, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DV_7, DV_RCBR, 1 << L_BASE, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DV_8, DV_RPRN, 1 << L_BASE, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DV_9, DV_RBRC, 1 << L_BASE, MOD_MASK_CAG),

  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_BRID, DV_PIPE, 1 << L_BASE, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DV_PLUS, DV_ASTR, 1 << L_BASE, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_VOLD, DV_AMPR, 1 << L_BASE, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DV_EQL, DV_HASH, 1 << L_BASE, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, DV_DLR, DV_AT, 1 << L_BASE, MOD_MASK_CAG),

  /******************************/
  /* Override for native dvovak */
  /******************************/
  // Symbol row override
  // NOTE: mask [c]trl [a]lt [g]ui so the symbol row override doesn't affect other stuff
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_1, KC_EXLM, 1 << L_NATV, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_2, KC_LBRC, 1 << L_NATV, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_3, KC_LPRN, 1 << L_NATV, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_4, KC_LCBR, 1 << L_NATV, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_5, KC_PERC, 1 << L_NATV, MOD_MASK_CAG),

  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_6, KC_CIRC, 1 << L_NATV, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_7, KC_RCBR, 1 << L_NATV, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_8, KC_RPRN, 1 << L_NATV, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_9, KC_RBRC, 1 << L_NATV, MOD_MASK_CAG),

  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_BRID, KC_PIPE, 1 << L_NATV, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_PLUS, KC_ASTR, 1 << L_NATV, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_VOLD, KC_AMPR, 1 << L_NATV, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_EQL, KC_HASH, 1 << L_NATV, MOD_MASK_CAG),
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_DLR, KC_AT, 1 << L_NATV, MOD_MASK_CAG),

  /******************/
  /* Layer agnostic */
  /******************/
  // Backspace
  &ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, KC_BSPC, KC_DEL, ~0, MOD_MASK_CAG),

  // &ko_make_basic(MOD_MASK_SHIFT, KC_0, TG(L_FUNC)),  // FIXME:

  // Ending NULL
  NULL
};

void set_fn_colors(void)
{
  // Loop over all LEDs to disable not specified ones
  for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    switch (i) {
    // function keys
    // lh
    case 6:
    case 11:
    case 16:
    case 21:
    case 26:
    case 27:
    // rh
    case 42:
    case 47:
    case 52:
    case 57:
    case 62:
    case 63:
      rgb_matrix_set_color(i, 15, 208, 255);  // cyan
      break;

    // music keys
    case 48:
    case 53:
    case 58:
      rgb_matrix_set_color(i, 255, 255, 255);
      break;

    // go back?
    case 0:
      rgb_matrix_set_color(i, 168, 16, 255);  // purple
      break;

    default:
      rgb_matrix_set_color(i, 0, 0, 0);
      break;
    }
  }
}

void set_natv_colors(void)
{
  // go back?
  rgb_matrix_set_color(40, 168, 16, 255);  // purple
}

void set_game_colors(void)
{
  // Loop over all LEDs to disable not specified ones
  for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    switch (i) {
    // lhs
    case 12:
    case 16:
    case 17:
    case 22:
    // rhs
    case 48:
    case 52:
    case 53:
    case 58:
      rgb_matrix_set_color(i, 15, 208, 255);  // cyan
      break;
    }
  }
}

// steal the magic handling logic to swap gui and control programmatically
// https://github.com/qmk/qmk_firmware/blob/master/quantum/process_keycode/process_magic.c
bool process_detected_host_os_user(os_variant_t os)
{
  keymap_config.raw = eeconfig_read_keymap();
  switch (os) {
  case OS_UNSURE:
  case OS_LINUX:
  case OS_WINDOWS:
    // Swap on linux system
    keymap_config.swap_rctl_rgui = true;
    keymap_config.swap_lctl_lgui = true;
    break;
  case OS_MACOS:
  case OS_IOS:
    // restore for darwin
    keymap_config.swap_rctl_rgui = false;
    keymap_config.swap_lctl_lgui = false;
    break;
  }
  return false;
}

bool rgb_matrix_indicators_user(void)
{
  switch (get_highest_layer(default_layer_state | layer_state)) {
  case L_FUNC:
    set_fn_colors();
    break;
  case L_NATV:
    set_natv_colors();
    break;
  case L_GAME:
    set_game_colors();
    break;
  }
  return true;
}
