#include <stdint.h>
#include <stdlib.h>
#include <xc.h>
#include "i2c.h"
#include "i2c_pancake.h"
#include "timer.h"

#define MAX_LOOP_TIME_DIFF_CONST 100

// Define Analog Channels
#define STRAIN1 0
#define STRAIN2 1
#define STRAIN3 2
#define PRESSURE1 10
#define PRESSURE2 9

uint16_t dip_inputs = 0;

static void __interrupt() interrupt_handler(void) {
    //We received a i2c request from master, handle it.
    if (SSP1IF == 1) {
       i2c_handle_interrupt();
    }
    // Timer0 has overflowed - update millis() function
    // This happens approximately every 500us
    if (INTCONbits.TMR0IE == 1 && INTCONbits.TMR0IF == 1) {
        timer0_handle_interrupt();
        INTCONbits.TMR0IF = 0;
    }
}

void read_dip_inputs(void) {
    uint16_t new_dip = 0;
    new_dip |= (!PORTAbits.RA6) ? (1) : 0;       //LSB
    new_dip |= (!PORTAbits.RA5) ? (1 << 1) : 0;
    new_dip |= (!PORTAbits.RA4) ? (1 << 2) : 0;
    new_dip |= (!PORTAbits.RA3) ? (1 << 3) : 0;  //MSB
    if(dip_inputs != new_dip) {
        dip_inputs = new_dip;
        i2c_slave_init(dip_inputs); //reinitialize i2c slave module with new slave address
    }
}

void setup(void) {
    TRISAbits.TRISA3 = 1; // DIP 1
    TRISAbits.TRISA4 = 1; // DIP 2
    TRISAbits.TRISA5 = 1; // DIP 3
    TRISAbits.TRISA6 = 1; // DIP 4
    TRISAbits.TRISA0 = 1; // STRAIN 1
    TRISAbits.TRISA1 = 1; // STRAIN 2
    TRISAbits.TRISA2 = 1; // STRAIN 3
    TRISBbits.TRISB2 = 1; // PRESSURE 1
    TRISBbits.TRISB3 = 1; // PRESSURE 2
    TRISBbits.TRISB5 = 0; // LED

    ANSELA = 0;             // Enable Analog Inputs on Port A
    ANSELAbits.ANSA0 = 1;
    ANSELAbits.ANSA1 = 1;
    ANSELAbits.ANSA2 = 1;

    ANSELB = 0;             // Enable Analog Inputs on Port B
    ANSELBbits.ANSB2 = 1;
    ANSELBbits.ANSB3 = 1;

    // Configure FVR module
    // b[7] enables FVR
    // b[1:0] sets the reference to 4.096
    FVRCON = 0b10000011;

    // Configure ADC module
    // b[7] sets right justification, b[6:4] sets CS = FRC,
    // b[2]+b[1:0] sets Vss and FVR as references.
    ADCON1 = 0b11110011;
}

int main(int argc, char** argv) {
    setup();                    //Set up digital + analog I/O
    timer0_init();              //Initialize timer
    set_led_off();
    dip_inputs = 0;
    i2c_slave_init(dip_inputs);
    read_dip_inputs();            //Get actual dip switch value to set slave address, init i2c

    uint32_t last_millis = millis();

    while (1) {
        //Heartbeat
        if (millis() - last_millis > MAX_LOOP_TIME_DIFF_CONST) {
            //One day I will configure this correctly, but ATM we only need the LED to blink ;-;
            last_millis = millis();

            //led_heartbeat();
        }

        read_analog_inputs(STRAIN1, 0);
        read_analog_inputs(STRAIN2, 1);
        read_analog_inputs(STRAIN3, 2);
        read_analog_inputs(PRESSURE1, 3);
        read_analog_inputs(PRESSURE2, 4);
        
        read_dip_inputs(); //Check if dip switch input has changed, re-init i2c if so
    }
    return (EXIT_SUCCESS);
}

