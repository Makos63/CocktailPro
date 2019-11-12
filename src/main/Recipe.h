#ifndef _REZEPT_H_479
#define _REZEPT_H_479

#include "RecipeStep.h"

#include <list>
#include <string>

/**
* @class Recipe
*
* @brief manages a list of RecipeStep
*
* it controls and shows the list of RecipeStep
*/

class Recipe {
private:

/**
* this is the list of RecipeStep
*/

    std::list<RecipeStep*> m_RecipeStep;

/**
* this is the name of the Recipe
*/

    std::string m_Name;

public:

/**
* @brief is a constructor for class Recipe
* declaration of constructor has no parameters
*
* initialize the list of RecipeStep and its name
*/

    Recipe(void);

/**
* @brief destructor for class Recipe
*/

    ~Recipe();

/**
* @brief returns size of RecipeSteplist
* declaration of getNoOfRecipeSteps has no parameters
* @return int is size of RecipeSteplist
*/

    int getNoOfRecipeSteps();

/**
* @brief fetches the i-th RecipeStep
* @param [in] i a positive integer for the i-th recipe
* @return A pointer to the requested recipe object, NULL for invalid i
*
* this method returns the i-th recipe;
* where i is an integer from 0 to n-1
* where n is the number of recipesteps in the Recipe
*/

    RecipeStep * getRecipeStep(unsigned int i);

/**
* @brief returns the name of the Recipe or its title
* declaration of getName has no parameters
* @return string is the name of Recipe or its title
*/

    std::string getName(void) const;

/**
* @brief set the name of Recipe
* @param Name is a string and a name of Recipe
*
* copy of Name
*/
    void setName(const std::string& Name);

/**
* @brief make a list of RecipeStep with the name of ingredient and amount of ingredient
* @param z is a string and a name of ingredient
* @param m is a float and amount of ingredient
*
* this method creates a Recipe
* It uses temporarily an object of the class Initialisierer
* to initialize the list of RecipeSteps
*/

    void appendStep(std::string z, float m);

/**
* @brief shows the list of RecipeSteps
* declaration of browse has no parameters
* output of the Recipe
*/
    void browse();

};

#endif
