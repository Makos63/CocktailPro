//
// Created by Christian on 02.12.2019.
//

//
// Created by Christian on 01.12.2019.
//

#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "Stampfer.h"
#undef protected
#undef private
#include "ctime"


class StampferTest : public ::testing::Test{
 protected: Stampfer* s;
  void SetUp(){
    s = new Stampfer();
  }
  virtual void TearDown(){
    delete s;
  };
};

/*TEST_F(StampferTest, testTimeLength){
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

TEST_F(StampferTest, testWithFailure){
  EXPECT_NO_FATAL_FAILURE(s->doIt(9));
}