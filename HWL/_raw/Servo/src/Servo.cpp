
/**
* @file Servo.cpp
* @brief  Demonstrate how to use the Servo connected to Intel Galileo board
*  using UPM library
*
* The Grove - Servo is DC motor with gearing and feedback system. It is a
* fun motion control device that can be located at any position between 0 to
* 180 degrees. With 4 shafts in different shapes, this Servo is ready to drive
* a small fan, lift an object, or mimic a clock hand.
*
* @note ES08A Servo motor needs to be connected to the Galileo Arduino via base
* shield D5.
* @note Galileo's Digital IO 5 PWM output is used to signal the servo.
* @note Additional linker flags: "upm-servo".
*
* @see http://iotdk.intel.com/docs/master/upm/
* @see https://software.intel.com/en-us/iot/hardware/sensors/es08a-servo
* @see https://software.intel.com/en-us/creating-an-app-that-rotates-a-servo-motor
* @see http://www.seeedstudio.com/wiki/Grove_-_Servo
* @see http://www.emaxmodel.com/es08a-ii.html
*
* @bug No known bugs
*
*/
/* -- Includes -- */

/* UPM library includes */
#include "es08a.h" //for servo->setAngle()

/* Standard IO includes */
#include <stdio.h> // for printf()

#include <unistd.h> //for sleep()


/**
 * @brief Main function for Servo control example
 *
 * It performs following tasks:
 * 1. Creates an instance servo of class ES08A using UPM.
 * 2. Sets up different angles for servo shaft using setAngle() function
 * 4. Enter infinite loop to toggle the on board LED as below:
 *
 *    Sets the shaft to 180, then to 90, then to 0,
 *    then back to 90, and finally back to 180,
 *    pausing for a second in between each angle
 *
 * Example usage:
 * @code{.c}
 * int main(void)
 * @endcode
 *
 * @param void This function does not take any input parameter.
 * @return Returns 0.
 *
 * @see http://iotdk.intel.com/docs/master/upm/classupm_1_1_e_s08_a.html
 *
 * @note UPM library has dependency on MRAA library functions.
 *
 * @warning None.
 */

int main()
{
    upm::ES08A *servo = new upm::ES08A(5);

    // Sets the shaft to 180, then to 90, then to 0,
    // then back to 90, and finally back to 180,
    // pausing for a second in between each angle
    servo->setAngle (30);
    printf("Set angle to 180\n");

    sleep(1);

    servo->setAngle (60);
    printf("Set angle to 90\n");

    sleep(1);

    servo->setAngle (90);
    printf("Set angle to 0\n");

    sleep(1);

    servo->setAngle (120);
    printf("Set angle to 90\n");

    sleep(1);

    servo->setAngle (180);
    printf("Set angle to 180\n");

    printf("exiting application\n");

    delete servo;
    return 0;
}
