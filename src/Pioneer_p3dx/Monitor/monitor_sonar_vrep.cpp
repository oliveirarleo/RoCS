//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "monitor_sonar_vrep.h"


MonitorSonarVrep::MonitorSonarVrep(SonarVREP &sensor_, std::vector<Observer *> &observers_) : Monitor(sensor_, observers_)
{

}

bool MonitorSonarVrep::getSonarData(Position& position, char** state)
{
	return sensor.getData(position, state);
}

std::ostream &operator<<(std::ostream &os, const MonitorSonarVrep &vrep)
{
	os << static_cast<const Monitor<SonarVREP> &>(vrep);
	return os;
}

SonarVREP MonitorSonarVrep::getSonar()
{
	return sensor;
}

