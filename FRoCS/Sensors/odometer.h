//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_ODOMETER_H_
#define ARCH_ODOMETER_H_

#include "../Knowledge/tire.h"
#include "vector"
#include "sensor.h"

template<class T>
class Odometer : public Sensor<T>
{
protected:
	double scan_interval;
	double resolution;
	std::vector<Tire> tires;

public:
	Odometer(double weight_, Position position_, double bandwidth_, double scan_interval_, double resolution_,
	         std::vector<Tire> tires_):
		Sensor(weight_, position_, bandwidth_)
	{
		scan_interval = scan_interval_;
		resolution = resolution_;
		tires = tires_;
	}
};


#endif //ARCH_ODOMETER_H_
