//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "sensor.h"

Sensor::Sensor(double weight_, Position position_, double bandwidth_) : position(position_) {
    weight = weight_;
    bandwidth = bandwidth_;
}
