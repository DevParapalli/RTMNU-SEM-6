# Practical 4: Buzzer

Aim: To interface buzzer with Galileo Board and write a program to buzz the buzzer at different frequencies.

## Theory

A buzzer is an electrical device that makes a loud buzzing or beeping sound when activated. It consists of a small speaker that vibrates or a metal bar that strikes against a contact to produce the sound.

Buzzers are commonly used in various applications, such as:

1. Alarms: Buzzers are used in smoke detectors, carbon monoxide detectors, and security systems to alert people of danger.
2. Timers: Buzzers are used in kitchen timers, countdown timers, and other devices to indicate the end of a set time.
3. Indicators: Buzzers are used in industrial equipment, machinery, and appliances to indicate a malfunction or to signal the completion of a task.
4. Games: Buzzers are used in game shows, quiz shows, and other interactive games to indicate a correct or incorrect answer.

---

Buzzers can be activated in various ways, such as through a manual switch, a timer, or a sensor. They can also be controlled through a microcontroller or a computer program.

When choosing a buzzer, it is important to consider the sound level, frequency, and power requirements. Some buzzers are designed for low-power applications, while others require more power to produce a loud sound. Additionally, some buzzers have adjustable volume controls, while others do not.

In summary, buzzers are versatile electrical devices that can be used in a wide range of applications. They are relatively inexpensive, easy to use, and can be controlled through various methods.

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
