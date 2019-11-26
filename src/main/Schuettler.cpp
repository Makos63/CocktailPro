//@(#) Schuettler.cpp


#include "Schuettler.h"

Schuettler::Schuettler() : InternalDevice() {
}

void Schuettler::doIt(float time) {
    myTimer->sleepInOneSecondIntervals(time * FACTOR);
    std::cout << std::endl;
}
