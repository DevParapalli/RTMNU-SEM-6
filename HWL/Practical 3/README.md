# EXPERIMENT NO 3

## AIM

To interface push button and LED with Intel Galileo board and write program to turn on LED when push button is pressed.

## TOOLS

1. IOT 3500 Development Kit
    1. Intel Galileo Board
    2. Push Button Module
    3. LED Module

## PROCEDURE

## PROGRAM

```cpp
#include "mraa.h"
#include <stdio.h>
#include <unistd.h>

#define BUTTON_PIN 2
#define LED_PIN 3

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
