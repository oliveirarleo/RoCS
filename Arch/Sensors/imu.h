//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_IMU_H_
#define ARCH_IMU_H_

#include "sensor.h"
#include "accelerometer.h"
#include "magnetometer.h"
#include "gyroscope.h"

class IMU: public Sensor
{
private:
    Accelerometer accelerometer;
    Gyroscope gyroscope;
    Magnetometer magnetometer;

public:
    IMU(Accelerometer, Gyroscope, Magnetometer);
};

#endif //ARCH_IMU_H_
