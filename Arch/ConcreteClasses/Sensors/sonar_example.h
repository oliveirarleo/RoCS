//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_SONAR_EXAMPLE_H_
#define ARCH_SONAR_EXAMPLE_H_

#include <ostream>
#include "../../Sensors/sonar.h"
#include "../../Util/position.h"

class SonarExample: public Sonar<double>
{
public:
    SonarExample(double weight_, Position position_, double bandwidth_, double max_range_, double resolution_,
                 double fov_angle_, double beam_angle_, double scan_interval_);
    double getData();

    friend std::ostream &operator<<(std::ostream &os, const SonarExample &example);

    double getBandwidth() const;
    const Position& getPosition() const;
    double getWeight() const;
};

#endif //ARCH_SONAR_EXAMPLE_H_
