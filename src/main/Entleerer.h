//@(#) Entleerer.h
/**
*	@class Entleerer
*
* 	@brief Class to empty the mixer
*
* 	The Class checks, if the right weight is reached.
* 	If so, the mixer prints a message and empties with the given speed.   
*/

#ifndef ENTLEERER_H_H
#define ENTLEERER_H_H

#include <iostream>

#include "Observer.h"
#include "InternalDevice.h"
#include "Waage.h"

class Entleerer : public InternalDevice, public Observer {
public:

/**
* 	@brief Default constructor.
*
* 	@param g (weight)
*	@param ze (time)
*	@param wg (scale)
*
* 	@return no return
*/
    Entleerer(float g, int ze, Waage * wg);
    ~Entleerer();
	
	/**
	* 	@brief Checks, if weight was reached.
	*/
    void update();

	/**
	*	@brief Empties the mixer.
	*
	*	@param valueInput represents the amount that needs to be given out
	*
	*	Prints the weight and that the empty-process starts.
	*	Outputs cocktail as long as "doinIt" is true and gets the value of outputted fluid.
	*/
    void doIt(float valueInput);

private:

	/**
	*	Variable wich contains the output value in g/t
	*/
    float grammProZeit;
	
	/**
	*  Object from the Type "myWaage"
	*/
    Waage * myWaage;

	/**
	*	Amount to output 
	*/
    float value;

};

#endif
