#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"

#define ______ KC_NO

enum anne_pro_layers {
  _BASE_LAYER, // base (en)
  _RU_BASE_LAYER, // base (ru)
  _NAVIGATION_LAYER,/* 2, // oneshot */
  /* 3, // ctrlnum */
  /* 4, // navigation */
  /* 5, // mouse */
};

// unicode snippet
void matrix_init_user(void) { set_unicode_input_mode(UC_LNX); };

// tap dance for Ь and Ъ
enum {
	/* RU_SOFT_HARD, */
	RU_ER_HARD,
	RU_ZHE_E,
	RU_HA_SHTI,
};
qk_tap_dance_action_t tap_dance_actions[] = {
	/* [RU_SOFT_HARD] = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_RBRC), */
	[RU_ER_HARD] = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_RBRC),
	[RU_ZHE_E] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),
	[RU_HA_SHTI] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_GRV),
};

 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE_LAYER] = KEYMAP(
/*
,-----------------------------------------------------------------------------------------.
|     |     |     |  X  |  Y  |  P  |Sft+I|  F  |  G  |  C  |  R  |     |  L  |           |
|-----------------------------------------------------------------------------------------+
|CtlSpace|  A  |  O  |  E  |  U  |  I  |     |  D  |  H  |  T  |  N  |  S  |     |        |
|-----------------------------------------------------------------------------------------+
|         |     |  Q  |  J  |  K  |     |     |  B  |  M  |  W  |  V  |  Z  |             |
|-----------------------------------------------------------------------------------------+
|            |     |TO(1)|  ,  |  .  |     |CtlBS|space|  /  |     |     |                |
|-----------------------------------------------------------------------------------------+
| OSctl |       |       |                                 |       |       | OSsft |       |
\-----------------------------------------------------------------------------------------/ */
	______, ______, ______, KC_X, KC_Y, KC_P, LSFT(KC_I), KC_F, KC_G, KC_C, KC_R, ______, KC_L, ______,
        LCTL(KC_SPC), KC_A, KC_O, KC_E, KC_U, KC_I, ______, KC_D, KC_H, KC_T, KC_N, KC_S, ______, ______,
        ______, ______, KC_Q, KC_J, KC_K, ______, ______, KC_B, KC_M, KC_W, KC_V, KC_Z, ______,
        ______, ______, TO(1), KC_COMM, KC_DOT, ______, LCTL(KC_BSPC), KC_SPC, KC_SLSH, ______, ______, ______,
        MO(_NAVIGATION_LAYER), ______, ______, KC_ENT, ______, ______, OSM(MOD_LSFT), ______
),
[_RU_BASE_LAYER] = KEYMAP(
/*
,-----------------------------------------------------------------------------------------.
|     |  Й  |     |  Ц  |  У  |  Е  |  Ф  |  Щ  |  Г  |  Т  |  Н  |     |  З  |           |
|-----------------------------------------------------------------------------------------+
|        |  К  |  М  |  В  |  А  |  П  |     |  Р Ъ|  О  |  Л  |  Д  |  Ж Э|     |        |
|-----------------------------------------------------------------------------------------+
|         |  Я  |  Ч  |  С  |  И  |  Ы  |     |  Ш  |  Ь  |  Б  |  Ю  |  Х Ё|             |
|-----------------------------------------------------------------------------------------+
|            |     |TO(1)|  ,  |  .  |     |CtlBS|space|  /  |     |     |                |
|-----------------------------------------------------------------------------------------+
| OSctl |       |       |                                 |       |       | OSsft |       |
\-----------------------------------------------------------------------------------------/ */
	______, KC_Q, ______, KC_W, KC_E, KC_T, KC_A, KC_O, KC_U, KC_N, KC_Y, ______, KC_P, ______,
        ______, KC_R, KC_V, KC_D, KC_F, KC_G, ______, TD(RU_ER_HARD), KC_J, KC_K, KC_L, TD(RU_ZHE_E), ______, ______,
        ______, KC_Z, KC_X, KC_C, KC_B, KC_S, ______, KC_I, KC_M, KC_COMM, KC_DOT, TD(RU_HA_SHTI), ______,
        ______, ______, TO(0), KC_QUES, KC_SLSH, ______, LCTL(KC_BSPC), KC_SPC, KC_PIPE, ______, ______, ______,
        OSM(MOD_LCTL), ______, ______, KC_ENT, ______, ______, OSM(MOD_LSFT), ______
),
[_NAVIGATION_LAYER] = KEYMAP(
/*
,-----------------------------------------------------------------------------------------.
|     |     |     |  X  |S_Dwn|S_Up |Sft+I|  F  |PgDwn| PgUp|  R  |     |  L  |           |
|-----------------------------------------------------------------------------------------+
|        |M_Lft|M_Dwn|M_Up |M_Rht|  I  |     |  D  | Left| Down| Up  |Right|     |        |
|-----------------------------------------------------------------------------------------+
|         |     |  Q  |  J  |  K  |     |     |  B  |  M  |  W  |  V  |  Z  |             |
|-----------------------------------------------------------------------------------------+
|            |     | M3  | M1  | M2  |     |CtlBS| Ctrl|  /  |     |     |                |
|-----------------------------------------------------------------------------------------+
| OSctl |       |       |                                 |       |       | OSsft |       |
\-----------------------------------------------------------------------------------------/ */
	______, ______, ______, KC_X, KC_MS_WH_DOWN, KC_MS_WH_UP, LSFT(KC_I), KC_F, KC_PGDN, KC_PGUP, KC_R, ______, KC_L, ______,
        ______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_I, ______, KC_D, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, ______, ______,
        ______, ______, KC_Q, KC_J, KC_K, ______, ______, KC_B, KC_M, KC_W, KC_V, KC_Z, ______,
        ______, ______, KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2, ______, LCTL(KC_BSPC), KC_LCTL, KC_SLSH, ______, ______, ______,
        MO(_NAVIGATION_LAYER), ______, ______, KC_ENT, ______, ______, OSM(MOD_LSFT), ______
),
};


const uint16_t keymaps_size = sizeof(keymaps);

void matrix_scan_user(void) {
}

// Code to run after initializing the keyboard
/* void keyboard_post_init_user(void) { */
    // Here are two common functions that you can use. For more LED functions, refer to the file "qmk_ap2_led.h"

    // annepro2-shine disables LEDs by default. Uncomment this function to enable them at startup.
    // annepro2LedEnable();

    // Additionally, it also chooses the first LED profile by default. Refer to the "profiles" array in main.c in
    // annepro2-shine to see the order. Replace "i" with the index of your preferred profile. (i.e the RED profile is index 0)
    // annepro2LedSetProfile(i);
/* } */

layer_state_t layer_state_set_user(layer_state_t layer) {
    return layer;
}

