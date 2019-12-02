//
// Created by Maciej Krzysztoń on 02.12.19.
//

#define protected public
#define private public
#include <gtest/gtest.h>
#include "Mixer.h"
#undef protected
#undef private

class MixerTest : public ::testing::Test{
 protected:
  Mixer* m;
  void SetUp(){
    m = new Mixer;
  }
  virtual void TearDown(){
    delete m;
  };
};

TEST_F(MixerTest, BasicUsability){
  EXPECT_NO_FATAL_FAILURE(m->doIt(10));

}