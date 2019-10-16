//@(#) MischbaresRezeptbuch.h

#ifndef MISCHBARESREZEPTBUCH_H_H
#define MISCHBARESREZEPTBUCH_H_H

#include "Recipe.h"
#include "RecipeBook.h"
#include "VorhandeneZutaten.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // fuer exit() unter Linux

/**
 *  Kennt die mischbaren Rezepte.
 *  Kann diese Ausgeben.
 *  
 */
class MischbaresRezeptbuch : public RecipeBook {
public:
    MischbaresRezeptbuch(VorhandeneZutaten * ze);
    void browse();

private:
    VorhandeneZutaten * myZutatenVerwalter;

    std::vector<Recipe *> rezepte;

    void loeschen();

    void setZutatenVerwalter(VorhandeneZutaten * ze);

};

#endif
