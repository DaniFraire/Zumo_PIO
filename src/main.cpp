//UNIVERSIDAD TECNOLOGICA DE NOGALES
//SISTEMAS DIGITALES//
#include <Arduino.h>
#include "pico/multicore.h"
<<<<<<< HEAD
//#include <StateMachine.h>
#include <States.h>
#include <proyectHardware.h>
=======
#include <States.h>
#include <Hardware.h>
>>>>>>> d594741386b3719f39e1a63dd3191741c6a3d895

void setup(){
  Serial.begin(115200);
  // DECLARACION DE LOS PINES DE ENTRADA DE LOS SENSORES FRONTALES
  sensor1.begin();
  sensor2.begin();
  // DECLARACION DE LOS PINES DE ENTRADA DE LOS SENSORES POSTERIORES
  sensor3.begin();
  sensor4.begin();
  // DECLARACION DE LOS PINES DE ENTRADA DE LOS SENSORES IZQUIERDA Y DERECHA
  sensorRight.begin();
  sensorLeft.begin();
}

#define Show true
void logData(bool show){
  if(show) Serial.println(
    "Sensor1: " + String(sensor1.getValue()) + 
    "\tSensor2: " + String(sensor2.getValue()) + 
    "\tSensor3: " + String(sensor3.getValue()) + 
    "\tSensor4: " + String(sensor4.getValue()) +
    "\tSensorRight: " + String(sensorRight.getValue()) + 
    "\tSensorRight: " + String(sensorLeft.getValue()) + 
    "\tSensorA1: " + String(sharpFront.getDistance()) + 
    "\tSensorA2: " + String(sharpBack.getDistance()) +
    "\tJudgeGo: " + String(JudgeGo.getValue()) +
    "\tJudgeRdy: " + String(JudgeRdy.getValue()) +
    "\tactive_waiting: " + String(active_waiting) +
    "\tactive_Searching: " + String(active_Searching) +
    "\tactive_Atacking: " + String(active_Atacking)
  );
}

void loop(){
  MotorLeft.Speed(100);
  MotorRight.Speed(100);
  //waiting(&active_waiting);
  //Searching(&active_Searching, &active_Atacking);
  //Atacking(&active_Atacking, &active_Searching);
  //logData(Show);
}