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

double Sensor::getWeight() const {
    return weight;
}

const Position &Sensor::getPosition() const {
    return position;
}

double Sensor::getBandwidth() const {
    return bandwidth;
}

std::ostream &operator<<(std::ostream &os, const Sensor &sensor) {
    os << "Weight: " << sensor.weight << " Position: "
       << sensor.position << " Bandwidth: " << sensor.bandwidth << " ";
    return os;
}
