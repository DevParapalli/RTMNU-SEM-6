/**
* @file Temperature.cpp
* @brief  Demonstrate how to acquire Temperature values from the Grove Temperature sensor
*  connected to Intel Galileo board using UPM library
*
* The Grove - Temperature Sensor uses a Thermistor to detect the ambient temperature.
* The resistance of a thermistor will increase when the ambient temperature decreases.
* It's this characteristic that we use to calculate the ambient temperature.
* The detectable range of this sensor is -40 - 125ºC, and the accuracy is ±1.5ºC
*
* @note Grove Temperature sensor needs to be connected to the Galileo Arduino via base
* shield Analog IO pin A0
*
* @note Default reference voltage for ADC is 5V, so full scale deflection is at 5V
* @note Ensure base shield VCC switch is set to 5V for this experiment,
* hence 5V input = 1024 (10 bit)
*
* @see http://iotdk.intel.com/docs/master/mraa/aio_8h.html
* @see http://www.seeedstudio.com/wiki/Grove_-_Temperature_Sensor_V1.2
* @see http://www.seeedstudio.com/wiki/images/4/4f/Grove_-_Temperature_sensor_v1.1.pdf
* @see http://www.seeedstudio.com/wiki/images/a/a1/NCP18WF104F03RC.pdf

* @bug No known bugs
*
*/
/* -- Includes -- */

#include "mraa/aio.h" //for mraa_aio_read()

#include <math.h> // for math functions

/* Standard IO includes */
#include <stdio.h> // for printf()

#include <unistd.h> //for sleep()


/**
 * @brief Main function for temperature sensor example
 *
 * It performs following tasks:
 * 1. Create object of class analog input and initialize A0 pin for input
 * 2. Enter a loop to acquire analog input and convert to temperature values
 * then print 5 times at time intervals of 1 second.
 *
 * Example usage:
 * @code{.c}
 * int main(void)
 * @endcode
 *
 * @param void This function does not take any input parameter.
 * @return Returns 0.
 *
 * @see http://iotdk.intel.com/docs/master/mraa/aio_8h.html
 *
 * @warning None.
 */

int main()
{
    mraa_aio_context adc_a0;
    uint16_t adc_value = 0;

    const int B=4275;                 // B value of the thermistor
    const int R0 = 100000;            // R0 = 100k

    //create object of analog input class using mraa lib
    adc_a0 = mraa_aio_init(0);

    if (adc_a0 == NULL) {
        return 1;
    }
    for (int i=5; i>0;i--) {
        adc_value = mraa_aio_read(adc_a0); //Max value @ 5V = 1024
        printf("ADC A0 read value : %d\n", adc_value);

        float R = 1023.0/((float)adc_value)-1.0;
        R = 100000.0*R;
        float temperature=1.0/(log(R/100000.0)/B+1/298.15)-273.15;//convert to temperature as per datasheet ;

        printf("Temperature value : %.2f Degree Celsius\n", temperature);

        sleep(1);
    }
    mraa_aio_close(adc_a0);
    printf("Exiting .. Bbye!");
    return MRAA_SUCCESS;
}
