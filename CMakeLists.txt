cmake_minimum_required(VERSION 3.14)
include(pico_sdk_import.cmake)
project(SHT40 VERSION 1.0.0)
add_executable(SHT40
               main.c
               ./sht40/sensirion_hw_i2c_implementation.c
               ./sht40/sensirion_common.c
               ./sht40/sht4x.c)

pico_sdk_init()

pico_enable_stdio_usb(SHT40 1)
pico_enable_stdio_uart(SHT40 1)
pico_add_extra_outputs(SHT40)

target_link_libraries(SHT40
                      pico_stdlib
                      hardware_gpio
                      hardware_i2c
                      hardware_spi
                      hardware_adc
                      hardware_uart)
