//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "odometer.h"

Odometer::Odometer(double weight_, Position position_, double bandwidth_, double scan_interval_, double resolution_,
                   std::vector<Tire> tires_): Sensor(weight_, position_, bandwidth_)
{
    scan_interval = scan_interval_;
    resolution = resolution_;
    tires = tires_;
}

