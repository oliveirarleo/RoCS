//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_SPEAKER_H_
#define ARCH_SPEAKER_H_

#include "actuator.h"

template <class T>
class Speaker: public Actuator<T>
{
protected:
    double volume;
    double max_volume;
};

#endif //ARCH_SPEAKER_H_
