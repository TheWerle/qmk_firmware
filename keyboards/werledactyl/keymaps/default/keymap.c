// Copyright 2022 Shem Sedrick (@ssedrick)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum key_layers {
    _BASE,
    _RAISE,
    _LOWER
};

#define RAISE LT(_RAISE,KC_DEL)
#define LOWER LT(_LOWER,KC_TAB)
#define SH_ESC SFT_T(KC_ESC)
#define ____ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,                        KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,   KC_G,                        KC_H,   KC_J,    KC_K,    KC_L,   KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,                        KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH,
                 KC_LGUI, KC_TAB,                                      KC_QUOT, KC_GRV,
                          KC_LCTL, KC_LALT, KC_SPC,    				KC_RSFT, KC_SPC, KC_BSPC,
                                   LOWER,  KC_LCTL,                   KC_ENT,RAISE
													KC_LSFT , 		KC_RSFT 
	),
    [_LOWER] = LAYOUT(
     KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,               KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
     S(KC_9), S(KC_0), KC_LBRC, KC_RBRC,  KC_EQL,                  ____, KC_MINS,  KC_EQL, KC_PIPE,    ____,
        ____,    ____,    ____,    ____,    ____,                  ____, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,
                 ____,    ____,                                                    KC_QUOT, KC_GRV,
                                   ____,    ____,  ____,     ____, ____,    ____,
                                   ____,    ____,            ____, ____,
											____, 			 ____
    ),
    [_RAISE] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
     S(KC_9), S(KC_0), KC_LCBR, KC_RCBR,  KC_EQL,               KC_MINS,    KC_4,    KC_5,    KC_6, KC_QUOT,
      QK_RBT, QK_BOOT, KC_LBRC, KC_RBRC,    ____,                  ____,    KC_1,    KC_2,    KC_3,    ____,
                 ____,    ____,                                                      KC_0,  KC_DOT,
                                   ____,    ____,  ____,     ____, ____,    ____,
                                   ____,    ____,                  ____,    ____,
													____, 		____
    )
};


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
  return true;
}