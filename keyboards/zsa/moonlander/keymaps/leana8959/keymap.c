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
#include "process_key_override.h"

enum layers {
  BASE,  // default layer
  MUS,   // music control
  FN     // function keys
};

enum custom_keycodes {
  CKC_SCROT_CLIP = SAFE_RANGE,  // screenshot to clipboard
  CKC_SCROT,                    // screenshot
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT(
        _______,  DV_1,    DV_2,    DV_3,    DV_4,    DV_5,    KC_BRIU,          KC_VOLU,   DV_6,    DV_7,    DV_8,    DV_9,    DV_0,     _______,

        KC_CAPS,  DV_QUOT, DV_COMM, DV_DOT,  DV_P,    DV_Y,    KC_BRID,          KC_VOLD,   DV_F,    DV_G,    DV_C,    DV_R,    DV_L,     DV_SLSH,
        KC_ESC,   DV_A,    DV_O,    DV_E,    DV_U,    DV_I,    DV_PLUS,          DV_EQL,    DV_D,    DV_H,    DV_T,    DV_N,    DV_S,     DV_MINS,
        KC_LSFT,  DV_SCLN, DV_Q,    DV_J,    DV_K,    DV_X,                                 DV_B,    DV_M,    DV_W,    DV_V,    DV_Z,     KC_RSFT,

        // TODO: macro to open iTerm on red button on the right hand
        KC_APP,   KC_LSFT, KC_LCTL, MT(MOD_LALT, KC_DOWN), MT(MOD_LGUI, KC_UP),         CKC_SCROT_CLIP,           DV_BSLS,            MT(MOD_RGUI, KC_LEFT), MT(MOD_RALT, KC_RIGHT), KC_RCTL, KC_RSFT, _______,
                                             KC_SPC,  KC_TAB, DV_DLR,            DV_GRV,    KC_ENT,  KC_BSPC
    ),


    [FN] = LAYOUT(
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,          _______,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
        _______,  _______, _______, _______, _______, KC_F6,   _______,          _______,  KC_F7,   _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,          _______,          _______,           _______, _______, _______, _______, _______,
                                             _______, _______, _______,          _______,  _______, _______
    ),


    [MUS] = LAYOUT(
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, _______, _______,
        _______,  _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,          _______,          _______,           _______, _______, _______, _______, _______,
                                             _______, _______, _______,          _______,  _______, _______
    ),


    // TODO: add qwerty translation layer
    // TODO: learn more about DF

};
// clang-format on

const key_override_t **key_overrides = (const key_override_t *[]){
  // Symbol row override
  &ko_make_basic(MOD_MASK_SHIFT, DV_1, DV_EXLM), &ko_make_basic(MOD_MASK_SHIFT, DV_2, DV_LBRC),
  &ko_make_basic(MOD_MASK_SHIFT, DV_3, DV_LPRN), &ko_make_basic(MOD_MASK_SHIFT, DV_4, DV_LCBR),
  &ko_make_basic(MOD_MASK_SHIFT, DV_5, DV_PERC),

  &ko_make_basic(MOD_MASK_SHIFT, DV_6, DV_CIRC), &ko_make_basic(MOD_MASK_SHIFT, DV_7, DV_RCBR),
  &ko_make_basic(MOD_MASK_SHIFT, DV_8, DV_RPRN), &ko_make_basic(MOD_MASK_SHIFT, DV_9, DV_RBRC),
  &ko_make_basic(MOD_MASK_SHIFT, DV_0, TG(FN)),

  &ko_make_basic(MOD_MASK_SHIFT, KC_BRID, DV_PIPE),
  &ko_make_basic(MOD_MASK_SHIFT, DV_PLUS, DV_ASTR),

  &ko_make_basic(MOD_MASK_SHIFT, KC_VOLD, DV_AMPR), &ko_make_basic(MOD_MASK_SHIFT, DV_EQL, DV_HASH),

  &ko_make_basic(MOD_MASK_SHIFT, DV_DLR, DV_AT),

  // Backspace
  &ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL), NULL
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode) {
  case CKC_SCROT_CLIP:
    if (record->event.pressed) {
      tap_code16(LGUI(LSFT(KC_4)));
    } else {
    }
    return false;
  default:
    return true;
  }
}
