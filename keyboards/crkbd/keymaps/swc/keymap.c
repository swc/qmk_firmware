/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 2
#define _RAISE 4
#define _FKEYS 8
#define _ADJUST 16

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO

// LAYERS
#define KC_LOWER MO(1)
#define KC_RAISE MO(2)
#define KC_FKEYS MO(3)
#define KC_ADJ MO(4)

// RGB
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD

// Home Row Mods
#define KC_ALGUI MT(MOD_LGUI, KC_A)
#define KC_SLALT MT(MOD_LALT, KC_S)
#define KC_DLSFT MT(MOD_LSFT, KC_D)
#define KC_FLCTL MT(MOD_LCTL, KC_F)
#define KC_JRCTL MT(MOD_RCTL, KC_J)
#define KC_KRSFT MT(MOD_RSFT, KC_K)
#define KC_LRALT MT(MOD_RALT, KC_L)
#define KC_QTRGUI MT(MOD_RGUI, KC_QUOT)

#define KC_RST   RESET

// Mod Tap
#define KC_GUIEI MT(MOD_LGUI, KC_LANG2)
#define KC_ALTKN MT(MOD_LALT, KC_LANG1)
#define KC_SHINS MT(MOD_LSFT, KC_INS)
#define KC_ESCTL MT(MOD_RCTL, KC_ESC)
// #define KC_GUIEI GUI_T(KC_LANG2)
// #define KC_ALTKN ALT_T(KC_LANG1)
// #define KC_SHINS LSFT(KC_INS)
// #define KC_ESCTL CTL_T(KC_ESC)

// Layer Tap
#define KC_ERAISE LT(2, KC_ENT)
#define KC_SPCRSE LT(2, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,----------------------------------------------------------.                     ,-------------------------------------------------------------.
       KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                           KC_Y,     KC_U,     KC_I,     KC_O,      KC_P,   KC_BSLS,
  //|--------+---------+---------+---------+---------+---------|                     |---------+---------+---------+---------+----------+----------|
     KC_ESCTL, KC_ALGUI, KC_SLALT, KC_DLSFT, KC_FLCTL,     KC_G,                           KC_H, KC_JRCTL, KC_KRSFT, KC_LRALT, KC_QTRGUI, KC_ERAISE,
  //|--------+---------+---------+---------+---------+---------|                     |---------+---------+---------+---------+----------+----------|
      KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                           KC_N,     KC_M,  KC_COMM,   KC_DOT,   KC_SLSH,   KC_RSFT,
  //\--------+---------+---------+---------+---------+---------+--------|  |---------+---------+---------+---------+---------+----------+----------/
                                             KC_FKEYS, KC_LOWER, KC_BSPC,   KC_SPCRSE, KC_LOWER, KC_FKEYS 
                                         //\----------------------------/  \-----------------------------/
  ),

  [1] = LAYOUT_split_3x6_3(
  //,----------------------------------------------------------.                     ,-------------------------------------------------------------.
       KC_GRV,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                           KC_6,     KC_7,     KC_8,     KC_9,      KC_0,   KC_PSCR,
  //|--------+---------+---------+---------+---------+---------|                     |---------+---------+---------+---------+----------+----------|
      _______,  KC_LBRC,  KC_RBRC,   KC_DOT,  _______,  _______,                        KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,   KC_SCLN,   _______,
  //|--------+---------+---------+---------+---------+---------|                     |---------+---------+---------+---------+----------+----------|
      _______,  _______,  _______,  _______,  _______, KC_PAUSE,                       KC_SHINS,  KC_COLN,  KC_MINS,   KC_EQL,   KC_BSLS,   _______,
  //\--------+---------+---------+---------+---------+---------+--------|  |---------+---------+---------+---------+---------+----------+----------/
                                              _______,  _______, KC_BSPC,     _______,  _______,   KC_ADJ 
                                         //\----------------------------/  \-----------------------------/
  ),

  [2] = LAYOUT_split_3x6_3(
  //,----------------------------------------------------------.                     ,-------------------------------------------------------------.
      KC_TILD,  KC_EXLM,    KC_AT,  KC_HASH,   KC_DLR,  KC_PERC,                        KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,   KC_RPRN,   _______,
  //|--------+---------+---------+---------+---------+---------|                     |---------+---------+---------+---------+----------+----------|
      _______,  KC_LCBR,  KC_RCBR,   KC_DOT,  KC_QUES,  _______,                        KC_HOME,  KC_PGDN,  KC_PGUP,   KC_END,   KC_COLN,   _______,
  //|--------+---------+---------+---------+---------+---------|                     |---------+---------+---------+---------+----------+----------|
      _______,  _______,  _______,  _______,  _______,  _______,                        _______,  _______,  KC_UNDS,  KC_PLUS,   KC_PIPE,   _______,
  //\--------+---------+---------+---------+---------+---------+--------|  |---------+---------+---------+---------+---------+----------+----------/
                                              _______,  _______, _______,     _______,  _______,  _______ 
                                         //\----------------------------/  \-----------------------------/
  ),

  [3] = LAYOUT_split_3x6_3(
  //,----------------------------------------------------------.                     ,-------------------------------------------------------------.
       KC_F12,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                        KC_PMNS,    KC_P7,    KC_P8,    KC_P9,    KC_F10,    KC_F11,
  //|--------+---------+---------+---------+---------+---------|                     |---------+---------+---------+---------+----------+----------|
      _______,  _______,  _______,  _______,  _______,  _______,                         KC_DLR,    KC_P4,    KC_P5,    KC_P6,   _______,   _______,
  //|--------+---------+---------+---------+---------+---------|                     |---------+---------+---------+---------+----------+----------|
      _______,  _______,  _______,  _______,  _______,  _______,                          KC_P0,    KC_P1,    KC_P2,    KC_P3,   _______,   _______,
  //\--------+---------+---------+---------+---------+---------+--------|  |---------+---------+---------+---------+---------+----------+----------/
                                              _______,  _______, _______,     KC_PDOT,  KC_COMM,  _______ 
                                         //\----------------------------/  \-----------------------------/
  ),

  [4] = LAYOUT_split_3x6_3(
  //,----------------------------------------------------------.                     ,-------------------------------------------------------------.
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,
  //|--------+---------+---------+---------+---------+---------|                     |---------+---------+---------+---------+----------+----------|
      KC_LTOG,  KC_LHUI,  KC_LSAI,  KC_LVAI,  XXXXXXX,  XXXXXXX,                        XXXXXXX,   KC_RST,  XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,
  //|--------+---------+---------+---------+---------+---------|                     |---------+---------+---------+---------+----------+----------|
      KC_LMOD,  KC_LHUD,  KC_LSAD,  KC_LVAD,  XXXXXXX,  XXXXXXX,                        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,
  //\--------+---------+---------+---------+---------+---------+--------|  |---------+---------+---------+---------+---------+----------+----------/
                                              _______,  _______, _______,     _______,  _______,  _______ 
                                         //\----------------------------/  \-----------------------------/
  )
};

#ifdef OLED_ENABLE
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwerty"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case _FKEYS:
            oled_write_ln_P(PSTR("F Keys"), false);
            break;
        case _ADJUST:
        case _ADJUST|_LOWER:
        case _ADJUST|_RAISE:
        case _ADJUST|_LOWER|_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE