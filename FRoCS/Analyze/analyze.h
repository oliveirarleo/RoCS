//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_ANALYZE_H_
#define ARCH_ANALYZE_H_


#include <thread>
#include <Knowledge/knowledge.h>
#include <Util/observer.h>
#include <Util/publisher.h>

template<typename ObservedValue, typename PublishedValue>
class Analyze : public Observer<ObservedValue>, public Publisher<PublishedValue>
{
protected:
	Knowledge &knowledge;
	bool publishing;
	int waiting_time;
	std::thread *publish_thread;

public:

	explicit Analyze(Knowledge &knowledge_)
		:knowledge(knowledge_), publishing(true), waiting_time(50), publish_thread(nullptr)
	{
	}

	virtual ~Analyze()
	{
		publishing = false;
		std::this_thread::sleep_for(std::chrono::milliseconds(waiting_time));
		if (publish_thread && publish_thread->joinable())
			publish_thread->join();
	}

	void startThread()
	{
		publish_thread = new std::thread(&Analyze::publishLoop, this);
	}

	virtual PublishedValue mergeAndProcess(ObservedValue ov) = 0;

	void publishLoop()
	{
		while (publishing)
		{
			PublishedValue p = mergeAndProcess(this->observed_value);
			this->publish(p);
			std::this_thread::sleep_for(std::chrono::milliseconds(waiting_time));
		}
	}

};


#endif // ARCH_ANALYZE_H_
