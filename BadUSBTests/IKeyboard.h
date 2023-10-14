#ifndef IKEYBOARD
#define IKEYBOARD

#include <cstddef>
#include <cstdint>

class IKeyboard
{
public:
	virtual void begin() = 0;
	virtual void end() = 0;

	virtual size_t write(uint8_t k) = 0;

    virtual size_t write(const uint8_t* buffer, size_t size) = 0;
    virtual size_t press(uint8_t k, uint16_t delayms) = 0;
    virtual size_t release(uint8_t k) = 0;
    virtual void releaseAll(void) = 0;

    virtual size_t pressRaw(uint8_t k) = 0;
    virtual size_t releaseRaw(uint8_t k) = 0;
};

#endif