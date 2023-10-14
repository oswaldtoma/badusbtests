#include "DevicesManager.h"
#include "Defines.h"
#include "SD.h"

USBHIDKeyboardWrapper DevicesManager::m_keyboard;
USBMSC DevicesManager::m_msc;
SPIClass DevicesManager::m_spi(FSPI);

int32_t DevicesManager::onWrite(uint32_t lba, uint32_t offset, uint8_t* buffer, uint32_t bufsize)
{
    SD.writeRAW((uint8_t*)buffer, lba);
    return bufsize;
}

int32_t DevicesManager::onRead(uint32_t lba, uint32_t offset, void* buffer, uint32_t bufsize)
{
    SD.readRAW((uint8_t*)buffer, lba);
    return bufsize;
}

bool DevicesManager::onStartStop(uint8_t power_condition, bool start, bool load_eject)
{
    return true;
}

bool DevicesManager::beginKeyboard()
{
    m_keyboard.begin();
    return true;
}

bool DevicesManager::beginSD()
{
    m_spi.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);
    SD.begin(SD_CS, m_spi, 40000000);
    m_msc.vendorID("ESP32");
    m_msc.productID("USB_MSC");
    m_msc.productRevision("1.0");
    m_msc.onRead(onRead);
    m_msc.onWrite(onWrite);
    m_msc.onStartStop(onStartStop);
    m_msc.mediaPresent(true);
    m_msc.begin(SD.cardSize() / 512, 512);

    return true;
}

void DevicesManager::allDevicesReady()
{
    USB.begin();
}