# Practical 6: Touch Sensor

Aim: To interface touch sensor with Intel Galileo board and write a program to sense finger when placed on sensor.

## Theory

A touch sensor is an electronic device that can detect the presence and location of a touch or near-touch by a user. It converts the mechanical stress from the touch into an electrical signal that can be processed and interpreted by electronic devices. Touch sensors are widely used in various applications such as smartphones, tablets, automotive controls, and home appliances to provide a friendly control scheme and interface.

## Procedure

1. Connect the touch sensor to the digital pin 4 of the Galileo board.
2. Connect the Galileo board to the computer using USB cable.
3. Use screen tool to connect the Galileo board to wifi and note its IP
4. Connect to Galileo board using Eclipse IDE.
5. Write a program to sense finger when placed on touch sensor.
6. Compile and run the program on Galileo board as target.

## Program

```cpp
#include "ttp223.h" // for button->value()
#include <stdio.h> // for printf()
#include <unistd.h> //for sleep()

void touchISR (void*);
int count = 3;

void touchISR(void*)
{
    count--;
    printf("\nHello World from ISR, will exit after %d touch events", count);
    fflush(stdout);
}

int main()
{
    upm::TTP223* touch = new upm::TTP223(4);
    touch->installISR(mraa::EDGE_FALLING, &touchISR, NULL);

    printf("\nWelcome, waiting for touch event.\nWill exit after 5 events");
    fflush(stdout);

    while(count>0);
    
    printf("\nExiting .. Bbye!");
    delete touch;   
    return MRAA_SUCCESS;
}
```
