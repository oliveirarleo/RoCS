//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "rfid.h"

RFID::RFID(double weight_, Position position_, double bandwidth_, double max_range_) :: Sensor(weight_, position_,
        bandwidth_)
{
    max_range = max_range_;
}