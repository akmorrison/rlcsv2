#ifndef TOWER_DAQ_H
#define TOWER_DAQ_H

#include"shared_types.h"

//how many samples to hold in our sliding window average
#define WINDOW_WIDTH 16

//call at startup. Sets pin modes, allocates space, whatever
void init_daq_pins();

//read the daq values into window array. Call this function very regularly
void read_daq_pins();

//perform filtering from window array. Call when you need the values
void compute_daq_values(daq_holder_t* output);

//scaling factors and other constants

#define PRESSURE1_SCALE 0.5
#define PRESSURE1_OFFSET 0
#define PRESSURE2_SCALE 0.5
#define PRESSURE2_OFFSET 0

#define IGNPRI_SCALE 1.1
#define IGNPRI_OFFSET 0
#define IGNSEC_SCALE 1.1
#define IGNSEC_OFFSET 0

#endif
