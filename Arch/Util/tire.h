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
    Tire(Position position_, double weight_, double size_x_, double size_y_, double size_z_);

};

#endif //ARCH_TIRE_H_
