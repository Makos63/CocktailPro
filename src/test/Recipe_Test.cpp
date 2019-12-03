//
// Created by Christian on 03.12.2019.
//

#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "Recipe.h"
#undef protected
#undef private

class RecipeTest : public ::testing::Test{
 protected:
  Recipe* r;
  void SetUp(){
    r = new Recipe;
  }
  virtual void TearDown(){
    delete r;
  }
};