//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_RFID_H
#define ARCH_RFID_H

#include "sensor.h"

template <class T>
class RFID: public Sensor<T>
{
protected:
    double max_range;

public:
    RFID(double weight_, Position position_, double bandwidth_, double max_range_):
            Sensor(weight_, position_, bandwidth_)
    {
        max_range = max_range_;
    }
};

#endif //ARCH_RFID_H
