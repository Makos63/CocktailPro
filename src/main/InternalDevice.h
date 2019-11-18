//@(#) InternalDevice.h

/**
*	@class InternalDevice
*
* 	@brief Cleanup after output
*
* 	The Class checks, if a output is made.
* 	If not, the mixer cleans itself.   
*/
#ifndef INTERNALDEVICE_H_H
#define INTERNALDEVICE_H_H

#include "Timer.h"

class InternalDevice {
public:
	/**
	* 	@brief virtual method with no declaration
	*/
    virtual void doIt(float value) = 0;

	/**
	*	@brief mixer is cleaning and prints it.
	*
	*	function prints, that the mixer is cleaning itself and prints out start and end of the process
	*/
    void putzen();

private:
	/**
	* 	@brief constructor call for Timer.
	*/
    //void setTimer();


public:
	/**
	*	@brief Constructor of InternalDevice
	*
	*	sets the Timer to the value of the Timer - getInstance value.
	*	sets doinIt to 0 / false
	*/
    InternalDevice();
    /*InternalDevice(int zeiteinheit_new = 0);*/
protected:
	/**
	*	saves the amound of time (probably in seconds).
	*/
    int zeiteinheit;

	/**
	*	bool object to see, if output is enabled or not 
	*	name is a bit odd but it is super duper important
	*/
    bool doinIt;

	/**
	*	Object of the type Timer
	*/
    Timer * myTimer;

};

#endif
