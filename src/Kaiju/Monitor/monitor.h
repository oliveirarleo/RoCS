//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_MONITOR_H_
#define ARCH_MONITOR_H_

#include <vector>
#include <ostream>
#include "interpteter.h"
#include "../Sensors/sensor.h"
#include "monitor_publisher.h"
#include "../Analyze/monitor_observer.h"

template<class MonitorSensor>
class Monitor : public MonitorPublisher
{
protected:
	std::vector<Interpreter> interpreters;
	MonitorSensor sensor;

public:
	Monitor(MonitorSensor &sensor_, std::vector<Observer *> &observers_)
		: MonitorPublisher(observers_), sensor(sensor_)
	{
	}

//	virtual void run() = 0;
	friend std::ostream &operator<<(std::ostream &os, const Monitor &monitor)
	{
		os << " sensor: " << monitor.sensor << std::endl;
		return os;
	}
};

#endif // ARCH_MONITOR_H_
