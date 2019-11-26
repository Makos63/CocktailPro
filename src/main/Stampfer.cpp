//@(#) Stampfer.cpp


#include "Stampfer.h"

Stampfer::Stampfer() : InternalDevice() {
}

void Stampfer::doIt(float time) {
    myTimer->sleepInOneSecondIntervals(time * FACTOR);
    std::cout << std::endl;
}
