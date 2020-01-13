//@(#) MischbaresRezeptbuch.cpp


#include "MischbaresRezeptbuch.h"
#include <iostream>
//

void MischbaresRezeptbuch::browse() {
    std::cout << "*********************************************" << std::endl;
    std::cout << "Es gibt " << this->getNumberOfRecipes() << " Cocktails" << std::endl;

    for (int i = 0; i<this->getNumberOfRecipes(); i++) {
        Recipe* r = this->getRecipe(i);
        std::cout << r->getRecipeNumber()<<". ";
        r->browse();
        std::cout << std::endl;
    }
    std::cout << "*********************************************" << std::endl;

}

MischbaresRezeptbuch::MischbaresRezeptbuch(VorhandeneZutaten * zv) {

    // Debug *********
    std::cout << "********** Rezepte vor dem Filtern **********" << std::endl;
    this->browse();
    // ******************

    setZutatenVerwalter(zv);
  loeschen();
}

void MischbaresRezeptbuch::setZutatenVerwalter(VorhandeneZutaten * zv) {
    myZutatenVerwalter = zv;
}

void MischbaresRezeptbuch::loeschen() {                         //besser dekrementieren
// int i = getnumberofrecipies-1; i > 0 ;i--)
  for (int i = this->getNumberOfRecipes()-1; i >= 0; i--) {
    bool ok;
    Recipe* r = getRecipe(i);
    ok = true;
    for (int j = 0; j < r->getNoOfRecipeSteps(); j++) {
      std::string gesuchteZutat;
      int gesuchteMenge = r->getRecipeStep(j)->getMenge();
      gesuchteZutat = r->getRecipeStep(j)->getZutat();

      bool z_ok = boolZutatenCheck(gesuchteZutat, gesuchteMenge);

      if (!z_ok) {
        ok = false;
      }
    }
    if (!ok) {
      deleteRecipe(i);
    }
  }
  if(this->getNumberOfRecipes() == 0){
    std::cout << "##########################################################" << std::endl;
    std::cout<< "WARNUNG, KEINE COCKTAILS MEHR MISCHBAR, BITTE NACHFUELLEN!" << std::endl;
    std::cout << "##########################################################" << std::endl;
  }
}

bool MischbaresRezeptbuch::boolZutatenCheck(const std::string &gesuchteZutat, int gesuchteMenge) const {
    if (myZutatenVerwalter->getZutat(gesuchteZutat) == gesuchteZutat) {
      if(myZutatenVerwalter->getMenge(gesuchteZutat) >= gesuchteMenge) {
        return true;
      }
    }
  return false;
}