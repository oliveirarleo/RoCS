//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_GYROSCOPE_H
#define ARCH_GYROSCOPE_H

#include "sensor.h"

class Gyroscope: public Sensor {
private:
    int number_of_axes;
    double output_range;
    double sensitivity;
    double bias;
    double measurement_range;

public:
    Gyroscope(int, double, double, double, double);
};


#endif // ARCH_GYROSCOPE_H
