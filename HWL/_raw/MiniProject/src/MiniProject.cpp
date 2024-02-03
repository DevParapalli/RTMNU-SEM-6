/**
* @file MiniProject.cpp
* @brief  Demonstrate how to combine some sensors and outputs to make a mini Project
*
* LCD module used here is JHD1313M1 which has an I2C controller for the 16x2
* LCD and an RGB backlight LED controller PCA9633 also I2C based. Hence the
* module has two I2C addresses: one belongs to LCD controller that controls the
* HD44780-based display, and the other controls only the backlight.
*
* main() function initializes all objects and calls screen_welcome(). Then
* enters while loop.
* sreen_welcome() function prints welcome message on LCD using various functions
* provided by the lcd class.
* buttonISR() is called upon button press. This function updates the count and
* reads latest light values using light_sensor->value() & light_sensor->raw_value()
* and finally calls screen_update().
* screen_update() prints light values on the LCD screen and plays a tone using
* buzzer
*
* @note Grove LCD RGB Backlight module needs to be connected to Galileo Arduino
*  via base shield's I2C port.
* @note Galileo has an exposed I2C bus = 0 and I2C addresses:
* LCD controller = 0x3E ; RGB LED = 0x62.
* @note grovebuzzer needs to be connected to the Galileo Arduino via base
* shield at D5.
* @note grovelight sensor needs to be connected to the Galileo Arduino via base
* shield analog port A0.
* @note grovebutton sensor needs to be connected to the Galileo Arduino via base
* shield at digital input D4.
*
* @note Additional linker flags: "upm-i2clcd", "upm-buzzer", "upm-grove".
*
* @see http://iotdk.intel.com/docs/master/upm/
* @see https://software.intel.com/en-us/iot/hardware/sensors/jhd1313m1-display
* @see http://www.seeedstudio.com/wiki/Grove_-_LCD_RGB_Backlight
* @see http://www.seeedstudio.com/wiki/images/0/03/JHD1214Y_YG_1.0.pdf
* @see http://www.seeedstudio.com/wiki/images/1/1c/PCA9633.pdf
*
* @bug screen_exit function not working properly, commented for now
*
**/
//=============================================================================
//                           Includes
//=============================================================================


/* UPM library includes */
#include <jhd1313m1.h>

/*for
	lcd->setCursor();
    lcd->write();
    lcd->setCursor();
    lcd->setColor();
 */

#include <grove.hpp> //for light->name(), light->value()

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
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdio.h>

/* Local Includes */
#include "colors.h"	// for predefined color values

//=============================================================================


//=============================================================================
//                           Function Prototypes
//=============================================================================
void buttonISR (void*);

int screen_update(
		float,
		int,
		struct color,
		int
		);

int screen_welcome();
//=============================================================================

//=============================================================================
//                           File scope variables
//=============================================================================
int count = 0;  int i = 0;
color col = green;
upm::GroveLight* light_sensor;
upm::Jhd1313m1 *lcd;
upm::Buzzer* buzz;
//=============================================================================

/**
 * @brief screen_welcome function
 *
 * It performs following tasks:
 * 1. Print welcome message
 *
 * Example usage:
 * @code{.c}
 * screen_welcome(void)
 * @endcode
 *
 * @param void This function does not take any input parameter.
 * @return Returns 1.
 *
 * @note UPM library has dependency on MRAA library functions.
 *
 * @warning None.
 */

int screen_welcome()
{

	std::stringstream row_1, row_2; // LCD rows

	row_1 << "Hi, Press button" ;
	row_2 << "to update Light." ;


	//display on LCD
	lcd->clear();
	lcd->setColor(col.r, col.g, col.b);
	//display row 1
	lcd->setCursor(0,0);
	lcd->write(row_1.str());

	//display row 2
	lcd->setCursor(1,0);
	lcd->write(row_2.str());

return 1;
}


/**
 * @brief screen_exit function
 *
 * It performs following tasks:
 * 1. Print exit message
 * 2. Wait 3 seconds
 * 3. return 1
 *
 * Example usage:
 * @code{.c}
 * screen_exit(void)
 * @endcode
 *
 * @param void This function does not take any input parameter.
 * @return Returns 1.
 *
 * @note UPM library has dependency on MRAA library functions.
 *
 * @warning None.
 */

