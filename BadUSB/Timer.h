// Timer.h

#ifndef _TIMER_h
#define _TIMER_h

#include "ITimer.h"
#include <cstdint>
#include <cstddef>

class Timer : public ITimer
{
public:
	Timer();

	virtual void start(uint32_t miliseconds) override;
	virtual bool isZero() override;

private:
	uint32_t duration;
	uint32_t startMillis;
};

#endif

