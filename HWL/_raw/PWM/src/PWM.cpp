/**
* @file PWM.cpp
* @brief Demonstrate how to generate a PWM signal using mraa lib
*
* PWM class is the Pulse Width Modulation interface to libmraa. It allows the
* generation of a PWM signal on a Digital I/O pin. Connecting the LED interface
* to this digital IO will make it glow with varying intensity. One can also
* connect an oscilloscope to observe the PWM signal with varying duty-cycle
*
* @note To verify PWM signal, you can connect an Oscilloscope to the digital
* output pin 3 - D3, or even an LED using the provided LED breakout board
* @note Additional linker flags: None.
*
* @see http://iotdk.intel.com/docs/master/mraa/pwm_8h.html
*
* @bug Freq seems to be fixed at 224.2 Hz, mraa_pwm_period() is not able to change the freq.
*
*/
/* -- Includes -- */
#include "mraa.h"
/* Standard IO includes */
#include <stdio.h> // for printf()

#include <unistd.h> //for sleep()

/**
 * @brief Main function for PWM generation
 *
 * It performs following tasks:
 * 1. Creates an instance pwm of class PWM using mraa lib.
 * 2. Configures the PWM signal period and starts PWM
 * 3. Enters a loop to increase the duty cycle from 0 to 100 (0 to 1.00) in increments of 1%
 * 4. Above loop exits after 5 cycles of varying the duty cycle
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

int main(){
     mraa_pwm_context pwm;
     pwm = mraa_pwm_init(3);

     if (pwm == NULL) {
            return 1;
        }

     mraa_pwm_period_us(pwm, 1);
     mraa_pwm_enable(pwm, 1);
     //Note: once enabled, PWM signal will continue to be generated until disabled,
     //even if program exits without disabling it. So make sure to disable it.

     printf("PWM signal ON\n");
     float value = 0.0f;
     //mraa_pwm_write(pwm, 0.5); //generate 50% duty cycle

     //Loop increases the duty cycle of the PWM signal from 0 to 100 in increments
     //of 1% then resets to 0. Loop runs for 5 cycles.

     printf("Increase PWM duty cycle from 1-100 in increments of 1%, repeat 5 times.. \n");
     for(int cycle = 5; cycle>0; ) {
         value = value + 0.01f;
         mraa_pwm_write(pwm, value);
         usleep(50000);

         if (value >= 1.0f) {
                value = 0.0f;
                cycle --;
            }
        }

     mraa_pwm_enable(pwm, 0); //disable PWM signal
     printf("PWM signal OFF\n");
     delete pwm;
     printf("Exiting .. Bbye!\n");
     return 1;
}
