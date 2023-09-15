#include QMK_KEYBOARD_H

#include "oled/ergohaven_dark.c"
// #include "oled/ergohaven_light.c"

#include "features/achordion.h"

#define BASE_LAYERS_LIST \
    LAYER(_BASE) \
    LAYER(_NAV) \
    LAYER(_NUM) \
    LAYER(_SYM) \
    LAYER(_FUN) \
    LAYER(_MEDIA) \
    LAYER(_MOUSE) \
    LAYER(_GAME) 

// Layers
enum {
    #define LAYER(_LAYER) _LAYER,
        BASE_LAYERS_LIST
    #undef LAYER
    _GAME_NUM,
    _GAME_FUN
};

// Tap dance 
enum {
    DT_BOOT,
    #define LAYER(_LAYER) DT_LL##_LAYER,
        BASE_LAYERS_LIST
    #undef LAYER
};

// Home row mods + Right Alts
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

#define HOME_SCLN LGUI_T(KC_SCLN)
#define HOME_L LALT_T(KC_L)
#define HOME_K LCTL_T(KC_K)
#define HOME_J LSFT_T(KC_J)

#define HOME_X RALT_T(KC_X)
#define HOME_DOT RALT_T(KC_DOT)

// Thumb double function keys
#define ESC_MEDIA LT(_MEDIA, KC_ESC)
#define SPC_NAV LT(_NAV, KC_SPC)
#define TAB_MOUSE LT(_MOUSE, KC_TAB)
#define ENT_SYM LT(_SYM, KC_ENT)
#define BSPC_NUM LT(_NUM, KC_BSPC)
#define DEL_FUN LT(_FUN, KC_DEL)

// Additional _GAME layers
#define GAME_NUM MO(_GAME_NUM)
#define GAME_FUN MO(_GAME_FUN)

// Common shortcuts
#define REDO C(KC_Y)
#define PASTE C(KC_V)
#define COPY C(KC_C)
#define CUT C(KC_X)
#define UNDO C(KC_Z)

// Workspace switching
#define LEFT_WS LGUI(LCTL(KC_LEFT)) 
#define RIGHT_WS LGUI(LCTL(KC_RIGHT)) 

// Tap Dances
#define TD_BOOT TD(DT_BOOT)

#define TD_BASE TD(DT_LL_BASE)
#define TD_NAV TD(DT_LL_NAV)
#define TD_NUM TD(DT_LL_NUM)
#define TD_SYM TD(DT_LL_SYM) 
#define TD_FUN TD(DT_LL_FUN)
#define TD_MEDIA TD(DT_LL_MEDIA)
#define TD_MOUSE TD(DT_LL_MOUSE)
#define TD_GAME TD(DT_LL_GAME)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,      KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                                   KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,   KC_RBRC, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,    HOME_A,    HOME_S,    HOME_D,    HOME_F,      KC_G,                                   KC_H,    HOME_J,    HOME_K,    HOME_L, HOME_SCLN,   KC_QUOT, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,      KC_Z,    HOME_X,      KC_C,      KC_V,      KC_B,                                   KC_N,      KC_M,   KC_COMM,  HOME_DOT,   KC_SLSH,   KC_LBRC, 
//      |----------+------      ----+----------+----------+----------+----------+-----|      |----------+----------+----------+----------+----------+----------+----------|
                                  XXXXXXX,   XXXXXXX, ESC_MEDIA,   SPC_NAV, TAB_MOUSE,          ENT_SYM,  BSPC_NUM,   DEL_FUN,   XXXXXXX,   XXXXXXX
