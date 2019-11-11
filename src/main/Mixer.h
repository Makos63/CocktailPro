//@(#) Mixer.h
/**
*	@class Mixer
*
* 	@brief Calls internalDevice and sleeps
*
* 	
* 	
*/
#ifndef MIXER_H_H
#define MIXER_H_H

#include <iostream>

#include "InternalDevice.h"

class Mixer : public InternalDevice {
public:
	/**
	*	@brief default constructor call
	*	
	*	@param none
	*
	*	@return none
	*
	*	constructor is not defined in the cpp
	*/
    Mixer();

	/**
	*	@brief gets time and sleeps 
	*
	*	@param float time
	*
	*	@return none
	*
	*	Gets the time as float and multiplies it with 1000 to get seconds.
	*	Sleeps for n-seconds and prints an endline.
	*/
    void doIt(float time);

private:

};

#endif
