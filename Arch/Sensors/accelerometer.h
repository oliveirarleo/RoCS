//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_ACCELEROMETER_H_
#define ARCH_ACCELEROMETER_H_

#include "sensor.h"

class Accelerometer: public Sensor
{
private:
    int number_of_axes;
    double output_range;
    double sensitivity;
    double zero_g_offset;
    double measurement_range;

public:
    Accelerometer(double weight_, Position position_, double bandwidth_, int number_of_axes_, double output_range_,
                  double sensitivity_, double zero_g_offset_, double measurement_range_);
};

#endif //ARCH_ACCELEROMETER_H_
