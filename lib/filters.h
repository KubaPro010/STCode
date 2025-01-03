#pragma once

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "constants.h"

#define FIR_PHASES 32
#define FIR_TAPS 32

typedef struct {
    float alpha;
    float prev_sample;
} Emphasis;

void init_emphasis(Emphasis *pe, float tau, float sample_rate);
float apply_pre_emphasis(Emphasis *pe, float sample);

typedef struct {
    float alpha;
    float prev_sample;
} LowPassFilter;

void init_low_pass_filter(LowPassFilter *lp, float cutoff_frequency, float sample_rate);
float apply_low_pass_filter(LowPassFilter *lp, float sample);


typedef struct {
    float *buffer;
    int write_idx;  // Write position
    int read_idx;   // Read position
    int size;       // Total buffer size
    int delay;      // Delay in samples
} DelayLine;

void init_delay_line(DelayLine *delay_line, int max_delay);
void set_delay_line(DelayLine *delay_line, int new_delay);
float delay_line(DelayLine *delay_line, float in);
void exit_delay_line(DelayLine *delay_line);