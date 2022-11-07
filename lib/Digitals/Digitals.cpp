#include "Arduino.h"
#include "Digitals.h"

Digital::Digital(int pin, bool invert, int samples){
    _pin = pin;
    _invert = invert;
    _samples = samples;
}

void Digital::begin(){
    if(!_invert){
        pinMode(_pin, INPUT_PULLDOWN);
    }
    else{
        pinMode(_pin, INPUT_PULLUP);
    }
}

bool Digital::getValue(){
    for (int i = 0; i < _samples; i++){
        _value += int(digitalRead(_pin));
    }
    _value = _value/_samples;
    return _value;
}