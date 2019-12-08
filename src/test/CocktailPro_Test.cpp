//
// Created by Christian on 07.12.2019.
//

#include <gtest/gtest.h>
#define protected public
#define private public
#include "CocktailPro.h"
#include "DeviceVerwalter.h"
#include "VorhandeneZutaten.h"
#include "MischbaresRezeptbuch.h"
#include "CocktailZubereiter.h"
#undef protected
#undef private


class CocktailProTest : public ::testing::Test{
 protected:
  CocktailPro* c;
  DeviceVerwalter* d;
  VorhandeneZutaten* v;
  MischbaresRezeptbuch* m;
  CocktailZubereiter* cz;
  void TestBody() {
  }
  void SetUp(){
    v = new VorhandeneZutaten();
    d = new DeviceVerwalter(v);
    m = new MischbaresRezeptbuch(v);
    //c = new CocktailPro(2, '-D');
  }
  virtual void TearDown(){
    delete c;
  }
};
