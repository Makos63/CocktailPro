//
// Created by Maciej Krzysztoń on 02.12.19.
//
#define protected public
#define private public
#include <gtest/gtest.h>
#include "Subject.h"
#include "Dosierer.h"
#undef protected
#undef private

class SubjectTest : public ::testing::Test{
 protected:
  Subject* s;
  Observer* d;
  void SetUp(){
    s = new Subject;
    d = new Dosierer;
  }
  virtual void TearDown(){
    delete s,d;
  };
};

TEST_F(SubjectTest, AttachTest){
  ASSERT_NO_FATAL_FAILURE(s->attach(d));
}

TEST_F(SubjectTest, NotifyTest){
  ASSERT_NO_FATAL_FAILURE(s->notify());
}