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
#include <stdbool.h>

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _COLEMAKDH 2
#define _LOWER 3
#define _RAISE 4
#define _FKEYS 5
#define _ADJUST 6

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO

// LAYERS
#define KC_LOWER MO(3)
#define KC_RAISE MO(4)
#define KC_FKEYS MO(5)
#define KC_ADJ MO(6)

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
#define KC_SLGUI MT(MOD_LGUI, KC_S)
#define KC_DLALT MT(MOD_LALT, KC_D)
// #define KC_BSSFT MT(MOD_LSFT, KC_BSPC)
#define KC_FLCTL MT(MOD_LCTL, KC_F)
#define KC_JRCTL MT(MOD_RCTL, KC_J)
#define KC_KRALT MT(MOD_RALT, KC_K)
#define KC_LRGUI MT(MOD_RGUI, KC_L)
// Home row Colemak Mods
#define KC_RLGUI MT(MOD_LGUI, KC_R)
#define KC_SLALT MT(MOD_LALT, KC_S)
#define KC_TLCTL MT(MOD_LCTL, KC_T)
#define KC_NRCTL MT(MOD_RCTL, KC_N)
#define KC_ERALT MT(MOD_RALT, KC_E)
#define KC_IRGUI MT(MOD_RGUI, KC_I)

#define KC_SESC S(KC_ESC)
#define KC_STAB S(KC_TAB)

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

// Thumb clusters
#define KC_4ESC LT(4, KC_ESC)
#define KC_3TAB LT(3, KC_TAB)
#define KC_SBSPC MT(MOD_LSFT, KC_BSPC)
#define KC_4SPC LT(4, KC_SPC)
#define KC_3ENT LT(3, KC_ENT)

#define KC_CUT C(KC_X)
#define KC_COP C(KC_C)
#define KC_PST C(KC_V)

#define KC_DF0 DF(0)
#define KC_DF1 DF(1)
#define KC_DF2 DF(2)

#define KC_3LOCK TO(3)

