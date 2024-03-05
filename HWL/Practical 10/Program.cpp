#include "grove.h" // for button->value()
#include <stdio.h> // for printf()
#include <unistd.h> //for sleep()

int main()
{
        upm::GroveRotary* knob = new upm::GroveRotary(1);
    while( 1 ) {
            float abs_value = knob->abs_value(); // Absolute raw value
            float abs_deg = knob->abs_deg();     // Absolute degrees
            float abs_rad = knob->abs_rad();     // Absolute radians
            float rel_value = knob->rel_value(); // Relative raw value
            float rel_deg = knob->rel_deg();     // Relative degrees
            float rel_rad = knob->rel_rad();     // Relative radians
            printf("Absolute: %4d raw %5.2f deg = %3.2f rad Relative: %4d raw %5.2f deg %3.2f rad\n",
                    (int16_t)abs_value, abs_deg, abs_rad, (int16_t)rel_value, rel_deg, rel_rad);
            sleep(1);
        }
    delete knob;
    return MRAA_SUCCESS;
}
