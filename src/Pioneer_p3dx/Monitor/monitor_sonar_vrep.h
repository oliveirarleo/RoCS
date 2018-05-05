//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_MONITOR_SONAR_VREP_H_
#define PIONEER_MONITOR_SONAR_VREP_H_

#include <ostream>
#include "Monitor/monitor.h"
#include "../Sensors/sonar_vrep.h"

class MonitorSonarVrep : public Monitor<SonarVREP>
{
public:
	MonitorSonarVrep(SonarVREP &sensor_, std::vector<Observer *> &observers_);

	bool getSonarData(Position& position, char& state);

	friend std::ostream &operator<<(std::ostream &os, const MonitorSonarVrep &vrep);

	SonarVREP getSonar();


};


#endif // PIONEER_MONITOR_SONAR_VREP_H_
