//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_MONITOR_H_
#define ARCH_MONITOR_H_

#include <vector>
#include <ostream>

#include "Sensors/sensor.h"
#include "Util/publisher.h"

template<typename Value>
class Monitor : public Publisher
{
protected:
	Sensor sensor;

public:
	Monitor(Sensor &sensor_);

	friend std::ostream &operator<<(std::ostream &os, const Monitor &monitor)
	{
		os << " sensor: " << monitor.sensor << std::endl;
		return os;
	}
};

// CONSTRUCTOR
template<typename Value>
Monitor<Value>::Monitor(Sensor &sensor_): sensor(sensor_)
{
}

#endif // ARCH_MONITOR_H_