//                                                  |----------+----------+----------|      |----------+----------+----------|
    ),
                                                                  
    [_NAV] = LAYOUT(
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,   TD_BOOT,   XXXXXXX,   TD_GAME,   TD_BASE,   XXXXXXX,                                   REDO,     PASTE,      COPY,       CUT,      UNDO,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|    
            XXXXXXX,   KC_LGUI,   KC_LALT,   KC_LCTL,   KC_LSFT,    KC_SPC,                                CW_TOGG,   KC_LEFT,   KC_DOWN,     KC_UP,   KC_RGHT,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|        
            XXXXXXX,   XXXXXXX,   KC_RALT,    TD_NUM,    TD_NAV,   XXXXXXX,                              KC_INSERT,   KC_HOME,   KC_PGDN,   KC_PGUP,    KC_END,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------+----------|      |----------+----------+----------+----------+----------+----------+----------|
                                  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,           KC_ENT,   KC_BSPC,    KC_DEL,   XXXXXXX,   XXXXXXX
//                                                  |----------+----------+----------|      |----------+----------+----------|
    ),    

    [_NUM] = LAYOUT(
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,   KC_LBRC,      KC_7,      KC_8,      KC_9,   KC_RBRC,                                XXXXXXX,   TD_BASE,   TD_GAME,   XXXXXXX,   TD_BOOT,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,   KC_SCLN,      KC_4,      KC_5,      KC_6,    KC_EQL,                                XXXXXXX,   KC_LSFT,   KC_LCTL,   KC_LALT,   KC_LGUI,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,    KC_GRV,      KC_1,      KC_2,      KC_3,   KC_BSLS,                                XXXXXXX,    TD_NUM,    TD_NAV,   KC_RALT,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------+----------|      |----------+----------+----------+----------+----------+----------+----------|
                                  XXXXXXX,   XXXXXXX,    KC_DOT,      KC_0,   KC_MINS,          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX
//                                                  |----------+----------+----------|      |----------+----------+----------|
    ),

    [_SYM] = LAYOUT(
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,   KC_LCBR,   KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RCBR,                                XXXXXXX,   TD_BASE,   TD_GAME,   XXXXXXX,   TD_BOOT,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,   KC_COLN,    KC_DLR,   KC_PERC,   KC_CIRC,   KC_PLUS,                                XXXXXXX,   KC_LSFT,   KC_LCTL,   KC_LALT,   KC_LGUI,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,   KC_TILD,   KC_EXLM,     KC_AT,   KC_HASH,   KC_PIPE,                                XXXXXXX,    TD_SYM,  TD_MOUSE,   KC_RALT,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------+----------|      |----------+----------+----------+----------+----------+----------+----------|
                                  XXXXXXX,   XXXXXXX,   KC_LPRN,   KC_RPRN,   KC_UNDS,          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX
//                                                  |----------+----------+----------|      |----------+----------+----------|
    ),

    [_FUN] = LAYOUT(
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,    KC_F12,     KC_F7,     KC_F8,     KC_F9,   KC_PSCR,                                XXXXXXX,   TD_BASE,   TD_GAME,   XXXXXXX,   TD_BOOT,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,    KC_F11,     KC_F4,     KC_F5,     KC_F6,   KC_SCRL,                                XXXXXXX,   KC_LSFT,   KC_LCTL,   KC_LALT,   KC_LGUI,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,    KC_F10,     KC_F1,     KC_F2,     KC_F3,    KC_BRK,                                XXXXXXX,    TD_FUN,  TD_MEDIA,   KC_RALT,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------+----------|      |----------+----------+----------+----------+----------+----------+----------|
                                  XXXXXXX,   XXXXXXX,    KC_APP,    KC_SPC,    KC_TAB,          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX
//                                                  |----------+----------+----------|      |----------+----------+----------|
    ),

    [_MEDIA] = LAYOUT(
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,   TD_BOOT,   XXXXXXX,   TD_GAME,   TD_BASE,   XXXXXXX,                                XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,   KC_LGUI,   KC_LALT,   KC_LCTL,   KC_LSFT,   XXXXXXX,                                XXXXXXX,   KC_MPRV,   KC_VOLD,   KC_VOLU,   KC_MNXT,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,   XXXXXXX,   KC_RALT,    TD_FUN,  TD_MEDIA,   XXXXXXX,                                XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------+----------|      |----------+----------+----------+----------+----------+----------+----------|
                                  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,           KC_MPLY,   KC_MSTP,   KC_MUTE,   XXXXXXX,   XXXXXXX
//                                                  |----------+----------+----------|      |----------+----------+----------|
    ),

    [_MOUSE] = LAYOUT(
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,   TD_BOOT,   XXXXXXX,   TD_GAME,   TD_BASE,   XXXXXXX,                                   REDO,     PASTE,      COPY,       CUT,      UNDO,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,   KC_LGUI,   KC_LALT,   KC_LCTL,   KC_LSFT,   XXXXXXX,                                XXXXXXX,   KC_MS_L,   KC_MS_D,   KC_MS_U,   KC_MS_R,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,   XXXXXXX,   KC_RALT,    TD_SYM,  TD_MOUSE,   XXXXXXX,                                XXXXXXX,   KC_WH_L,   KC_WH_D,   KC_WH_U,   KC_WH_R,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------+----------|      |----------+----------+----------+----------+----------+----------+----------|
                                  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,          KC_BTN1,   KC_BTN2,   KC_BTN3,   XXXXXXX,   XXXXXXX
//                                                  |----------+----------+----------|      |----------+----------+----------|
    ),

    [_GAME] = LAYOUT(
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
             KC_ESC,   XXXXXXX,   XXXXXXX,      KC_K,   XXXXXXX,     KC_F5,                                XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
               KC_I,    KC_TAB,      KC_Q,      KC_W,      KC_E,      KC_R,                                XXXXXXX,   TD_BASE,   GAME_FUN, GAME_NUM,   TD_BOOT,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            KC_LSFT,   KC_LSFT,      KC_A,      KC_S,      KC_D,      KC_F,                                XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            KC_LCTL,   KC_LCTL,      KC_Z,      KC_X,      KC_C,      KC_V,                                XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------+----------|      |----------+----------+----------+----------+----------+----------+----------|
                                  XXXXXXX,   XXXXXXX,   KC_LALT,    KC_SPC,      KC_J,          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX
//                                                  |----------+----------+----------|      |----------+----------+----------|
    ),

    [_GAME_NUM] = LAYOUT(
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
               KC_L,    KC_EQL,      KC_7,      KC_8,      KC_9,      KC_J,                                XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
               KC_K,   KC_MINS,      KC_4,      KC_5,      KC_6,      KC_G,                                XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
               KC_O,      KC_0,      KC_1,      KC_2,      KC_3,      KC_B,                                XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------+----------|      |----------+----------+----------+----------+----------+----------+----------|
                                  XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,         XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX
//                                                  |----------+----------+----------|      |----------+----------+----------|
    ),

    [_GAME_FUN] = LAYOUT(
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
            XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
               KC_T,    KC_F12,     KC_F7,     KC_F8,     KC_F9,      KC_U,                                XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
               KC_Y,    KC_F11,     KC_F4,     KC_F5,     KC_F6,      KC_H,                                XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------|                            |----------+----------+----------+----------+----------+----------|
               KC_P,    KC_F10,     KC_F1,     KC_F2,     KC_F3,      KC_N,                                XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, 
//      |----------+----------+----------+----------+----------+----------+----------|      |----------+----------+----------+----------+----------+----------+----------|
                                  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX
//                                                  |----------+----------+----------|      |----------+----------+----------|
    )
};

