/*
 * main.c
 *
 *  Created on: 28 de nov de 2017
 *      Author: luiz
 */

#include "src/gpio.h"
#include "src/ultrasonic.h"
#include "src/servo.h"

int main (int argc, char **argv)
{

	servo_reset ();

	if (!servo_setup()) {
		printf("ERROR: failed to setup motor\n");
		return 0;
	}

	printf("%s\n", "rotate 90!");
	servo_set_angle (90.0);
	delay(3);
	printf("%s\n", "rotate 0!");
	servo_set_angle(0.0);
	delay(3);
	servo_reset();

	return 0;
}
