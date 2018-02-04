//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_MONITOR_OBSERVER_H_
#define ARCH_MONITOR_OBSERVER_H_

#include "../Util/observer.h"

class MonitorObserver: public Observer
{
public:
    virtual void update() = 0;
};


#endif // ARCH_MONITOR_OBSERVER_H_
