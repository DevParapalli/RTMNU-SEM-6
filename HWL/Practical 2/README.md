# EXPERIMENT NO 2

## AIM

To interface LED with Galileo board and program it to blink with 1 second interval.

## PROCEDURE

1. Pin 13 is connected to onboard LED.
2. Connect the Galileo board to the computer using USB cable.
3. Use screen tool to connect the Galileo board to wifi and note its IP
4. Connect to Galileo board using Eclipse IDE.
5. Write a program to blink LED with 1 second interval.
6. Compile and run the program on Galileo board as target.

## PROGRAM

```cpp
#include "mraa.h"
#include <stdio.h>

int main()
{
    mraa_gpio_context d_pin = NULL;
    d_pin = mraa_gpio_init(13);

    if (d_pin == NULL) {
        fprintf(stderr, "MRAA couldn't initialize GPIO, exiting");
        return MRAA_ERROR_UNSPECIFIED;
    }

    if (mraa_gpio_dir(d_pin, MRAA_GPIO_OUT) != MRAA_SUCCESS) {
        fprintf(stderr, "Can't set digital pin as output, exiting");
        return MRAA_ERROR_UNSPECIFIED;
    };

    for (int i=10;i>0;i--) {
        printf("LED OFF\n");
        mraa_gpio_write(d_pin, 0);
        sleep(1);
        printf("LED ON\n");
        mraa_gpio_write(d_pin, 1);
        sleep(1);
    }

    return MRAA_SUCCESS;
}
```

## CONCLUSION
