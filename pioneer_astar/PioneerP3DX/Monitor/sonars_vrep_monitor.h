//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_SONAR_VREP_MONITOR_H_
#define PIONEER_SONAR_VREP_MONITOR_H_

#include <Monitor/monitor.h>
#include <thread>
#include "../Sensors/sonar_output.h"
#include "../Sensors/sonar_vrep.h"

class SonarsVREPMonitor: public Monitor<SonarOutput>
{
public:
	SonarsVREPMonitor(std::vector<SonarVREP *> &sensors_);

	void publishLoop() override;

};


#endif // PIONEER_SONAR_VREP_MONITOR_H_
