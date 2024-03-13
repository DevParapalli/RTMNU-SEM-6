# Practical 10: Rotary Sensor

Aim: To interface Rotary Sensor with Intel Galileo board and write a program to display the rotation position.

## Theory

A Rotary Angle Sensor based on a potentiometer is a type of mechanical rotary angle sensor that measures the angular position of a shaft by converting the mechanical motion into an electrical signal using a potentiometer.

The potentiometer consists of a resistive element, usually a strip of conductive material, with a sliding contact or wiper that moves along the resistive element as the shaft rotates. The resistive element has a known resistance, and the voltage divider principle is used to measure the angular position of the shaft.

When the shaft rotates, the wiper moves along the resistive element, changing the resistance between the two ends of the potentiometer. The voltage at the wiper is proportional to the angular position of the shaft, and this voltage can be measured and converted to a digital signal using an analog-to-digital converter (ADC).

Potentiometer-based rotary angle sensors are relatively simple and inexpensive, making them a popular choice for many applications. However, they have some limitations, such as a lower resolution and accuracy compared to other types of rotary angle sensors. Additionally, potentiometer-based sensors can wear out over time due to the mechanical movement of the wiper, leading to reduced accuracy and reliability.

Potentiometer-based rotary angle sensors are commonly used in applications such as joysticks, volume controls, and position feedback systems. They are also used in industrial automation, robotics, and medical equipment. When selecting a potentiometer-based rotary angle sensor, it is essential to consider the application's specific requirements, such as the measurement range, resolution, accuracy, and environmental conditions.

## Procedure

1. Connect the Rotary Sensor to the A1 port of the Galileo board.
2. Connect the Galileo board to the computer using USB cable.
3. Use screen tool to connect the Galileo board to wifi and note its IP
4. Connect to Galileo board using Eclipse IDE.
5. Write a program to display the rotation position of the Rotary Sensor.
6. Compile and run the program on Galileo board as target.

## Program

```cpp
#include "grove.h" // for button->value()
#include <stdio.h> // for printf()
#include <unistd.h> //for sleep()

int main()
{
        upm::GroveRotary* knob = new upm::GroveRotary(1);
    while( 1 ) {
            float abs_value = knob->abs_value(); // Absolute raw value
            float abs_deg = knob->abs_deg();     // Absolute degrees
            float abs_rad = knob->abs_rad();     // Absolute radians
            float rel_value = knob->rel_value(); // Relative raw value
            float rel_deg = knob->rel_deg();     // Relative degrees
            float rel_rad = knob->rel_rad();     // Relative radians
            printf("Absolute: %4d raw %5.2f deg = %3.2f rad Relative: %4d raw %5.2f deg %3.2f rad\n",
                    (int16_t)abs_value, abs_deg, abs_rad, (int16_t)rel_value, rel_deg, rel_rad);
            sleep(1);
        }
    delete knob;
    return MRAA_SUCCESS;
}

```
