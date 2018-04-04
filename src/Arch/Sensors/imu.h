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

template <class T, class AccelerometerT, class GyroscopeT, class MagnetometerT>
class IMU: public Sensor
{
protected:
    Accelerometer<AccelerometerT> accelerometer;
    Gyroscope<GyroscopeT> gyroscope;
    Magnetometer<MagnetometerT> magnetometer;

public:
    IMU(Accelerometer<AccelerometerT> accelerometer_, Gyroscope<GyroscopeT> gyroscope_,
        Magnetometer<MagnetometerT> magnetometer_):
            Accelerometer(accelerometer_),
            Gyroscope(gyroscope_),
            Magnetometer(magnetometer_)
    {}
};

#endif //ARCH_IMU_H_
