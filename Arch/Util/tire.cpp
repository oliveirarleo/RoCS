//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "tire.h"

Tire::Tire(Position position_, double weight_, double size_x_, double size_y_, double size_z_) : Position(position_)
{
    weight = weight_;
    size_x = size_x_;
    size_y = size_y_;
    size_z = size_z_;

}