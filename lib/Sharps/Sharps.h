
/*
  Sharps.h - Library for flashing Sharps code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#ifndef Sharps_h
#define Sharps_h

#include "Arduino.h"

class Sharp{
  public:
    Sharp(int pin, int samples = 20);
    int getRAW();
    int getDistance();
    int getVoltage();
  private:
    int _samples;
    int _pin;
    int _raw;
    int _distance;
};
#endif