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