void double_tap_boot(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    reset_keyboard();
  }
}

#define LAYER(_LAYER) \
    void double_tap_lock_layer_##_LAYER(tap_dance_state_t *state, void *user_data) { \
        if (state->count == 2) { \
            default_layer_set((layer_state_t)1 << _LAYER); \
        } \
    }  
    BASE_LAYERS_LIST
#undef LAYER

tap_dance_action_t tap_dance_actions[] = {
    [DT_BOOT] = ACTION_TAP_DANCE_FN(double_tap_boot),
    #define LAYER(_LAYER) [DT_LL##_LAYER] = ACTION_TAP_DANCE_FN(double_tap_lock_layer_##_LAYER),
        BASE_LAYERS_LIST
    #undef LAYER
};

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
    if (tap_hold_record->event.key.row % (MATRIX_ROWS / 2) == 3) {
        return true;
    }

    if (other_record->event.key.row % (MATRIX_ROWS / 2) == 3) { 
        return true;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  
     }
    else {
    return OLED_ROTATION_270;  
    }
  return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        ergohaven_dark_draw();
        // ergohaven_light_draw();
    } else {
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) { 
        return false;
    }

    switch (keycode) {
        case CW_TOGG: // Shift + Caps Word -> Caps Lock
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT){
                    register_code(KC_CAPS);
                } else {
                    caps_word_toggle();
                }
            } else {
                unregister_code(KC_CAPS);
            }

            return false;
    }

    return true;
}

void matrix_scan_user(void) {
    achordion_task();
}