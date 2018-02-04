//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "imu.h"

IMU::IMU(Accelerometer accelerometer_, Gyroscope gyroscope_, Magnetometer magnetometer_): Accelerometer(accelerometer_),
                                                                                          Gyroscope(gyroscope_),
                                                                                          Magnetometer(magnetometer_)
{}