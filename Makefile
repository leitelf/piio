all: ultrasonic servo main

main: main.c
	gcc main.c -o ./build/main

ultrasonic: setup_ultrasonic.c
	gcc ultrasonic.c -o ./build/ultrasonic

servo: servo.c
	gcc servo.c -o ./build/servo
