#include <Wire.h>
#include <stdint.h>

#ifndef RELAY_BUS_H
#define RELAY_BUS_H

#ifdef __cplusplus
extern "C" {
#endif

/*Write instruction on the I2C bus for the relay boards.
uint8_t addr is slave address
uint8_t data is data desired to be written
*/
uint8_t relay_bus_write(uint8_t addr, uint8_t data);

/*Read Data on the I2C bus for the relay boards.
uint8_t addr is slave address
*/
uint8_t relay_bus_read(uint8_t addr);

#ifdef __cplusplus
}
#endif

#endif //ifndef RELAY_BUS_H
