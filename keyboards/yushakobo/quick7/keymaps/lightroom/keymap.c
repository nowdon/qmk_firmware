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
    YUSHAURL = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_P, MO(_FUNC1), KC_I,
        LSFT(KC_TAB), LSFT(KC_R), KC_TAB,
        LSFT(KC_A), LSFT(LALT(KC_R)), LALT(KC_Z)
    ),
    [_FUNC1] = LAYOUT(
        RGB_TOG, KC_TRNS, RGB_MOD,
        KC_G, KC_D, KC_F,
        KC_E, KC_C, KC_H
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case YUSHAURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://yushakobo.jp/\n");
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
            tap_code(KC_RIGHT);
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
