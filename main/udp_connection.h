#ifndef UDP_CONNECTION_H
#define UDP_CONNECTION_H

/*#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

// Set WiFi credentials
#define WIFI_SSID "Veronica"//"hwp20lte";//
#define WIFI_PASS "kq27p2kk"//"00000000";
#define UDP_PORT 4210

// UDP
extern WiFiUDP UDP;
extern char packet[255];
extern char reply[];

*/
#include <WiFi.h>

void setupUDPConnection();

void sendMessage(String& msg);


#endif // UDP_CONNECTION_H
