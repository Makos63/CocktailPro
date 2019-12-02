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
  Waage* w;
  float grammProZeit;
  void SetUp(){
    e = new Entleerer(20,1,w);
    grammProZeit =20;
  }
  virtual void TearDown(){
    delete w;
    delete e;
  };
};


/*TEST_F(EntleererTest, DoItTest){
  EXPECT_NO_FATAL_FAILURE(e->doIt(5));
}
TEST_F(EntleererTest, update){
  EXPECT_NO_FATAL_FAILURE(e->update());
}*/
