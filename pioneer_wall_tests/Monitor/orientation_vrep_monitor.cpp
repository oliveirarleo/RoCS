//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "orientation_vrep_monitor.h"

OrientationVREPMonitor::OrientationVREPMonitor(Knowledge &knowledge)
	:Monitor(knowledge)
{
}


OrientationVREPMonitor::OrientationVREPMonitor(Knowledge knowledge_, Sensor<Orientation> *orientation_sensor)
	:Monitor(knowledge_, orientation_sensor)
{
}

Orientation OrientationVREPMonitor::interpret(Orientation raw)
{
//	std::cout << raw << "\n";
	return raw;
}

