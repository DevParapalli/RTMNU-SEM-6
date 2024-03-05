#include "grove.h" //for light->name(), light->value()
#include <stdio.h> // for printf()
#include <unistd.h> //for sleep()

int main()
{
        upm::GroveLight* light = new upm::GroveLight(0);
        for (int i=5;i>0;i--) {
            printf(" Light value is %f which is roughly %d lux \n", light->raw_value(), light->value());
            fflush(stdout);
            sleep(1);
        }
        // Delete the light sensor object
        printf("Exiting .. bbye!");
        delete light;
}
