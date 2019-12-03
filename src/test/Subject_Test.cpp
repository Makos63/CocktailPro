//
// Created by Christian on 03.12.2019.
//

#include <limits.h>
#include <string>
#include "gtest/gtest.h"


#define protected public
#define private public
#include "Subject.h"
#include "Dosierer.h"
#undef protected
#undef private


#include <sstream>

class SubjectTest: public ::testing::Test
{
 protected:
  Subject* subject;


  virtual void SetUp()
  {
    subject = new Subject();
  }

  virtual void TearDown()
  {

    delete subject;
  }
};

TEST_F(SubjectTest, attach)
{
subject->attach(new Dosierer(10, 1, "Eis", new Waage()));
EXPECT_EQ(subject->observers.size(), 1);
}

TEST_F(SubjectTest, notify)
{
EXPECT_NO_THROW(subject->notify());
}