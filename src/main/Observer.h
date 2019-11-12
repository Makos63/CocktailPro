//@(#) Observer.h

#ifndef OBSERVER_H_H
#define OBSERVER_H_H

/**
* @brief an "interface" class
*
* allows one objects to notify other objects about changes in their state, usually by calling their method
*/

class Observer {
public:
/**
*
* @brief update of any state changes
*
* is called by the object that's being observed, when that object decides its time to update all its observers
*/
    virtual void update() = 0;

};

#endif
