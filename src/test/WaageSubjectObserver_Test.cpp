
#include <gtest/gtest.h>
#define protected public
#define private public
#include "Dosierer.h"
#include "Waage.h"
#include "Entleerer.h"
#undef protected
#undef private

class WaageSubjectObserverTest : public ::testing::Test{
 protected:
  Dosierer* d;
  Waage* w;
  Entleerer* e;
  void SetUp(){
    d = new Dosierer();
    e = new Entleerer();
    w = new Waage();
  }
  virtual void TearDown(){
    delete w;
    delete d;
  };
};

/*
TEST_F(WaageSubjectObserverTest, AttachTest){
  ASSERT_NO_FATAL_FAILURE(w->attach(d));
}

TEST_F(WaageSubjectObserverTest, NotifyTest){
  EXPECT_NO_FATAL_FAILURE(w->notify());
}

TEST_F(WaageSubjectObserverTest, UpdateTest){
  e->outputEnable=false;
  EXPECT_NO_FATAL_FAILURE(e->update());
}*/