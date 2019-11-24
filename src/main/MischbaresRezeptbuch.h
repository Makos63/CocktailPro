//@(#) MischbaresRezeptbuch.h
/**
*	@class MischbaresRezeptbuch
*
* 	@brief outputs the available recipes
*
* 	Prints all available recipes and has the ability to check, 
* 	which recipes are possible and if not, deletes them from the current vector
*/

#ifndef MISCHBARESREZEPTBUCH_H_H
#define MISCHBARESREZEPTBUCH_H_H

#include "Recipe.h"
#include "RecipeBook.h"
#include "VorhandeneZutaten.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // fuer exit() unter Linux

/**
 *  Kennt die mischbaren Rezepte.
 *  Kann diese Ausgeben.
 *  
 */
class MischbaresRezeptbuch : public RecipeBook {
public:

	/**
	*	@brief Calls standart constructor
	*	
	*	@param ze object of "Vorhandene Zutaten"
	*
	*	prints "all available recipes before filtering"
	*	calls browse, to print the recipes
	*/
    explicit MischbaresRezeptbuch(VorhandeneZutaten * ze);
	
	/**
	*	@brief Prints Recipes.
	*
	*	prints number of recipes.
	*	then it  iterates through the vector "rezepte" and calls the browse for the object in the vector
	*/
    void browse();

private:
	/**
	*	Object of the type "myZutatenverwalter" to check, which ingredients are available
	*/
    VorhandeneZutaten * myZutatenVerwalter;

	/**
	*	vector of Recipe pointer, to store all Recipes
	*/
    std::vector<Recipe *> rezepte;

	/**
	*	@brief	deletes non available recipes
	*
	*	iterates through all recipes and checks, if all ingredients are available.
	*	if not, it deletes it, to reduce size of the vector.
	*	Look thru the lists of the cocktails recipes and get recipe steps and
	*	calls @ref gesuchteZutatenExists
	*/
    void loeschen();

	/**
	*	@brief transferes the "VorhandeneZutaten" to myZutatenVerwalter
	*
	*	@param ze pointer to VorhandeneZutaten
	*
	*	sets myZutatenVerwalter to VorhandeneZutaten
	*/
    void setZutatenVerwalter(VorhandeneZutaten * ze);
/**
 *
 * @param gesuchteZutat name of the ingredient
 * look thru the lists of the cocktails ingredient and get recipe steps
 * @return give
 */

  /**
   *
   * @param gesuchteZutat name of the ingredient
   * look thru every ingredient in given recipe and compere with given ingredient name
   * see @ref VorhandeneZutaten and getZutat()
   * @return
   */
  bool boolZutatenCheck(const std::string &gesuchteZutat) const;
};

#endif
