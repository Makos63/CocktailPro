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
  m_Recipe.clear();
  std::string fileName = "Rezepte.csv";

   try {
     std::ifstream in;



     in.open(fileName.c_str(), std::ios::in);
     if(!in){
       throw "File Rezepte.csv could not be found or opened..";
     }
     //readFile(in);
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
  m_Recipe.clear();
}

int RecipeBook::getNumberOfRecipes() {
  return (m_Recipe.size());
}

Recipe * RecipeBook::findRecipe(unsigned int i) {
  for(std::list<Recipe*>::iterator p = m_Recipe.begin(); p != m_Recipe.end(); ++p) {
    if((*p)->getRecipeNumber() == i) return *p;
  }
  return NULL;
}

Recipe *RecipeBook::getRecipe(unsigned int i) {
  if (i > m_Recipe.size()) return NULL;
  else {
    std::list<Recipe *>::iterator p; // Iterator
    advance(p = m_Recipe.begin(), i); // p zeigt jetzt auf das i-te Element
    return *p; // Wert von p - also den Pointer zurueck
  }

}

bool RecipeBook::deleteRecipe(unsigned int i) {
  if (i >= m_Recipe.size()) {
    return false;
  } else {
    std::list<Recipe *>::iterator p; // Iterator
    advance(p = m_Recipe.begin(), i); // now p points to the i-th Element
    m_Recipe.erase(p); // delete the element p is pointing to
    return true; // Success!
  }
}
void RecipeBook::createBackupRecipes() {
  Recipe *r1;

  r1 = new Recipe;
  r1->setRecipeNumber(1);
  r1->setName("Caipirinha");
  r1->appendStep("Limettenstuecke", 8);
  r1->appendStep("Zucker", 15);
  r1->appendStep("Stampfen", 20);
  r1->appendStep("Eis", 90);
  r1->appendStep("Cachaca", 5);
  r1->appendStep("Mischen", 10);
  this->m_Recipe.push_back(r1);

  r1 = new Recipe;
  r1->setRecipeNumber(2);
  r1->setName("Margarita");
  r1->appendStep("Zitronensaft", 2);
  r1->appendStep("Cointreau", 2);
  r1->appendStep("Tequilla", 4);
  r1->appendStep("Eis", 50);
  r1->appendStep("Mischen", 20);
  this->m_Recipe.push_back(r1);

  r1 = new Recipe;
  r1->setRecipeNumber(3);
  r1->setName("Daiquiri");
  r1->appendStep("Limettensaft", 2);
  r1->appendStep("Zuckersirup", 2);
  r1->appendStep("Rum weiss", 5);
  r1->appendStep("Eis", 50);
  r1->appendStep("Mischen", 20);
  this->m_Recipe.push_back(r1);

  r1 = new Recipe;
  r1->setRecipeNumber(4);
  r1->setName("Planters Punch");
  r1->appendStep("Zitronensaft", 2);
  r1->appendStep("Grenadine", 1);
  r1->appendStep("Orangensaft", 8);
  r1->appendStep("Rum braun", 6);
  r1->appendStep("Eis", 100);
  r1->appendStep("Mischen", 20);
  this->m_Recipe.push_back(r1);

  r1 = new Recipe;
  r1->setRecipeNumber(5);
  r1->setName("Caipiroska");
  r1->appendStep("Limettenstuecke", 8);
  r1->appendStep("Zucker", 15);
  r1->appendStep("Stampfen", 20);
  r1->appendStep("Eis", 90);
  r1->appendStep("Wodka", 5);
  r1->appendStep("Mischen", 10);
  this->m_Recipe.push_back(r1);

  r1 = new Recipe;
  r1->setRecipeNumber(6);
  r1->setName("Caipirissima");
  r1->appendStep("Limettenstuecke", 8);
  r1->appendStep("Zucker", 15);
  r1->appendStep("Stampfen", 20);
  r1->appendStep("Eis", 90);
  r1->appendStep("Rum weiss", 5);
  r1->appendStep("Mischen", 10);
  this->m_Recipe.push_back(r1);

  r1 = new Recipe;
  r1->setRecipeNumber(7);
  r1->setName("Cuban Island");
  r1->appendStep("Zitronensaft", 2);
  r1->appendStep("Cointreau", 2);
  r1->appendStep("Rum weiss", 2);
  r1->appendStep("Wodka", 2);
  r1->appendStep("Eis", 30);
  r1->appendStep("Mischen", 30);
  this->m_Recipe.push_back(r1);


  r1 = new Recipe;
  r1->setRecipeNumber(8);
  r1->setName("Martini James B");
  r1->appendStep("Gin", 6);
  r1->appendStep("Wodka", 2);
  r1->appendStep("Noilly Prat", 1);
  r1->appendStep("Schuetteln", 10);
  this->m_Recipe.push_back(r1);
/*
  r1 = new Recipe;
  r1->setRecipeNumber(98);
  r1->setName("TestCocktailLime80%");
  r1->appendStep("Limettenstuecke", 80);
  this->m_Recipe.push_back(r1);

  r1 = new Recipe;
  r1->setRecipeNumber(99);
  r1->setName("TestCocktailIce80%");
  r1->appendStep("Eis", 800);
  this->m_Recipe.push_back(r1);
*/


  r1 = new Recipe;
  r1->setRecipeNumber(100);
  r1->setName("LimettenstueckeTest159");
  r1->appendStep("Limettenstuecke", 159);
  this->m_Recipe.push_back(r1);


  r1 = new Recipe;
  r1->setRecipeNumber(101);
  r1->setName("LimettenstueckeTest170");
  r1->appendStep("Limettenstuecke", 170);
  this->m_Recipe.push_back(r1);
}

/*void RecipeBook::readFile(std::ifstream &in) {


  std::string zeile;
  getline(in, zeile);


  while (getline(in, zeile)) {

    std::istringstream inputString(zeile);
    std::string Name, Zutat, tempstring;

    float Menge;

    Recipe *r1;

    r1 = new Recipe;


    getline(inputString, Name, ';');

    r1->setName(Name);


    while (getline(inputString, Zutat, ';') && !Zutat.empty()) {

      if (getline(inputString, tempstring, ';')) {
        std::istringstream(tempstring) >> Menge;
      }
      r1->appendStep(Zutat, Menge);

    }
    this->m_Recipe.push_back(r1);
  }
  in.close();

}*/
