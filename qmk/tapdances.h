#pragma once

void semiquotegui(tap_dance_state_t *state, void *user_data);
void semiquotegui_reset(tap_dance_state_t *state, void *user_data);

void esctabctl(tap_dance_state_t *state, void *user_data);
void esctabctl_reset(tap_dance_state_t *state, void *user_data);

enum {
    TD_SEMI_QUOTE,
    TD_ESC_TAB
};
