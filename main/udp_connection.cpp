#include "udp_connection.h"
#include <WiFi.h>
#include <WiFiUdp.h>

#define UDP_PORT 4210


WiFiUDP UDP;
char packet[255];
//char reply[] = "hola";

void setupUDPConnection() {
  // Setup serial port
  Serial.begin(115200);
  Serial.println();
  
 //wifi connection

 // Credenciales de red
 char* ssid = "Veronica";
 char* password ="kq27p2kk";

// Objeto WiFi para la conexión a la red
WiFiClient espClient;

// Conexión a la red Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a la red Wi-Fi...");
  }
  Serial.println("Conexión establecida.");

 
  // Begin listening to UDP port
  UDP.begin(UDP_PORT);
  Serial.print("Listening on UDP port ");
  Serial.println(UDP_PORT);
}

  void sendMessage(String& msg){
      char packet[255];
      const char* reply = msg.c_str();
      UDP.beginPacket("192.168.100.7",4210);
      UDP.write((uint8_t*) reply, strlen(reply));
      Serial.print(msg);
      UDP.endPacket();  
  }

  
