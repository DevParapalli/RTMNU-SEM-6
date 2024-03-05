# Practical 7: Light Sensor

Aim: To interface light sensor with Intel Galileo board and write a program to detect surrounding light intensity.

## Procedure

1. Connect the light sensor to the analog pin 0 of the Galileo board.
2. Connect the Galileo board to the computer using USB cable.
3. Use screen tool to connect the Galileo board to wifi and note its IP
4. Connect to Galileo board using Eclipse IDE.
5. Write a program to detect surrounding light intensity.
6. Compile and run the program on Galileo board as target.

## Program

```cpp
#include "grove.h" //for light->name(), light->value()
#include <stdio.h> // for printf()
#include <unistd.h> //for sleep()

int main()
{
        upm::GroveLight* light = new upm::GroveLight(0);
        for (int i=5;i>0;i--) {
            printf(" Light value is %f which is roughly %d lux \n", light->raw_value(), light->value());
            fflush(stdout);
            sleep(1);
        }
        // Delete the light sensor object
        printf("Exiting .. bbye!");
        delete light;
}

```
