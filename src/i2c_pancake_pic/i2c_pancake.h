#ifndef I2C_PANCAKE_H
#define I2C_PANCAKE_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_INPUTS 5

extern uint16_t analog_inputs[5];

uint16_t read_analog_inputs(uint8_t port, unsigned index);

void set_led_on(void);

void set_led_off(void);

void led_heartbeat(void);


//internal functions
void set_led(bool out);


#endif /* I2C_PANCAKE_H */

