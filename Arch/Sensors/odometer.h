//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_ODOMETER_H_
#define ARCH_ODOMETER_H_

#include "../Util/tire.h"
#include "vector"
#include "sensor.h"

class Odometer: public Sensor
{
private:
    double scan_interval;
    double resolution;
    std::vector<Tire> tires;

public:
    Odometer(double weight_, Position position_, double bandwidth_, double scan_interval_, double resolution_, std::vector<Tire> tires_);
};


#endif //ARCH_ODOMETER_H_
