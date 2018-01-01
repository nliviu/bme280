#pragma once
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif
struct mgos_bme280;

/*
 * `temp` - temperature in degrees Celsius
 * `press` - pressure in Pa
 * `humid` - humidity in %
 */
struct mgos_bme280_data
{
    double temp;
    double press;
    double humid;
};

/*
 * Creates a `struct mgos_bme280` for the device with `addr` address
 * Returns opaque handle (NULL if an error occurred)
 */
struct mgos_bme280* mgos_bme280_i2c_create(uint8_t addr);

/*
 * Deletes the handle and frees resources.
 */
void mgos_bme280_delete(struct mgos_bme280* bme);

/*
 * Reads the temperature, pressure and humidity in the provided `data` structure.
 * If the device is BMP280, the humidity will be 0.
 */
int8_t mgos_bme280_read(struct mgos_bme280* bme, struct mgos_bme280_data* data);

/*
 * Returns true if a BME280 device is connected
 */
bool mgos_bme280_is_bme280(struct mgos_bme280* bme);

#ifdef __cplusplus
}
#endif

