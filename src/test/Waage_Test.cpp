//
// Created by Christian on 01.12.2019.
//

#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "Waage.h"
#undef protected
#undef private
#include "ctime"

class WaageTest : public ::testing::Test{
 protected:
  Waage* w1;
  Waage* w2;
  void SetUp(){
    w1 = new Waage();
    w2 = new Waage();
    w1->changeWeight(5);
    w2->changeWeight(0);
  }
};

TEST_F(WaageTest, testForWaage1TaraReturnIsZero){
  EXPECT_EQ(w1->tara(), 0);
}
TEST_F(WaageTest, testReturnWaage1Weight){
  EXPECT_EQ(w1->getWeight(), 5);
}
TEST_F(WaageTest, testForReturnWaage1Delta){
  EXPECT_EQ(w1->getDelta(), 5);
}
