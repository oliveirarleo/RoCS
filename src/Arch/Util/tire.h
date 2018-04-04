//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_TIRE_H_
#define ARCH_TIRE_H_

#include "position.h"

class Tire
{
private:
    Position position;
    double weight;
    double size_x;
    double size_y;
    double size_z;

public:
    Tire(const Position &position, double weight, double size_x, double size_y, double size_z) :
            position(position),
            weight(weight),
            size_x(size_x),
            size_y(size_y),
            size_z(size_z)
    {}

};

#endif //ARCH_TIRE_H_
