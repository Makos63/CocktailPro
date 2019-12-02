//
// Created by Maciej Krzysztoń on 02.12.19.
//
/*
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
  Waage* w;
  float grammProZeit;
  void SetUp(){
    d = new Dosierer(20000,1,"Eis",w);
    grammProZeit =20;
    }
  virtual void TearDown(){
    delete w;
    delete d;
  };
};


TEST_F(DosiererTest, UpdateTest){
  EXPECT_NO_FATAL_FAILURE(d->update());
}
TEST_F(DosiererTest, GetStuckTest){
  EXPECT_EQ(d->getStueckProZeit(),20000);
}
TEST_F(DosiererTest, DoItTest){
  EXPECT_NO_FATAL_FAILURE(d->doIt(5));
}

*/
