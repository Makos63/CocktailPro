//@(#) CocktailPro.h
/**
* @class CocktailPro
*
* @brief Manager class which main task is to supervise @see CocktailZubereiter, @see DeviceVerwalter, @see MischbaresRezeptbuch, @see VorhandeneZutaten
*
* Shows welcome text to start of the program, is also responsible for main logic of CocktailPro.
*/


#ifndef COCKTAILPRO_H_H
#define COCKTAILPRO_H_H

#include "DeviceVerwalter.h"
#include "VorhandeneZutaten.h"
#include "MischbaresRezeptbuch.h"
#include "CocktailZubereiter.h"

/**
* @class CocktailPro
*
* @brief Manager class which main task is to supervise @see CocktailZubereiter, @see DeviceVerwalter, @see MischbaresRezeptbuch, @see VorhandeneZutaten
*
* Shows welcome text to start of the program, is also responsible for main logic of CocktailPro.
*/


class CocktailPro {
 protected:

  /**
   * @brief bool for Testclass to break infinite loop
   */
  bool test = true;

  /** @defgroup CocktailProMain Manager
 *  This is are instances of another parts of the program
 */
 /**@{*/
  /**
   * Singelton pattern of CocktailZubereiter
   */
    CocktailZubereiter * theCocktailZubereiter;

 protected:
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
/**@} */ 

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
  //TODO change description of debug mode
   /**
    * @brief constructor for CocktailPro
    * gives the exec modes of the CocktailPro, -d Debug
    * @param argc number of arguments,
    * @param turbo similar to main(argc*, argv**),
    */
    CocktailPro(int argc, char * * turbo);

  /**
 * @brief copy constructor for CocktailPro
 *
 * @param &org copy of CocktailPro
 */
    CocktailPro(const CocktailPro &org);


  /**
   * @brief print welcome in the program and starts method weahle() .
   */
    void start();

/**
 * @brief checks if recipe exists at input
 * @return bool
 */
  bool inputCheck(unsigned int);

};

#endif
