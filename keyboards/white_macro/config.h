// Copyright 2022 Daniel White (@Daniel White)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* encoders */
#define ENCODERS_PAD_A { F6, F4 }
#define ENCODERS_PAD_B { F7, F5 }
// #define ENCODER_DIRECTION_FLIP
// #define ENCODER_RESOLUTIONS { 4, 4 }
// default pos if encoder skips pulses when it changes directions
// #define ENCODER_DEFAULT_POS 0x3
