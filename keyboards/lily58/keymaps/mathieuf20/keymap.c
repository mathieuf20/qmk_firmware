#include QMK_KEYBOARD_H
#include "raw_hid.h"

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern uint8_t is_master;

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _MACROS,
  _SQWERT,
  _RESET
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  /   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   q  |   w  |   e  |   r  |   t  |                    |   y  |   u  |   i  |   o  |   p  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ***1 |   a  |   s  |   d  |   f  |   g  |-------.    ,-------|   h  |   j  |   k  |   l  |   ;  |  è   |
 * |------+------+------+------+------+------|   (   |    |    )  |------+------+------+------+------+------|
 * |LShift|   z  |   x  |   c  |   v  |   b  |-------|    |-------|   n  |   m  |   ,  |   .  |   é  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RALT |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 * ***1: LCTL when held, ESC when tapped
 */
 #define PARLEFT LSFT(KC_9)
 #define PARRGHT LSFT(KC_0)
 #define CTRLESC MT(MOD_LCTL,KC_ESC)
 #define GOLOWER MO(_LOWER)
 #define GORAISE MO(_RAISE)
 [_QWERTY] = LAYOUT(
  KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_BSPC,\
  KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,                KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_MINS,\
  CTRLESC,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,                KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,\
  KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,PARLEFT,PARRGHT,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,\
                          KC_LALT,KC_LGUI,GOLOWER,KC_SPC ,KC_ENT ,GORAISE,KC_BSPC,KC_RALT\
),
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |      |  È   |
 * |------+------+------+------+------+------|   <   |    |    >  |------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |      |      |   É  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RALT |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
#define GREATER ALGR(KC_DOT)
#define SMALLER ALGR(KC_COMM)
#define ACUTE_E LSFT(KC_SLSH)
#define GRAVE_E LSFT(KC_QUOT)
[_SQWERT] = LAYOUT( \
  _______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,\
  _______,S(KC_Q),S(KC_W),S(KC_E),S(KC_R),S(KC_T),                S(KC_Y),S(KC_U),S(KC_I),S(KC_O),S(KC_P),_______,\
  _______,S(KC_A),S(KC_S),S(KC_D),S(KC_F),S(KC_G),                S(KC_H),S(KC_J),S(KC_K),S(KC_L),_______,GRAVE_E,\
  _______,S(KC_Z),S(KC_X),S(KC_C),S(KC_V),S(KC_B),SMALLER,GREATER,S(KC_N),S(KC_M),_______,_______,ACUTE_E,_______,\
                          _______,_______,XXXXXXX,_______,_______,XXXXXXX,_______,_______\
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |RSTLYR|      |      |      |      |      |                    |      |      |      |      |      |DELETE|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ?  |   &  |   *  |   (  |   )  |   \  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   '  |   _  |   +  |   ^  |   ç  |   à  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \SEnter\  |RAISE |DELETE| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
#define SBRKLFT RALT(KC_9)
#define SBRKRGT RALT(KC_0)
#define GORESET MO(_RESET)
#define TILDE   ALGR(KC_RBRC)
#define RSQWERT LM(_QWERTY, MOD_RSFT)
#define SHFTENT LSFT(KC_ENT)
#define APSTRPH LSFT(KC_COMM)
#define QUOTMRK LSFT(KC_DOT)
[_LOWER] = LAYOUT( \
  GORESET,_______,_______,_______,_______,_______,                _______,_______,_______,_______,KC_PSCR,KC_DEL ,\
  KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,                KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,\
  TILDE  ,KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC,                KC_CIRC,KC_AMPR,KC_ASTR,APSTRPH,QUOTMRK,KC_TILD,\
  _______,_______,_______,_______,_______,_______,SBRKLFT,SBRKRGT,APSTRPH,KC_UNDS,KC_PLUS,KC_LBRC,KC_RBRC,KC_BSLS,\
                          _______,_______,_______,_______,SHFTENT,_______,KC_DEL ,KC_RGUI\
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |   =  |   >  |                    | Mute | Prev | Play | Next |PRTSCR|Ctrl+V|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | Vol+ | HOME | PgDn | PgUp | END  |Ctrl+C|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |   <  |  >   |-------.    ,-------| Vol- | Left | Down |  Up  | Right|Ctrl+X|
 * |------+------+------+------+------+------|   {   |    |    }  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   "  |   -  |   =  |   ¨  |   Ç  |   À  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \ Enter\  |RAISE |DELETE| RCTL |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
#define LSQWERT LM(_QWERTY, MOD_LSFT)
#define BRKLEFT RALT(KC_7)
#define BRKRGHT RALT(KC_8)
#define SHFPSCR S(KC_PSCR)
#define CTRL_X  LCTL(KC_X)
#define CTRL_C  LCTL(KC_C)
#define CTRL_V  LCTL(KC_V)
#define GOMACRO MO(_MACROS)
[_RAISE] = LAYOUT( \
  _______,_______,_______,_______,KC_EQL ,GREATER,                KC_MUTE,KC_MPRV,KC_MPLY,KC_MNXT,SHFPSCR,CTRL_V ,\
  _______,_______,_______,_______,_______,_______,                KC_VOLU,KC_HOME,KC_PGDN,KC_PGUP,KC_END ,CTRL_C ,\
  _______,_______,_______,_______,SMALLER,GREATER,                KC_VOLD,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,CTRL_X ,\
  _______,_______,_______,_______,_______,_______,BRKLEFT,BRKRGHT,QUOTMRK,KC_MINS,KC_EQL ,KC_LCBR,KC_RCBR,KC_PIPE,\
                          GOMACRO,_______,_______,_______,_______,_______,KC_DEL ,KC_RCTL\
),
[_RESET] = LAYOUT( \
  _______,_______,_______,_______,_______, RESET ,                _______,_______,_______,_______,_______,_______,\
  _______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,\
  _______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,\
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,\
                          _______,_______,_______,_______,_______,_______,_______,_______\
)
};

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

void print_hydra_logo(void);
// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    //oled_write_ln(read_layer_state(), false);
	  //oled_write_ln(read_keylog(), false);
    //oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
  	//oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
	  //oled_write(read_logo(), false);
    print_hydra_logo();
  } else {
    //oled_write(read_logo(), false);
    print_hydra_logo();
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    //set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _SQWERT);
  return state;
}