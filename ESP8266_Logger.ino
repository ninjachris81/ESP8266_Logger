/* META INFOS
target_package=esp8266
target_platform=esp8266
board=generic
*/
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include "ESP_TS_Log.h"

ESPTSLog espTSLog;

void setup() {
  espTSLog.init();
}

void loop() {
  espTSLog.update();
  delay(10);
}
