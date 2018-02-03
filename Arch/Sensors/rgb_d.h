//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_RGB_D_H_
#define ARCH_RGB_D_H_

#include "sensor.h"
#include "camera.h"
#include "range.h"

class RGBD: public Sensor
{
private:
    Camera camera;
    Range range_sensor;

public:
    RGBD(Camera, Range);
};

#endif //ARCH_RGB_D_H_
