#pragma once
#include "mgos_bme280.h"

class BME280
{
public:

    /*
     * Creates the BME280 object for the device with `addr` address
     */
    BME280(uint8_t addr)
    : _bme(mgos_bme280_i2c_create(addr))
    {
    }

    /*
     * Deletes the object and frees resources.
     */
    ~BME280()
    {
        mgos_bme280_delete(_bme);
    }

    /*
     * Reads the temperature, pressure and humidity in the provided `data` structure.
     * If the device is BMP280, the humidity will be 0.
     */
    int8_t read(struct mgos_bme280_data& data)
    {
        return mgos_bme280_read(_bme, &data);
    }

    /*
     * Returns true if a BME280 device is connected
     */
    bool isBME280()
    {
        return mgos_bme280_is_bme280(_bme);
    }
private:
    struct mgos_bme280* _bme;
};

