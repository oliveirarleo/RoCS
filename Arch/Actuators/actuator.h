//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_ACTUATOR_H_
#define ARCH_ACTUATOR_H_

#include "actuator_accessor.h"
#include "../Util/position.h"

template <class T>
class Actuator: public ActuatorAccessor<T>
{
protected:
    double weight;
    Position position;
};

#endif //ARCH_ACTUATOR_H_