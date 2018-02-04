//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_CAMERA_H_
#define ARCH_CAMERA_H_

#include "sensor.h"
#include "../Util/fov.h"

class Camera: public Sensor
{
private:
    double resolution_x;
    double resolution_y;
    ColorSystem color_system;
    FOV fov;

public:
    Camera(double weight_, Position position_, double bandwidth_, double resolution_x_, double resolution_y_,
           double resolution_z_);
};

#endif //ARCH_CAMERA_H_
