//@(#) CocktailPro.cpp

/**
 *
 *
 */
#include "CocktailPro.h"
#include <string>

void CocktailPro::start(){
    while (true) {
        int CocktailNo = waehle();
            Recipe * rezeptptr = theMischbaresRezeptbuch->findRecipe(CocktailNo);
            if(rezeptptr !=NULL){
              std::cout << rezeptptr->getName() << std::endl;
              theCocktailZubereiter->cocktailZubereiten(rezeptptr);
        } else {
              std::cout << "Falsche Cocktailnummer!" << std::endl;
            }
      if(test){break;}
    }

}
/*
CocktailPro::CocktailPro(const CocktailPro &org) {
  theZutatenVerwalter = new VorhandeneZutaten(*org.theZutatenVerwalter);
  theMischbaresRezeptbuch = new MischbaresRezeptbuch(*org.theMischbaresRezeptbuch);
  theDeviceVerwalter = new DeviceVerwalter(*org.theDeviceVerwalter);
  theCocktailZubereiter = new CocktailZubereiter(*org.theCocktailZubereiter);

}
*/


CocktailPro::CocktailPro(int argc, char * * param, bool m_test) {
    theZutatenVerwalter = new VorhandeneZutaten();
    theMischbaresRezeptbuch = new MischbaresRezeptbuch(theZutatenVerwalter);
    theDeviceVerwalter = new DeviceVerwalter(theZutatenVerwalter);
    theCocktailZubereiter = new CocktailZubereiter(theDeviceVerwalter);
    test = m_test;


    Timer * theTimer = Timer::getInstance();
    if (argc == 2) {// this has to be changed later
        if (std::string(param[1]) == "-D") {
            theTimer->set_Turbo(1000);
            this->demo();
            exit(0);
        } else { // Parameter => Turbo an
            theTimer->set_Turbo(10);
        }
    }
    // Mischen
}

void CocktailPro::demo() {
    int CocktailNo = 1;
        Recipe * rezeptptr = theMischbaresRezeptbuch->findRecipe(CocktailNo);
        if(rezeptptr !=NULL){
        std::cout << rezeptptr->getName() << std::endl;
        theCocktailZubereiter->cocktailZubereiten(rezeptptr);
    } else {
        std::cout << "Falsche Cocktailnummer!" << std::endl;
    }
}


int CocktailPro::waehle() {
    while (true) {
        std::cout << "********** Mischbare Rezepte **********" << std::endl;
        theMischbaresRezeptbuch->browse();
        theDeviceVerwalter->printWarning();
        std::cout << "Was haetten Sie denn gern? (-1 zum Verlassen)" << std::endl;

        std::string eingabe = "";

        //cin.ignore();       
        std::cin >> eingabe;

        int zahl = atoi(eingabe.c_str());

        if (zahl == -1) {
        exit(0);
        }
      if(inputCheck(zahl)) {
        return zahl;
      } else {
        std::cout << "Wrong input" << std::endl;
      }
    }
}
bool CocktailPro::inputCheck(unsigned int i) {
  if(theMischbaresRezeptbuch->findRecipe(i) != NULL) {
    return true;
  }
  return false;
}



