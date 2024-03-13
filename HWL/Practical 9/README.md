# Practical 9: LCD Display

Aim: To interface LCD with Intel Galileo board and write a program to display any text.

## Theory

An LCD (Liquid Crystal Display) is a type of flat panel display that uses liquid crystals to create images and text. LCDs are commonly used in a variety of applications, including IoT (Internet of Things) devices and projects that use microcontrollers.

In the context of IoT and microcontrollers, LCD displays are often used to provide a visual interface for users to interact with and receive information from the device. For example, an LCD display might be used on a smart home device to show the current temperature, or on a home security system to display the status of the system.

LCD displays can be connected to a microcontroller using a variety of communication protocols, including I2C (Inter-Integrated Circuit). I2C is a two-wire communication protocol that allows multiple low-speed devices to be connected to a microcontroller using only two data lines. This makes it a popular choice for connections in IoT applications.

## Procedure

1. Connect the LCD to the I2C port of the Galileo board.
2. Connect the Galileo board to the computer using USB cable.
3. Use screen tool to connect the Galileo board to wifi and note its IP
4. Connect to Galileo board using Eclipse IDE.
5. Write a program to display any text on LCD.
6. Compile and run the program on Galileo board as target.

## Program

```cpp
#include "jhd1313m1.h"
/*for
    lcd->setCursor();
    lcd->write();
    lcd->setCursor();
    lcd->setColor();
 */
#include <stdio.h> // for printf()
#include <unistd.h> //for sleep()

int main(void)
{
    // 0x62 RGB_ADDRESS, 0x3E LCD_ADDRESS
    upm::Jhd1313m1 *lcd;
    lcd = new upm::Jhd1313m1(0, 0x3E, 0x62);
    //arguments: I2C addresses of LCD controller and LED backlight controller

    printf("Display text on LCD\n");

    lcd->setCursor(0,0);    //bring cursor to top left corner
    lcd->write("23: Rohini");    //print text
    lcd->setCursor(1,0);    //bring cursor to second row
    lcd->write("35: Devansh");    //print text

    printf("Sleeping for 10 seconds\n");
    sleep(10);
    printf("Starting Color loop...\n");

    //Run loop for toggling backlight color between Red->Green->Blue x 5 times
    for (int i = 5; i>0 ;i--){
    lcd->setColor(255,0,0);   
    sleep(1);
    lcd->setColor(0,255,0);    
    sleep(1);
    lcd->setColor(0,0,255);  
    sleep(1);
    }

    printf("Exiting .. bbye!\n");

    delete lcd;  
    return 0;
}

```
