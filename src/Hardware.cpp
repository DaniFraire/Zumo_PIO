#include <Arduino.h>
#include "pico/multicore.h"
#include <Motors.h>
#include <Sharps.h>
#include <Digitals.h>

#ifndef Hardware_cpp
#define Hardware_cpp

//OBJETOS PARA MOTORES
Motor MotorRight(12,13,14);
Motor MotorLeft(11,10,9);

//OBJETOS PARA SENSORES DE DISTANCIA
Sharp sharpFront(A0);
Sharp sharpBack(A1);

//--DECLARACION DE ENTRADAS PARA SENSORES DIGITALES DE DETECCION DE SUELO
Digital sensorLine(2); //OBJETO DEL SENSOR DE DETECCION DE LINEA FRONT#1
Digital sensor2(3); //OBJETO DEL SENSOR DE DETECCION DE LINEA FRONT#2
Digital sensor3(4); //OBJETO DEL SENSOR DE DETECCION DE LINEA POSTERIOR#1
Digital sensor4(5); //OBJETO DEL SENSOR DE DETECCION DE LINEA POSTERIOR#2

//--DECLARACION DE ENTRADAS PARA SENSORES DIGITALES IZQUIERDA Y DERECHA
Digital sensor5(6); //DERECHO
Digital sensor6(7); //IZQUIERDO

#endif