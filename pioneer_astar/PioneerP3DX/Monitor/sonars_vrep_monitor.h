//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_SONAR_VREP_MONITOR_H_
#define PIONEER_SONAR_VREP_MONITOR_H_

#include <Monitor/monitor.h>
#include <thread>
#include "../Knowledge/sonar_output.h"
#include "../Sensors/range_vrep.h"

class SonarsVREPMonitor: public Monitor<SonarOutput>
{
public:
	SonarsVREPMonitor(std::vector<RangeVREP *> &sensors_);

	void publishLoop() override;

};


#endif // PIONEER_SONAR_VREP_MONITOR_H_
