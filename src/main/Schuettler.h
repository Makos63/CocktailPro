//@(#) Schuettler.h

#ifndef SCHUETTLER_H_H
#define SCHUETTLER_H_H

#include "InternalDevice.h"

class Schuettler : public InternalDevice {
public:
    Schuettler();

    void doIt(float time);

private:
};

#endif
