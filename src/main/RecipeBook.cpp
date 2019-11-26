/**********************************************************************************/
/*                                 Definitionsmodul                               */
/**********************************************************************************/
/*
 * File       : RecipeBook.cpp
 *
 */

#include <algorithm>

#include "RecipeBook.h"

RecipeBook::RecipeBook(void) {

    mRecipe.clear();
    
       // Stream anlegen
    std::ifstream in;

  mRecipe.clear();
  std::string fileName = "Rezepte.csv";

   try {
     std::ifstream in;



     in.open(fileName.c_str(), std::ios::in);
     if(!in){
       throw "File Rezepte.csv could not be found or opened..";
     }
     readFile(in);
   }catch(const char* e){
     std::cout <<e<<std::endl;
     std::cout <<"creating backup recipes..."<<std::endl;
     createBackupRecipes();
   }
   catch(...){
     std::cout<<"sth went really wrong.."<<std::endl;
   }
}



RecipeBook::~RecipeBook() {
  mRecipe.clear();
}


    r1 = new Recipe;
    r1->setName("Caipirinha");
    r1->appendStep("Limettenstuecke", 8);
    r1->appendStep("Zucker", 15);
    r1->appendStep("Stampfen", 20);
    r1->appendStep("Eis", 90);
    r1->appendStep("Cachaca", 5);
    r1->appendStep("Mischen", 10);
    this->mRecipe.push_back(r1);

    r1 = new Recipe;
    r1->setName("Margarita");
    r1->appendStep("Zitronensaft", 2);
    r1->appendStep("Cointreau", 2);
    r1->appendStep("Tequilla", 4);
    r1->appendStep("Eis", 50);
    r1->appendStep("Mischen", 20);
    this->mRecipe.push_back(r1);

    r1 = new Recipe;
    r1->setName("Daiquiri");
    r1->appendStep("Limettensaft", 2);
    r1->appendStep("Zuckersirup", 2);
    r1->appendStep("Rum weiss", 5);
    r1->appendStep("Eis", 50);
    r1->appendStep("Mischen", 20);
    this->mRecipe.push_back(r1);

    r1 = new Recipe;
    r1->setName("Planters Punch");
    r1->appendStep("Zitronensaft", 2);
    r1->appendStep("Grenadine", 1);
    r1->appendStep("Orangensaft", 8);
    r1->appendStep("Rum braun", 6);
    r1->appendStep("Eis", 100);
    r1->appendStep("Mischen", 20);
    this->mRecipe.push_back(r1);

    r1 = new Recipe;
    r1->setName("Caipiroska");
    r1->appendStep("Limettenstuecke", 8);
    r1->appendStep("Zucker", 15);
    r1->appendStep("Stampfen", 20);
    r1->appendStep("Eis", 90);
    r1->appendStep("Wodka", 5);
    r1->appendStep("Mischen", 10);
    this->mRecipe.push_back(r1);

    r1 = new Recipe;
    r1->setName("Caipirissima");
    r1->appendStep("Limettenstuecke", 8);
    r1->appendStep("Zucker", 15);
    r1->appendStep("Stampfen", 20);
    r1->appendStep("Eis", 90);
    r1->appendStep("Rum weiss", 5);
    r1->appendStep("Mischen", 10);
    this->mRecipe.push_back(r1);

    r1 = new Recipe;
    r1->setName("Cuban Island");
    r1->appendStep("Zitronensaft", 2);
    r1->appendStep("Cointreau", 2);
    r1->appendStep("Rum weiss", 2);
    r1->appendStep("Wodka", 2);
    r1->appendStep("Eis", 30);
    r1->appendStep("Mischen", 30);
    this->mRecipe.push_back(r1);

int RecipeBook::getNumberOfRecipes() {
  return (mRecipe.size());
}

Recipe *RecipeBook::getRecipe(unsigned int i) {
  if (i > mRecipe.size()) return NULL;
  else {
    std::list<Recipe *>::iterator p; // Iterator
    advance(p = mRecipe.begin(), i); // p zeigt jetzt auf das i-te Element
    return *p; // Wert von p - also den Pointer zurueck
  }
}

