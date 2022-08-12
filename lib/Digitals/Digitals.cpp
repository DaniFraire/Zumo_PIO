#include "Arduino.h"
#include "Digitals.h"


Digital::Digital(int pin, bool invert, int samples){
    _pin = pin;
    _invert = invert;
    _samples =  samples = 20;
}

void Digital::begin(){
    if(!_invert){
        pinMode(_pin, INPUT);
    }
    else{
        pinMode(_pin, INPUT_PULLUP);
    }
}

int Digital::getValue(){
    for (int i = 0; i < _samples; i++){
        _value += int(digitalRead(_pin));
    }
    _value = _value/_samples;
    return _value;
}

