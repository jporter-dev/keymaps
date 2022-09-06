#include "tapdances.h"

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SEMI_QUOTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, semiquotegui, semiquotegui_reset),
    [TD_ESC_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, esctabctl, esctabctl_reset),
};

void semiquotegui(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        // single tap
        if (state->interrupted || !state->pressed) register_code(KC_SEMICOLON);
        // single hold
        else register_code(KC_RGUI);
    }
    else if (state->count == 2) {
        // single double tap
        if (state->interrupted) register_code(KC_QUOTE);
        // double hold
        else if (state->pressed) register_code(KC_RGUI);
        // double tap
        else register_code(KC_QUOTE);
    }
}

void semiquotegui_reset(qk_tap_dance_state_t *state, void *user_data)
{
    unregister_code(KC_RGUI);
    unregister_code(KC_SEMICOLON);
    unregister_code(KC_QUOTE);
}

void esctabctl(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        // single tap
        if (state->interrupted || !state->pressed) register_code(KC_TAB);
        // single hold
        else register_code(KC_LCTL);
    }
    else if (state->count == 2) {
        // single double tap
        if (state->interrupted) register_code(KC_ESC);
        // double hold
        else if (state->pressed) register_code(KC_LCTL);
        // double tap
        else register_code(KC_ESC);
    }
}

void esctabctl_reset(qk_tap_dance_state_t *state, void *user_data)
{
    unregister_code(KC_LCTL);
    unregister_code(KC_TAB);
    unregister_code(KC_ESC);
}
