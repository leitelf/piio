#include "src/ultrasonic.h"
#include "srv/gpio.h"

int main (int argc, char **argv)
{
  gpio trig = atoi (arg[1]);
  gpio echo = atoi (arg[2]);

  float distance = 0;

  ultrasonic_setup (trig, echo);
  
  return 0;
}