bool numLock = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
      _______,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                              KC_Y,     KC_U,     KC_I,     KC_O,      KC_P,   KC_3LOCK,
      _______,     KC_A, KC_SLGUI, KC_DLALT, KC_FLCTL,     KC_G,                              KC_H, KC_JRCTL, KC_KRALT, KC_LRGUI,   KC_QUOT,   _______,
      _______,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                              KC_N,     KC_M,  KC_COMM,   KC_DOT,   KC_SLSH,   _______,
                                              KC_4ESC,  KC_3TAB, KC_SBSPC,       KC_4SPC,  KC_3ENT, KC_FKEYS
  ),
  [_COLEMAK] = LAYOUT_split_3x6_3(
      _______,     KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,                              KC_J,     KC_L,     KC_U,     KC_Y,   KC_QUOT,   _______,
      _______,     KC_A, KC_RLGUI, KC_SLALT, KC_TLCTL,     KC_D,                              KC_H, KC_NRCTL, KC_ERALT, KC_IRGUI,      KC_O,   _______,
      _______,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                              KC_K,     KC_M,  KC_COMM,   KC_DOT,   KC_SLSH,   _______,
                                              KC_4ESC,  KC_3TAB, KC_SBSPC,       KC_4SPC,  KC_3ENT, KC_FKEYS
  ),

      // colemak DH
  [_COLEMAKDH] = LAYOUT_split_3x6_3(
      _______,     KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,                              KC_J,     KC_L,     KC_U,     KC_Y,   KC_QUOT,   _______,
      _______,     KC_A, KC_RLGUI, KC_SLALT, KC_TLCTL,     KC_G,                              KC_M, KC_NRCTL, KC_ERALT, KC_IRGUI,      KC_O,   _______,
      _______,     KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,                              KC_K,     KC_H,  KC_COMM,   KC_DOT,   KC_SLSH,   _______,
                                              KC_4ESC,  KC_3TAB, KC_SBSPC,       KC_4SPC,  KC_3ENT, KC_FKEYS
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
      _______,  _______,  KC_CIRC,  KC_HASH,   KC_DLR,  KC_PERC,                           KC_SLSH,     KC_7,     KC_8,     KC_9,   KC_ASTR,   _______,
      _______,  _______,  KC_MINS,  KC_EXLM,  KC_QUES,  KC_AMPR,                            KC_EQL,     KC_4,     KC_5,     KC_6,   KC_PLUS,   _______,
      _______,  _______,  _______,    KC_AT,  KC_ASTR,  KC_PIPE,                              KC_0,     KC_1,     KC_2,     KC_3,   _______,   _______,
                                              _______,  _______,  _______,        KC_DOT,  KC_COMM, KC_3LOCK
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
      _______,  KC_GRV,    KC_LT,    KC_GT,  KC_LCBR,  KC_RCBR,                           _______,  _______,  _______,  _______,   KC_PSCR,   _______,
      _______,  KC_UNDS,  _______,  KC_COLN,  KC_LPRN,  KC_RPRN,                           KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,   _______,   _______,
      _______,   KC_TILD,  KC_BSLS,  KC_SLSH,  KC_LBRC,  KC_RBRC,                           KC_HOME,  KC_PGDN,  KC_PGUP,   KC_END,   _______,   _______,
                                              KC_SESC,  KC_STAB,   KC_DEL,        KC_DOT,  KC_COMM,   KC_ADJ 
  ),

  [_FKEYS] = LAYOUT_split_3x6_3(
      _______,  _______,  _______,  _______,  KC_MRWD,  KC_MFFD,                            KC_F12,    KC_F7,    KC_F8,    KC_F9,   _______,   _______,
      _______,  _______,  KC_MPRV,  KC_MNXT,  KC_MPLY,  KC_MUTE,                            KC_F11,    KC_F4,    KC_F5,    KC_F6,   _______,   _______,
      _______,  _______,  _______,  _______,  KC__VOLDOWN,  KC__VOLUP,                      KC_F10,    KC_F1,    KC_F2,    KC_F3,   _______,   _______,
                                               KC_ADJ,  _______,  _______,       _______,  _______,   KC_ADJ
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                            KC_DF0,   KC_DF1,   KC_DF2,  XXXXXXX,   XXXXXXX,    KC_RST,
      KC_LTOG,  KC_LHUI,  KC_LSAI,  KC_LVAI,  XXXXXXX,  XXXXXXX,                           XXXXXXX,  CG_TOGG,  XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,
      KC_LMOD,  KC_LHUD,  KC_LSAD,  KC_LVAD,  XXXXXXX,  XXXXXXX,                           XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,   EEPROM_RESET,
                                              _______,  _______,  _______,       _______,  _______,  _______ 
  )
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//     state = update_tri_layer_state(state, _RAISE, _LOWER, _FKEYS, _ADJUST);
//     return state;
// }

// bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case MT(MOD_LSFT, KC_BSPC):
//             return true;
//         default:
//             return true;
//     }
// }

// KEY OVERRIDES
const key_override_t cut_override = ko_make_basic(MOD_BIT(KC_LCTL), KC_4ESC, KC_CUT);
const key_override_t copy_override = ko_make_basic(MOD_BIT(KC_LCTL), KC_3TAB, KC_COP);
const key_override_t paste_override = ko_make_basic(MOD_BIT(KC_LCTL), KC_SBSPC, KC_PST);
const key_override_t cut_override_mac = ko_make_basic(MOD_BIT(KC_LGUI), KC_4ESC, KC_CUT);
const key_override_t copy_override_mac = ko_make_basic(MOD_BIT(KC_LGUI), KC_3TAB, KC_COP);
const key_override_t paste_override_mac = ko_make_basic(MOD_BIT(KC_LGUI), KC_SBSPC, KC_PST);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &cut_override,
    &copy_override,
    &paste_override,
    &cut_override_mac,
    &copy_override_mac,
    &paste_override_mac,
    NULL // Null terminate the array of overrides!
};


// COMBOS
const uint16_t PROGMEM combo_caps_lock[] = {KC_SBSPC, KC_4SPC, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_caps_lock , KC_CAPS)
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return OLED_ROTATION_270;
}

void render_samus_logo(void) {
    static const char PROGMEM samus_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(samus_logo, false);
}

#    define KEYLOG_LEN 6
char     keylog_str[KEYLOG_LEN] = "     ";
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

