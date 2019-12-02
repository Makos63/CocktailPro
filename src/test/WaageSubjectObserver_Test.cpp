
#include <gtest/gtest.h>
#define protected public
#define private public
#include "Dosierer.h"
#include "Waage.h"
#undef protected
#undef private

class WaageSubjectObserverTest : public ::testing::Test{
 protected:
  Dosierer* d;
  Waage* w;
  void SetUp(){
    d = new Dosierer(10, 20, "test", w);
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
  EXPECT_NO_FATAL_FAILURE(d->update());
}*/