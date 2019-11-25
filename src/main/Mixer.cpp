//@(#) Mixer.cpp


#include "Mixer.h"

Mixer::Mixer() : InternalDevice() {

}

void Mixer::doIt(float time) {
    myTimer->sleepInOneSecondIntervals(time * FACTOR);
    std::cout << std::endl;
}
