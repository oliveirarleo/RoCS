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

template<class T>
class Monitor : public MonitorPublisher
{
private:
	std::vector<Interpreter> interpreters;
	Sensor<T> sensor;

public:
	virtual Monitor(const Sensor<T> &sensor, const std::vector<MonitorObserver> observers) = 0;

	virtual void run() = 0;
};

#endif // ARCH_MONITOR_H_
