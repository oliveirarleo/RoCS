//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "position.h"

Position::Position(double x_, double y_, double z_){
    x = x_;
    y = y_;
    z = z_;
}

std::ostream &operator<<(std::ostream &os, const Position &position) {
    os << "x: " << position.x << " y: " << position.y << " z: " << position.z << " ";
    return os;
}
