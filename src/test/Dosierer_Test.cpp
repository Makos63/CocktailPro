//
// Created by Maciej Krzysztoń on 02.12.19.
//
#include <gtest/gtest.h>

#define protected public
#define private public
#include "Dosierer.h"
#include "Waage.h"
#undef protected
#undef private

class DosiererTest : public ::testing::Test{
 protected:
  Dosierer* d;
  float grammProZeit;
  void SetUp(){
    d = new Dosierer(20000,1,"Eis",new Waage);
    }
  virtual void TearDown(){
    delete d;
  };
};


TEST_F(DosiererTest, UpdateTest){
  EXPECT_NO_FATAL_FAILURE(d->update());
}
TEST_F(DosiererTest, GetStuckTest){
  EXPECT_NO_FATAL_FAILURE(d->getStueckProZeit());
}
TEST_F(DosiererTest, DoItTest){
  EXPECT_NO_FATAL_FAILURE(d->doIt(5));
}


