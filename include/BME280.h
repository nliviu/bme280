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
     * Reads the temperature in the provided `temp` reference to double.
     * Returns 0 if success
     */
    int8_t readTemperature(struct mgos_bme280* bme, double& temp)
    {
        return mgos_bme280_read_temperature(_bme, &temp);
    }

    /*
     * Reads the pressure in the provided `press` reference to double.
     * Returns 0 if success
     */
    int8_t readPressure(struct mgos_bme280* bme, double& press)
    {
        return mgos_bme280_read_pressure(_bme, &press);
    }

    /*
     * Reads the humidity in the provided `humid` reference to double.
     * If the device is BMP280, the humidity will be 0.
     * Returns 0 if success
     */
    int8_t readHumidity(struct mgos_bme280* bme, double& humid)
    {
        return mgos_bme280_read_humidity(_bme, &humid);
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

