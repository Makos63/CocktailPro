//@(#) Timer.h

#ifndef TIMER_H_H
#define TIMER_H_H

#include <chrono>
using namespace std::chrono;
#include <iostream>
/**
 *@class Timer
 *@brief a singleton pattern class,that
manages the wait time through the different stages in
theCocktail Mixer
 *
 *A timer is used to control the quantity of ingredients used.
 *It is also used to set up wait time untill the mixing or the 
cleaning is finished
 *There can only be one instance of this class throughout 
the whole Cocktail Mixer Sim.
 */

class Timer {
 public:
/**
 *@brief function enables speeding up or slowing time for test purposes
 *@param turbo an interger used to accelerate or decelerate time. 
 Higher ist faster.
 *@return  it has no return type
 */
 
    void setTurbo(int turbo);
/**
 *@brief function used to implement single ton pattern,returns the only 
instance of time
 *@return a pointer to an object of type Timer
 */

    static Timer * getInstance();

    /**
     * 	~Timer( )
     *     {
     *         instanceFlag = false;
     *     };
     */
/**
 *@brief controls the waits to be as long as desired and outputs an '*'
 to screen on every second passing.
 *@param milliseconds the total amount of time to wait  in milliseconds.
 *@return  it has no return type
 */
    void sleepInOneSecondIntervals(long milliseconds);
/**
 *@brief controls the waiting time, without outputting anything to screen.
 *@param delay_in_ms  delaying time in milliseconds.
 *@return has no return type
 */ 
    void sleep(long delayInMs);


 private:
/**
 *a static variable of type Timer to help implement the singleton pattern
 */
    static bool instanceFlag;
/**
 *a static pointer of type Timer to help implement the singleton pattern
 */

    static Timer * theTimer;
/**
 * an interger to accelerate  or decelerate the waiting time
 */
    int booster;
/**
 * a private constructor to create an instance with a singleton pattern
*/
    Timer() : booster(1) {
    };

};

#endif
