/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _QWERTY = 0,
    _FUNCNAV,
    _SYM,
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)

#define SYM      MO(_SYM)
#define FNAV     MO(_FUNCNAV)

//#define LSFT_TAB  MT(MOD_LSFT, KC_TAB)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  BSpc  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Tab/LSft|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCtrl  |   Z  |   X  |   C  |   V  |   B  | [ {  |  (   |  |  )   |  ] } |   N  |   M  |   ,  |   .  |   ?  | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Mute |LAlt  | Space| LGUI |F-Nav |  |  Sym |Enter | Space|AltGr | Caps |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
     KC_ESC ,  KC_Q , KC_W , KC_E  , KC_R ,   KC_T ,                                         KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
     MT(MOD_LSFT,KC_TAB) ,  KC_A,  KC_S , KC_D  , KC_F ,   KC_G ,                            KC_H,   KC_J ,  KC_K ,   KC_L , KC_SCLN, KC_QUOTE,
     KC_LCTL,  KC_Z,  KC_X , KC_C  , KC_V ,   KC_B ,   KC_LBRC, KC_LPRN,    KC_RPRN, KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT , KC_QUES, KC_RSFT,
                     KC_AUDIO_MUTE , KC_LALT, KC_SPC, KC_LGUI , FNAV ,        SYM,   KC_ENT , KC_SPC, KC_RALT, KC_CAPS
    ),

/*
 * FNav Layer: F-keys, navigation 
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   | F2   | F3   | F4   |  F5  |                              |Insert| Home |   ↑  | End  |      | Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | F6   | F7   | F8   | F9   |  F10 |                              |      |  ←   |   ↓  |   →  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | F11  | F12  | F13  | F14  |  F15 |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCNAV] = LAYOUT(
      _______,  KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                                  KC_INS , KC_HOME, KC_UP  , KC_END  , XXXXXXX , KC_DEL ,
      _______,  KC_F6 , KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10,                                    XXXXXXX , KC_LEFT, KC_DOWN, KC_RGHT , XXXXXXX , XXXXXXX,
      _______,  KC_F11 , KC_F12 ,  KC_F13 ,  KC_F14 , KC_F15, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX , XXXXXXX, _______ ,
                                 XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX
    ),

/* 
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  1   |  2   |  3   |  4   |  5   |                              |   !  |  @   |  &   |  $   |  %   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  6   |  7   |  8   |  9   |  0   |                              |   ~  |  ^   |  _   |  `   |  :   |   "    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  =   |  -   |  +   |  #   |  *   |  /   |  <   |  |  >   |   \  |   |  |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
     _______ , KC_1 ,   KC_2 ,  KC_3 ,   KC_4 ,  KC_5 ,                                         KC_EXLM, KC_AT ,  KC_AMPR , KC_DLR, KC_PERC, _______ ,
     _______ , KC_6 ,   KC_7 ,  KC_8,    KC_9,   KC_0,                                          KC_TILD, KC_CIRC, KC_UNDS, KC_GRV, KC_COLN, KC_DQUO,
     _______ , KC_EQL,  KC_MINS , KC_PLUS, KC_HASH, KC_ASTR, KC_SLSH, KC_LT, KC_GT, KC_BSLS, KC_PIPE, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, _______,
                                 XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX
    ),

};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif