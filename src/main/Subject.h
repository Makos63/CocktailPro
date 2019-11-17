//@(#) Subject.h

#ifndef SUBJECT_H_H
#define SUBJECT_H_H

#include "Observer.h"

#include <vector>
#include <iostream>
/**
*@ class Subject 
*
*@ class Subject is responsible  for adding and
* removing observers in the list.
* 
* it checks each observer, in case  it exists already in the list,
* whether it has to added to the list or deleted.Furthermore it can
* makes updates of any user given in paramater( setting to 0).   
*/ 
class Subject {
public:
/**
 * A void Function with no returntype taking an argument as parameter
 *@param observer is an Observer pointer.
 * this functions adds a pointer to an observer to the list.
*/
    void attach(Observer * observer);
/**
 *A void function with no returntype taking an argument as parameter
 *@param observer is an Observer pointer.
 *this function  deletes a pointer to an observer from the list of pointers
*/
    void detach(Observer * observer);
/**
 * a function with no returntype and no arguments.
 * it updates all the pointers to observers and sets them to 0
*/ 
    void notify();

private:
/**
* a private Data structure
* containing all the pointers to  Observers
*/

    std::vector<Observer *> observers;

};

#endif
