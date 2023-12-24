// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┬───┬───┬───┐
     * │   │   │   │   │   │   │ │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┤ ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │ │   │   │   │   │   │   │
     * └───┴───┴───┼───┼───┼───┤ ├───┼───┼───┼───┴───┴───┘
     *             │   │   │   │ │   │   │   │
     *             └───┴───┴───┘ └───┴───┴───┘
     */
    [0] = LAYOUT_steno_12x3(
        KC_NO,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,   STN_ST3,  STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
        KC_NO,  STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,   STN_ST4,  STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                                  STN_N1,  STN_A ,  STN_O,     STN_E,    STN_U,   STN_NC
    )
};
