//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ROCS_SONARVREPPUBLISHER_H_
#define ROCS_SONARVREPPUBLISHER_H_

#include "Monitor/monitor_publisher.h"

class SonarVREPPublisher : public MonitorPublisher
{
public:
	SonarVREPPublisher(const std::vector<MonitorObserver> &observers);

	void attach(Observer observer) override;
};


#endif // ROCS_SONARVREPPUBLISHER_H_
