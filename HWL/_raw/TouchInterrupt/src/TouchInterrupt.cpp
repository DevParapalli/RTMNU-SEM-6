/**
* @file TouchInterrupt.cpp
* @brief Demonstrate how to trigger interrupt using Grove button
*
* This touch sensor detects when a finger is near the metallic pad by the change
* in capacitance. It can replace a more traditional push button. The touch sensor
* can still function when placed under a non-metallic surface like glass or plastic.
*
* @note grovetouch sensor needs to be connected to the Galileo Arduino via base
* shield D4.
* @note Additional linker flags: "upm-ttp223".
*
* @see http://iotdk.intel.com/docs/master/upm/classupm_1_1_t_t_p223.html
* @see https://software.intel.com/en-us/iot/hardware/sensors/ttp223-touch-sensor
* @see http://www.seeedstudio.com/wiki/Grove_-_Touch_Sensor
*
* @bug No known bugs
*
*/
/* -- Includes -- */

/* UPM library includes */
#include "ttp223.h" // for button->value()

/* Standard IO includes */
#include <stdio.h> // for printf()

#include <unistd.h> //for sleep()

void touchISR (void*);
int count = 3;

/**
 * @brief touchISR is the Interrupt Service Routine for touch event
 *
 * It performs following tasks:
 * 1. It gets called upon touch event
 * 2. Update the touch event count and print a message
 * 3. Exit
 *
 * Example usage: ISR will be called when events occur, it has to be registered
 * for touch event by another function (main)
 * @code{.c}
 * touch->installISR(mraa::EDGE_FALLING, &touchISR, NULL);
 * @endcode
 * @param void This function does not take any input parameter.
 * @return Returns 0.
 *
 * @see http://iotdk.intel.com/docs/master/upm/classupm_1_1_t_t_p223.html
 *
 * @note UPM library has dependency on MRAA library functions.
 *
 * @warning None.
 *
 */

void touchISR(void*)
{
    count--;
    printf("\nHello World from ISR, will exit after %d touch events", count);
    fflush(stdout);
}

/**
 * @brief Main function for touch sensor example
 *
 * It performs following tasks:
 * 1. Creates an instance button of class TTP223 using UPM.
 * 2. Installs an ISR function which will be called on touch input.
 * 3. ISR prints message on touch event.
 *
 * Example usage:
 * @code{.c}
 * int main(void)
 * @endcode
 *
 * @param void This function does not take any input parameter.
 * @return Returns 0.
 *
 * @see http://iotdk.intel.com/docs/master/upm/classupm_1_1_t_t_p223.html
 *
 * @note UPM library has dependency on MRAA library functions.
 *
 * @warning None.
 *
 */

int main()
{
    // Create the button object using GPIO pin 4
    upm::TTP223* touch = new upm::TTP223(4);
    // Read the input and print, waiting one second between readings

    touch->installISR(mraa::EDGE_FALLING, &touchISR, NULL);

    printf("\nWelcome, waiting for touch event.\nWill exit after 5 events");
    fflush(stdout);

    while(count>0);

    printf("\nExiting .. Bbye!");

    delete touch;     // Delete the button object

}
