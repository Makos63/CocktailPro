//@(#) CocktailZubereiter.h

#ifndef COCKTAILZUBEREITER_H_H
#define COCKTAILZUBEREITER_H_H



#include "Recipe.h"
#include "RecipeBook.h"
#include "DeviceVerwalter.h"


/**
 * @class CocktailZubereiter
 *
 * @brief is responsible for preparing chosen cocktail
 *
 * awaits recipe and directs them to DeviceVerwalter.
 *
 */
class CocktailZubereiter {
public:


  /**
   *
   * @brief constructor for CocktailZubereiter require an instance of DeviceVerwalter
   *
   * @param dv instance of DeviceVerwalter.
   */

    CocktailZubereiter(DeviceVerwalter * dv);
/**
   *@brief logic of mixing a cocktail and control of DeviceVerwalter
   *
   * Print welcome message of CocktailZubereiter with chosen recipe. Afterwards look after required steps
   * and get needed ingredients with appropriate amount. Next give all steps to DeviceVerwalter. Clean
   * after is done and close the valves.
   *
   *
   * @param rzpt instance of recipe
   * @return returns true when cocktail is done
   */
    bool cocktailZubereiten(Recipe * rzpt);

private:
  /**
   * It is needed for communication with DeviceVerwalter.-
   */
    DeviceVerwalter * myDeviceVerwalter;


};

#endif