void render_keylogger_status(void) {
    oled_write_P(PSTR("     "), false);
    oled_write(keylog_str, false);
}

// void render_default_layer_state(void) {
//   switch (get_highest_layer(default_layer_state|layer_state))
//   {
//       case _QWERTY:
//         oled_write_ln_P(PSTR("QWRTY"),layer_state_is(0));
//         break;
//       case _COLEMAK:
//         oled_write_ln_P(PSTR("COLMK"),layer_state_is(1));
//         break;
//       case _COLEMAKDH:
//         oled_write_ln_P(PSTR("CLMKD"),layer_state_is(2));
//         break;
//     }
// }

void render_layer_state(void) {
  switch (get_highest_layer(default_layer_state))
  {
      case _QWERTY:
        oled_write_ln_P(PSTR("QWRTY"),false);
        break;
      case _COLEMAK:
        oled_write_ln_P(PSTR("COLMK"),false);
        break;
      case _COLEMAKDH:
        oled_write_ln_P(PSTR("CLMKD"),false);
        break;
    }

    oled_write_P(PSTR("Lower"), layer_state_is(3));
    oled_write_P(PSTR("Raise"), layer_state_is(4));
    oled_write_P(PSTR("FKeys"), layer_state_is(5));
    oled_write_P(PSTR("Adjst"), layer_state_is(6));
}

void render_keylock_status(uint8_t led_usb_state) {
    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR("   "), false);
    oled_write_P(PSTR("N"), numLock);
    // oled_write_ln_P(PSTR("S"), led_usb_state & (1 << USB_LED_SCROLL_LOCK));
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR(" "), false);
    if (keymap_config.swap_lctl_lgui) {
      oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
      oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
      oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
      oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    }
    else {
      oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
      oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
      oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
      oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    }

    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR("  "), false);
    oled_write_P(PSTR("N"), numLock);
    oled_write_P(PSTR("  "), false);
}

void render_bootmagic_status(void) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    oled_write_P(PSTR("    "), false);
    oled_write_P(PSTR("    "), false);
    // oled_write_P(logo[0][0], !keymap_config.swap_lctl_lgui);
    // oled_write_P(logo[1][0], keymap_config.swap_lctl_lgui);
    // oled_write_P(PSTR(" "), false);
    // oled_write_P(logo[0][1], !keymap_config.swap_lctl_lgui);
    // oled_write_P(logo[1][1], keymap_config.swap_lctl_lgui);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(PSTR("    "), false);
        oled_write_P(logo[1][0], false);
        oled_write_P(PSTR("   "), false);
        oled_write_P(logo[1][1], false);
    }
    else {
        oled_write_P(PSTR("    "), false);
        oled_write_P(logo[0][0], false);
        oled_write_P(PSTR("   "), false);
        oled_write_P(logo[0][1], false);
    }
}

void render_status_main(void) {
    /* Show Keyboard Layout  */
    // render_default_layer_state();
    // render_keylock_status(host_keyboard_leds());

    // render_default_layer_state();
    render_layer_state();
    render_mod_status(get_mods());
    // render_keylock_status(host_keyboard_led_state());
    render_keylogger_status();
    render_bootmagic_status();
}

void oled_task_user(void) {
    update_log();
    if (is_keyboard_master()) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_samus_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool processNormally = true;

    switch (keycode) {
        case KC_DF0:
            if (record->event.pressed) {
                set_single_persistent_default_layer(0);
            }
            processNormally = false;
            break;
        case KC_DF1: 
            if (record->event.pressed) {
                set_single_persistent_default_layer(1);
            }
            processNormally = false;
            break;
        case KC_DF2:
            if (record->event.pressed) {
                set_single_persistent_default_layer(2);
            }
            processNormally = false;
            break;
        case KC_3LOCK:
            if (record->event.pressed) {
                if (numLock) {
                    layer_off(3);
                    processNormally = false;
                }

                numLock = !numLock;
            }
            break;
        case KC_3TAB:
            if (!record->event.pressed) {
                processNormally = !numLock;
            }
            break;
    }

    if (record->event.pressed) {
        add_keylog(keycode);
    }
    return processNormally;
}
#endif // OLED_ENABLE