#include <Arduino.h>
#include "pico/multicore.h"

#include <Hardware.h>

#ifndef States_cpp
#define States_cpp 

bool active_waiting = false;
void waiting(bool *Active){
    // To do in state
    if(Active){
        MotorLeft.Speed(0);
        MotorRight.Speed(0);
    }
    //When leave state
    if(Active && JudgeGo.getValue()){
        bool newState = false;
        Active = &newState;
    }
}

bool active_Searching = false;
void Searching(bool *Active, bool *GoTo, int Radius = 40){
    //To do in state
    if(Active){
        MotorLeft.Speed(-80);
        MotorRight.Speed(80);
    }

    //When leave state
    if(Active && (sharpFront.getDistance() > Radius)){
        MotorLeft.Speed(0);
        MotorRight.Speed(0);
        *Active = false;
        *GoTo = true;
    }
}

bool active_Atacking = false;
void Atacking(bool *Active, bool *GoTo, int Radius = 20){
    //To do in state
    if(Active){
        MotorLeft.Speed(100);
        MotorRight.Speed(100);
    }
    //When leave state
    if(sharpFront.getDistance() > Radius){
        *Active = false;
        *GoTo = true;
    }
}

void zoneLimit(bool *interruptAtack, bool *interruptSearching){
    if(sensor1.getValue() && sensor2.getValue()){
        *interruptSearching = false;
        *interruptAtack = false;
        MotorLeft.Speed(-100);
        MotorRight.Speed(0);
    }
    else if(sensor3.getValue() && sensor4.getValue()){
        MotorLeft.Speed(100);
        MotorRight.Speed(0);
    }
    else if(!sensor1.getValue() && sensor2.getValue()){
        *interruptSearching = false;
        *interruptAtack = false;
        MotorLeft.Speed(-100);
        MotorRight.Speed(0);
    }
    
    else if(!sensor3.getValue() && sensor4.getValue()){
        MotorLeft.Speed(100);
        MotorRight.Speed(0);
    }
    else if(sensor1.getValue() && !sensor2.getValue()){
        *interruptSearching = false;
        *interruptAtack = false;
        MotorLeft.Speed(0);
        MotorRight.Speed(100);
    }
    else if(sensor3.getValue() && !sensor4.getValue()){
        MotorLeft.Speed(100);
        MotorRight.Speed(0);
    }
}
#endif