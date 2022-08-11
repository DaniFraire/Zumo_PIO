#include "Arduino.h"
#include "Sharps.h"


Sharp::Sharp(int pin, int samples = 20){
    _pin = pin;
    _samples =  samples = 20;
}

int Sharp::getRAW(){
    for (int i = 0; i < _samples; i++){
        _raw += analogRead(_pin);
    }
    _raw = _raw/_samples;
    return _raw;
}

int Sharp::getVoltage(){
    return int(getRAW()) * (3.3/255.0);
}

int Sharp::getDistance(){
    _distance = 29.988 * pow(getVoltage(), -1.173);

    if(_distance > 80) return 81;
    else if(_distance < 10) return 9;
    else return _distance;
}