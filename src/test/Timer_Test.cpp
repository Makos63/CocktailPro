//
// Created by Christian on 02.12.2019.
//
#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "Timer.h"
#undef protected
#undef private

class TimerTest : public ::testing::Test{
 protected:
  Timer* t;
  void SetUp(){
    t = new Timer;
  }
  virtual void TearDown(){
    delete t;
  };
};

TEST_F(TimerTest, set_Turbo)
{
t->set_Turbo(10);
EXPECT_EQ(t->booster, 10);
}

TEST_F(TimerTest, sleep)
{
EXPECT_NO_FATAL_FAILURE(t->sleep(1000));
}

TEST_F(TimerTest, sleepInOneSecondIntervals)
{
EXPECT_NO_THROW(t->sleep_in_one_second_intervals(1000));
}

TEST_F(TimerTest, getInstance)
{
EXPECT_EQ(Timer::getInstance(), Timer::getInstance());
}