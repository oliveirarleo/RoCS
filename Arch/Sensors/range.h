//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_RANGE_H_
#define ARCH_RANGE_H_

#include "sensor.h"

class Range: public Sensor
{
private:
    double max_range;
    double resolution;
    double fov_angle;
    double beam_angle;
    double scan_interval;

public:
    Range(double weight_, Position position_, double bandwidth_, double max_range_, double resolution_,
          double fov_angle_, double beam_angle_, double scan_interval_);
};

#endif //ARCH_RANGE_H_
