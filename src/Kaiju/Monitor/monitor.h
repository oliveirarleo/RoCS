//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_MONITOR_H_
#define ARCH_MONITOR_H_

#include <vector>
#include "interpteter.h"
#include "../Sensors/sensor.h"
#include "monitor_publisher.h"
#include "../Analyze/monitor_observer.h"

template<class MonitorSensor>
class Monitor : public MonitorPublisher
{
private:
	std::vector<Interpreter> interpreters;
	MonitorSensor sensor;

public:
	Monitor(const MonitorSensor &sensor, const std::vector<Observer *> &observers)
	{
	}

	virtual void run() = 0;
};

#endif // ARCH_MONITOR_H_
