//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_MAGNETOMETER_H_
#define ARCH_MAGNETOMETER_H_

#include "sensor.h"

template <class T>
class Magnetometer: public Sensor<T> {
private:
    int number_of_axes;
    double output_range;
    double sensitivity;
    double bias;
    double measurement_range;

public:
    Magnetometer(double weight_, Position position_, double bandwidth_, int number_of_axes_, double output_range_,
                 double sensitivity_, double bias_, double measurement_range_):
            Sensor(weight_, position_, bandwidth_)
    {
        number_of_axes = number_of_axes_;
        output_range = output_range_;
        sensitivity = sensitivity_;
        bias = bias_;
        measurement_range = measurement_range_;
    }
};


#endif //ARCH_MAGNETOMETER_H_
