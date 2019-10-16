//@(#) Stampfer.h

#ifndef STAMPFER_H_H
#define STAMPFER_H_H

#include "InternalDevice.h"

class Stampfer : public InternalDevice {
public:
    Stampfer();

    void doIt(float time);

private:
};

#endif
