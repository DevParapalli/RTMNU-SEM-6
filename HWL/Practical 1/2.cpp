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
