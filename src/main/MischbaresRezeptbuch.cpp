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
    for (int i = 0; i<this->getNumberOfRecipes(); i++) {
        bool ok;
        Recipe* r = getRecipe(i);
      ok = true;
        for (int j = 0; j < r->getNoOfRecipeSteps(); j++) {
            std::string gesuchteZutat;

            gesuchteZutat = r->getRecipeStep(j)->getZutat();
          ok = gesuchteZutatenExists(gesuchteZutat);

        }
        if (!ok) {
            deleteRecipe(i);
        }
    }
}
bool MischbaresRezeptbuch::gesuchteZutatenExists(const std::string &gesuchteZutat) const {
  bool ok = true;
  bool z_ok;
//todo that can be probably deleted
  z_ok = gesuchteZutatExists(gesuchteZutat);
  if (!z_ok) {
    ok = false;
  }
  return ok;
}
bool MischbaresRezeptbuch::gesuchteZutatExists(const std::string &gesuchteZutat) const {
  bool z_ok;
  for (int k = 0; k < myZutatenVerwalter->getAnzahlVorhandeneZutaten(); k++) {
      if (myZutatenVerwalter->getZutat(k) == gesuchteZutat) {
        z_ok = true;
          break;
      }
  }
  return z_ok;
}
