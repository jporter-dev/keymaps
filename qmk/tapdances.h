#pragma once

void semiquotegui(qk_tap_dance_state_t *state, void *user_data);
void semiquotegui_reset(qk_tap_dance_state_t *state, void *user_data);

void esctabctl(qk_tap_dance_state_t *state, void *user_data);
void esctabctl_reset(qk_tap_dance_state_t *state, void *user_data);

enum {
    TD_SEMI_QUOTE,
    TD_ESC_TAB
};
