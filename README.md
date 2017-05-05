# ESP8266_Logger

Create a file credentials with following structure:

#ifndef CREDENTIALS_H
#define CREDENTIALS_H

static const char* wifi_ssid = "XXXXXXXX";  //  your network SSID (name)
static const char* wifi_pass = "XXXXXXXX";       // your network password

static const char* server = "api.thingspeak.com";
static String tsAPIKey = "XXXXXXXX";

#endif    // CREDENTIALS_H

