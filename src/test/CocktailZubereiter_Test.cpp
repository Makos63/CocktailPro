//
// Created by Christian on 07.12.2019.
//

#include <gtest/gtest.h>
#define protected public
#define private public
#include "CocktailZubereiter.h"
#include "RecipeBook.h"
#undef protected
#undef private


class CocktailZubereiterTest : public ::testing::Test{
 protected:
  CocktailZubereiter* cz;
  DeviceVerwalter * d;
  VorhandeneZutaten* v;
  RecipeBook* r;
  std::basic_streambuf<char>* old_buf;
  std::stringstream ss;

  void SetUp(){
    old_buf = std::cout.rdbuf(ss.rdbuf());
    v = new VorhandeneZutaten();
    d = new DeviceVerwalter(v);
    r = new RecipeBook();
    cz = new CocktailZubereiter(d);

    r->m_Recipe.clear();
    Recipe* r1;
    r1 = new Recipe;
    r1->setName("Caipirinha");
    r1->appendStep("Limettenstuecke", 8);
    r->m_Recipe.push_back(r1);

  }
  virtual void TearDown(){
    std::cout.rdbuf(old_buf);
    delete cz;
    delete v;
    delete d;
    delete r;
  };
};


TEST_F(CocktailZubereiterTest, testCocktailZubereitung)
{
  Recipe * rez;
  rez = r->getRecipe(0);
  EXPECT_TRUE(cz->cocktailZubereiten(rez));
}

TEST_F(CocktailZubereiterTest, testTextOutput){
  ss.clear();
  Recipe * rez;
  rez = r->getRecipe(0);
  cz->cocktailZubereiten(rez);
  EXPECT_EQ("Hallo, ich bin der CocktailZubereiter!",ss.str().substr(348,38));
  std::cout.rdbuf(old_buf);
}