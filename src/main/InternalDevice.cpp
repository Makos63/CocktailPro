//@(#) InternalDevice.cpp


#include "InternalDevice.h"

/*void InternalDevice::setTimer() {

}*/

InternalDevice::InternalDevice() {
    myTimer = Timer::getInstance();
    this->doinIt = false;
    this->zeiteinheit = 0;
}

InternalDevice::InternalDevice(bool dointIt_new ,int zeiteinheit_new)
                                : doinIt(dointIt_new), zeiteinheit(zeiteinheit_new){
  myTimer = Timer::getInstance();
}

void InternalDevice::putzen() {
    //std::cout << "Ich putze mich..." << std::endl;
    //myTimer->sleep(500);
    //std::cout << "Ich bin fertig mit putzen!" << std::endl;
}
