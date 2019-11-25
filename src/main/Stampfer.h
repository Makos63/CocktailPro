//@(#) Stampfer.h

#ifndef STAMPFER_H_H
#define STAMPFER_H_H

/**
* @class Stampfer
*
* @brief is a derived class of base class InternalDevice
*
* controls the masher
*/

#include "InternalDevice.h"

class Stampfer : public InternalDevice {
public:

/**
* @brief constructor for class Stampfer
* has no parameters
*/
    Stampfer();

/**
* @brief sets the timer of masher
* @param time is a float and it depends on the timer of InternalDevice
*/

    void doIt(float time);
/**
* a static constant interger variable.
*/
static const int FACTOR =1000;
private:
};

#endif
