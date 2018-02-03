//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ROCS_SENSOR_H_
#define ROCS_SENSOR_H_

#include "sensor_accessor.h"
#include "../Util/position.h"

class Sensor: public SensorAccessor
{
private:
    double weight;
    Position position;
    double bandwidth;

public:
    Sensor(double weight_, Position_, double bandwidth_);
};


#endif // ROCS_SENSOR_H_
