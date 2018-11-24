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

template<typename RawData, typename Value>
class Monitor : public Publisher<std::vector<Value>>
{
protected:
	std::vector<Sensor<RawData> *> &sensors;
	bool publishing;
	int waiting_time;
	std::thread *publish_thread;

public:
	Monitor(std::vector<Sensor<Value> *> &sensors_) : sensors(sensors_), publishing(true), waiting_time(50)
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

	virtual Value interpret(RawData raw) = 0;

	virtual void publishLoop()
	{
		while (publishing)
		{
			std::vector<Value> values{sensors.size()};
			int i = 0;
			for (Sensor<RawData> *s: sensors)
			{
				RawData r;
				s->getData(r);
				values[i] = interpret(r);
				i++;
			}
			this->publish(values);
			std::this_thread::sleep_for(std::chrono::milliseconds(waiting_time));
		}
	};

};


#endif // ARCH_MONITOR_H_
