//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_MONITOR_H_
#define ARCH_MONITOR_H_

#include <vector>
#include <ostream>
#include <thread>

#include "Sensors/sensor.h"
#include "Util/publisher.h"

template<typename Value>
class Monitor : public Publisher<Value>
{
protected:
	Sensor<Value>& sensor;
	bool publishing;
	std::thread publish_thread;

public:
	Monitor(Sensor<Value> &sensor_);

	~Monitor();

	virtual void publishLoop() = 0;

	friend std::ostream &operator<<(std::ostream &os, const Monitor &monitor)
	{
		os << " sensor: " << monitor.sensor << std::endl;
		return os;
	}


};

// CONSTRUCTOR
template<typename Value>
Monitor<Value>::Monitor(Sensor<Value> &sensor_): sensor(sensor_), publishing(true), publish_thread(&Monitor::publishLoop, this)
{
}

// DESTRUCTOR
template<typename Value>
Monitor<Value>::~Monitor()
{
	publishing = false;
	if(publish_thread.joinable())
		publish_thread.join();
}

#endif // ARCH_MONITOR_H_
