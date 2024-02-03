/**
* @file Light.cpp
* @brief Demonstrate how to measure light using sensor connected to
* Intel Galileo board using UPM library
*
* @note grovelight sensor needs to be connected to the Galileo Arduino via base
* shield analog port A0.
* @note Additional linker flags: "upm-grove".
*
* @see http://iotdk.intel.com/docs/master/upm/
* @see https://software.intel.com/en-us/iot/hardware/sensors/grove-light-sensor
* @see http://www.seeedstudio.com/wiki/Grove_-_Light_Sensor
* @see http://akizukidenshi.com/download/ds/senba/GL55%20Series%20Photoresistor.pdf
*
* @bug No known bugs
*
*/
/* -- Includes -- */

/* UPM library includes */
#include "grove.h" //for light->name(), light->value()

/* Standard IO includes */
#include <stdio.h> // for printf()

#include <unistd.h> //for sleep()

/**
 * @brief Main function for light sensor example
 *
 * It performs following tasks:
 * 1. Creates an instance light of class grovelight using UPM.
 * 2. Enter a loop to acquire and print light values at intervals of 1 second.
 * 3. Exit loop after 5 iterations.
 *
 * Example usage:
 * @code{.c}
 * int main(void)
 * @endcode
 *
 * @param void This function does not take any input parameter.
 * @return Returns 0.
 *
 * @see http://iotdk.intel.com/docs/master/upm/classupm_1_1_grove_light.html
 *
 * @note UPM library has dependency on MRAA library functions.
 *
 * @warning None.
 */

int main()
{
	  // Create the light sensor object using AIO pin 0
	    upm::GroveLight* light = new upm::GroveLight(0);
	    // Read the input and print both the raw value and a rough lux value,
	    // waiting one second between readings
	    for (int i=5;i>0;i--) {
	        printf(" Light value is %f which is roughly %d lux \n", light->raw_value(), light->value());
	        fflush(stdout);
	        sleep(1);
	    }
	    // Delete the light sensor object
	    printf("Exiting .. bbye!");
	    delete light;
}
