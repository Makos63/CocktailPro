//@(#) Schuettler.h

#ifndef SCHUETTLER_H_H
#define SCHUETTLER_H_H

/**
* @class Schuettler
*
* @brief is derived class of base class InternalDevice
*
* to control the Shaker using the Timer
*/

#include "InternalDevice.h"

class Schuettler : public InternalDevice {
public:

/**
* @brief constructor of class Schuettler
*/
    Schuettler();

/**
* @brief sets the timer of shaker
* @param time is a float and it depends on the timer of InternalDevice
*
*/
    void doIt(float time);

private:
};

#endif
