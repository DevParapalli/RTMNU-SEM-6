# EXPERIMENT NO 3

## AIM

To interface push button and LED with Intel Galileo board and write program to turn on LED when push button is pressed.

## TOOLS

1. IOT 3500 Development Kit
    1. Intel Galileo Board
    2. Push Button Module
    3. LED Module

## PROCEDURE

1. Connect the push button module to the digital pin 2 of the Galileo board. Pin 13 is connected to onboard LED.
2. Connect the Galileo board to the computer using USB cable.
3. Use screen tool to connect the Galileo board to wifi and note its IP
4. Connect to Galileo board using Eclipse IDE.
5. Write a program to turn on LED when push button is pressed.
6. Compile and run the program on Galileo board as target.

## PROGRAM

```cpp
#include "mraa.h"
#include <stdio.h>
#include <unistd.h>

#define BUTTON_PIN 2
#define LED_PIN 13

int main()
{
    mraa_init();
    mraa_gpio_context button = mraa_gpio_init(BUTTON_PIN);
    mraa_gpio_dir(button, MRAA_GPIO_IN);

    mraa_gpio_context led = mraa_gpio_init(LED_PIN);
    mraa_gpio_dir(led, MRAA_GPIO_OUT);

    for(;;) {
        if (mraa_gpio_read(button)) mraa_gpio_write(led, 1);
        else mraa_gpio_write(led, 0);
        usleep(100000);
    }

    mraa_gpio_close(led);
    mraa_gpio_close(button);
    mraa_deinit();
    
    return MRAA_SUCCESS;
}
```

## CONCLUSION
