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

  /*for (int i = myZutatenVerwalter->getAnzahlVorhandeneZutaten()-1; i >= 0; i--) {
      myZutat=myZutatenVerwalter->getZutat(i);
      if (myZutat == "Eis")
          myDevices->insert(std::make_pair(myZutat, new Dosierer(20, 1000, myZutat, theWaage)));
      else if (myZutat == "Limettenstuecke")
          myDevices->insert(std::make_pair(myZutat, new Dosierer(10, 1000, myZutat, theWaage)));
      else
          myDevices->insert(std::make_pair(myZutat, new Dosierer(1, 1000, myZutat, theWaage)));
  }*/
}

void DeviceVerwalter::setZutatenVerwalter(VorhandeneZutaten *zv) {
  myZutatenVerwalter = zv;
}

void DeviceVerwalter::rezeptSchrittZubereiten(std::string zutat, float menge) {

  //std::map<std::string, InternalDevice *>::iterator tmpDevice;

  //tmpDevice = myDevices->find(zutat);
  std::unordered_map<std::string, float> *zutatenMap = myZutatenVerwalter->getZutatenMap();
  auto iterator = zutatenMap->find(zutat);


  if (zutat == "Limettenstuecke") {
    // Der Kunde will Limetten ja unbedingt nach Stueck und nicht nach Gewicht abmessen...
    //int stckProZeit = ((Dosierer *) myDevices->at(zutat))->getStueckProZeit();
    int stckProZeit = reinterpret_cast<Dosierer *>(myDevices->at(zutat))->getStueckProZeit();
    myDevices->at(zutat)->doIt(menge * stckProZeit);

  } else {
    myDevices->at(zutat)->doIt(menge);
  }
  iterator->second = iterator->second - menge;

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
  std::unordered_map<std::string, float> *zutatenMap = myZutatenVerwalter->getZutatenMap();

  for (auto it = zutatenMap->begin(); it != zutatenMap->end(); ++it) {
    if (it->first != "Limettenstuecke" && it->second <= 1000 * 0.2) {
      std::cout << "ACHTUNG: Zutat " << it->first << " ist unter 20% ..." << std::endl;
    }
    else if(it->second <= 100*0.2){
      std::cout << "ACHTUNG: Zutat " << it->first << " ist unter 20% ..." << std::endl;
    }
  }

}

void DeviceVerwalter::printAmount(){
  std::unordered_map<std::string, float> *zutatenMap = myZutatenVerwalter->getZutatenMap();

  for (auto it = zutatenMap->begin(); it != zutatenMap->end(); ++it) {

    if(checkForSpecial(it->first)==true) {

      std::cout << "Zutat " << it->first << " besitzt den Fuellstand: " << checkForDouble(it->first)<< std::endl;
    //std::cout << "Zutat " << it->first << " besitzt den Fuellstand: " << it->second << std::endl;
    }
  }
}

int DeviceVerwalter::checkForDouble(std::string ingredient) {
  int o = 0;
  std::unordered_map<std::string, float> *zutatenMap = myZutatenVerwalter->getZutatenMap();
  auto checkForSecond = zutatenMap->find(ingredient);
  for (auto it = zutatenMap->begin(); it != zutatenMap->end(); ++it){
    for(int i = 0; i <13; ++i){
      if(it->first != doubleIngredients[i]){

        if(it == checkForSecond){                                                                   //er springt nicht hier rein, obwohl er es sollte. bitte nochmal nachschauen
          return it->second;
        }
        else{
          doubleIngredients[o] = it->first;
          ++o;
          return 0/*it->second + checkForSecond->second*/;
        }
      }
      else{continue;}
    }
  }

  return 0;
}

bool DeviceVerwalter::checkForSpecial(std::string ingredient){
  if(ingredient == "Schuetteln" || ingredient == "Mischen" || ingredient == "Stampfen"){
    return false;
  }
  else return true;
}