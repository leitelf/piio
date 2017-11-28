/*
 * servo.h
 *
 *  Created on: 28 de nov de 2017
 *      Author: luiz
 */

#ifndef SRC_SERVO_H_
#define SRC_SERVO_H_


#include "gpio.h"
#include <time.h>

bool servo_setup (gpio pin)
{
	if (gpio_setup(pin, OUTPUT)) {
		return true;
	}

	gpio_reset(pin);

	return false;
}

void servo_set_angle (gpio pin, float angle)
{
  float duty_cycle = angle / 18 + 2;
  gpio_start_pwm (pin, 50.0, duty_cycle, 1);
  gpio_set_val (pin, LOW);
}

bool servo_stop (gpio pin)
{
  if (gpio_reset(pin)) {
    return true;
  }

  return false;
}

#endif /* SRC_SERVO_H_ */
