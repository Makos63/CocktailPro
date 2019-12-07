//
// Created by Christian on 07.12.2019.
//

#include <gtest/gtest.h>
#define protected public
#define private public
#include "CocktailZubereiter.h"
#undef protected
#undef private


class CocktailProTest : public ::testing::Test{
 protected:
  CocktailZubereiter* cz;
  DeviceVerwalter * d;
  VorhandeneZutaten* v;


  void SetUp(){
    v = new VorhandeneZutaten();
    d = new DeviceVerwalter(v);
    cz = new CocktailZubereiter(d);
  }
  virtual void TearDown(){
    delete cz;
  }
};
