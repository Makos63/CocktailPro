//@(#) Waage.h

#ifndef WAAGE_H_H
#define WAAGE_H_H

#include "Subject.h"
/**
 *@class Waage
 *@brief this is responsible of managing  weight.
 *
 *a Waage-object enables us to weigh amount of a substance. 
 *In case modifications are to be done on the desired weight,it carries out
 *the modifications.
 */
class Waage : public Subject {
 public:
/**
 *@brief function modifies the value of the current weight.
 *@param  v an interger taken as parameter and to which 
 *the current weight is added to to get the desired weight of the user.
 *it has no  return type.
 */
    void changeWeight(int v);
/**
 *@brief sets the value of deltaweight to 0 .
 *@return returns an interger(deltaweight).
 */
    int tara();
/**
 *@brief it returns the weight
 *@return an interger(weight)
 */
    int getWeight();
/**
 *@brief it returns the actual value of deltagewicht
 *@return an interger(deltagewicht )
 *
*/
    int getDelta();
 private:
/* 
 *this variable holds the original weight 
 */  
  int weight;
/*
 *this variable contains the change in weight.
 */
    int deltaweight;
};

#endif
