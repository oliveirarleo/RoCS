//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_SONAR_H_
#define ARCH_SONAR_H_

#include <ostream>
#include "range.h"

class Sonar: public Range{
public:
    Sonar(double weight_, Position position_, double bandwidth_, double max_range_, double resolution_,
          double fov_angle_, double beam_angle_, double scan_interval_);

    friend std::ostream &operator<<(std::ostream &os, const Sonar &sonar);
};

#endif //ARCH_SONAR_H_
