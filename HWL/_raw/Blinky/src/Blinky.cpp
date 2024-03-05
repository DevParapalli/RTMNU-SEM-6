/**
* @file Blinky.cpp
* @brief  Demonstrate how to blink the on board LED by writing a digital value to an output pin using the MRAA library.
*
* @note No external hardware is needed for this experiment.
* @note Galileo has GPIO - Digital IO 13 connected to on board LED DS2.
* @note Additional linker flags: none.
*
* @see http://iotdk.intel.com/docs/master/mraa/
* @see http://download.intel.com/support/galileo/sb/galileo_boarduserguide_330237_001.pdf
*
* @bug No known bugs
**/

/* -- Includes -- */

/* MRAA library includes */
#include "mraa.h"
/*
 * for
 * mraa_get_platform_type()
 * mraa_gpio_init()
 * mraa_gpio_dir()
 * mraa_gpio_write()
 *
 */

/* Standard IO includes */
#include <stdio.h>
/*
 * for
 * fprintf()
 *
 */

/**
 * @brief Main function for LED blink on Galileo
 *
 * It performs following tasks:
 * 1. Initialize GPIO pin for Galileo using mraa_gpio_init() funtion.
 * 2. Configure the GPIO as a digital output.
 * 3. Enter loop to toggle the on board LED 10 times as below:
 *         Loop n times:
 *             Turn off LED
 *             wait 1 second
 *             Turn on LED
 *             wait 1 second
 *             Loop
 *
 * Example usage:
 * @code{.c}
 * int main(void)
 * @endcode
 *
 * @param void This function does not take any input parameter.
 * @return Returns MRA return code for Errors or Success.
 *
 * @see http://iotdk.intel.com/docs/master/mraa/gpio_8h.html
 *
 * @note For definition of MRAA return types, please refer types.h
 * (under Includes/<MRAA include folder>).
 *
 * @warning None.
 *192.168.43.82
 */

int main()
{
    // create a GPIO object from MRAA using it
    mraa_gpio_context d_pin = NULL;
    d_pin = mraa_gpio_init(13);

    if (d_pin == NULL) { // error check
        fprintf(stderr, "MRAA couldn't initialize GPIO, exiting");
        return MRAA_ERROR_UNSPECIFIED;
    }

    // configure the GPIO pin as output
    if (mraa_gpio_dir(d_pin, MRAA_GPIO_OUT) != MRAA_SUCCESS) {
        fprintf(stderr, "Can't set digital pin as output, exiting");
        return MRAA_ERROR_UNSPECIFIED;
    };

    // loop to toggle on-board every second for 10 times
    for (int i=10;i>0;i--) {
        printf("LED OFF\n");
        mraa_gpio_write(d_pin, 0); // turn off LED
        sleep(1); //wait 1 second
        printf("LED ON\n");
        mraa_gpio_write(d_pin, 1); // turn on LED
        sleep(10); //wait 1 second
    }

    return MRAA_SUCCESS;
}
