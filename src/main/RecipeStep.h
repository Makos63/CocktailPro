#ifndef _REZEPTSCHRITT_H_472
#define _REZEPTSCHRITT_H_472

#include <list>
#include <string>

/**
* @class RecipeStep
*
* @brief RecipeStep manages step by step of the Recipe
*
* also shows the name of ingredient and amount of ingredient for the Recipe
* you can use the name of ingredient and amount of ingredient in class Recipe by calling the function
*/

class RecipeStep {
 private:

/**
* this is the name of ingredient that RecipeStep manages
*/

    std::string mZutat;

/**
*This is amount of ingredient that RecipeStep manages
*/
    float mMenge;

 public:

/**
* @brief constructor that create RecipeStep
*
* declaration of the constructor has no parameters
* initialize the name of ingredient and amount of ingredient
*/

    RecipeStep(void);

/**
* @brief destructor for class RecipeStep
*/

    ~RecipeStep();

/**
* @brief returns the name of ingredients
* declaration of getZutat has no parameters
* @return string is the name of ingredient
*/

    std::string getZutat(void) const;

/**
* @brief returns amount of ingredient
* declaration of getMenge has no parameters
* @return float is amount of ingredient
*/
    float getMenge(void) const;

/**
* @brief set the name of ingredient
* @param zutat is a string and a name of ingredient
*
* copy of zutat
*/
    void setZutat(std::string zutat);

/**
* @brief set amount of ingredient
* @param menge is a float and amount of the ingredient
*
* copy of menge
*/

    void setMenge(float menge);

};
#endif
