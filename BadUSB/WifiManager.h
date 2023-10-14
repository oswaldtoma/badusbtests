// WifiManager.h

#ifndef _WIFIMANAGER_h
#define _WIFIMANAGER_h

#include "WiFi.h"
#include "AsyncTCP.h"
#include "ESPAsyncWebServer.h"

class WifiManager
{
public:
	static void init();
	static void run(String filecontent);

	static void setOnPostRequestCb(void (*onPostRequest)(String bodyContent)) { onPostRequestCb = onPostRequest; }
	static void setOnGetRequestCb(void (*onGetRequest)(uint8_t* rawBytes, uint16_t size)) { onGetRequestCb = onGetRequest; }

private:

	static AsyncWebServer server;

	static const String pageContentPart1;
	static const String pageContentPart2;
	static String pageContent;

	static uint8_t fileContent[3000];

	static void (*onPostRequestCb)(String);
	static void (*onGetRequestCb)(uint8_t*, uint16_t);
};

#endif

