
#include <algorithm>

#include "RecipeStep.h"

/**
 * Konstruktor 
 *  
 */
RecipeStep::RecipeStep(void): mZutat(""), mMenge(0) {
}

RecipeStep::~RecipeStep() {
}

std::string RecipeStep::getZutat(void) const {
    return mZutat;
}

float RecipeStep::getMenge(void) const {
    return mMenge;
}

void RecipeStep::setZutat(std::string zutat) {
    this->mZutat = zutat;
}

void RecipeStep::setMenge(float menge) {
    this->mMenge = menge;
}
