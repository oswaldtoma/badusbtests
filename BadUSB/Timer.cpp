#include "Timer.h"
#include "Arduino.h"

Timer::Timer()
{
	startMillis = 0;
}

void Timer::start(uint32_t miliseconds)
{
	duration = miliseconds;
	startMillis = millis();
}

bool Timer::isZero()
{
	return millis() > (startMillis + duration);
}
