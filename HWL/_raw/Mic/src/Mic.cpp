/**
* @file Mic.cpp
* @brief Demonstrate how to use Grove Mic connected to Intel Galileo
*
* Grove - Sound Sensor can detect the sound strength of the environment. The main
* component of the module is a simple microphone, which is based on the LM358 amplifier
* and an electret microphone. This module's output is analog and can be easily sampled
*
* @note grove mic sensor needs to be connected to the Galileo Arduino A0 via base
* shield.
* @note Additional linker flags: "upm-mic".
*
* @see http://iotdk.intel.com/docs/master/upm/classupm_1_1_microphone.html#details
* @see http://www.seeedstudio.com/wiki/Grove_-_Sound_Sensor
* @see https://software.intel.com/en-us/iot/hardware/sensors/analog-microphone
*
* @bug No known bugs
*
*/
/* -- Includes -- */

/* UPM library includes */
#include "mic.h" // for

/* Standard IO includes */
#include <stdio.h> // for printf()

#include <unistd.h> //for sleep()

#include <signal.h>

#include <sys/time.h>

int is_running = 1;
uint16_t buffer [128];    //define buffer to store captures values

upm::Microphone *mic = NULL;    //create microphone object

/**
 * @brief sig_handler is the routine to catch kill signal events
 *
 * It performs following tasks:
 * 1. It gets called upon kill signal received (Ctrl + C to stop program)
 * 2. Set flag to gracefully exit the program
 * 3. Exit
 *
 * Example usage: sig_handler() has to be installed to capture signal event
 * in another function (main)
 * @code{.c}
 * signal(SIGINT, sig_handler);
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

void sig_handler(int signo)
{
    printf("got signal\n");
    if (signo == SIGINT) {
        is_running = 0;
    }
}

/**
 * @brief Main function for sound sensor example
 *
 * It performs following tasks:
 * 1. Install signal handler to catch kill signal
 * 2. Creates an instance Mic of class Microphone using UPM.
 * 3. Take a sample every 2 microseconds; find the average of 128 samples
 * 4. Print a running graph of the averages
 *
 * Example usage:
 * @code{.c}
 * int main(void)
 * @endcode
 *
 * @param void This function does not take any input parameter.
 * @return Returns 0.
 *
 * @see http://iotdk.intel.com/docs/master/upm/classupm_1_1_microphone.html
 *
 * @note UPM library has dependency on MRAA library functions.
 *
 * @warning None.
 */

int main(int argc, char **argv)
{
    // Attach microphone to analog port A0
    mic = new upm::Microphone(0);

    if (signal(SIGINT, sig_handler) == SIG_ERR)
          printf("\ncan't catch SIGINT\n");

    thresholdContext ctx;
    ctx.averageReading = 0;
    ctx.runningAverage = 0;
    ctx.averagedOver   = 2;

    // Infinite loop, ends when program is cancelled
    // Repeatedly, take a sample every 2 microseconds;
    // find the average of 128 samples; and
    // print a running graph of the averages
    while (is_running) {
        int len = mic->getSampledWindow (2, 128, buffer);
        if (len) {
            int thresh = mic->findThreshold (&ctx, 30, buffer, len);
            mic->printGraph(&ctx);

            if (thresh) {
                // do something ....
            }
        }
    }
    printf ("exiting application\n");
    delete mic;
    return 0;

}
