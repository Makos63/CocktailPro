//
// Created by Maciej Krzysztoń on 02.12.19.
//


#include <gtest/gtest.h>
#define protected public
#define private public
#include "Entleerer.h"
#include "Waage.h"
#undef protected
#undef private

class EntleererTest : public ::testing::Test{
 protected:
  Entleerer* e;

  void SetUp(){

    e = new Entleerer(2,1,new Waage);
  }
  virtual void TearDown(){

    delete e;
  }
};


TEST_F(EntleererTest, DoItTest){
  EXPECT_NO_FATAL_FAILURE(e->doIt(5));
}
TEST_F(EntleererTest, updateTestForFailure){
  EXPECT_NO_FATAL_FAILURE(e->update());
}
