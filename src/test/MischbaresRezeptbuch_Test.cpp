//
// Created by Maciej Krzysztoń on 02.12.19.
//

#include <gtest/gtest.h>

#define protected public
#define private public
#include "MischbaresRezeptbuch.h"
#include "VorhandeneZutaten.h"
#undef protected
#undef private

class MischbaresRezeptbuchTest : public ::testing::Test{
 protected:
MischbaresRezeptbuch* m;
VorhandeneZutaten* z;

  void SetUp(){

    z = new VorhandeneZutaten();
    m = new MischbaresRezeptbuch(z);

  }
  virtual void TearDown(){
    delete m;
    delete z;
  };
};

TEST_F(MischbaresRezeptbuchTest, SetZutatenVerwalterTest){
  EXPECT_NO_FATAL_FAILURE(m->setZutatenVerwalter(z));
}
TEST_F(MischbaresRezeptbuchTest, boolZutatenCheckTest){
  EXPECT_NO_FATAL_FAILURE(m->boolZutatenCheck("Eis", 50));
}
