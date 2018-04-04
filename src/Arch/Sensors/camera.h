//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_CAMERA_H_
#define ARCH_CAMERA_H_

#include "sensor.h"
#include "../Util/fov.h"

template <class T>
class Camera: public Sensor<T>
{
protected:
    double resolution_x;
    double resolution_y;
    ColorSystem color_system;
    FOV fov;

public:
    Camera(double weight_, Position position_, double bandwidth_, double resolution_x_, double resolution_y_,
           double resolution_z_):
            Sensor(weight_, position_, bandwidth_)
    {
        resolution_x = resolution_x_;
        resolution_y = resolution_y_;
        resolution_z = resolution_z_;

    }
};

#endif //ARCH_CAMERA_H_
