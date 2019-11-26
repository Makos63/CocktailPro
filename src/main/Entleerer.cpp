//@(#) Entleerer.cpp


#include "Entleerer.h"

Entleerer::Entleerer(float g, int ze, Waage * wg) : InternalDevice() {
    this->grammProZeit = g;
    this->zeitEinheit = ze;
    this->myWaage = wg;
    this->myWaage->attach(this);
    this->value = 0.0;
}

Entleerer::~Entleerer(){

}

//

void Entleerer::update() {
    if (!this->outputEnable) return;
    if (myWaage->getWeight() <= this->value)
      outputEnable = 0;
}

void Entleerer::doIt(float valueInput) {
  std::cout << "Ihr Cocktail hat ein Gesamtgewicht von " << myWaage->getWeight() << "g"
            << std::endl;
  std::cout << "Entleervorgang wird begonnen..." << std::endl;
  this->value = valueInput;

  doIt = 1;
  while (doIt) {
    myTimer->sleepInOneSecondIntervals(zeitEinheit);

    outputEnable = 1;
    while (outputEnable) {
      myTimer->sleepInOneSecondIntervals(zeitEinheit);

      myWaage->changeWeight(-grammProZeit);
    }
    std::cout << std::endl;
    std::cout << "Entleervorgang wurde beendet, bitte entnehmen Sie ihren Cocktail!" << std::endl;
    std::cout << std::endl;
  }
}