#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"

#define BASE 0 // default layer
#define BASE_MAC 1 // default layer mac
#define NUMB_SYMB 2 // F# and symbols
#define ACCENTS 3 // french accents keys

#define C_MAJ_CEDILLA 0x00C7  // Ç
#define C_MIN_CEDILLA 0x00E7  // ç

#define E_MAJ_ACCENT_AIGU 0x00C9  // É
#define E_MIN_ACCENT_AIGU 0x00E9  // é

#define A_MIN_ACCENT_GRAVE 0x00E0  // à
#define A_MAJ_ACCENT_GRAVE  0x00C0  // À
#define E_MAJ_ACCENT_GRAVE 0x00C8  // È
#define E_MIN_ACCENT_GRAVE 0x00E8  // è
#define U_MAJ_ACCENT_GRAVE 0x00D9  // Ù
#define U_MIN_ACCENT_GRAVE 0x00F9  // ù

#define A_MAJ_CIRCONFLEXE 0x00C2  // Â
#define A_MIN_CIRCONFLEXE 0x00E2  // â
#define E_MAJ_CIRCONFLEXE 0x00CA  // Ê
#define E_MIN_CIRCONFLEXE 0x00EA  // ê
#define I_MAJ_CIRCONFLEXE 0x00CE// Î
#define I_MIN_CIRCONFLEXE 0x00EE  // î
#define O_MAJ_CIRCONFLEXE 0x00D4  // Ô
#define O_MIN_CIRCONFLEXE 0x00F4  // ô
#define U_MAJ_CIRCONFLEXE 0x00DB  // Û
#define U_MIN_CIRCONFLEXE 0x00FB  // û

#define E_MAJ_TREMA 0x00CB  // Ë
#define E_MIN_TREMA 0x00EB  // ë
#define I_MAJ_TREMA 0x00CF// Ï
#define I_MIN_TREMA 0x00EF  // ï
#define U_MAJ_TREMA 0x00DC// Ü
#define U_MIN_TREMA 0x00FC  // ü


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `/~  |   1  |   2  |   3  |   4  |   5  | Ins |           | Win   |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  '   |           |  {   |   Y  |   U  |   I  |   O  |   P  |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Ctrl Tab|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Numlock|
 * |--------+------+------+------+------+------| Esc  |           | Del  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | 1 num  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Ctrl  |  Win |      |      | Meh  |                                       |  left| Down |   up | right|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Home | End  |       |      |Print |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       |      |        |      |
 *                                 | Space|  Alt |------|       |------|  Enter |bckspc|
 *                                 |      |      | PgDwn|       | L3   |        |      |
 *                                 `--------------------'       `----------------------'
 */
	[BASE] = LAYOUT_ergodox(
          KC_GRAVE,KC_1,KC_2,KC_3,KC_4,KC_5,TG(1),
          KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_QUOTE,
          KC_TRANSPARENT,KC_A,KC_S,KC_D,KC_F,KC_G,
          KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_ESCAPE,
          KC_LCTRL,KC_LGUI,KC_TRANSPARENT,KC_TRANSPARENT,MEH_T(KC_NO),
          KC_HOME,KC_END,KC_PGUP,
          KC_SPACE,ALT_T(KC_NO),LT(1,KC_PGDOWN),
          
          KC_LGUI,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINUS,
          KC_LCBR,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_EQUAL,
          KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_NUMLOCK,
          KC_DELETE,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_KP_1,
          KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,MO(1),
          TO(1),KC_PSCREEN,KC_TRANSPARENT,
          LT(2,KC_NO),KC_ENTER,KC_BSPACE),
		

/* Keymap 1: Basic layer MACS (Same as pc, except for cmd/ctrl, which are swapped)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | POM  |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |  |   |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      | Ctrl |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
 
	[BASE_MAC] = LAYOUT_ergodox(
          KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
          KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
          KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
          KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
          KC_LGUI,KC_LGUI,KC_TRNS,KC_TRNS,KC_TRNS,
          KC_TRNS,KC_TRNS,KC_TRNS,
          KC_TRNS,KC_LCTRL,KC_TRNS,
          
          KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
          KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
          KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
          KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
          KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
          KC_TRNS,KC_TRNS,KC_TRNS,
          KC_TRNS,KC_TRNS,KC_TRNS),

		
	[NUMB_SYMB] = LAYOUT_ergodox(KC_TRANSPARENT,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_BSLASH,KC_PIPE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_LABK,KC_RABK,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_TRANSPARENT,KC_TRANSPARENT,KC_LCBR,KC_RCBR,KC_TRANSPARENT,KC_TRANSPARENT,KC_F12,KC_TRANSPARENT,KC_LPRN,KC_RPRN,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_LBRACKET,KC_RBRACKET,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),
  
  /* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   è  |   é  |      |      |      |           |      |      |   ù  |   î  |   ô  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   à  |   ë  |   ê  |      |      |------|           |------|      |   û  |   ï  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Rotate3|   â  |      |   ç  |      |      |      |           |      |      |   ü  |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Home | End  |       |      |Print |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       |      |        |      |
 *                                 | Space|  Alt |------|       |------|  Enter |bckspc|
 *                                 |      |      | PgDwn|       | L3   |        |      |
 *                                 `--------------------'       `----------------------'
 */
  [ACCENTS] = LAYOUT_ergodox(
		KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
		KC_TRANSPARENT,KC_TRANSPARENT,UC(E_MIN_ACCENT_GRAVE),UC(E_MIN_ACCENT_AIGU),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
		KC_TRANSPARENT,UC(A_MIN_ACCENT_GRAVE),UC(E_MIN_TREMA),UC(E_MIN_CIRCONFLEXE),KC_TRANSPARENT,KC_TRANSPARENT,
		MO(3),UC(A_MIN_CIRCONFLEXE),KC_TRANSPARENT,UC(C_MIN_CEDILLA),KC_TRANSPARENT,KC_TRANSPARENT,
		KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
		KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
		KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
		
		KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
		KC_TRANSPARENT,KC_TRANSPARENT,UC(U_MIN_ACCENT_GRAVE),UC(I_MIN_CIRCONFLEXE),UC(O_MIN_CIRCONFLEXE),KC_TRANSPARENT,KC_TRANSPARENT,
		KC_TRANSPARENT,UC(U_MIN_CIRCONFLEXE),UC(I_MIN_TREMA),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
		KC_TRANSPARENT,KC_TRANSPARENT,UC(U_MIN_TREMA),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
		KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
		KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
		KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT)

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
    set_unicode_input_mode(UC_WINC);
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;

  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }
    return state;

};