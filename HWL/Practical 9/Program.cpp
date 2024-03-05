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

    delete lcd;    //free up memory.
    return 0;
}
