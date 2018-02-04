//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "range.h"

Range::Range(double weight_, Position position_, double bandwidth_, double max_range_, double resolution_,
             double fov_angle_, double beam_angle_, double scan_interval_) : Sensor(weight_, position_, bandwidth_)
{
    max_range = max_range_;
    resolution = resolution_;
    fov_angle = fov_angle_;
    beam_angle = beam_angle_;
    scan_interval = scan_interval_;
}