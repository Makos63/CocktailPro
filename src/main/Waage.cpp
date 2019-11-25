//@(#) Waage.cpp


#include "Waage.h"


Waage::Waage(){
  weight = 0;
  deltaWeight =0;
}


Waage::Waage(const Waage &org){
  this->weight = org.weight;
  this->deltaWeight = org.deltaWeight;
}

void Waage::changeWeight(int v) {
    weight += v;
    if (weight < 0)
        weight = 0;
    deltaWeight += v;
    notify();
}

int Waage::tara() {
    return deltaWeight = 0;
}

int Waage::getWeight() {
    return weight;
}

int Waage::getDelta() {
    return deltaWeight;
}

