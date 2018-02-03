//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_MAGNETOMETER_H_
#define ARCH_MAGNETOMETER_H_

#include "sensor.h"

class Magnetometer: public Sensor {
private:
    int number_of_axes;
    double output_range;
    double sensitivity;
    double bias;
    double measurement_range;

public:
    Magnetometer(int, double, double, double, double);
};


#endif //ARCH_MAGNETOMETER_H_
