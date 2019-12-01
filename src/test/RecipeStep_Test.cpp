//
// Created by Christian on 01.12.2019.
//

#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "RecipeStep.h"
#undef protected
#undef private

class RecipeStepTest : public ::testing::Test{
 protected:
  RecipeStep* rs1;
  RecipeStep* rs2;
  void SetUp(){
    rs1 = new RecipeStep();
    rs2 = new RecipeStep();

    rs1->setMenge(2);
    rs1->setZutat("Eis");
    rs2->setMenge(8);
    rs2->setZutat("Limettensaft");
  }
  virtual void TearDown(){
    delete rs1,rs2;
  };
};

TEST_F(RecipeStepTest, getMengeAndZutat){
  EXPECT_EQ(rs1->getMenge(),2);
  EXPECT_EQ(rs1->getZutat(),"Eis");

  EXPECT_EQ(rs2->getMenge(),8);
  EXPECT_EQ(rs2->getZutat(),"Limettensaft");
}