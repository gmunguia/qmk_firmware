/* Copyright 2015-2017 Jack Humbert
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
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

enum custom_layers {
  _DVORAK,
  _LOWER,
  _RAISE,
  _I18N,
  _SHIFT,
  _I18NCAPS
};

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  LOWER,
  RAISE,
  ESC_CTL, // If tapped, ESC; if used in combination with other keys, works as LCTL.
  ENT_SFT, // If tapped, ENT; if used in combination with other keys, works as RSFT.
  aACUTE,
  oACUTE,
  eACUTE,
  uACUTE,
  iACUTE,
  nTILDE,
  AACUTE,
  OACUTE,
  EACUTE,
  UACUTE,
  IACUTE,
  NTILDE
};

#define XXXXXXX KC_NO
#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |      |      |      |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * |ES/CTL|   A  |   O  |   E  |   U  |   I  |      |      |      |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |      |      |      |   B  |   M  |   W  |   V  |   Z  |EN/SFT|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite|      |      | Alt  |Lower | SPC  |      |      |      | SPC  |Raise | GUI  |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    _______, _______, _______, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC },
  { ESC_CTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    _______, _______, _______, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH },
  { KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    _______, _______, _______, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    ENT_SFT },
  { BACKLIT, _______, _______, KC_LALT, LOWER,   KC_SPC,  _______, _______, _______, KC_SPC,  RAISE,   KC_RGUI, _______, _______, _______ }
},

/* Lower
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |      |      |      |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |      |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |      |  F12 |      |      | HOME | END  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `--------------------------------------------------------------------------------------------------------'
  */
[_LOWER] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC },
  { KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE },
  { _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, _______, _______, KC_F12,  _______, _______, KC_HOME, KC_END,  _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY }
},

/* Raise
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |      |      |      |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |      |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |      |  F12 | Left | Down |  Up  | Rght |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_RAISE] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC },
  { KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS },
  { _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, _______, _______, KC_F12,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY }
},

/* I18N
 * ,--------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * |      |  Á   |  Ó   |  É   |  Ú   |  Í   |      |      |      |      |      |      |  Ñ   |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
[_I18N] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { RGB_TOG, aACUTE,  oACUTE,  eACUTE,  uACUTE,  iACUTE,  _______, _______, _______, _______, _______, _______, nTILDE,  _______, _______ },
  { _______, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, RGB_MODE_FORWARD, RGB_MODE_REVERSE, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
},
[_SHIFT] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
},
[_I18NCAPS] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, AACUTE,  OACUTE,  EACUTE,  UACUTE,  IACUTE,  _______, _______, _______, _______, _______, _______, NTILDE,  _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
}
};

enum smart_key {
  KEY_NOT_USED,
  KEY_USED
};

enum smart_key smart_ctrl_state = KEY_NOT_USED;
enum smart_key smart_sft_state = KEY_NOT_USED;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    smart_ctrl_state = KEY_USED;
    smart_sft_state = KEY_USED;
  }

  switch (keycode) {
    case ESC_CTL:
      if (record->event.pressed) {
        smart_ctrl_state = KEY_NOT_USED;
        register_code(KC_LCTL);
      }
      else {
        unregister_code(KC_LCTL);
        if (smart_ctrl_state == KEY_NOT_USED) {
          register_code(KC_ESC);
          unregister_code(KC_ESC);
        }
      }
      return false;
      break;
    case ENT_SFT:
      if (record->event.pressed) {
        smart_sft_state = KEY_NOT_USED;
        register_code(KC_RSFT);
        layer_on(_SHIFT);
        update_tri_layer(_I18N, _SHIFT, _I18NCAPS);
      }
      else {
        unregister_code(KC_RSFT);
        layer_off(_SHIFT);
        update_tri_layer(_I18N, _SHIFT, _I18NCAPS);
        if (smart_sft_state == KEY_NOT_USED) {
          register_code(KC_ENT);
          unregister_code(KC_ENT);
        }
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _I18N);
        update_tri_layer(_I18N, _SHIFT, _I18NCAPS);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _I18N);
        update_tri_layer(_I18N, _SHIFT, _I18NCAPS);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _I18N);
        update_tri_layer(_I18N, _SHIFT, _I18NCAPS);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _I18N);
        update_tri_layer(_I18N, _SHIFT, _I18NCAPS);
      }
      return false;
      break;
    case KC_LSFT:
    case KC_RSFT:
      if (record->event.pressed) {
        layer_on(_SHIFT);
        update_tri_layer(_I18N, _SHIFT, _I18NCAPS);
      } else {
        layer_off(_SHIFT);
        update_tri_layer(_I18N, _SHIFT, _I18NCAPS);
      }
      break;
    case aACUTE:
      if (record->event.pressed) SEND_STRING(SS_LCTRL(SS_LSFT("u"))"e1 ");
      return false;
    case AACUTE:
      if (record->event.pressed) SEND_STRING(SS_LCTRL(SS_LSFT("u"))"c1 ");
      return false;
    case oACUTE:
      if (record->event.pressed) SEND_STRING(SS_LCTRL(SS_LSFT("u"))"f3 ");
      return false;
    case OACUTE:
      if (record->event.pressed) SEND_STRING(SS_LCTRL(SS_LSFT("u"))"d3 ");
      return false;
    case eACUTE:
      if (record->event.pressed) SEND_STRING(SS_LCTRL(SS_LSFT("u"))"e9 ");
      return false;
    case EACUTE:
      if (record->event.pressed) SEND_STRING(SS_LCTRL(SS_LSFT("u"))"c9 ");
      return false;
    case uACUTE:
      if (record->event.pressed) SEND_STRING(SS_LCTRL(SS_LSFT("u"))"fa ");
      return false;
    case UACUTE:
      if (record->event.pressed) SEND_STRING(SS_LCTRL(SS_LSFT("u"))"da ");
      return false;
    case iACUTE:
      if (record->event.pressed) SEND_STRING(SS_LCTRL(SS_LSFT("u"))"ed ");
      return false;
    case IACUTE:
      if (record->event.pressed) SEND_STRING(SS_LCTRL(SS_LSFT("u"))"cd ");
      return false;
    case nTILDE:
      if (record->event.pressed) SEND_STRING(SS_LCTRL(SS_LSFT("u"))"f1 ");
      return false;
    case NTILDE:
      if (record->event.pressed) SEND_STRING(SS_LCTRL(SS_LSFT("u"))"d1 ");
      return false;
  }
  return true;
}
