#include "Arduino.h"
#include "Digitals.h"

<<<<<<< HEAD

=======
>>>>>>> d594741386b3719f39e1a63dd3191741c6a3d895
Digital::Digital(int pin, bool invert, int samples){
    _pin = pin;
    _invert = invert;
    _samples = samples;
}

void Digital::begin(){
    if(!_invert){
        pinMode(_pin, INPUT);
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