/* Copyright 2019 Tim Shearer
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

//
// Defining layer names
//

#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _FN 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_NO,      KC_NO,      KC_NO,      KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPACE, \
    KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_NO,      KC_NO,      KC_NO,      KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_DEL, \
    KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_NO,      KC_NO,      KC_NO,      KC_H,       KC_J,       KC_K,       KC_L,       KC_SCOLON,  KC_QUOTE, \
    KC_LSHIFT,  KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_NO,      KC_NO,      KC_NO,      KC_N,       KC_M,       KC_COMMA,   KC_DOT,     KC_SLASH,   KC_ENTER,   \
    MO(_FN),    KC_LCTL,    KC_LGUI,    KC_LALT,    MO(_LOWER), KC_SPC,     KC_ENTER,   KC_SPC,     MO(_RAISE), KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT
  ),

  [_RAISE] =  LAYOUT(
    KC_GRV,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_NO,      KC_NO,      KC_NO,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_BSPACE, \
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_7,       KC_8,       KC_9,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_DEL, \
    KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_4,       KC_5,       KC_6,       KC_H,       KC_MINUS,   KC_EQUAL,   KC_LBRC,    KC_RBRC,    KC_BSLS, \
    KC_LSHIFT,  KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_1,       KC_2,       KC_3,       KC_N,       KC_M,       KC_COMMA,   KC_DOT,     KC_SLASH,   KC_ENTER,   \
    MO(_RAISE), KC_LCTL,    KC_LGUI,    KC_LALT,    MO(_LOWER), KC_SPC,     KC_0,       KC_SPC,     MO(_RAISE), KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END
  ),

  [_LOWER] = LAYOUT(
    KC_TILDE,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_NO,      KC_NO,      KC_NO,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_BSPACE, \
    KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_NO,      KC_NO,      KC_NO,      KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_DEL, \
    KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_NO,      KC_NO,      KC_NO,      KC_H,       KC_UNDS,    KC_PLUS,    KC_LCBR,    KC_RCBR,    KC_PIPE, \
    KC_LSHIFT,  KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_NO,      KC_NO,      KC_NO,      KC_N,       KC_M,       KC_COMMA,   KC_DOT,     KC_SLASH,   KC_ENTER,   \
    MO(_RAISE), KC_LCTL,    KC_LGUI,    KC_LALT,    MO(_LOWER), KC_SPC,     KC_NO,      KC_SPC,     MO(_RAISE), KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT
    ),

  [_FN] = LAYOUT(
    KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_NO,      KC_NO,      KC_NO,      KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPACE, \
    KC_TAB,     KC_Q,       KC_W,       KC_E,       RESET,      KC_T,       KC_NO,      KC_NO,      KC_NO,      KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_DEL, \
    KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_NO,      KC_NO,      KC_NO,      KC_H,       KC_UNDS,    KC_PLUS,    KC_L,       KC_SCOLON,  KC_QUOTE, \
    KC_LSHIFT,  KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_NO,      KC_NO,      KC_NO,      KC_N,       KC_M,       KC_COMMA,   KC_DOT,     KC_SLASH,   KC_ENTER,   \
    MO(_RAISE), KC_LCTL,    KC_LGUI,    KC_LALT,    MO(_LOWER), KC_SPC,     KC_NO,      KC_SPC,     MO(_RAISE), KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT
   ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {   
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (biton32(layer_state)) {
        case _BASE:
          oled_write_P(PSTR("DEFAULT\n"), false);
          break;
        case _FN:
          oled_write_P(PSTR("FUNCTION\n"), false);
          break;
        case _RAISE:
          oled_write_P(PSTR("RAISE\n"), false);
          break;
        case _LOWER:
          oled_write_P(PSTR("LOWER\n"), false);
          break;
        default:
         // Or use the write_ln shortcut over adding '\n' to the end of your string
          oled_write_ln_P(PSTR("Undefined"), false);
  }

  // Host Keyboard LED Status
  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("NUM LOCK ") : PSTR("       "), false);
  oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("CAPS LOCK ") : PSTR("       "), false);
  oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("SCROLL LOCK ") : PSTR("       "), false);
}
#endif
