/**
* @file Buzzer.cpp
* @brief Demonstrate how to play tones using Buzzer connected to Intel Galileo board
*  using UPM library
*
* The Grove - Buzzer module has a piezo buzzer as the main component. The piezo
* can be connected to digital outputs, and will emit a tone when the output is
* HIGH. Alternatively, it can be connected to a pulse-width modulation
* output to generate various tones and effects.
*
* @note grovebuzzer sensor needs to be connected to the Galileo Arduino via base
* shield at D5.
* @note Additional linker flags: "upm-buzzer".
*
* @see http://iotdk.intel.com/docs/master/upm/classupm_1_1_buzzer.html
* @see https://software.intel.com/en-us/iot/hardware/sensors/grove-buzzer
* @see http://www.seeedstudio.com/wiki/Grove_-_Buzzer
*
* @bug No known bugs
*
*/
/* -- Includes -- */

/* UPM library includes */
#include <buzzer.hpp>

/* for
 * sound->playSound()
 * sound->stopSound()
 * sound->setVolume()
 * sound->getVolume()
 */

/* Standard IO includes */
#include <stdio.h> // for printf()

#include <unistd.h> //for sleep()

/**
 * @brief Main function for Buzzer example
 *
 * It performs following tasks:
 * 1. Creates an instance button of class Buzzer using UPM.
 * 2. play sound (DO, RE, MI, etc...) for 1 second, pausing for 0.1 seconds between notes.
 *
 * Example usage:
 * @code{.c}
 * int main(void)
 * @endcode
 *
 * @param void This function does not take any input parameter.
 * @return Returns 0.
 *
 * @see http://iotdk.intel.com/docs/master/upm/classupm_1_1_buzzer.html#details
 *
 * @note UPM library has dependency on MRAA library functions.
 *
 * @warning None.
 */

int main()
{
    int chord[] = { DO, RE, MI, FA, SOL, LA, SI, DO, SI };
	    // create Buzzer instance
	    upm::Buzzer* sound = new upm::Buzzer(5);

	    printf("Volume = %f\n", sound->getVolume());
	    sound->setVolume(0.1);
	    printf("Volume = %f\n", sound->getVolume());
	    fflush(stdout);

	    // play sound (DO, RE, MI, etc...), pausing for 0.1 seconds between notes
	    printf("\nPlaying notes, pausing for 0.1 seconds between notes...\n");
	    fflush(stdout);

	    for (int chord_ind = 0; chord_ind < 7; chord_ind++) {
	        // play each note for one second
	        printf(" %d\n",  sound->playSound(chord[chord_ind], 500000) );
	        usleep(100000);
	    }
	    printf("Exiting, bbye!\n");

	    delete sound;
}
