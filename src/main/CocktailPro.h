//@(#) CocktailPro.h

#ifndef COCKTAILPRO_H_H
#define COCKTAILPRO_H_H

#include "DeviceVerwalter.h"
#include "VorhandeneZutaten.h"
#include "MischbaresRezeptbuch.h"
#include "CocktailZubereiter.h"

/**
 * @class Cocktailpro
 *
 * @brief Manager class which main task is to supervise CocktailZubereiter, DeviceVerwalter, MischbaresRezepbucb, Vorhandenezutaten.
 *
 * Shows welcome text to start of the program,
 * is also responsible for main logic of CocktailPro.
 */
class CocktailPro {
 protected:
  /**
   * protected variables to another parts of the program
   */
  /**
   * Singelton pattern of CocktailZubereiter
   */
    CocktailZubereiter * theCocktailZubereiter;
  /**
   * Singelton pattern of DeviceVerwalter
   */
    DeviceVerwalter * theDeviceVerwalter;
  /**
   * Singelton pattern of MischbaresRezeptbuch
   */
    MischbaresRezeptbuch * theMischbaresRezeptbuch;
  /**
   * Singelton pattern of VorhandeneZutaten
   */
    VorhandeneZutaten * theZutatenVerwalter;

 protected:
  /**
   * @brief show all possible cocktails and give which one was selected.
   *
   * This method look after possible cocktails based on the available ingredients and wait for user to chose one.
   * If user selects one, that does not have enough ingredients than it will await new input.
   * known bug:
   * input will crash after multiple writing and deleting of input
   *
   * @return Will return integer of chosen cocktail formula.
   */
    int waehle();
    /**
     * @brief test method of waehle(), input is hardcoded aka. unittest
     *
     * Hardcoded method with one cocktail, to se if program is working.
     *
     * @return no return, void.
     */
    void demo();

 public:
  /**
   * @brief constructor for @class CocktailPro
   * gives the exec modes of the CocktailPro, gives the speed of execution slow or fast. usage: -D,  "-D means fast"
   *
   * @param argc number of arguments,
   * @param **turbo similar to main(argc*, argv**),
   *
   */
    CocktailPro(int argc, char * * turbo);


  /**
   * @brief print welcome in the program and starts method weahle() .
   */
    void start();


};

#endif
