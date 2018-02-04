//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "camera.h"

Camera::Camera(double weight_, Position position_, double bandwidth_, double resolution_x_, double resolution_y_,
               double resolution_z_): Sensor(weight_, position_, bandwidth_)
{
    resolution_x = resolution_x_;
    resolution_y = resolution_y_;
    resolution_z = resolution_z_;

}