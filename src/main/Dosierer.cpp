//@(#) Dosierer.cpp


#include "Dosierer.h"



Dosierer::Dosierer(float g, int ze, std::string i, Waage * wg) : InternalDevice(), myWaage(wg), gwicht(0.00), inhalt(i) {
    this->grammProZeit = g;
    this->zeitEinheit = ze;
    //this->inhalt = i;
    //this->myWaage = wg;
    this->myWaage->attach(this);
    //this->gwicht = 0.00;
}

void Dosierer::update() {
    if (!this->outputEnable) return;
    if (myWaage->getDelta() >= gwicht) {
      outputEnable = false;
    }

}

void Dosierer::doIt(float gramm) {
    this->gwicht = gramm;
    myWaage->tara();
  outputEnable = true;
    std::cout << inhalt << " Ventil wurde geoeffnet" << std::endl;

    while (doinIt) {
        myTimer->sleepInOneSecondIntervals(zeitEinheit);

    while (outputEnable) {
        myTimer->sleepInOneSecondIntervals(zeitEinheit);

        myWaage->changeWeight(grammProZeit);
        //myWaage->changeWeight(0);
    }
    std::cout << std::endl << inhalt << " Ventil wurde geschlossen" << std::endl;
    std::cout << "Es wurden " << myWaage->getDelta() << "g " << inhalt << " abgefuellt" << std::endl;
    std::cout << std::endl;
}

int Dosierer::getStueckProZeit() {
    return this->grammProZeit;
}

