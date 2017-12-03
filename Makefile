all: setup_ultrasonic main

main: main.c
	gcc main.c -o ./build/main
setup_ultrasonic: setup_ultrasonic.c
	gcc setup_ultrasonic.c -o ./build/setup_ultrasonic
