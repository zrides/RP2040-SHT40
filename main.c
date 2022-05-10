/*
 * SHT40 for Raspberry Pi Pico
 *
 * @version     1.0.0
 * @author      Zach Rideout
 * @copyright   2022
 * @licence     MIT
 *
 */
#include "main.h"
#include "./sht40/sht4x.h"
#include <stdio.h>  // printf

int main() {
    // Use for debugging
    stdio_init_all();

    /* Initialize the i2c bus for the current platform */
    sensirion_i2c_init();

    /* Busy loop for initialization, because the main loop does not work without
     * a sensor.
     */
    while (sht4x_probe() != STATUS_OK) {
        printf("SHT sensor probing failed\n");
        sensirion_sleep_usec(1000000); /* sleep 1s */
    }
    printf("SHT sensor probing successful\n");

    while (1) {
        int32_t temperature, humidity;
        /* Measure temperature and relative humidity and store into variables
         * temperature, humidity (each output multiplied by 1000).
         */
        int8_t ret = sht4x_measure_blocking_read(&temperature, &humidity);
        if (ret == STATUS_OK) {
            printf("measured temperature: %0.2f degreeCelsius, "
                   "measured humidity: %0.2f percentRH\n",
                   temperature / 1000.0f, humidity / 1000.0f);
        } else {
            printf("error reading measurement\n");
        }

        sensirion_sleep_usec(1000000); /* sleep 1s */
    }
    return 0;
}
