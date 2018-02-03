//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_CAMERA_H_
#define ARCH_CAMERA_H_

#include "sensor.h"

class Camera: public Sensor
{
private:
    double resolution_x;
    double resolution_y;
    ColorSystem color_system;
    FOV fov;
};

#endif //ARCH_CAMERA_H_
