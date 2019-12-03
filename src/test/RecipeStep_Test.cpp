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
  }
};

/*TEST_F(RecipeStepTest, setMenge){
  EXPECT_NO_FATAL_FAILURE(rs1->setMenge(2));
  EXPECT_NO_FATAL_FAILURE(rs2->setMenge(8));
}
TEST_F(RecipeStepTest, setZutat){
  EXPECT_NO_FATAL_FAILURE(rs1->setZutat("Eis"));
  EXPECT_NO_FATAL_FAILURE(rs2->setZutat("Limettensaft"));
}*/


TEST_F(RecipeStepTest, getMengeOfZutat){
  EXPECT_EQ(rs1->getMenge(),2);

  EXPECT_EQ(rs2->getMenge(),8);
}

TEST_F(RecipeStepTest, getZutatName){
EXPECT_EQ(rs1->getZutat(),"Eis");

EXPECT_EQ(rs2->getZutat(),"Limettensaft");
}

TEST_F(RecipeStepTest, setIngredientAndsetQuantitySettingTheRightValue) {
  EXPECT_NO_THROW(rs1->setZutat("Wodka"));
  EXPECT_EQ("Wodka", rs1->getZutat());
  EXPECT_NO_THROW(rs1->setMenge(5));
  EXPECT_EQ(5, rs1->getMenge());

}