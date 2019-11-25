//@(#) Timer.cpp


#include "Timer.h"

void Timer::setTurbo(int turbo) {
    this->booster = turbo;
}

Timer * Timer::getInstance() {
    if (!instanceFlag) {
        theTimer = new Timer();
        instanceFlag = true;
        return theTimer;
    } else {
        return theTimer;
    }
}

void Timer::sleep(long delayInMs){
    // if netbeans does not recognize system_clock you have to set the project properties to C++11:
    // Project-Properties->Code Assistance -> C++ (and C). Seit it to C++!
    long nowMillis = time_point_cast<milliseconds>(system_clock::now()).time_since_epoch().count();      
    long limit = nowMillis + (delayInMs / booster);
    
    while (limit > nowMillis) {

        nowMillis = time_point_cast<milliseconds>(system_clock::now()).time_since_epoch().count();;
    }
}

void Timer::sleepInOneSecondIntervals(long delayInMs) {
    // to improve compatibility between Linux and Windows this implementation
    // is using busy wait (and avoids threads)! On purpose...
    long delay=0;
    
    while (delayInMs >0) {
        std::cout << "*" << std::flush;
        if (delayInMs >=1000){
            delay = 1000;
            delayInMs = delayInMs-delay;
        } else {
            delay = delayInMs;
            delayInMs = 0;          
        }
        sleep(delay);
    }   
}


bool Timer::instanceFlag = false;

Timer * Timer::theTimer = 0;
