//
// Created by leleco on 05/12/18.
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

