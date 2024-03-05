/**
* @file ButtonInterrupt.cpp
* @brief Demonstrate how to trigger interrupt using Grove button
*
* The Grove - Button is a momentary push button. It contains one independent
* "momentary on/off" button. 'Momentary' means that the button rebounds on its
*  own after it is released. The button outputs a HIGH signal when pressed,
*  and LOW when released.
*
* @note grovebutton sensor needs to be connected to the Galileo Arduino via base
* shield at digital input D4.
* @note Additional linker flags: "upm-grove".
*
* @see http://iotdk.intel.com/docs/master/upm/
* @see https://software.intel.com/en-us/iot/hardware/sensors/grove-button
* @see http://www.seeedstudio.com/wiki/Grove_-_Button
*
* @bug No known bugs
*
*/
/* -- Includes -- */

/* UPM library includes */
#include "grove.h" // for button->value()

/* Standard IO includes */
#include <stdio.h> // for printf()

#include <unistd.h> //for sleep()

void buttonISR (void*);
int count = 0;

/**
 * @brief buttonISR is the Interrupt Service Routine for Button press
 *
 * It performs following tasks:
 * 1. It gets called upon button press
 * 2. Update the button press count and print a message
 * 3. Exit
 *
 * Example usage:
 * ISR will be called when events occur, it has to be registered
 * for button press event by another function (main)
 * @code{.c}
 * button->installISR(mraa::EDGE_FALLING, &buttonISR, NULL);
 * @endcode
 *
 * @param void This function does not take any input parameter.
 * @return Returns 0.
 *
 * @see http://iotdk.intel.com/docs/master/upm/classupm_1_1_grove_button.html
 *
 * @note UPM library has dependency on MRAA library functions.
 *
 * @warning None.
 *
 */

void buttonISR(void*)
{
    count++;
    printf("\nHello World from ISR, count = %d \n", count);
    fflush(stdout);

}

/**
 * @brief Main function
 *
 * It performs following tasks:
 * 1. Creates an instance button of class grovebutton using UPM.
 * 2. Installs an ISR function which will be called on button press.
 * 3. ISR prints message on button press.
 * 4. Enter empty while loop to keep the program running till the button
 * press count reaches 5.
 *
 * Example usage:
 * @code{.c}
 * int main(void)
 * @endcode
 *
 * @param void This function does not take any input parameter.
 * @return Returns 0.
 *
 * @see http://iotdk.intel.com/docs/master/upm/classupm_1_1_grove_button.html
 *
 * @note UPM library has dependency on MRAA library functions.
 *
 * @warning None.
 *
 */
int main()
{
    // Create the button object using GPIO pin 4
    upm::GroveButton* button = new upm::GroveButton(4);
    // Read the input and print, waiting one second between readings

    button->installISR(mraa::EDGE_FALLING, &buttonISR, NULL);

    printf("Waiting for Button press, will exit when count = 5 \n");

    while(count<5);

    printf("Exiting, bbye!\n");

    delete button;     // Delete the button object

}
