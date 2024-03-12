# Practical 5: Temperature

Aim: To interface temperature sensor with Intel Galileo board and write a program to print temperature readings.

## Theory

A temperature sensor is an electronic device that measures the temperature of its surrounding environment or a specific object and converts it into an electrical signal. There are several types of temperature sensors, including:

1. Thermocouples: These sensors consist of two different metals that are joined together. When the temperature changes, a voltage is generated between the two metals, which can be measured and converted into a temperature reading.
2. Resistive Temperature Detectors (RTDs): These sensors use a coil of fine wire, usually platinum, that changes resistance as the temperature changes. The resistance is measured and converted into a temperature reading.
3. Thermistors: These sensors are made of a ceramic material that changes resistance as the temperature changes. Thermistors are very accurate and are commonly used in applications where precise temperature measurement is required.
4. Infrared Temperature Sensors: These sensors measure the infrared energy emitted by an object and convert it into a temperature reading. These sensors are commonly used in non-contact temperature measurement applications.

---

Temperature sensors are used in a wide range of applications, including:

1. Industrial Process Control: Temperature sensors are used in various industrial processes, such as chemical manufacturing, food processing, and pharmaceuticals, to control and monitor temperature.
2. HVAC Systems: Temperature sensors are used in heating, ventilation, and air conditioning systems to control temperature and ensure occupant comfort.
3. Medical Devices: Temperature sensors are used in medical devices, such as thermometers, incubators, and patient monitoring systems, to measure body temperature.
4. Automotive Applications: Temperature sensors are used in automotive applications, such as engine management systems, to monitor and control temperature.

When choosing a temperature sensor, it is important to consider the temperature range, accuracy, response time, and environmental factors, such as humidity and vibration. Additionally, the sensor should be calibrated and tested to ensure accurate temperature measurement.

## Procedure

1. Connect the temperature sensor to the analog pin 0 of the Galileo board.
2. Connect the Galileo board to the computer using USB cable.
3. Use screen tool to connect the Galileo board to wifi and note its IP
4. Connect to Galileo board using Eclipse IDE.
5. Write a program to print temperature readings.
6. Compile and run the program on Galileo board as target.

## Program

```cpp
#include "mraa/aio.h" //for mraa_aio_read()
#include <math.h> // for math functions
#include <stdio.h> // for printf()
#include <unistd.h> //for sleep()

int main()
{
    mraa_aio_context adc_a0;
    uint16_t adc_value = 0;

    const int B=4275;                 // B value of the thermistor
    const int R0 = 100000;            // R0 = 100k

    adc_a0 = mraa_aio_init(0);

    if (adc_a0 == NULL) {
        return 1;
    }
    for (int i=5; i>0;i--) {
        adc_value = mraa_aio_read(adc_a0); //Max value @ 5V = 1024
        printf("ADC A0 read value : %d\n", adc_value);

        float R = 1023.0/((float)adc_value)-1.0;
        R = 100000.0*R;
        float temperature=1.0/(log(R/100000.0)/B+1/298.15)-273.15; //convert to temperature as per datasheet

        printf("Temperature value : %.2f Degree Celsius\n", temperature);

        sleep(1);
    }
    mraa_aio_close(adc_a0);
    printf("Exiting .. Bbye!");
    return MRAA_SUCCESS;
}

```
