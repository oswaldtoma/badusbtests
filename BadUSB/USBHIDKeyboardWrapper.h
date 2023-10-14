#include "IKeyboard.h"
#include "USBHIDKeyboard.h"

class USBHIDKeyboardWrapper : public IKeyboard
{
public:
    void begin() override;
    void end() override;

    size_t write(uint8_t k) override;

    size_t write(const uint8_t* buffer, size_t size) override;
    size_t press(uint8_t k, uint16_t delayms) override;
    size_t release(uint8_t k) override;
    void releaseAll() override;

    size_t pressRaw(uint8_t k) override;
    size_t releaseRaw(uint8_t k) override;

private:
    USBHIDKeyboard m_keyboard;
};

