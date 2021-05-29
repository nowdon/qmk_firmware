/* Copyright 2020 yushakobo
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FUNC1
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    YUSHAURL = SAFE_RANGE,
    VALUE,
    FORMULA,
    FORMAT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_MUTE,   MO(_FUNC1), RGB_MOD,
        VALUE, FORMULA, FORMAT,
        LALT(KC_A),   KC_E,    KC_ENT
    ),
    [_FUNC1] = LAYOUT(
        KC_MUTE,   KC_TRNS, RGB_MOD,
        LALT(LSFT(KC_SCLN)), LALT(KC_MINS), KC_F4,
        LCTL(KC_2),   LCTL(KC_3),    KC_ENT
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VALUE:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING(SS_LCTL("esv"));
            } else {
                // when keycode QMKURL is released
            }
            break;
        case FORMULA:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING(SS_LCTL("esf"));
            } else {
                // when keycode QMKURL is released
            }
            break;
        case FORMAT:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING(SS_LCTL("est"));
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // Left encoder
        if (clockwise) {
            tap_code(KC_RGHT);
        } else {
            tap_code(KC_LEFT);
        }
    }
    else if (index == 1) { // Right encoder
        if (clockwise) {
            tap_code(KC_UP);
        } else {
            tap_code(KC_DOWN);
        }
    }
}
