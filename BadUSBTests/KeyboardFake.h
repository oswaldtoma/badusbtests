#pragma once

#include "../BadUSB/IKeyboard.h"

class KeyboardFake : public IKeyboard
{
public:
	KeyboardFake() : pressedButtons{ 0 }, pressIndex(0)
	{

	}

	virtual void begin() override;
	virtual void end() override;
	virtual size_t write(uint8_t k) override;
	virtual size_t write(const uint8_t* buffer, size_t size) override;
	virtual size_t press(uint8_t k, uint16_t delayms) override;
	virtual size_t release(uint8_t k) override;
	virtual void releaseAll(void) override;
	virtual size_t pressRaw(uint8_t k) override;
	virtual size_t releaseRaw(uint8_t k) override;

	virtual uint8_t getPressedKey(uint16_t index) { return pressedButtons[index]; }

	virtual void KeyboardFake::clearPressedIndex();

private:
	uint8_t pressedButtons[1024];
	uint16_t pressIndex;
};

