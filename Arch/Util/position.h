//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_POSITION_H_
#define ARCH_POSITION_H_

#include <ostream>

class Position
{
private:
    double x;
    double y;
    double z;

public:
    Position(double x_, double y_, double z_);

    friend std::ostream &operator<<(std::ostream &os, const Position &position);
};

#endif //ARCH_POSITION_H_
