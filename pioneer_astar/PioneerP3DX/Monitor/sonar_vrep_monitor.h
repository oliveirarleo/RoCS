//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_SONAR_VREP_MONITOR_H_
#define PIONEER_SONAR_VREP_MONITOR_H_

#include <Monitor/monitor.h>
#include <thread>

class SonarVREPMonitor: public Monitor<Position>
{
private:
	bool publishing = true;

public:
	SonarVREPMonitor(Sensor<Position> &sensor_);

	void publishLoop() override;

};


#endif // PIONEER_SONAR_VREP_MONITOR_H_
