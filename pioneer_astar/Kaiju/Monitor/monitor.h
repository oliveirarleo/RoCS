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
class Monitor : public Publisher<std::vector<Value>>
{
protected:
	std::vector<Sensor<Value> *> &sensors;
	bool publishing;
	std::thread *publish_thread;

public:
	Monitor(std::vector< Sensor<Value> * >& sensors_): sensors(sensors_), publishing(true)
	{

	}

	~Monitor()
	{
		publishing = false;
		if (publish_thread && publish_thread->joinable())
			publish_thread->join();
	}

	void startThread()
	{
		publish_thread = new std::thread(&Monitor::publishLoop, this);
	}

	virtual void publishLoop() = 0;

};


#endif // ARCH_MONITOR_H_
