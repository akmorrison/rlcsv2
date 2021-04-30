#ifndef I2C_PANCAKE_H
#define I2C_PANCAKE_H

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover Mode (Internal/External Switchover Mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

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

