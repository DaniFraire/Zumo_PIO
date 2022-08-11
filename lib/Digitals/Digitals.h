
/*
  Digitals.h - Library for flashing Digitals code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#ifndef Digitals_h
#define Digitals_h

#include "Arduino.h"
class Digital{
  public:
    Digital(int pin, bool invert = false, int samples = 20);
    void begin();
    int getValue();
  private:
    int _pin;
    bool _invert;
    int _samples;
    int _value;
};


#endif