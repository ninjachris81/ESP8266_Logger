#include "ESP_TS_Log.h"

ESPTSLog::ESPTSLog() {
}

void ESPTSLog::init(int baudRate) {
  INPUT_SERIAL.begin(baudRate);

#ifdef PRINT_BACK
    INPUT_SERIAL.print(F("INIT"));
#endif

  WiFi.mode(WIFI_STA);
  WiFi.begin(wifi_ssid, wifi_pass);
}

void ESPTSLog::update() {
  if (INPUT_SERIAL.available() > 0) {

#ifdef PRINT_BACK
    INPUT_SERIAL.print(F("Available: "));
    INPUT_SERIAL.println(INPUT_SERIAL.available(), DEC);
#endif

    inputStringBuffer = INPUT_SERIAL.readStringUntil('\n');
  }
  if (inputStringBuffer.length()==0) return;

  // make sure we're connected
  timeout = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    timeout++;
    if (timeout > 10) {
      return;
    }
  }

#ifdef PRINT_BACK
  INPUT_SERIAL.println(F("Connected"));
#endif
  
  if (client.connect(server, 80)) {
    
    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + tsAPIKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(inputStringBuffer.length());
    client.print("\n\n");
    client.print(inputStringBuffer);
    client.print("\n\n");

#ifdef PRINT_BACK
    INPUT_SERIAL.println(inputStringBuffer);
#endif

    inputStringBuffer = "";
  } else {
#ifdef PRINT_BACK
    INPUT_SERIAL.println(F("Error connecting to server"));
#endif

  }
  client.stop();
}
