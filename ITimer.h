#ifndef _ITIMER_h
#define _ITIMER_h

#include <cstdint>
#include <cstddef>

class ITimer
{
public:
	virtual void start(uint32_t miliseconds) = 0;
	virtual bool isZero() = 0;
};


#endif

