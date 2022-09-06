// RGB LED Indicators
// 0-5    = UNDERGLOW
//     24|23|18|17|10|9    9|10|17|18|23|24
//     25|22|19|16|11|8    8|11|16|19|22|25
//     26|21|20|15|12|7    7|12|15|20|21|26
//              14|13|6    6|13|14
#ifdef RGBLIGHT_ENABLE

    #define HSV_PRIMARY HSV_BLUE
    #define HSV_SECONDARY HSV_MAGENTA
    #define HSV_ACCENT HSV_GREEN
    #define NUM_UNDERGLOW HSV_GOLD
    #define SYM_UNDERGLOW HSV_SPRINGGREEN
    #define FN_UNDERGLOW HSV_RED
    #define HSV_TERTIARY HSV_RED

    /************************
    *       LEFT RGBS       *
    * 0-5 UNDERGLOW         *
    *     24|23|18|17|10|9  *
    *     25|22|19|16|11|8  *
    *     26|21|20|15|12|7  *
    *              14|13|6  *
    ************************/
    const rgblight_segment_t PROGMEM num_left_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0,27,0,0,0},
        {0, 6, NUM_UNDERGLOW},
        // pgup/pgdn/end/home
        {7, 3, HSV_SECONDARY},
        {12, 1, HSV_SECONDARY},
        // arrows
        {11, 1, HSV_TERTIARY},
        {16, 2, HSV_TERTIARY},
        {19, 1, HSV_TERTIARY},
        {10, 1, HSV_PRIMARY},
        {18, 1, HSV_PRIMARY},
        // meh key
        {22, 1, HSV_ACCENT},
        // tilde
        {24, 1, HSV_ACCENT}
    );
    const rgblight_segment_t PROGMEM sym_left_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0,27,0,0,0},
        {0, 6, SYM_UNDERGLOW},
        {13, 1, HSV_TERTIARY},
        // tilde
        {24, 1, HSV_ACCENT},
        // top row
        {9, 2, HSV_PRIMARY},
        {17, 2, HSV_PRIMARY},
        {23, 1, HSV_PRIMARY}
    );
    const rgblight_segment_t PROGMEM fn_left_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0,27,0,0,0},
        {0, 6, HSV_MAGENTA},
        // FN keys
        {9, 2, HSV_SECONDARY},
        {17, 2, HSV_SECONDARY},
        {23, 2, HSV_SECONDARY},
        // RGB toggles
        {19, 1, HSV_ACCENT},
        {22, 1, HSV_ACCENT},
        {25, 2, HSV_ACCENT},
        // copypasta
        {12, 1, HSV_TERTIARY},
        {15, 1, HSV_TERTIARY},
        {20, 2, HSV_TERTIARY},
        // media keys
        {8, 1, HSV_PRIMARY},
        {11, 1, HSV_PRIMARY},
        {16, 1, HSV_PRIMARY}
    );

    /************************
    *       RIGHT RGBS      *
    * 0-5 UNDERGLOW         *
    *     9|10|17|18|23|24  *
    *     8|11|16|19|22|25  *
    *     7|12|15|20|21|26  *
    *     6|13|14           *
    ************************/
    const rgblight_segment_t PROGMEM num_right_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0,27,0,0,0},
        {0, 6, NUM_UNDERGLOW},
        {13, 1, HSV_TERTIARY},
        // numbers
        {10, 3, HSV_PRIMARY},
        {14, 7, HSV_PRIMARY},
        {23, 1, HSV_PRIMARY},
        // symbols
        {7, 1, HSV_SECONDARY},
        {21, 2, HSV_SECONDARY},
        {24, 3, HSV_SECONDARY}
    );
    const rgblight_segment_t PROGMEM sym_right_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0,27,0,0,0},
        {0, 6, SYM_UNDERGLOW},
        // symbols
        {7, 6, HSV_PRIMARY},
        {15, 9, HSV_PRIMARY},
        // backspace
        {24, 1, HSV_ACCENT}
    );
    const rgblight_segment_t PROGMEM fn_right_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0,27,0,0,0},
        {0, 6, HSV_MAGENTA},
        // FN keys
        {9, 2, HSV_SECONDARY},
        {17, 2, HSV_SECONDARY},
        {23, 2, HSV_SECONDARY},
        // media keys
        {8, 1, HSV_PRIMARY},
        {11, 1, HSV_PRIMARY},
        {16, 1, HSV_PRIMARY}
    );

    // Now define the array of layers. Later layers take precedence
    const rgblight_segment_t* const PROGMEM left_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        num_left_layer,
        sym_left_layer,
        fn_left_layer
    );

    // Now define the array of layers. Later layers take precedence
    const rgblight_segment_t* const PROGMEM right_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        num_right_layer,
        sym_right_layer,
        fn_right_layer
    );

    void keyboard_post_init_user(void) {
        // Enable the LED layers
        if(!is_keyboard_master()) {
            rgblight_layers = left_rgb_layers;
        } else {
            rgblight_layers = right_rgb_layers;
        }
    }

    layer_state_t layer_state_set_user(layer_state_t state) {
        rgblight_set_layer_state(0, layer_state_cmp(state, _NUM));
        rgblight_set_layer_state(1, layer_state_cmp(state, _SYM));
        rgblight_set_layer_state(2, layer_state_cmp(state, _FN));
        return state;
    }
#endif // RGBLIGHT_ENABLE
