#ifndef RECIPEBOOK_H_489
#define RECIPEBOOK_H_489

#include <fstream>
#include <sstream>

#include <cstdlib> // fuer exit() unter Linux

#include <iostream>

#include <list>
#include <string>
#include <exception>


#include "Recipe.h"

/**
 * @class RecipeBook
 *
 * @brief RecipeBook manages a collection of recipes
 *
 * A RecipeBook knows a list of recipes
 * You can ask for the number of recipes, query recipes by index
 * or delete a recipe
 *
 */
class RecipeBook {
  /**
  * This is the list of recipes that the RecipeBook manages
  */
 private:
  std::list<Recipe*> m_Recipe;

 public:
  /** @brief Construktor that creates a RecipeBook
  * @return A pointer to the created RecipeBook
  *
  * This method creates a RecipeBook.
  * It uses temporarily an object of the class Initialisierer
  * to initialize the list of recipes. After that the
  * Initialisierer is destroyed.
  */
  RecipeBook(void);

  /** @brief Destructor that deletes the RecipeBook
  */
  virtual ~RecipeBook();

  /** @brief Returns the number of recipes
  * @return The number of recipes in the RecipeBook
  */
  int getNumberOfRecipes();

  /** @brief fetches the i-th recipe
  * @param [in] i a positive integer for the i-th recipe
  * @return A pointer to the requested recipe object, NULL for invalid i
  *
  * This method returns the i-th recipe;
  * where i is an integer from 0 to n-1
  * where n is the number of recipes in the RecipeBook
  */
  Recipe *getRecipe(unsigned int i);

  /**
    * @brief a method for searching a Recipe by comparing the input with the m_Number
    * values of the Recipe
    * @param i contains the Recipe Number that findRecipe is searching for
    * @return returns a pointer of the searched Recipe
    */
  Recipe * findRecipe(unsigned int i);

  /** @brief Deletes the i-th recipe from the RecipeBook
  * @param [in] i a positive integer for the i-th recipe
  * @return Boolean that indicates whether the deletion was successful
  *
  * This method deletes the i-th recipe from the RecipeBook.
  * And returns true if the deletion was successful (valid i).
  * For values of i that are invalid (i <0 or i>=n) the function return false.
  */
  bool deleteRecipe(unsigned int i);

  /** @brief creates backup Recipes
  * When no file to read will be found this will be used instead.
  * It is better to use a file!
  */
  void createBackupRecipes();
/*@brief will read csv file format
 * supported format:
 * recipeName, zutatName, menge
 * string,string,float
 * @param filename file to be read
 */
  //void readFile(std::ifstream &filename);
};

#endif
