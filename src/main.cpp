//UNIVERSIDAD TECNOLOGICA DE NOGALES
//SISTEMAS DIGITALES//
#include <Arduino.h>
#include "pico/multicore.h"
//#include <StateMachine.h>
#include <States.h>
#include <proyectHardware.h>

void setup ()
{
  Serial.begin(115200);
  // DECLARACION DE LOS PINES DE ENTRADA DE LOS SENSORES FRONTALES
  sensor1.begin();
  sensor2.begin();
  // DECLARACION DE LOS PINES DE ENTRADA DE LOS SENSORES POSTERIORES
  sensor3.begin();
  sensor4.begin();
  // DECLARACION DE LOS PINES DE ENTRADA DE LOS SENSORES IZQUIERDA Y DERECHA
  sensor5.begin();
  sensor6.begin();
}

void loop()
{
  Serial.println(
    "Sensor1: " + String(sensor1.getValue()) + 
    "\tSensor2: " + String(sensor2.getValue()) + 
    "\tSensor3: " + String(sensor3.getValue()) + 
    "\tSensor4: " + String(sensor4.getValue()) + 
    "\tSensor5: " + String(sensor5.getValue()) + 
    "\tSensor6: " + String(sensor6.getValue()) + 
    "\tSensorA1: " + String(sharpFront.getRAW()) + 
    "\tSensorA2: " + String(sharpBack.getRAW())
  );
}