/*
 * SHT40 for Raspberry Pi Pico
 *
 * @version     1.0.0
 * @author      Zach Rideout
 * @copyright   2022
 * @licence     MIT
 *
 */
#ifndef _SHT40_MAIN_HEADER_
#define _SHT40_MAIN_HEADER_

/*
 * C HEADERS
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * PICO HEADERS
 */
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"
#include "hardware/spi.h"
#include "hardware/adc.h"
#include "hardware/uart.h"

#endif // _SHT40_MAIN_HEADER_
