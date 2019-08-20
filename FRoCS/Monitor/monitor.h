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

#include <Knowledge/knowledge.h>
#include "Sensors/sensor.h"
#include "Util/publisher.h"

template<typename RawData, typename Value>
class Monitor : public Publisher<std::vector<Value>>
{
protected:
	Knowledge &knowledge;
	std::vector<Sensor<RawData> *> sensors;
	bool publishing;
	int waiting_time;
	std::thread *publish_thread;

public:
	explicit Monitor(Knowledge &knowledge)
		:knowledge(knowledge), sensors(), publishing(true), waiting_time(50), publish_thread(nullptr)
	{
	}

	Monitor(Knowledge &knowledge, Sensor<RawData> *sensor_)
		:knowledge(knowledge), sensors(), publishing(true), waiting_time(50), publish_thread(nullptr)
	{
		sensors.emplace_back(sensor_);
	}

	Monitor(Knowledge &knowledge, std::vector<Sensor<RawData> *> &sensors_)
		:knowledge(knowledge), sensors(sensors_), publishing(true), waiting_time(50), publish_thread(nullptr)
	{
//		sensors.insert(sensors_);
	}

	~Monitor()
	{
		publishing = false;
		std::this_thread::sleep_for(std::chrono::milliseconds(waiting_time));
		if (publish_thread && publish_thread->joinable())
			publish_thread->join();
	}

	void insertSensor(Sensor<RawData> *sensor_)
	{
		sensors.emplace_back(sensor_);
	}

	void insertSensors(std::vector<Sensor<RawData> *> &sensors_)
	{
		sensors.emplace_back(sensors_);
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
