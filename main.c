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
	gpio motor = 23;

	servo_stop (motor);

	if (!servo_setup(motor)) {
		printf("ERROR: failed to setup motor\n");
		return 0;
	}

	servo_set_angle (motor, 90);
	delay(3);
	servo_set_angle(motor, 0);

	servo_stop(motor);

	return 0;
}
