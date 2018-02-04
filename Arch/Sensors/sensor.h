//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ROCS_SENSOR_H_
#define ROCS_SENSOR_H_

#include <ostream>
#include "sensor_accessor.h"
#include "../Util/position.h"

class Sensor: public SensorAccessor<double>
{
private:
    double weight;
    Position position;
    double bandwidth;

public:
    Sensor(double weight_, Position position_, double bandwidth_);

    double getWeight() const;

    const Position &getPosition() const;

    double getBandwidth() const;

    friend std::ostream &operator<<(std::ostream &os, const Sensor &sensor);
};


#endif // ROCS_SENSOR_H_
