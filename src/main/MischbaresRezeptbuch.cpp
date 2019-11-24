//@(#) MischbaresRezeptbuch.cpp


#include "MischbaresRezeptbuch.h"
#include <iostream>
//

void MischbaresRezeptbuch::browse() {
    std::cout << "*********************************************" << std::endl;
    std::cout << "Es gibt " << this->getNumberOfRecipes() << " Cocktails" << std::endl;

    for (int i = 0; i<this->getNumberOfRecipes(); i++) {
        Recipe* r = this->getRecipe(i);
        std::cout << i + 1 << ". ";
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

void MischbaresRezeptbuch::loeschen() {
  for (int i = 0; i < this->getNumberOfRecipes(); i++) {
    bool ok;
    Recipe* r = getRecipe(i);
    ok = true;
    for (int j = 0; j < r->getNoOfRecipeSteps(); j++) {
      std::string gesuchteZutat;

      gesuchteZutat = r->getRecipeStep(j)->getZutat();
      bool z_ok = false;

      z_ok = boolZutatenCheck(gesuchteZutat);

      if (!z_ok) {
        ok = false;
      }
    }
    if (!ok) {
      deleteRecipe(i);
      --i;
    }
  }
}

bool MischbaresRezeptbuch::boolZutatenCheck(const std::string &gesuchteZutat) const {
  for (int k = 0; k < myZutatenVerwalter->getAnzahlVorhandeneZutaten(); k++) {
    if (myZutatenVerwalter->getZutat(k) == gesuchteZutat) {
      return true;
    }
  }
  return false;
}