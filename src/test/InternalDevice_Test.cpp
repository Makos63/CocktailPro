//
// Created by Christian on 03.12.2019.
//

#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "InternalDevice.h"
#undef protected
#undef private

#include <sstream>

class InternalDeviceTest : public InternalDevice , public ::testing::Test {
 protected:
  InternalDevice* i;

  void doIt(float value) {

  }

  void TestBody() {
  }

  virtual void SetUp() {
    i = new InternalDeviceTest();
  }

  virtual void TearDown() {

    delete i;
  }

};

TEST_F(InternalDeviceTest, ConstructorOfInternalDeviceExecutesWithoutFailure) {
  EXPECT_NO_FATAL_FAILURE(InternalDeviceTest());

}

TEST_F(InternalDeviceTest, cleanExecutesWithoutFatalFailure) {
  EXPECT_NO_FATAL_FAILURE(i->putzen());
}