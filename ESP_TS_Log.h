#ifndef ESPTSLOG_H
#define ESPTSLOG_H

#include <ESP8266WiFi.h>

#include "credentials.h"

#define INPUT_SERIAL Serial

//#define PRINT_BACK

class ESPTSLog {
public:
  ESPTSLog();

  void init(int baudRate=115200);

  void update();

private:
  WiFiClient client;
  String inputStringBuffer;
  
  uint8_t timeout = 0;

};



#endif // ESPTSLOG_H
