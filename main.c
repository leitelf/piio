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

	gpio trig1 = 23;
	gpio echo1 = 24;

	gpio trig2 = 2;
	gpio echo2 = 3;

	float distance1, distance2;

	ultrasonic_stop (trig1, echo1);
	ultrasonic_stop (trig2, echo2);

	servo_reset ();

	ultrasonic_setup (trig1, echo1);
	ultrasonic_setup (trig2, echo2);

	servo_setup ();

	while (true) {
		distance1 = ultrasonic_get_distance (trig1, echo1);
		distance2 = ultrasonic_get_distance (trig2, echo2);

		if (distance1 < 20.0) && (distance2 < 20.0) {
			printf("%s\n", "Opening the gate...");
			servo_set_angle(90);
			delay(3);
			printf("%s\n", "Closing the gate...");
			servo_set_angle(0);
		}
	}
	return 0;
}
