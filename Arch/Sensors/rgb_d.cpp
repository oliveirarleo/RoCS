//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "rgb_d.h"

RGBD::RGBD(double weight_, Position position_, double bandwidth_, Camera camera_, Range range_) : Sensor(weight_,
           position_, bandwidth_), Camera(camera_), Range(range_)
{}