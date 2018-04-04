//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <string>
#include "sonar_example.h"

SonarExample::SonarExample(double weight_, Position position_, double bandwidth_, double max_range_, double resolution_,
                           double fov_angle_, double beam_angle_, double scan_interval_) : Sonar(weight_, position_,
                           bandwidth_, max_range_, resolution_, fov_angle_, beam_angle_, scan_interval_)
{

}

double SonarExample::getData()
{
    return 99;
}

double SonarExample::getWeight() const {
    return weight;
}

const Position& SonarExample::getPosition() const {
    return position;
}

double SonarExample::getBandwidth() const {
    return bandwidth;
}

std::ostream &operator<<(std::ostream &os, const SonarExample &example) {
    os << static_cast<const Sonar<double> &>(example);
    return os;
}



