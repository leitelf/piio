/*
 * main.c
 *
 *  Created on: 28 de nov de 2017
 *      Author: luiz
 */

#include "src/gpio.h"
#include "src/ultrasonic.h"

int main (int argc, char **argv)
{
	gpio trig, echo;

	trig = 23;
	echo = 24;


	ultrasonic_stop(trig, echo);

	if (!ultrasonic_setup(trig, echo)) {
		printf("ERROR: failed to setup ultrasonic\n");
		return 0;
	}
	if (gpio_access(trig) || gpio_access(echo)) {
		printf("%s\n", "failed");
		return -1;
	}
	/*while(true) {
		printf("%f\n", ultrasonic_get_distance(trig, echo));
	}*/
	printf("%s\n", "read problem");
	return 0;
}
