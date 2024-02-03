/**
* @file LCD.cpp
* @brief  Demonstrate how to use the 16x2 LCD with RGB backlight connected to
*  Intel Galileo board using UPM library
*
* LCD module used here is JHD1313M1 which has an I2C controller for the 16x2
* LCD and an RGB backlight LED controller PCA9633 also I2C based. Hence the
* module has two I2C addresses: one belongs to LCD controller that controls the
* HD44780-based display, and the other controls only the backlight.
*
* @note Grove LCD RGB Backlight module needs to be connected to Galileo Arduino
*  via base shield's I2C port.
* @note Grove LCD needs 5V to operate normally, ensure Grove shield switch
* is set to 5V
* @note Galileo has an exposed I2C bus = 0 and I2C addresses:
* LCD controller = 0x3E ; RGB LED = 0x62.
* @note Additional linker flags: "upm-i2clcd".
*
* @see http://iotdk.intel.com/docs/master/upm/
* @see https://software.intel.com/en-us/iot/hardware/sensors/jhd1313m1-display
* @see http://www.seeedstudio.com/wiki/Grove_-_LCD_RGB_Backlight
* @see http://www.seeedstudio.com/wiki/images/0/03/JHD1214Y_YG_1.0.pdf
* @see http://www.seeedstudio.com/wiki/images/1/1c/PCA9633.pdf
*
* @bug No known bugs
*
*/
/* -- Includes -- */

/* UPM library includes */
#include "jhd1313m1.h"

/*for
	lcd->setCursor();
    lcd->write();
    lcd->setCursor();
    lcd->setColor();
 */

/* Standard IO includes */
#include <stdio.h> // for printf()

#include <unistd.h> //for sleep()


/**
 * @brief Main function for printing text on LCD and changing backlight colors
 *
 * It performs following tasks:
 * 1. Creates an instance lcd of class Jhd1313m1 using UPM.
 * 2. Set cursor position
 * 3. Print text
 * 4. Enter loop to toggle backlight color between Red->Green->Blue at
 * intervals of 1 second.
 *
 * Example usage:
 * @code{.c}
 * int main(void)
 * @endcode
 *
 * @param void This function does not take any input parameter.
 * @return Returns 0.
 *
 * @see http://iotdk.intel.com/docs/master/upm/classupm_1_1_jhd1313m1.html
 *
 * @note UPM library has dependency on MRAA library functions.
 *
 * @warning None.
 */

int main(void)
{
    // 0x62 RGB_ADDRESS, 0x3E LCD_ADDRESS
	upm::Jhd1313m1 *lcd;
    lcd = new upm::Jhd1313m1(0, 0x3E, 0x62); //Create lcd instance
    //arguments: I2C addresses of LCD controller and LED backlight controller

    printf("Display text on LCD\n");

    lcd->setCursor(0,0);	//bring cursor to top left corner
    lcd->write("Hello world");	//print text
    lcd->setCursor(2,2);	//bring cursor to second row
    lcd->write("");	//print text

    printf("Sleeping for 5 seconds\n");
    sleep(3);
    printf("Starting Color loop...\n");

    //Run loop for toggling backlight color between Red->Green->Blue x 5 times
    for (int i = 3; i>0 ;i--){
    lcd->setColor(255,0,0);	//set backlight color to Red
    sleep(1);
    lcd->setColor(0,255,0);	//set backlight color to Green
    sleep(1);
    lcd->setColor(0,0,255);	//set backlight color to Blue
    sleep(1);
    }

    printf("Exiting .. bbye!\n");

    delete lcd;	//free up memory.
    return 0;
}
