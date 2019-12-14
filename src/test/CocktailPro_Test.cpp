//
// Created by Christian on 07.12.2019.
//
#include <limits.h>
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
#include <thread>
#include <future>
#include <sstream>
#include <string>
using namespace std;
class CocktailProTest : public ::testing::Test{
 protected:
  CocktailPro* c;
  DeviceVerwalter* d;
  VorhandeneZutaten* v;
  MischbaresRezeptbuch* m;
  CocktailZubereiter* cz;
  basic_streambuf<char> *old_buf;
  basic_streambuf<char> *old_inputbuf;
  stringstream ss;
  stringstream inputStream;
  char * s= "-D";
  char **turbo = &s;

  void SetUp(){
    old_buf = cout.rdbuf(ss.rdbuf());
    old_inputbuf = cin.rdbuf(inputStream.rdbuf());
    v = new VorhandeneZutaten();
    d = new DeviceVerwalter(v);
    m = new MischbaresRezeptbuch(v);
    c = new CocktailPro(2, turbo);
    ss.str("");
  }
  virtual void TearDown(){
    cout.rdbuf(old_buf);
    cin.rdbuf(old_inputbuf);
    delete c;
  }
};

TEST_F(CocktailProTest, start) {
  inputStream << -1;
  EXPECT_EXIT(c->start(), ::testing::ExitedWithCode(0), "");
}

TEST_F(CocktailProTest, demo) {
  c->demo();
  EXPECT_EQ(ss.str().substr(0, 10), "Caipirinha");
}

TEST_F(CocktailProTest, choose) {
  inputStream << 1;
  EXPECT_EQ(c->waehle(), 1);
}