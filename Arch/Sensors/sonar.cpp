//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "sonar.h"

Sonar::Sonar(double weight_, Position position_, double bandwidth_, double max_range_, double resolution_,
             double fov_angle_, double beam_angle_, double scan_interval_) : Range (weight_, position_, bandwidth_,
             max_range_, resolution_, fov_angle_, beam_angle_, scan_interval_)
{

}

std::ostream &operator<<(std::ostream &os, const Sonar &sonar) {
    os << static_cast<const Range &>(sonar);
    return os;
}
