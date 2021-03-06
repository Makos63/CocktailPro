#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "RecipeBook.h"
#undef protected
#undef private

class RecipeBookTest : public ::testing::Test {
 protected:
  RecipeBook* r;

  virtual void SetUp() {
        r = new RecipeBook();
        // you never know what the constructor is really doing
        // so make the list empty and fill it yourself!
        
        r->m_Recipe.clear();
        Recipe* r1;

        r1 = new Recipe;
        r1->setName("Caipirinha");
        r1->appendStep("Limettenstuecke", 8);
        r->m_Recipe.push_back(r1);

        r1 = new Recipe;
        r1->setName("Margarita");
        r1->appendStep("Zitronensaft", 2);
        r->m_Recipe.push_back(r1);
          
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
    delete r;
  }
};
/*
 * tests, if num of recipes is equal to number of recipes of obj r
 */
TEST_F(RecipeBookTest,getNumberOfRecipesReturnsValueOfAttribute){
    int noOfRecipes=r->m_Recipe.size();
    EXPECT_EQ(noOfRecipes,r->getNumberOfRecipes());
}

/*
 * test, if the returned recipe is the expected
 * note that you have to give the expected return value, otherwise it does not know, for what to check
 */
TEST_F(RecipeBookTest,getRecipeReturnsCorrectRecipe){
    Recipe* rez;
    rez = r->getRecipe(0);
    EXPECT_EQ(rez->getName(),"Caipirinha");

    rez = r->getRecipe(1);
    EXPECT_EQ(rez->getName(),"Margarita");
}

/*
 * test of delete function
 */
TEST_F(RecipeBookTest,deleteRecipeRemovesCorrectRecipe){
    //Testcases, if vector does not have values at given position -> expected false
    EXPECT_FALSE(r->deleteRecipe(-1));
    EXPECT_FALSE(r->deleteRecipe(42));
    EXPECT_FALSE(r->deleteRecipe(2)); 

    //deletes position 0 -> everything else has now a lower number by 1
    EXPECT_TRUE(r->deleteRecipe(0));
    // Since recipe #0 is deleted now Margarita is #0
    Recipe* rez;
    //check, if recipe[0] is indeed the expected cocktail: Margarita
    rez = r->getRecipe(0);
    EXPECT_EQ(rez->getName(),"Margarita");
}