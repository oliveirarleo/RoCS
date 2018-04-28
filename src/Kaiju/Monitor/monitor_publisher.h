//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ARCH_MONITOR_PUBLISHER_H_
#define ARCH_MONITOR_PUBLISHER_H_

#include <vector>
#include "../Util/publisher.h"

class MonitorPublisher : public Publisher
{
public:
	explicit MonitorPublisher(const std::vector<Observer *> &observers) : Publisher(observers)
	{
	}
};


#endif // ARCH_MONITOR_PUBLISHER_H_
