#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>

#define GPIO_PIN 0          // Define GPIO pin (using wiringPi numbering, pin 1 = GPIO18 on Pi)
#define PULSE_DURATION 100  // Pulse duration in milliseconds
#define INTERVAL 500        // Interval between pulses in milliseconds

int main()
{
    if (wiringPiSetup() == -1) {
        fprintf(stderr, "wiringPi setup failed\n");
        return 1;
    }

    pinMode(GPIO_PIN, OUTPUT); // Set GPIO as output

    while (1) {
        digitalWrite(GPIO_PIN, HIGH); // Set GPIO high
        delay(PULSE_DURATION); // Hold high for the pulse duration

        digitalWrite(GPIO_PIN, LOW); // Set GPIO low
        delay(INTERVAL - PULSE_DURATION); // Delay for the rest of the interval
    }

    return 0;
}
