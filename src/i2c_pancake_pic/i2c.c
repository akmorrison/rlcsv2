#include "i2c.h"
#include "i2c_pancake.h"

uint16_t i2cSlaveRecv; // Data received on i2c
uint16_t i2cSlaveSend; // Data to be sent on i2c

void i2c_slave_init(uint16_t address) {
    SSPSTAT = 0x80;
    SSPADDbits.SSPADD = address << 1; //7 bit addressing, LSB is unused
    SSPCON = 0x36;
    SSPCON2 = 0x01;
    TRISB1 = 1; // SDA
    TRISB4 = 1; // SCL
    GIE = 1;
    PEIE = 1;
    SSP1IF = 0;
    SSP1IE = 1;
}

void i2c_handle_interrupt(void) {
    uint16_t temp;
    SSPCONbits.CKP = 0;

    SSP1IF = 0;

    // If overflow or collision.
    if ((SSPCONbits.SSPOV) || (SSPCONbits.WCOL)) {
        temp = SSPBUF; // Read the previous value to clear the buffer
        SSPCONbits.SSPOV = 0; // Clear the overflow flag
        SSPCONbits.WCOL = 0;   // Clear the collision bit
        SSPCONbits.CKP = 1;
        return;
    }

    // If last byte was Address + write
    if (!SSPSTATbits.D_nA && !SSPSTATbits.R_nW) {
        while(!BF);
        temp = SSP1BUF;
        BF = 0;
        SSPCONbits.CKP = 1;
        while(!BF);
        i2cSlaveRecv = SSP1BUF;
        if (i2cSlaveRecv == 2) {
            set_led_on();
        } else {
            set_led_off();
        }
        SSPCONbits.CKP = 1;
        BF = 0;
        // We already set this above but for some reason we need to set it here too
        SSP1IF = 0;
    }
    // If this is a read
    else if (SSPSTATbits.R_nW) {
        static uint8_t read_pointer;
        // If this is the first byte in a read
        if (!SSPSTATbits.D_nA) {
            read_pointer = 0;
        }
        temp = SSPBUF;
        BF = 0;
        
        for (uint8_t x = 0; x < NUM_INPUTS; x++) {
            if (read_pointer == x * 2) {
                SSPBUF = (uint8_t)(analog_inputs[x]);
            }
            if (read_pointer == (x * 2) + 1) {
                SSPBUF = (uint8_t)(analog_inputs[x] >> 8);
            }
            
//            SSPBUF = 'R';
        } // for
        read_pointer++;
        SSPCONbits.CKP = 1;
        while(SSPSTATbits.BF);
    }
}
