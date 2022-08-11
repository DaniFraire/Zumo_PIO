//UNIVERSIDAD TECNOLOGICA DE NOGALES
//SISTEMAS DIGITALES//
#include <Arduino.h>
#include <Motors.h>
#include "pico/multicore.h"

Motor MotorR(12,13,14);
Motor MotorL(11,10,9);

//--DECLARACION DE ENTRADAS PARA SENSORES DIGITALES DE DETECCION DE SUELO
int sensor1 = 12;
int sensor2 = 3;
int sensor3 = 13;
int sensor4 = 2;

//--DECLARACION DE ENTRADAS PARA SENSORES DIGITALES IZQUIERDA Y DERECHA
int sensor5 = 11; //DERECHO
int sensor6 = 8; //IZQUIERDO

//VARIABLE PARA ALMACENAR EL VALOR ANALOGICO SENSOR DE DISTANCIA
const byte Sensor1Analog = A0;
const byte Sensor2Analog = A1;

//-----VARIABLES PARA ALMACENAR ESTADOS DE LOS SENSORES DIGITALES
int estadoSensor1 = 0; //ESTADO DEL SENSOR DETECCION DE LINEA FRONT#1
int estadoSensor2 = 0; //ESTADO DEL SENSOR DETECCION DE LINEA FRONT#2
int estadoSensor3 = 0; //ESTADO DEL SENSOR DETECCION DE LINEA POSTERIOR#1
int estadoSensor4 = 0; //ESTADO DEL SENSOR DETECCION DE LINEA POSTERIOR#2
int estadoSensor5 = 0; //ESTADO DEL SENSOR DETECCION DE LADO DERECHO
int estadoSensor6 = 0; //ESTADO DEL SENSOR DETECCION DE LADO IZQUIERDO

//-----VARIABLES PARA ALMACENAR ESTADOS DE LOS SENSORES ANALOGICOS
int Sensor1AnalogValor = 0;
int Sensor2AnalogValor = 0;


void setup ()
{
  analogReadResolution(8);
  Serial.begin(115200);
  // DECLARACION DE LOS PINES DE ENTRADA DE LOS SENSORES FRONTALES
  pinMode (sensor1, INPUT);
  pinMode (sensor2, INPUT);
  // DECLARACION DE LOS PINES DE ENTRADA DE LOS SENSORES POSTERIORES
  pinMode (sensor3, INPUT);
  pinMode (sensor4, INPUT);
  // DECLARACION DE LOS PINES DE ENTRADA DE LOS SENSORES IZQUIERDA Y DERECHA
  pinMode (sensor5, INPUT);
  pinMode (sensor6, INPUT);
}

void getRAWReads(int samples){
  for (int i = 0; i < samples; i++)
  {
    //LECTURA DE LOS ESTADOS DE LOS SENSORES FRONTALES
    estadoSensor1 += digitalRead(sensor1); //LECTURA#1
    estadoSensor2 += digitalRead(sensor2); //LECTURA#2
    estadoSensor3 += digitalRead(sensor3); //LECTURA#3
    estadoSensor4 += digitalRead(sensor4); //LECTURA#4
    estadoSensor5 += !digitalRead(sensor5); //LECTURA#5
    estadoSensor6 += !digitalRead(sensor6); //LECTURA#6
    // LECTURA DE SENSOR FRONTAL DEL SUMO DISTANCIA
    Sensor1AnalogValor += analogRead(Sensor1Analog);
    Sensor2AnalogValor += analogRead(Sensor2Analog);
  }
  //LECTURA DE LOS ESTADOS DE LOS SENSORES FRONTALES
  estadoSensor1 = estadoSensor1/samples; //PROMEDIO#1
  estadoSensor2 = estadoSensor2/samples; //PROMEDIO#2
  estadoSensor3 = estadoSensor3/samples; //PROMEDIO#3
  estadoSensor4 = estadoSensor4/samples; //PROMEDIO#4
  estadoSensor5 = estadoSensor5/samples; //PROMEDIO#5
  estadoSensor6 = estadoSensor6/samples; //PROMEDIO#6
  // LECTURA DE SENSOR FRONTAL DEL SUMO DISTANCIA
  Sensor1AnalogValor = Sensor1AnalogValor/samples;
  Sensor2AnalogValor = Sensor2AnalogValor/samples;
}

void loop()
{
  getRAWReads(20);
  Serial.println("Sensor1: " + String(estadoSensor1) + "\tSensor2: " + String(estadoSensor2) + "\tSensor3: " + String(estadoSensor3) + "\tSensor4: " + String(estadoSensor4) + "\tSensor5: " + String(estadoSensor5) + "\tSensor6: " + String(estadoSensor6) + "\tSensorA1: " + String(Sensor1AnalogValor) + "\tSensorA2: " + String(Sensor2AnalogValor));
}