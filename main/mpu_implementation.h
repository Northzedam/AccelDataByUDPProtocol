#ifndef MPU_IMPLEMENTATION
#define MPU_IMPLEMENTATION

#include <Wire.h>
#include <Adafruit_MPU6050.h>

//Prototipo de la funcion para iniciar el sensor
bool mpuBegin();

//Prototipo de la funcion para leer el sensor
String getSensorData();

//Prototipo de la funcion para convertir float to string
String floatToString ( float, int=8,int=2,boolean=true);

#endif
