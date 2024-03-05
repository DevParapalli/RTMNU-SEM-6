/**
* @file RotaryAngle.cpp
* @brief Demonstrate how to use Grove Rotary Angle Sensor connected to Intel Galileo
*
* The rotary angle sensor produces analog output between 0 and Vcc (5V DC)
* on its D1 connector. The D2 connector is not used. The angular range is 300 degrees
* with a linear change in value. The resistance value is 10k ohms.
* This may also be known as a 'potentiometer'
*
* @note grovebutton sensor needs to be connected to the Galileo Arduino A1 via base
* shield.
* @note Additional linker flags: "upm-grove".
*
* @see http://iotdk.intel.com/docs/master/upm/classupm_1_1_grove_rotary.html
* @see http://www.seeedstudio.com/wiki/Grove_-_Rotary_Angle_Sensor
* @see http://www.csl.mtu.edu/cs4411.choi/www/Resource/signal.pdf
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
 * @brief Main function for light sensor example
 *
 * It performs following tasks:
 * 1. Creates an instance knob of class groverotary using UPM.
 * 2. Enter a loop to check for button value at intervals of 1 second.
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
      // Instantiate a rotary sensor on analog pin A1
        upm::GroveRotary* knob = new upm::GroveRotary(1);
    // Read the input and print, waiting one second between readings
    while( 1 ) {
            float abs_value = knob->abs_value(); // Absolute raw value
            float abs_deg = knob->abs_deg();     // Absolute degrees
            float abs_rad = knob->abs_rad();     // Absolute radians
            float rel_value = knob->rel_value(); // Relative raw value
            float rel_deg = knob->rel_deg();     // Relative degrees
            float rel_rad = knob->rel_rad();     // Relative radians
            printf("Absolute: %4d raw %5.2f deg = %3.2f rad Relative: %4d raw %5.2f deg %3.2f rad\n",
                    (int16_t)abs_value, abs_deg, abs_rad, (int16_t)rel_value, rel_deg, rel_rad);
            sleep(1); // Sleep for 1s
        }
    // Delete the button object
    delete knob;
    //Will the program ever reach here? If no, then how can we delete knob?
    //Hint: See boiler plate for link to signal document
}
