#include "Helper.h"
#include "Defines.h"
#include "DevicesManager.h"
#include "ScriptManager.h"
#include "SD.h"
#include "ScriptLang.h"
#include "WifiManager.h"

void log(const char* str)
{
    Serial.println(str);
}

bool isBootButtonClicked()
{
    return digitalRead(BOOT_BUTTON) == LOW;
}

static uint8_t fileData[500] = { '\0' };

static void getFileContent(uint8_t* rawBytes, uint16_t size)
{
    if (SD.exists("/script.txt"))
    {
        File file = SD.open("/script.txt");
        file.readBytes((char*)rawBytes, size);
        file.close();
    }
}

static void postHandler(String bodyContent)
{
    bodyContent.toCharArray((char*)fileData, 500);
    ScriptManager::executeScript(fileData, 500);
}

void setup()
{
    pinMode(BOOT_BUTTON, INPUT_PULLUP);

    Serial.begin(115200);

    DevicesManager::beginSD();
    DevicesManager::beginKeyboard();
    DevicesManager::allDevicesReady();
 
    ScriptManager::init(DevicesManager::getKeyboard());

    DevicesManager::getKeyboard()->releaseAll();

    delay(500);

    WifiManager::setOnGetRequestCb(getFileContent);
    WifiManager::setOnPostRequestCb(postHandler);
    WifiManager::init();

    delay(500);
}                          

void loop()
{
    static bool firstRun = false;

    if (isBootButtonClicked())
    {
        firstRun = false;
    }
    
    if(firstRun)
    {       
        log("klik!");
        if (SD.exists("/script.txt"))
        {
            File file = SD.open("/script.txt");
            file.readBytes((char*)fileData, 500);
            ScriptManager::executeScript(fileData, 500);
            log("executed!");
        }

        firstRun = false;
    }
   
    if (millis() % 1000 == 0)
    {
        Serial.printf("%d\n", ESP.getFreeHeap());
    }
}
