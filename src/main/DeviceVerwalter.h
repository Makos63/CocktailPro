//@(#) DeviceVerwalter.h

#ifndef DEVICEVERWALTER_H_H
#define DEVICEVERWALTER_H_H

#include <string>
#include <map>

#include "InternalDevice.h"
#include "VorhandeneZutaten.h"
#include "Dosierer.h"
#include "Mixer.h"
#include "Stampfer.h"
#include "Schuettler.h"
#include "Entleerer.h"
#include "Waage.h"

/*
 * Befuellt die Dosierer, verwaltet die Interne Hardware
 *  
 */
class DeviceVerwalter {
public:
    DeviceVerwalter(VorhandeneZutaten * ze);

    void rezeptSchrittZubereiten(std::string zutat, float menge);

    void entleeren(float menge);

    void putzen();

private:
    void setZutatenVerwalter(VorhandeneZutaten * ze);

    std::map<std::string, InternalDevice *> * myDevices;

    Entleerer * myEntleerer;

    Mixer * myMixer;

    Stampfer * myStampfer;

    Schuettler * mySchuettler;

    VorhandeneZutaten * myZutatenVerwalter;

    Waage * theWaage;

    void createDevices();

};

#endif
