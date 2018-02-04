//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "accelerometer.h"

Accelerometer::Accelerometer(double weight_, Position position_, double bandwidth_, int number_of_axes_,
                            double output_range_, double sensitivity_, double zero_g_offset_, double measurement_range_):
                            Sensor(weight_, position_, bandwidth_)
{
    number_of_axes = number_of_axes_;
    output_range = output_range_;
    sensitivity = sensitivity_;
    zero_g_offset = zero_g_offset_;
    measurement_range = measurement_range_;
}