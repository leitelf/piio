/*
 * servo.h
 *
 *  Created on: 28 de nov de 2017
 *      Author: luiz
 */

#ifndef SRC_SERVO_H_
#define SRC_SERVO_H_


#include "gpio.h"
#include "pwm.h"
#include <time.h>
#include <unistd.h>

bool servo_setup ()
{
	return pwm_setup(100.0);
}

void servo_set_angle (float angle)
{
  float duty_cycle = (angle / 180 + 1)*5.0;
  pwm_set_duty_cycle (duty_cycle);
	pwm_start();
	sleep(3);
	pwm_stop();
	pwm_set_duty_cycle (0.0);
}


bool servo_reset ()
{
	return pwm_reset();
}
#endif /* SRC_SERVO_H_ */
