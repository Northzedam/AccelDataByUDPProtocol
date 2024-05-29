#include "udp_connection.h"
#include "mpu_implementation.h"

void setup() {
  Serial.begin(115200);

  setupUDPConnection();

  /*if (!mpuBegin()) {
   Serial.println("Failed to initialize MPU6050!");
   while (1);
  }*/
}

void loop() {
    String targetIP = "192.168.100.5";
    int targetPort = 4210;
    String mpuData = getSensorData(); // este metodo es de mpu_implementation.cpp
    // Send return packet
    
    sendMessage(mpuData);
    //"192.168.100.5",4210
    delay(1000);
}
