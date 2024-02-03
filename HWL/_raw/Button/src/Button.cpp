/**
* @file Button.cpp
* @brief Demonstrate how to use Grove button connected to Intel Galileo
*
* The Grove - Button is a momentary push button. It contains one independent
* "momentary on/off" button. 'Momentary' means that the button rebounds on its
*  own after it is released. The button outputs a HIGH signal when pressed,
*  and LOW when released.
*
* @note grovebutton sensor needs to be connected to the Galileo Arduino via base
* shield at Digital input D4.
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

/**
 * @brief Main function for button example
 *
 * It performs following tasks:
 * 1. Creates an instance button of class grovebutton using UPM.
 * 2. Enter a loop to read and print button D4 values at intervals of 0.5 second.
 * 3. Exit loop after detecting button press for 5 times
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
 */

int main()
{
    // Create the button object using GPIO pin D4
    upm::GroveButton* button = new upm::GroveButton(4);
    // Read the input and print, waiting one second between readings

    int count = 5;
    int button_val=0;

    while( count > 0 ) {

    	button_val = button->value(); //read button value and store to local variable
    	printf ("Program will exit after %d button presses\n", count);
    	printf ("Button value is: %d\n ", button_val);

        if (button_val)
        	count--;

        usleep(500000); //0.5 second
    }
	printf ("Exiting, bbye!");
    // Delete the button object
    delete button;
}
