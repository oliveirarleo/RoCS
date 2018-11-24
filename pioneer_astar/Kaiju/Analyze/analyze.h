//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_ANALYZE_H_
#define ARCH_ANALYZE_H_

#include <Knowledge/robot_model.h>
#include <thread>
#include "../Util/observer.h"
#include "../Util/publisher.h"

template<typename ObservedValue, typename PublishedValue>
class Analyze : public Observer<ObservedValue>, public Publisher<PublishedValue>
{
protected:
	RobotModel robot;
	bool publishing;
	int waiting_time;
	std::thread *publish_thread;
public:
	Analyze(const RobotModel &robot) : robot(robot), publishing(true), waiting_time(25)
	{
	}

	virtual ~Analyze()
	{
		publishing = false;
		if (publish_thread && publish_thread->joinable())
			publish_thread->join();
	}

	void startThread()
	{
		publish_thread = new std::thread(&Analyze::publishLoop, this);
	}

	void publishLoop()
	{
		while (publishing)
		{
			PublishedValue p = process(this->observed_value);
			this->publish(p);
			std::this_thread::sleep_for(std::chrono::milliseconds(waiting_time));
		}
	}

	virtual PublishedValue process(ObservedValue ov) = 0;

};


#endif // ARCH_ANALYZE_H_
