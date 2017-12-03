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

//	gpio trig1 = 23;
//	gpio echo1 = 24;

//	gpio trig2 = 27;
//	gpio echo2 = 22;

	ultrasonic u1, u2;

	ultrasonic_set_trig (&u1, 23);
	ultrasonic_set_echo (&u1, 24);
	ultrasonic_set_trig (&u2, 27);
	ultrasonic_set_echo (&u2, 22);


	float distance1, distance2;
	ultrasonic_stop (u1);
	ultrasonic_stop (u2);

	servo_reset ();

	printf("Setting up ultrasonic...\n");
	ultrasonic_setup (u1);
	ultrasonic_setup (u2);

	printf("Setting up servo...\n");
	servo_setup ();

	printf("System started!\n");
	while (1) {
		distance1 = ultrasonic_get_distance (u1);
		distance2 = ultrasonic_get_distance (u2);
		//printf("%.2f, %.2f\n", distance1, distance2);
		if ((distance1 < 20.0) && (distance2 < 20.0)) {
			printf("%s\n", "Opening the gate...");
			servo_set_angle(90);
			delay(3);
			printf("%s\n", "Closing the gate...");
			servo_set_angle(0);
		}
	}
	return 0;
}
