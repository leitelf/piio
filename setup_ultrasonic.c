#include "src/ultrasonic.h"
#include "src/gpio.h"

int main (int argc, char **argv)
{
  gpio trig = atoi (argv[1]);
  gpio echo = atoi (argv[2]);

  float distance = 0;

  ultrasonic_setup (trig, echo);

  return 0;
}
