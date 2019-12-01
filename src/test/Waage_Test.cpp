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
  Waage* w;
  void SetUp(){
    w = new Waage();
    w->changeWeight(5);
  }
};

TEST_F(WaageTest, testForTaraReturnIsZero){
  EXPECT_EQ(w->tara(), 0);
}
TEST_F(WaageTest, testReturnWeight){
  EXPECT_EQ(w->getWeight(), 5);
}
TEST_F(WaageTest, testForReturnDelta){
  EXPECT_EQ(w->getDelta(), 5);
}