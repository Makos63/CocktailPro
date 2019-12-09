//
// Created by Christian on 01.12.2019.
//

#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "Schuettler.h"
#undef protected
#undef private
#include "ctime"


class SchuettlerTest : public ::testing::Test{
 protected: Schuettler* s;
  void SetUp(){
    s = new Schuettler();
  }
  virtual void TearDown(){
    delete s;
  }
};

/*TEST_F(SchuettlerTest, testTimeLength){
  time_t start, end;
  time(&start);
  s->doIt(4);
  time(&end);
  double duration = int(end - start);
  EXPECT_EQ(4, duration);

  time(&start);
  s->doIt(2);
  time(&end);
  duration = double(end - start);
  EXPECT_EQ(2, duration);
}*/
TEST_F(SchuettlerTest, testWithFailure){
  EXPECT_NO_FATAL_FAILURE(s->doIt(4));
}

/*TEST_F(SchuettlerTest, doYourTaskRunsForTheExpectedTime) {
  time_t start, end;
  time(&start);
  s->doIt(4);
  time(&end);
  double duration = double(end - start);
  EXPECT_EQ((4 / s->myTimer->get_Turbo()), duration);

  time(&start);
  s->doIt(8);
  time(&end);
  duration = int(end - start);
  EXPECT_EQ((8 / s->myTimer->get_Turbo()), duration);
}*/