
#ifndef proyectHardware_cpp
#define proyectHardware_cpp

#include <Arduino.h>
#include "pico/multicore.h"
#include <Motors.h>
#include <Sharps.h>
#include <Digitals.h>

//OBJETOS PARA MOTORES
Motor MotorRight(12,13,14);
Motor MotorLeft(11,10,9);

//Judge Sensors
Digital JudgeRdy(16);
Digital JudgeGo(17);

//OBJETOS PARA SENSORES DE DISTANCIA
Sharp sharpFront(A0);
Sharp sharpBack(A1);

//--DECLARACION DE ENTRADAS PARA SENSORES DIGITALES DE DETECCION DE SUELO
Digital sensor1(2); //OBJETO DEL SENSOR DE DETECCION DE LINEA FRONT#1
Digital sensor2(3); //OBJETO DEL SENSOR DE DETECCION DE LINEA FRONT#2
Digital sensor3(4); //OBJETO DEL SENSOR DE DETECCION DE LINEA POSTERIOR#1
Digital sensor4(5); //OBJETO DEL SENSOR DE DETECCION DE LINEA POSTERIOR#2

//--DECLARACION DE ENTRADAS PARA SENSORES DIGITALES IZQUIERDA Y DERECHA
Digital sensorRight(6); //DERECHO
Digital sensorLeft(7); //IZQUIERDO
#endif