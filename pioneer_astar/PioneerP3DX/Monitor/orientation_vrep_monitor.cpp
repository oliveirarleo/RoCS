//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "orientation_vrep_monitor.h"


OrientationVREPMonitor::OrientationVREPMonitor(std::vector<OrientationVREPSensor *> &sensors_) : Monitor(
				(std::vector<Sensor<EulerAngle> *> &) sensors_)
{
}


EulerAngle OrientationVREPMonitor::interpret(EulerAngle raw)
{
	return raw;
}
