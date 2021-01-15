#include <xc.h>
#include "i2c_pancake.h"

uint16_t analog_inputs[NUM_INPUTS];
uint16_t read_analog_inputs(uint8_t port, unsigned index) {
    ADCON0 = 0x01 | (port << 2); // Turn ADC on, select port to read from
    ADCON0 |= 1 << 1; // set b[1] "go" bit
    uint8_t done_bit = 0;
    do { //wait for ADC to complete (go bit switches to 0 automatically when done)
        done_bit = ADCON0 & (1 << 1);
    } while (done_bit); //while go bit is on (AD conversion in progress)

    uint16_t adc_result = (ADRESH << 8) | ADRESL; //combine two 8bit values into a 16bit value
    analog_inputs[index] = adc_result;

    ADCON0 = 0x00; //Turn ADC off return;

    return adc_result;
}

void set_led_on(void) {
    set_led(true);
}

void set_led_off(void) {
    set_led(false);
}

void set_led(bool out) {
    if (out) {
        LATBbits.LATB5 = 1;
    } else {
        LATBbits.LATB5 = 0;
    }
}

void led_heartbeat(void) {
    static bool led_on = false;
    if (led_on) {
        set_led_off();
        led_on = false;
    } else {
        set_led_on();
        led_on = true;
    }
}
