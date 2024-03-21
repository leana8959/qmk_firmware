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
#include "version.h"
#include "keymap_dvorak.h"

enum layers {
    BASE, // default layer
    SYMB, // symbols
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT(
        _______,  DV_1,    DV_2,    DV_3,    DV_4,    DV_5,    KC_BRIU,          KC_VOLU,   DV_6,    DV_7,    DV_8,    DV_9,    DV_0,     _______,

        KC_CAPS,  DV_QUOT, DV_COMM, DV_DOT,  DV_P,    DV_Y,    KC_BRID,          KC_VOLD,   DV_F,    DV_G,    DV_C,    DV_R,    DV_L,     DV_SLSH,
        // TODO: make escape a hold toggle to fn keys
        KC_ESC,   DV_A,    DV_O,    DV_E,    DV_U,    DV_I,    DV_PLUS,          DV_EQL,    DV_D,    DV_H,    DV_T,    DV_N,    DV_S,     DV_MINS,
        MO(SYMB), DV_Z,    DV_Q,    DV_J,    DV_K,    DV_X,                                 DV_B,    DV_M,    DV_W,    DV_V,    DV_Z,     MO(SYMB),

        // TODO: macro to open iTerm on red button on the right hand
        // TODO: macro to screenshot on red button on the left hand
        KC_APP,   MO(SYMB),KC_LCTL, KC_LOPT, KC_LCMD,         _______,           _______,            KC_RCMD, KC_ROPT, KC_RBRC, MO(SYMB), _______,
                                             KC_SPC,  KC_TAB, DV_DLR,            DV_GRV,    KC_ENT,  KC_BSPC
    ),


    [SYMB] = LAYOUT(
        // Hijack shift behaviour for the number row
        _______,  DV_EXLM,    DV_LBRC,    DV_LPRN,    DV_LBRC,    DV_PIPE,    _______,          _______,   DV_AMPR,    DV_RBRC,    DV_RPRN,    DV_RBRC,    _______,     _______,
        // Shift alphabets normally
        _______,  S(DV_QUOT), S(DV_COMM), S(DV_DOT),  S(DV_P),    S(DV_Y),    _______,          _______,   S(DV_F),    S(DV_G),    S(DV_C),    S(DV_R),    S(DV_L),     S(DV_SLSH),
        _______,  S(DV_A),    S(DV_O),    S(DV_E),    S(DV_U),    S(DV_I),    DV_ASTR,          DV_HASH,   S(DV_D),    S(DV_H),    S(DV_T),    S(DV_N),    S(DV_S),     S(DV_MINS),
        _______,  S(DV_Z),    S(DV_Q),    S(DV_J),    S(DV_K),    S(DV_X),                                 S(DV_B),    S(DV_M),    S(DV_W),    S(DV_V),    S(DV_Z),     _______,
        _______,  _______,    _______,    _______,    _______,                _______,          _______,               _______,    _______,    _______,    _______,     _______,
                                                      _______,    _______,    DV_AT,            DV_TILD,   _______,    _______
    ),

    // TODO: add qwerty translation layer

    /*
    [BLANK] = LAYOUT(
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______,          _______,  _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,          _______,          _______,           _______, _______, _______, _______, _______,
                                             _______, _______, _______,          _______,  _______, _______
    ),
    */

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}
