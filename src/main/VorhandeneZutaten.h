//@(#) VorhandeneZutaten.h

#ifndef VorhandeneZutaten_H_H
#define VorhandeneZutaten_H_H

#include <string>
#include <unordered_map>
#include <vector>
#include <list>
#include <fstream>
#include <cstdlib> // fuer exit() unter Linux
#include <iostream>
#include <sstream>

/**
 *  @class VorhandeneZutaten
 *  @brief Class for managing the available ingredients.
 *
 * This class inputs zhe available ingredients from a text file and manages
them.
 */
class VorhandeneZutaten {
 public:
/**
 *@brief General Constructor of VorhandeneZutaten
*/
    VorhandeneZutaten(void);

/**
* @brief copy Contructor of VorhandeneZutaten
*/
    VorhandeneZutaten(const VorhandeneZutaten &vz);

/**
 *@brief  virtual Destructor of VorhandeneZutaten
*/ 
  virtual ~VorhandeneZutaten();
/**
 *@brief outputs the avaible ingredients to the console
 *@return  has no return type
  
 */

    void browse(void);
/**
 *@brief returns ingredients at the  specified place in the vector
 *@return  a string-variable
 */

    std::string getZutat(std::string);

/**
 *@brief returns the amount of available ingredients
 *@return an interger
 */

    int getAnzahlVorhandeneZutaten();

 private:
/**
 *a data strucuture(vector) containing all the available ingredients 
as string variables
 */
    std::vector<std::string> * zutaten;

/**
* a data structure (map) containing all availablie ingredients and amount
*/

    std::unordered_map<std::string, float>* zutatenMap;
 public:
  /**
   * Getter for ZutatenMap
   * @return pointer to unordned_map
   */
  std::unordered_map<std::string, float> *getZutatenMap() const;
 private:
/**
 * a static constant boolean variable  for debugging
*/
    static const bool DEBUG = false;
/**
 *@brief reads the given text file for the ingredients
 *@return void
 *
 *this function calls ZtatenDateiEinlesen() and adds special Ingredients
*/ 
    void lesen();
/**
 *@brief add a number of different zutaten into the list of zutaten
 */
    //void DummyZutatenEinfuegen();
/**
 *@brief reads the given ingredient file
 *@param  has a string-variable as parameter
*/
    virtual void ZutatenDateiEinlesen(std::string);

/**
 *@brief adds special ingredients Stampfen und Mischen to the Vector
 *@return  no returntype
 */
    void addSpecial();
/**
 * variable containing the number of Dosers in this CocktailPro
 */
    int anzahlDosierer;
};
/**
 * a static string variable  holding the name of the file
*/

static std::string FileName;

#endif
