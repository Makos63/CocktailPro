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
/**
 * @class DeviceVerwalter
 *
 * @brief provides Dosierer and internal components
 *
 * It keep tracke of all devices and ingredients in an map and initialize Waage.
 * Also it managed the Entleerer, Mixer, Stamper, Schuettler, VorhandeneZutaten, Waage.
 * The following methods are implemented in this class putzen, entleeren,
 * rezeptSchrittZubereiten, setZutatenVerwalter and createDevice which is private.
 *
 */

class DeviceVerwalter {
public:
  /**
   * Constructor for DeviceVerwalter
   * @param ze is the instance which managed all recipes
   */
  explicit DeviceVerwalter(VorhandeneZutaten * ze);
/**
 *
 * @param zutat is a string and a name of ingredient
 * @param menge is a float and the amount of the specified ingredient
 */
    void rezeptSchrittZubereiten(std::string zutat, float menge);
/**
 * Is call to function of class Entleerer
 * @param menge is a float which will be parsed to Entleerer
 */
    void entleeren(float menge);

    /**
     * clean all devices from map
     */
    void putzen();

private:
  /**
   * sets the ze for this class
   * @param ze is the instance which managed all recipes
   */
   //es macht uberhaupt kein Sinn
    void setZutatenVerwalter(VorhandeneZutaten * ze);
  /**
   * save all the devices in map.
   */
    std::map<std::string, InternalDevice *> * myDevices;
  /**
   * It is needed for communication with Entleerer.
   */
    Entleerer * myEntleerer;
  /**
   * It is needed for communication with Mixer.
   */
    Mixer * myMixer;
  /**
   * It is needed for communication with Stampfer.
   */
    Stampfer * myStampfer;
  /**
   * It is needed for communication with Schuettler.
   */
    Schuettler * mySchuettler;
  /**
   * It is needed for communication with VorhandeneZutaten.
   */
    VorhandeneZutaten * myZutatenVerwalter;
  /**
   * It is needed for communication with Waage.
   */
    Waage * theWaage;
/**
 *  @brief Initializes all devices and add them into map myDevices
 *
 *  Initialisation of Waage,
 *  Initialisation of Entleerer,
 *  Initialisation of Stampfer,
 *  Initialisation of Schuettler,
 *  Initialisation of Mixer
 *
 *  Check, if ice or lime is added as ingredient 
 *
 */
    void createDevices();
};

#endif
