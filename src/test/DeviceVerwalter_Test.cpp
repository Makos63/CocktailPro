//
// Created by Maciej Krzysztoń on 02.12.19.
//

#include <gtest/gtest.h>
#define protected public
#define private public
#include "DeviceVerwalter.h"
#include "VorhandeneZutaten.h"
#undef protected
#undef private

class DeviceVerwalterTest : public ::testing::Test{
 protected:
  DeviceVerwalter* d;
  VorhandeneZutaten* z;
  void SetUp(){
    z = new VorhandeneZutaten();
    d = new DeviceVerwalter(z);
  }
  virtual void TearDown(){
    delete d;
  };
};
TEST_F(DeviceVerwalterTest,CreateDevicesTest){
  ASSERT_NO_FATAL_FAILURE(d->createDevices());
}
TEST_F(DeviceVerwalterTest,PutzenTest){
  EXPECT_NO_FATAL_FAILURE(d->putzen());
}
TEST_F(DeviceVerwalterTest,SetVorhandeneZutatenTest){
  EXPECT_NO_FATAL_FAILURE(d->setZutatenVerwalter(z));
}
TEST_F(DeviceVerwalterTest,EntleerenTest){
  EXPECT_NO_FATAL_FAILURE(d->entleeren(10.9));
}
TEST_F(DeviceVerwalterTest,ZubreitenDefaultTest){
  EXPECT_NO_FATAL_FAILURE(d->rezeptSchrittZubereiten("Eis",10.0));
}
TEST_F(DeviceVerwalterTest,ZubreitenLimettenTest){
  EXPECT_NO_FATAL_FAILURE(d->rezeptSchrittZubereiten("Limettenstuecke",10.0));
}
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