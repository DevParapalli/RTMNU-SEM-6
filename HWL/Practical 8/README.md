# Practical 8: Sound Sensor

Aim: To interface sound sensor with Intel Galileo board and write a program to detect surrounding sound intensity.

## Theory

A sound sensor, often as a microphone, converts sound energy (vibrations in air pressure) into an electrical signal. This signal can then be processed or analyzed. The microphone, a type of sound sensor, is a transducer that converts sound waves into an electrical signal, which can then be amplified, transmitted, or recorded. The diaphragm in a microphone vibrates when sound waves hit it, causing a current to flow that corresponds to the sound's pressure, frequency, and amplitude.

## Procedure

1. Connect the sound sensor to the analog pin 0 of the Galileo board.
2. Connect the Galileo board to the computer using USB cable.
3. Use screen tool to connect the Galileo board to wifi and note its IP
4. Connect to Galileo board using Eclipse IDE.
5. Write a program to detect surrounding sound intensity.
6. Compile and run the program on Galileo board as target.

## Program

```cpp
#include "mic.h" // for
#include <stdio.h> // for printf()
#include <unistd.h> //for sleep()
#include <signal.h>
#include <sys/time.h>

int is_running = 1;
uint16_t buffer [128];    
upm::Microphone *mic = NULL;   

void sig_handler(int signo)
{
    printf("got signal\n");
    if (signo == SIGINT) {
        is_running = 0;
    }
}

int main(int argc, char **argv)
{
    mic = new upm::Microphone(0);

    if (signal(SIGINT, sig_handler) == SIG_ERR)
          printf("\ncan't catch SIGINT\n");

    thresholdContext ctx;
    ctx.averageReading = 0;
    ctx.runningAverage = 0;
    ctx.averagedOver   = 2;

    while (is_running) {
        int len = mic->getSampledWindow (2, 128, buffer);
        if (len) {
            int thresh = mic->findThreshold (&ctx, 30, buffer, len);
            mic->printGraph(&ctx);

            if (thresh) {
                // do something ....
            }
        }
    }
    printf ("exiting application\n");
    delete mic;
    return 0;

}


```
