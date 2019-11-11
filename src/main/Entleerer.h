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
* 	@param Gets Parmeter: weight (g)
*	@param Gets Parmeter: time (ze) 
*	@param Gets Parmeter: scale (wg)
*
* 	@return no return
*/
    Entleerer(float g, int ze, Waage * wg);
    ~Entleerer();
	
	/**
	* 	@brief Checks, if weight was reached.
	*
	* 	@param no parameters
	*
	* 
	*/
    void update();

	/**
	*	@brief Empties the mixer.
	*
	*	@param takes the float "value"
	*
	*	Prints the weight and that the empty-process starts.
	*	Outputs cocktail as long as "doinIt" is true and gets the value of outputted fluid.
	*/
    void doIt(float value);

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
