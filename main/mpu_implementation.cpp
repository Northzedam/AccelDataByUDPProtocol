#include "mpu_implementation.h"
#include <Wire.h>
#include <Adafruit_MPU6050.h>

  // Convierte float en string
  // n -> numero a convertir
  // l -> longitud total de la cadena, por defecto 8
  // d -> decimales, por defecto 2
  // z -> si se desea rellenar con ceros a la izquierda, por defecto true

  //Controlador de acelerometro
  Adafruit_MPU6050 mpu;

    bool mpuBegin() {
      if (!mpu.begin()) {
        return false;
      }
    
      // Configurar la sensibilidad para medir aceleraciones, inclinaciones y ruidos
      mpu.setAccelerometerRange(MPU6050_RANGE_8_G); // estaba en 8_G
      mpu.setGyroRange(MPU6050_RANGE_500_DEG); // estaba en 500_DEG
      mpu.setFilterBandwidth(MPU6050_BAND_21_HZ); // estaba en 21_HZ
      
      return true;
    }
  
    String getSensorData(){
    sensors_event_t a, g, temp;
    mpu.getEvent(&a,&g,&temp);

    float xAccel = a.acceleration.x;
    float yAccel = a.acceleration.y;
    float zAccel = a.acceleration.z;
  
    //offsets para calibrar el cero de cada eje
    float offsetX = -30;
    float offsetY = 0;
    float offsetZ = 0;

    // Obtener valores de inclinación
    float xIncl = (atan2(a.acceleration.x, sqrt(pow(a.acceleration.y, 2) + pow(a.acceleration.z, 2))) * (180 / PI)) + offsetX;
    float yIncl = (atan2(a.acceleration.y, sqrt(pow(a.acceleration.x, 2) + pow(a.acceleration.z, 2))) * (180 / PI)) + offsetY;
    float zIncl = (atan2(sqrt(pow(a.acceleration.x, 2) + pow(a.acceleration.y, 2)), a.acceleration.z) * (180 / PI)) + offsetX;

    // Mostrar valores por consola
    Serial.print("Aceleración (m/s^2): ");
    Serial.print("X = "); Serial.print(xAccel);
    Serial.print(", Y = "); Serial.print(yAccel);
    Serial.print(", Z = "); Serial.print(zAccel);
  
    Serial.print("  |  ");
  
    Serial.print("Inclinación (grados): ");
    Serial.print("X = "); Serial.print(xIncl);
    Serial.print(", Y = "); Serial.print(yIncl);
    Serial.print(", Z = "); Serial.println(zIncl);

    String xA = floatToString(xAccel,2,0,false);
    String yA = floatToString(yAccel,2,0,false);       
    String zA = floatToString(zAccel,2,0,false);
    String xI = floatToString(xIncl,2,0,false);
    String yI = floatToString(yIncl,2,0,false);
    String zI = floatToString(zIncl,2,0,false);
    
    String datosEnString  = ( xA + "," + xI + "," + yA + "," + yI + "," + zA + "," + zI);
    return datosEnString;
  }

   String floatToString (float n, int l, int d, boolean z){
    char c[l+1];
    String s;
    dtostrf(n,l,d,c);
    s = String(c);
    if(z){ s.replace(" ","0"); }
    return s;
  }



 

  
