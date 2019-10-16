//@(#) Entleerer.h

#ifndef ENTLEERER_H_H
#define ENTLEERER_H_H

#include <iostream>

#include "Observer.h"
#include "InternalDevice.h"
#include "Waage.h"

class Entleerer : public InternalDevice, public Observer {
public:
    Entleerer(float g, int ze, Waage * wg);
    ~Entleerer();
    void update();

    void doIt(float value);

private:
    float grammProZeit;

    Waage * myWaage;

    float value;

};

#endif
