//@(#) Dosierer.h

#ifndef DOSIERER_H_H
#define DOSIERER_H_H

#include <string>
#include <iostream>

#include "Observer.h"
#include "InternalDevice.h"
#include "Waage.h"
/**
 *@class Dosierer
 *
 * @brief is responsible for opening the output to glass.
 *
 * Multiple Inheritance form class InternlDevice and Observer
 * It????
 */

class Dosierer : public InternalDevice, public Observer {
public:
  /**
   * @brief Initialise Dosierer and set an Observer
   *
   * @param g weight of the substance
   * @param ze amount of time for how long the output has to be enable in s;
   * @param i the name of the substance
   * @param wg instance of Waage
   */
    Dosierer(float g, int ze, std::string i, Waage * wg);
  Dosierer();
  /**
   * @brief check if needed amount has been used, if not than it wont change doinIt to false
   */
    virtual void update();


 /**
  * @brief Open the vents and outputs the substance until required amount has been reached.
  * Increment die scale dependent on the weight of the input
  * @param gramm amount of gramm to be processed in float
  */
    void doIt(float gramm);

    /**
     *
     * @return give back how many grams are leaving the Dosierer per second
     */
    int getStueckProZeit();

private:
  /**
   * It is the amount of output of the Dosier in time
   */
    float grammProZeit;
/**
 * That is instance of Waage used to weight the cocktail
 */
    Waage * myWaage;
/**
 * This float is the amount in g to be processed
 */
    float gwicht;
/**
 * Is the name of substance
 */
    std::string inhalt;
};

#endif
