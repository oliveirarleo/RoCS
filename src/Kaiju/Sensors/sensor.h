//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ROCS_SENSOR_H_
#define ROCS_SENSOR_H_

#include <ostream>
#include "sensor_accessor.h"
#include "../Knowledge/position.h"

template<class T>
class Sensor : public SensorAccessor<T>
{
protected:
	double weight;
	Position position;
	double bandwidth;

public:
	Sensor(double weight_, Position position_, double bandwidth_) :
		weight(weight_), position(position_), bandwidth(bandwidth_)
	{
	}

	friend std::ostream &operator<<(std::ostream &os, const Sensor<T> &sensor)
	{
		os << "Weight: " << sensor.weight << " Position: " << sensor.position << " Bandwidth: "
			 << sensor.bandwidth << " ";
		return os;
	}
};


#endif // ROCS_SENSOR_H_
