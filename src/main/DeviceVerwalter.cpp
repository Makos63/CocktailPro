//@(#) DeviceVerwalter.cpp


#include "DeviceVerwalter.h"

DeviceVerwalter::DeviceVerwalter(VorhandeneZutaten *zv) {
  setZutatenVerwalter(zv);
  this->createDevices();
}

void DeviceVerwalter::createDevices() {
  theWaage = new Waage();
  myDevices = new std::map<std::string, InternalDevice *>;

  myEntleerer = new Entleerer(25, 1000, theWaage);
  myDevices->insert(std::make_pair("Entleeren", myEntleerer));

  myStampfer = new Stampfer();
  myDevices->insert(std::make_pair("Stampfen", myStampfer));

  mySchuettler = new Schuettler();
  myDevices->insert(std::make_pair("Schuetteln", mySchuettler));

  myMixer = new Mixer();
  myDevices->insert(std::make_pair("Mischen", myMixer));

  std::string myZutat;
  //std::map<std::string, int> *t= myZutatenVerwalter->getZutatenMap();

  for (auto j = myZutatenVerwalter->getZutatenMap()->begin();
       j != myZutatenVerwalter->getZutatenMap()->end(); ++j) {
    myZutat = j->first;
    if (myZutat == "Eis")
      myDevices->insert(std::make_pair(myZutat, new Dosierer(20, 1000, myZutat, theWaage)));
    else if (myZutat == "Limettenstuecke")
      myDevices->insert(std::make_pair(myZutat, new Dosierer(10, 1000, myZutat, theWaage)));
    else
      myDevices->insert(std::make_pair(myZutat, new Dosierer(1, 1000, myZutat, theWaage)));
  }
}

void DeviceVerwalter::setZutatenVerwalter(VorhandeneZutaten *zv) {
  myZutatenVerwalter = zv;
}

void DeviceVerwalter::rezeptSchrittZubereiten(std::string zutat, float menge) {

  std::unordered_multimap<std::string, float> *zutatenMap = myZutatenVerwalter->getZutatenMap();
  auto iterator = zutatenMap->find(zutat);


  if (zutat == "Limettenstuecke") {
    int stckProZeit = reinterpret_cast<Dosierer *>(myDevices->at(zutat))->getStueckProZeit();


    myDevices->at(zutat)->doIt(menge * stckProZeit);

  } else {
    myDevices->at(zutat)->doIt(menge);
  }

  //old
  //iterator->second = iterator->second - menge;


  //is there enough in the container?
  //if not search for container which has something in it
  //else give up searching

  int rest = menge;
  while (rest > 0) {
    if (iterator->second > 0) {
      iterator->second = iterator->second - 1;
      --rest;
    } else {

      for (auto secondContainer = zutatenMap->begin(); secondContainer != zutatenMap->end();
           ++secondContainer) {

        if (iterator->first == secondContainer->first && secondContainer->second > 0) {
          while (rest > 0) {
            secondContainer->second = secondContainer->second - 1;
            --rest;
          }
        }
      }
    }
  }

}


void DeviceVerwalter::entleeren(float menge) {
  myEntleerer->doIt(menge);
}

void DeviceVerwalter::putzen() {
  for (std::map<std::string, InternalDevice *>::iterator i = myDevices->begin();
       i != myDevices->end(); ++i) {
    std::cout << "Device mit der Aktion: " << i->first << " wird jetzt geputzt: " << std::endl;
    i->second->putzen();
  }

}
void DeviceVerwalter::printWarning() {
  std::unordered_multimap<std::string, float> *zutatenMap = myZutatenVerwalter->getZutatenMap();
  std::unordered_map<std::string, bool>
      *alreadyPrinted = new std::unordered_map<std::string, bool>();
  //std::unordered_map<std::string, bool> alreadyPrinted;

  for (auto it = zutatenMap->begin(); it != zutatenMap->end(); ++it) {
    checkForProcentage(alreadyPrinted, it);
  }
  delete alreadyPrinted;
}
void DeviceVerwalter::checkForProcentage(std::unordered_map<std::string, bool> *alreadyPrinted,
                                         const std::unordered_multimap<std::string,
                                                                       float>::iterator &it) {
  if (it->first != "Limettenstuecke"
      && it->second <= 1000 * 0.2
      && alreadyPrinted->find(it->first) == alreadyPrinted->end()) {

    std::cout << "ACHTUNG: Zutat " << it->first << " ist unter 20% ..." << std::endl;
    alreadyPrinted->insert(std::pair<std::string, bool>(it->first, false));

  } else if (checkForSpecial(it->first)
      && checkForDouble(it->first) <= 200 * 0.2
      && alreadyPrinted->find(it->first) == alreadyPrinted->end()) {

    std::cout << "ACHTUNG: Zutat " << it->first << " ist unter 20% ..." << std::endl;
    alreadyPrinted->insert(std::pair<std::string, bool>(it->first, false));
  }
}

void DeviceVerwalter::printAmount() {
  std::unordered_multimap<std::string, float> *zutatenMap = myZutatenVerwalter->getZutatenMap();
  std::map<std::string, bool> *alreadyPrinted = new std::map<std::string, bool>();

  for (auto it = zutatenMap->begin(); it != zutatenMap->end(); ++it) {

    if (checkForSpecial(it->first) && alreadyPrinted->find(it->first) == alreadyPrinted->end()) {
      alreadyPrinted->insert(std::pair<std::string, bool>(it->first, false));
      std::cout << "Zutat " << it->first << " besitzt den Fuellstand: " << checkForDouble(it->first)
                << std::endl;
    }
  }
  delete alreadyPrinted;
}

float DeviceVerwalter::checkForDouble(std::string ingredient) {
  std::unordered_multimap<std::string, float> *zutatenMap = myZutatenVerwalter->getZutatenMap();
  float amountOfSecondContainer = 0;


  for (auto &ing1 : *zutatenMap) {
    if (ing1.first == ingredient && checkForSpecial(ingredient)) {
      amountOfSecondContainer += ing1.second;
    }
  }


  return amountOfSecondContainer;
}

bool DeviceVerwalter::checkForSpecial(const std::string &ingredient) {
  return !(ingredient == "Schuetteln" || ingredient == "Mischen" || ingredient == "Stampfen");
}

