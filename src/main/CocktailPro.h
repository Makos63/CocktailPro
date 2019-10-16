//@(#) CocktailPro.h

#ifndef COCKTAILPRO_H_H
#define COCKTAILPRO_H_H

#include "DeviceVerwalter.h"
#include "VorhandeneZutaten.h"
#include "MischbaresRezeptbuch.h"
#include "CocktailZubereiter.h"

/**
 * Gesamtsystem
 *  
 */
class CocktailPro {
 protected:
    CocktailZubereiter * theCocktailZubereiter;

    DeviceVerwalter * theDeviceVerwalter;

    MischbaresRezeptbuch * theMischbaresRezeptbuch;

    VorhandeneZutaten * theZutatenVerwalter;

 protected:
    int waehle();
    void demo();

 public:
    CocktailPro(int argc, char * * turbo);
    void start();


};

#endif
