#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "keymap_bepo.h"

#define BASE 0 
#define CURSOR_KEYS 1
#define NPAD 2
#define GAME 3 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   #    |   "  |   «  |   »  |   (  |   )  | INS  |           |   %  |   @  |   +  |   -  |   /  |   *  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   B  |   É  |   P  |   O  |   È  |Back  |           |Back  |   !  |   V  |   D  |   L  |   J  |   Z    |
 * |--------+------+------+------+------+------|Space |           |Space |------+------+------+------+------+--------|
 * | ~L1/Ê  |   A  |   U  |   I  |   E  |   ;  |------|           |------|   C  |   T  |   S  |   R  |   N  |   M    |
 * |--------+------+------+------+------+------|Enter |           |Enter |------+------+------+------+------+--------|
 * | Ç      |   À  |   Y  |   X  |   .  |   K  |      |           |      |   ?  |   Q  |   G  |   H  |   F  |   W    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | MUTE |  V+  |  V-  | GUI  | LAlt |                                       | MENU |  L3  |      |      |    L2  |
 *   `----------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | DEL  | GUI  |       | PgUp | Esc  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | LAlt |       | PgDn |        |      |
 *                                 | Space|LShift|------|       |------| RShift |Space |
 *                                 |      |      |ctr/Es|       | RAlt |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_                      *
[BASE] = KEYMAP(  // layer                       0 : default
        // left hand
   BP_DOLLAR,                        BP_DOUBLE_QUOTE,     BP_LEFT_GUILLEMET,   BP_RIGHT_GUILLEMET,   BP_LEFT_PAREN, BP_RIGHT_PAREN,   KC_INSERT,
   KC_TAB,                           BP_B,                BP_E_ACUTE,          BP_P,                 BP_O,          BP_E_GRAVE,       KC_BSPC,
   LT(CURSOR_KEYS, BP_E_CIRCUMFLEX), BP_A,                BP_U,                BP_I,                 BP_E,          BP_COMMA,         
   BP_C_CEDILLA,                     BP_A_GRAVE,          BP_Y,                BP_X,                 BP_DOT,        BP_K,             KC_ENT,
   KC_MUTE,                          KC_VOLU,             KC_VOLD,             KC_LGUI,              KC_LALT,
                                                                                                           KC_DELETE,        KC_RGUI,
                                                                                                                             KC_LALT,
                                                                                            KC_SPC,        KC_LSHIFT,        CTL_T(KC_ESCAPE),

        // right hand
   BP_PERCENT,              BP_AT,               BP_PLUS,             BP_MINUS,             BP_SLASH,      BP_ASTERISK,         BP_EQUAL,
   KC_BSPC,                 BP_DEAD_CIRCUMFLEX,  BP_V,                BP_D,                 BP_L,          BP_J,                BP_Z,
                            BP_C,                BP_T,                BP_S,                 BP_R,          BP_N,                BP_M,
   KC_ENT,                  BP_APOSTROPHE,       BP_Q,                BP_G,                 BP_H,          BP_F,                BP_W,
                                                 KC_APP,              TG(GAME),             KC_UNDEFINED,  KC_UNDEFINED,        TG(NPAD),
   KC_PGUP,                 KC_ESC,
   KC_PGDN,
   KC_RALT,                 KC_RSHIFT,           KC_SPACE
    ),
/* Keymap 1: Cursor keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      | WHUP |      |           | Lclk |      | Home |  Up  | End  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | MsLe | MsDo | MsRi | WHD  |------|           |------|      | Left | Down | Right|      |        |
 * |--------+------+------+------+------+------|      |           | Rclk |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[CURSOR_KEYS] = KEYMAP(
       // left hand
       KC_UNDEFINED,  KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5,         KC_F6,
       KC_UNDEFINED,  KC_UNDEFINED,  KC_UNDEFINED,  KC_MS_U,       KC_UNDEFINED,  KC_WH_U,  KC_UNDEFINED,
       KC_TRNS,       KC_UNDEFINED,  KC_MS_L,       KC_MS_D,       KC_MS_R,       KC_WH_D,  
       KC_UNDEFINED,  KC_UNDEFINED,  KC_UNDEFINED,  KC_UNDEFINED,  KC_UNDEFINED,  KC_UNDEFINED,  KC_UNDEFINED,
       KC_UNDEFINED,  KC_UNDEFINED,  KC_UNDEFINED,  KC_TRNS,       KC_TRNS,
                                                                                  KC_TRNS,  KC_TRNS,
                                                                                                 KC_TRNS,
                                                                   KC_TRNS,  KC_TRNS,  KC_TRNS,
       // right hand
       KC_F7,        KC_F8,          KC_F9,          KC_F10,          KC_F11,          KC_F12,       KC_UNDEFINED,
       KC_BTN1, KC_UNDEFINED,   KC_HOME,        KC_UP,           KC_END,          KC_UNDEFINED, KC_UNDEFINED,
                     KC_UNDEFINED,   KC_LEFT,        KC_DOWN,         KC_RIGHT,        KC_UNDEFINED, KC_UNDEFINED,
       KC_BTN2, KC_UNDEFINED,   KC_UNDEFINED,   KC_UNDEFINED,    KC_UNDEFINED,    KC_UNDEFINED, KC_UNDEFINED,
                     KC_UNDEFINED,   KC_UNDEFINED,   KC_UNDEFINED,    KC_UNDEFINED,    KC_UNDEFINED,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS,   KC_TRNS
),
/* Keymap 2: Keypad
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |  +   |  -   |  /   |  *   |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  7   |  8   |  9   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |  4   |  5   |  6   |      |        |
 * |--------+------+------+------+------+------|      |           | ENT  |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  1   |  2   |  3   |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0   |  ,   |  .   |      | L0   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NPAD] = KEYMAP(
        // left hand
       KC_UNDEFINED,  KC_UNDEFINED,  KC_UNDEFINED,  KC_UNDEFINED,       KC_UNDEFINED,  KC_UNDEFINED,  KC_UNDEFINED,
       KC_UNDEFINED,  KC_UNDEFINED,  KC_UNDEFINED,  KC_UNDEFINED,       KC_UNDEFINED,  KC_UNDEFINED,  KC_UNDEFINED,
       KC_UNDEFINED,  KC_UNDEFINED,  KC_UNDEFINED,  KC_UNDEFINED,       KC_UNDEFINED,  KC_UNDEFINED,  
       KC_UNDEFINED,  KC_UNDEFINED,  KC_UNDEFINED,  KC_UNDEFINED,       KC_UNDEFINED,  KC_UNDEFINED,  KC_UNDEFINED,
       KC_UNDEFINED,  KC_UNDEFINED,  KC_UNDEFINED,  KC_UNDEFINED,       KC_UNDEFINED,
                                                                                  KC_UNDEFINED,  KC_UNDEFINED,
                                                                                                 KC_UNDEFINED,
                                                                   KC_UNDEFINED,  KC_UNDEFINED,  KC_UNDEFINED,
       // right hand
       KC_NUMLOCK, KC_UNDEFINED,   KC_KP_PLUS,        KC_KP_MINUS,         KC_KP_SLASH,           KC_KP_ASTERISK,  KC_KP_EQUAL,
       KC_TRNS,      KC_UNDEFINED,   KC_KP_7,           KC_KP_8,             KC_KP_9,               KC_UNDEFINED, KC_UNDEFINED,
                     KC_UNDEFINED,   KC_KP_4,           KC_KP_5,             KC_KP_6,               KC_UNDEFINED, KC_UNDEFINED,
       KC_KP_ENTER,  KC_UNDEFINED,   KC_KP_1,           KC_KP_2,             KC_KP_3,               KC_UNDEFINED, KC_UNDEFINED,
                                     KC_KP_0,           KC_KP_COMMA ,        KC_KP_DOT,             KC_UNDEFINED, KC_TRNS,
       KC_UNDEFINED, KC_UNDEFINED,
       KC_UNDEFINED,
       KC_UNDEFINED, KC_UNDEFINED,   KC_UNDEFINED
),

/* Keymap 3: Gaming
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   #    |   "  |   «  |   »  |   (  |   )  | INS  |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  TAB   |   1  |  2   | UP   |  3   |  4   |Back  |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|Space |           |      |------+------+------+------+------+--------|
 * |   A    |   5  | LEFT | DOWN | RIGHT|  6   |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   B    |   7  |  8   |   9  |  0   |  C   |Enter |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | MUTE |  V+  |  V-  | GUI  | LAlt |                                       |      |  L0  |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | DEL  | GUI  |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LAlt |       |      |      |      |
 *                                 | Space|LShift|------|       |------|      |      |
 *                                 |      |      |ctr/Es|       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[GAME] = KEYMAP(
        // left hand
       BP_DOLLAR,    BP_DOUBLE_QUOTE,     BP_LEFT_GUILLEMET,   BP_RIGHT_GUILLEMET,   BP_LEFT_PAREN,    BP_RIGHT_PAREN,   KC_INSERT,
       KC_TAB,       KC_KP_1,             KC_KP_2,             KC_UP,                KC_KP_3,          KC_KP_4,          KC_BSPC,
       BP_A,         KC_KP_5,             KC_LEFT,             KC_DOWN,              KC_RIGHT,         KC_KP_6,  
       BP_B,         KC_KP_7,             KC_KP_8,             KC_KP_9,              KC_KP_0,          BP_C,             KC_ENT,
       KC_MUTE,      KC_VOLU,             KC_VOLD,             KC_LGUI,              KC_LALT,
                                                                                                       KC_DELETE,        KC_RGUI,
                                                                                                                         KC_LALT,
                                                                                     KC_SPC,           KC_LSHIFT,        CTL_T(KC_ESCAPE),
       // right hand
       KC_UNDEFINED, KC_UNDEFINED,        KC_UNDEFINED,        KC_UNDEFINED,         KC_UNDEFINED,     KC_UNDEFINED,     KC_UNDEFINED,
       KC_UNDEFINED, KC_UNDEFINED,        KC_UNDEFINED,        KC_UNDEFINED,         KC_UNDEFINED,     KC_UNDEFINED,     KC_UNDEFINED,
                     KC_UNDEFINED,        KC_UNDEFINED,        KC_UNDEFINED,         KC_UNDEFINED,     KC_UNDEFINED,     KC_UNDEFINED,
       KC_UNDEFINED, KC_UNDEFINED,        KC_UNDEFINED,        KC_UNDEFINED,         KC_UNDEFINED,     KC_UNDEFINED,     KC_UNDEFINED,
                                          KC_UNDEFINED,        KC_TRNS,              KC_UNDEFINED,     KC_UNDEFINED,     KC_UNDEFINED,
       KC_UNDEFINED, KC_UNDEFINED,
       KC_UNDEFINED,
       KC_UNDEFINED, KC_UNDEFINED,        KC_UNDEFINED
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(CURSOR_KEYS)                // FN1 - Momentary Layer 1 (Symbols)
};

 const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case CURSOR_KEYS:
            ergodox_right_led_1_on();
            break;
        case NPAD:
            ergodox_right_led_2_on();
            break;
        case GAME:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
