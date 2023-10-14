#include "WifiManager.h"

AsyncWebServer WifiManager::server(80);

void (*WifiManager::onGetRequestCb)(uint8_t*, uint16_t) = nullptr;
void (*WifiManager::onPostRequestCb)(String) = nullptr;

const String WifiManager::pageContentPart1 = R"rawliteral(
<html>
    <head>
    </head>
    <body>
        <script>
            function scrollToBottom()
            {
                var code = document.getElementById("code");
                code.scrollTop = code.scrollHeight;
            }

            function addString(value)
            {
                document.getElementById("code").value += "\n" + value + " ";
                scrollToBottom();
            }
        </script>
        <div id="main" style="height: 75%;">
            <form id="codeform" style="display: flex;" action="/post" method="POST">
                <div id="text" style="flex: 3;">
                    <textarea name="code" id="code" placeholder="Enter your code here." autofocus="true" style="resize: none; width: 80%; height: 100%; font-size: 18px;">)rawliteral";


const String WifiManager::pageContentPart2 = R"rawliteral(</textarea>
                </div>
                <div id="buttons" style="flex: 1;">
                    <input type="button" value="Comment" style="padding: 50px 54px; font-size: 20px;" onclick="addString('COM')"><br><br><br><br>
                    <input type="button" value="Wait" style="padding: 30px 34px; font-size: 20px;" onclick="addString('WT')"><br><br><br><br>
                    <input type="button" value="OS" style="padding: 30px 34px; font-size: 20px;" onclick="addString('OS')"><br><br><br><br>
                    <input type="button" value="Context menu" style="padding: 30px 34px; font-size: 20px;" onclick="addString('CON')"><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
                    <input type="submit" value="Execute" style="padding: 30px 34px; font-size: 20px;"><br><br><br><br>
                </div>
            </form>
        </div>
        <script>
            scrollToBottom();
        </script>
    </body>
</html>
)rawliteral";

String WifiManager::pageContent = "";
uint8_t WifiManager::fileContent[3000] = { 0 };

void WifiManager::init()
{
    WiFi.softAP("ESP32", 0, 10);
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);

    server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
        pageContent = "";

        onGetRequestCb(fileContent, 3000);

        pageContent += pageContentPart1;
        pageContent += (char*)fileContent;
        pageContent += pageContentPart2;

        static char buffer[3000] = { 0 };
        pageContent.toCharArray(buffer, 3000);

        request->send_P(200, "text/html", buffer);
    });

    server.on("/post", HTTP_POST, 
        [](AsyncWebServerRequest* request) {
            Serial.println("POST");
            
            if (request->hasArg("code"))
            {
                if (onPostRequestCb)
                {
                    onPostRequestCb(request->arg("code"));
                }
            }

            request->send(200);
    });

    server.begin();
}

void WifiManager::run(String filecontent)
{

}