int screen_exit()
{

	std::stringstream row_1, row_2; // LCD rows

	row_1 << "5 chances over.." ;
	row_2 << "Bye Bye !" ;


	//display on LCD
	lcd->clear();
	lcd->setColor(col.r, col.g, col.b);
	//display row 1
	lcd->setCursor(0,0);
	lcd->write(row_1.str());

	//display row 2
	lcd->setCursor(1,0);
	lcd->write(row_2.str());

	sleep(3);

return 1;
}

/**
 * @brief screen_update function
 *
 * It performs following tasks:
 * 1. creates print string
 * 2. clears lcd screen
 * 3. sets cursor position
 * 4. prints light valuess
 *
 * Example usage:
 * @code{.c}
 * screen_update(light_sensor->raw_value(), light_sensor->value(), col, 0);
 * @endcode
 *
 * @param void This function does not take any input parameter.
 * @return Returns 1.
 *
 * @note UPM library has dependency on MRAA library functions.
 *
 * @warning None.
 */

int screen_update(
		float light_raw,
		int light_lux,
		struct color col,
		int verbose
		){

	std::stringstream row_1, row_2; // LCD rows

	if (verbose){
		printf("Light Raw = %f\n", light_raw);
		printf("Light Lux = %d\n", light_lux);
	}

	row_1 << "Light Raw  " << std::setprecision(4) << light_raw;
	row_2 << "Light Lux  " << std::setprecision(4) << light_lux;


	//display on LCD
	lcd->clear();
	lcd->setColor(col.r, col.g, col.b);
	//display row 1
	lcd->setCursor(0,0);
	lcd->write(row_1.str());

	//display row 2
	lcd->setCursor(1,0);
	lcd->write(row_2.str());

	buzz->playSound(1000, 50000);

return 1;
}

/**
 * @brief ISR function triggered by button press
 *
 * It performs following tasks:
 * 1. update count
 * 2. toggle screen color
 * 3. read light sensor values
 * 4. update screen
 * 5. play a short beep to notify action done
 *
 * Example usage:
 * ISR will be called when events occur, it has to be registered
 * for button press event by another function (main)
 * @code{.c}
 * button->installISR(mraa::EDGE_FALLING, &buttonISR, NULL);
 * @endcode
 *
 * @param void This function does not take any input parameter.
 * @return Returns none.
 *
 * @note UPM library has dependency on MRAA library functions.
 *
 * @warning None.
 */

void buttonISR(void*)
{
	count++; //1. update count
	//printf("\nHello World from ISR %d", count);
	//fflush(stdout);

	//2. toggle color between yellow and green
	col = i ? green: yellow; i= i ? 0:1;

    //3. Get light sensor values and update screen
	printf("Button pressed, read light sensor and update screen\n");
    screen_update(light_sensor->raw_value(), light_sensor->value(), col, 0);
}


/**
 * @brief Main function does initializations, installs ISR, enters loop
 *
 * It performs following tasks:
 * 1. Create instance light_sensor of class Grive Light using UPM
 * 2. Create an instance lcd of class Jhd1313m1 using UPM.
 * 3. Create instance button of class Grove Button using UPM
 * 4. Install ISR for button press action
 * 5. Create instance of Buzzer and set volume
 * 6. Print welcome message on LCD
 * 7. Enter while loop till interrupt count reaches 6
 * 8. Delete all objects to free up memory and exit
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
    //Init Light sensor
	  // Create the light sensor object using AIO pin 0
	 light_sensor = new upm::GroveLight(0);

	//Init LCD
	// 0x62 RGB_ADDRESS, 0x3E LCD_ADDRESS
    lcd = new upm::Jhd1313m1(0, 0x3E, 0x62); //Create lcd instance

    // Create the button object using GPIO pin 4
    upm::GroveButton* button = new upm::GroveButton(4);
    // Read the input and print, waiting one second between readings

    button->installISR(mraa::EDGE_FALLING, &buttonISR, NULL);

    // create Buzzer instance and initialize volume
    buzz = new upm::Buzzer(5);
    buzz->setVolume(0.1);

    printf("Press button to capture light values and update LCD\n");

    screen_welcome(); // print welcome message

    while(count<5);

    //screen_exit(); // print exit message //@@bug

    sleep(1);

    delete button;
    delete lcd;	//free up memory
    delete light_sensor;
    delete buzz;

    printf("Exiting .. bbye\n");

    return 0;
}
