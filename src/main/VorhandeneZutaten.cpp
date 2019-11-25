//@(#) VorhandeneZutaten.cpp

#include "VorhandeneZutaten.h"
//

VorhandeneZutaten::VorhandeneZutaten(void) {
    this->zutaten = new std::vector<std::string>;
    lesen();
    this->anzahlDosierer = zutaten->size();

}
VorhandeneZutaten::VorhandeneZutaten(const VorhandeneZutaten &vz) {
    //TODO zutaten schould be initialised in lesen()
    this->zutaten = new std::vector<std::string>;
    lesen();
    this->anzahlDosierer = vz.anzahlDosierer;

}


VorhandeneZutaten::~VorhandeneZutaten(void) {
 //TODO potencial memoryleak
}

void VorhandeneZutaten::ZutatenDateiEinlesen(std::string myfile) {
    std::ifstream in;

    fileName = myfile;

    in.open(fileName.c_str(), std::ios::in); // c_str wandelt den String in char[]
    // das braucht fstream

    if (!in) {// File konnte nicht geoeffnet werden
        std::string myException = "File not found: " + fileName;
        std::cout << myException << std::endl;
        throw myException;
    }

    std::cout << "Oeffne Zutatendatei " << fileName << std::endl;

    std::string zeile;
    while (getline(in, zeile)) {

        // Cut trailing \r - to make Linux or Windows Files equal
        if (zeile.size() && zeile[zeile.size() - 1] == '\r') {
            zeile = zeile.substr(0, zeile.size() - 1);
        }

        this->zutaten->push_back(zeile);
    }
    in.close();
}

/*void VorhandeneZutaten::DummyZutatenEinfuegen() {
    zutaten->push_back("Limettenstuecke");
    zutaten->push_back("Zucker");
    zutaten->push_back("Cointreau");
    zutaten->push_back("Eis");
    zutaten->push_back("Wodka");
    zutaten->push_back("Rum weiss");
    zutaten->push_back("Zitronensaft");
    zutaten->push_back("Grenadine");
    //    zutaten->push_back("Limettensaft");
    //    zutaten->push_back("Tequilla");
    //    zutaten->push_back("Gin");
    //    zutaten->push_back("Noilly Prat");
}*/

void VorhandeneZutaten::lesen() {
    // int einlesen(list<string>* zutaten, std::string FileName)
    // Stream anlegen

        if (DEBUG) {//TODO  this part should be rewritten with define makros etc, using this code fragment should be based on compiler option. looks like pseudo unit-test

            //DummyZutatenEinfuegen();
        } else {
            ZutatenDateiEinlesen("zutaten.txt");
        }

            this->browse();

        addSpecial();
}

void VorhandeneZutaten::browse(void) {
    std::cout << "*********** Verfuegbare Einheiten bzw. Zutaten: ***********" << std::endl;
    for (unsigned int i = 0; i < zutaten->size(); i++/*std::string zutat : zutaten*/) {
        std::cout << zutaten->at(i) << std::endl;
    }
    std::cout << "**********************************************************" << std::endl;
}

void VorhandeneZutaten::addSpecial() {
    zutaten->push_back("Mischen");
    zutaten->push_back("Stampfen");
}

std::string VorhandeneZutaten::getZutat(int i) {
    return zutaten->at(i);
}

int VorhandeneZutaten::getAnzahlVorhandeneZutaten() {
    return zutaten->size();
}
