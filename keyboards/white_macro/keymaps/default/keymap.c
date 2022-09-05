#include QMK_KEYBOARD_H

enum white_macro_layers {
    _NUMPAD, // num-pad-like
    _GAME,   // general gaming keys
    _LOL,    // League of Legends - specific
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *         ┌───┬───┐
     *         │TO2│>>|│
     * ┌───┬───┼───┼───┤
     * │ 7 │ 8 │ 9 │ * │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ - │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ + │
     * ├───┼───┼───┼───┤
     * │ / │ 0 │ . │ENT│
     * └───┴───┴───┴───┘
     */
    [_NUMPAD] = LAYOUT(
		                  TO(_GAME), KC_MPLY,
		KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_ASTERISK,
		KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_MINUS,
		KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_PLUS,
		KC_KP_SLASH, KC_KP_0, KC_KP_DOT, KC_KP_ENTER
    ),

    /*
     *         ┌───┬───┐
     *         │TO2│>>|│
     * ┌───┬───┼───┼───┤
     * │ 4 │ 1 │ 2 │ 3 │
     * ├───┼───┼───┼───┤
     * │ r │ q │ w │ e │
     * ├───┼───┼───┼───┤
     * │SHF│ a │ s │ d │
     * ├───┼───┼───┼───┤
     * │CTL│   │ f │SPC│
     * └───┴───┴───┴───┘
     */
    [_GAME] = LAYOUT(
		                  TO(_LOL),KC_MPLY,
		KC_4,    KC_1,    KC_2,    KC_3,
		KC_R,    KC_Q,    KC_W,    KC_E,
		KC_LSFT, KC_A,    KC_S,    KC_D,
		KC_LCTL, KC_NO,   KC_F,    KC_SPC
    ),

    /*
     *         ┌───┬───┐
     *         │TO0│>>|│
     * ┌───┬───┼───┼───┤
     * │ 1 │ 2 │ 3 │ 4 │
     * ├───┼───┼───┼───┤
     * │ q │ w │ e │ r │
     * ├───┼───┼───┼───┤
     * │ a │ 5 │ d │ f │
     * ├───┼───┼───┼───┤
     * │ b │SHF│ALT│SPC│
     * └───┴───┴───┴───┘
     */
    [_LOL] = LAYOUT(
		                 TO(_NUMPAD),KC_MPLY,
		KC_1,   KC_2,    KC_3,    KC_4,
		KC_Q,   KC_W,    KC_E,    KC_R,
		KC_A,   KC_5,    KC_D,    KC_F,
		KC_B,   KC_LSFT, KC_LALT, KC_SPC
    )
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_NUMPAD] =   { ENCODER_CCW_CW(S(A(KC_TAB)), A(KC_TAB)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_GAME  ] =   { ENCODER_CCW_CW(S(A(KC_TAB)), A(KC_TAB)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_LOL   ] =   { ENCODER_CCW_CW(S(A(KC_TAB)), A(KC_TAB)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
};
#endif

#ifdef OLED_ENABLE

// static void render_logo(void) {
//     static const char PROGMEM qmk_logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//         0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//         0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//     };

//     oled_write_P(qmk_logo, false);
// }

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}

bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _NUMPAD:
            oled_write_P(PSTR("NumPad\n\n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game\n\n"), false);
            break;
        case _LOL:
            oled_write_P(PSTR("League\n\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined\n\n"), false);
    }
    //render_logo();
    return false;
}

#endif
