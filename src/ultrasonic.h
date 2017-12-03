/*
 * ultrasonic.h
 *
 *  Created on: 28 de nov de 2017
 *      Author: luiz
 */

#ifndef SRC_ULTRASONIC_H_
#define SRC_ULTRASONIC_H_


#include "gpio.h"
#include <time.h>

typedef struct {
	gpio trig;
	gpio echo;
} ultrasonic;

void ultrasonic_set_trig (ultrasonic *u, gpio trig)
{
	u->trig = trig;
}

void ultrasonic_set_echo (ultrasonic *u, gpio echo)
{
	u->echo = echo;
}

bool ultrasonic_setup (ultrasonic u)
{
	if (gpio_setup(u.trig, OUTPUT)) {
		if (gpio_setup(u.echo, INPUT)) {
			return true;
		}
	}

	gpio_reset(u.trig);
	gpio_reset(u.echo);

	return false;
}

bool ultrasonic_stop (ultrasonic u)
{
	if (gpio_reset(u.trig) && gpio_reset(u.echo))
		return true;
	return false;
}

double ultrasonic_get_distance (ultrasonic u)
{

	clock_t pulse_start=1, pulse_end=1;
	float distance;

	if(gpio_access(u.trig) || gpio_access(u.echo)) {
		printf("ERROR: trig or echo not setted up.\n");
		return 0;
	}
	gpio_set_val(u.trig, HIGH);
	mdelay(0.01);
	gpio_set_val(u.trig, LOW);

	while (gpio_get_val(u.echo) == LOW) {
		pulse_start = clock();
	}

	while (gpio_get_val(u.echo) == HIGH) {
		pulse_end = clock();
	}


	return ((float) (pulse_end-pulse_start)*17150/CLOCKS_PER_SEC);
}


#endif /* SRC_ULTRASONIC_H_ */
