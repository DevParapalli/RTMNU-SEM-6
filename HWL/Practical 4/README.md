# Practical 4: Buzzer

Aim: To interface buzzer with Galileo Board and write a program to buzz the buzzer at different frequencies.

## Procedure

1. Connect the buzzer to the Galileo board using port D5.
2. Connect to the board in Eclipse IDE.
3. Write the program given below
4. Execute the program on target.

## Program

```cpp
#include <buzzer.hpp>
#include <stdio.h>
#include <unistd.h> 

int main() {
    int chord[] = {DO, RE, MI, FA, SOL, LA, SI, DO, SI};
    upm::Buzzer* sound = new upm::Buzzer(5);
    printf("Volume = %f\n", sound->getVolume());
    sound->setVolume(0.1);
    printf("Volume = %f\n", sound->getVolume());
    fflush(stdout);
    printf("\nPlaying notes, pausing for 0.1 seconds between notes...\n");
    fflush(stdout);
    for (int chord_ind = 0; chord_ind < 7; chord_ind++) {
        printf(" %d\n", sound->playSound(chord[chord_ind], 500000));
        usleep(100000);
    }
    printf("Exiting, bbye!\n");
    delete sound;
}
```
