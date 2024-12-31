#include "oscillator.h"

void init_oscillator(Oscillator *osc, float frequency, float sample_rate) {
    osc->phase = 0.0f;
    osc->phase_increment = (M_2PI * frequency) / sample_rate;
    osc->sample_rate = sample_rate;
}

void change_oscillator_frequency(Oscillator *osc, float frequency) {
    osc->phase_increment = (M_2PI * frequency) / osc->sample_rate;
}

float get_oscillator_sin_sample(Oscillator *osc) {
    float sample = sinf(osc->phase);
    osc->phase += osc->phase_increment;
    if (osc->phase >= M_2PI) {
        osc->phase -= M_2PI;
    }
    return sample;
}

float get_oscillator_cos_sample(Oscillator *osc) {
    float sample = cosf(osc->phase);
    osc->phase += osc->phase_increment;
    if (osc->phase >= M_2PI) {
        osc->phase -= M_2PI;
    }
    return sample;
}