bool RecipeBook::deleteRecipe(unsigned int i) {
  if (i >= mRecipe.size()) {
    return false;
  } else {
    std::list<Recipe *>::iterator p; // Iterator
    advance(p = mRecipe.begin(), i); // now p points to the i-th Element
    mRecipe.erase(p); // delete the element p is pointing to
    return true; // Success!
  }
}
void RecipeBook::createBackupRecipes() {
  Recipe *r1;

  r1 = new Recipe;
  r1->setName("Caipirinha");
  r1->appendStep("Limettenstuecke", 8);
  r1->appendStep("Zucker", 15);
  r1->appendStep("Stampfen", 20);
  r1->appendStep("Eis", 90);
  r1->appendStep("Cachaca", 5);
  r1->appendStep("Mischen", 10);
  this->mRecipe.push_back(r1);

  r1 = new Recipe;
  r1->setName("Margarita");
  r1->appendStep("Zitronensaft", 2);
  r1->appendStep("Cointreau", 2);
  r1->appendStep("Tequilla", 4);
  r1->appendStep("Eis", 50);
  r1->appendStep("Mischen", 20);
  this->mRecipe.push_back(r1);

  r1 = new Recipe;
  r1->setName("Daiquiri");
  r1->appendStep("Limettensaft", 2);
  r1->appendStep("Zuckersirup", 2);
  r1->appendStep("Rum weiss", 5);
  r1->appendStep("Eis", 50);
  r1->appendStep("Mischen", 20);
  this->mRecipe.push_back(r1);

  r1 = new Recipe;
  r1->setName("Planters Punch");
  r1->appendStep("Zitronensaft", 2);
  r1->appendStep("Grenadine", 1);
  r1->appendStep("Orangensaft", 8);
  r1->appendStep("Rum braun", 6);
  r1->appendStep("Eis", 100);
  r1->appendStep("Mischen", 20);
  this->mRecipe.push_back(r1);

  r1 = new Recipe;
  r1->setName("Caipiroska");
  r1->appendStep("Limettenstuecke", 8);
  r1->appendStep("Zucker", 15);
  r1->appendStep("Stampfen", 20);
  r1->appendStep("Eis", 90);
  r1->appendStep("Wodka", 5);
  r1->appendStep("Mischen", 10);
  this->mRecipe.push_back(r1);

  r1 = new Recipe;
  r1->setName("Caipirissima");
  r1->appendStep("Limettenstuecke", 8);
  r1->appendStep("Zucker", 15);
  r1->appendStep("Stampfen", 20);
  r1->appendStep("Eis", 90);
  r1->appendStep("Rum weiss", 5);
  r1->appendStep("Mischen", 10);
  this->mRecipe.push_back(r1);

  r1 = new Recipe;
  r1->setName("Cuban Island");
  r1->appendStep("Zitronensaft", 2);
  r1->appendStep("Cointreau", 2);
  r1->appendStep("Rum weiss", 2);
  r1->appendStep("Wodka", 2);
  r1->appendStep("Eis", 30);
  r1->appendStep("Mischen", 30);
  this->mRecipe.push_back(r1);


  r1 = new Recipe;
  r1->setName("Martini James B");
  r1->appendStep("Gin", 6);
  r1->appendStep("Wodka", 2);
  r1->appendStep("Noilly Prat", 1);
  r1->appendStep("Schuetteln", 10);
  this->mRecipe.push_back(r1);
}
void RecipeBook::readFile(std::ifstream &in) {


  std::string zeile;
  getline(in, zeile);


  while (getline(in, zeile)) {

    std::istringstream inputString(zeile);
    std::string name, zutat, tempString;


    r1 = new Recipe;
    r1->setName("Martini James B");
    r1->appendStep("Gin", 6);
    r1->appendStep("Wodka", 2);
    r1->appendStep("Noilly Prat", 1);
    r1->appendStep("Schuetteln", 10);
    this->mRecipe.push_back(r1);
    // cout << m_Liste->size() << endl;
        
        
        
        
    } else {
        /* Daten lesen und ausgeben */
        std::string zeile;

        // 1. Zeile ist Ueberschrift - Einlesen und wegwerfen!
        getline(in, zeile);
        // cout << zeile << endl;

        while (getline(in, zeile)) {
            //      cout << zeile << endl;
                std::istringstream inputString(zeile);
    std::string name;
    std::string zutat;
    std::string tempString;
    float menge;




    Recipe *r1;

    r1 = new Recipe;


    // Aus istringstream Name einlesen mit Komma als Trennzeichen
    getline(inputString, name, ';');
    // Weiter einlesen bis zum naechsten Trennzeichen (Zutat)
    r1->setName(name);
    //cout << "Name: " << Name << endl;

    while (getline(inputString, zutat, ';')&& !zutat.empty()) {
        // Weiter einlesen bis zum naechsten Trennzeichen (Menge)
        if (getline(inputString, tempString, ';')) {
            std::istringstream(tempString) >> menge;
        }
        r1->appendStep(zutat, menge);
        //cout << " Zutat: " << Zutat << " Menge: " << Menge << "\n" << endl;
    }
    this->mRecipe.push_back(r1);
        }


    getline(inputString, name, ';');

    r1->setName(name);




RecipeBook::~RecipeBook() {
   mRecipe.clear();
}

int RecipeBook::getNumberOfRecipes() {
    return (mRecipe.size());
}

Recipe * RecipeBook::getRecipe(unsigned int i) {
    if (i > mRecipe.size()) return NULL;
    else {
        std::list<Recipe*>::iterator p; // Iterator
        advance(p = mRecipe.begin(), i); // p zeigt jetzt auf das i-te Element
        return *p; // Wert von p - also den Pointer zurueck

    while (getline(inputString, zutat, ';') && !Zutat.empty()) {

      if (getline(inputString, tempString, ';')) {
        std::istringstream(tempString) >> menge;
      }
      r1->appendStep(zutat, menge);


    }
    this->mRecipe.push_back(r1);
  }
  in.close();
}


bool RecipeBook::deleteRecipe(unsigned int i) {
    if (i >= mRecipe.size()) {
        return false;
    } else {
        std::list<Recipe*>::iterator p; // Iterator
        advance(p = mRecipe.begin(), i); // now p points to the i-th Element
        mRecipe.erase(p); // delete the element p is pointing to
        return true; // Success!
    }
}


