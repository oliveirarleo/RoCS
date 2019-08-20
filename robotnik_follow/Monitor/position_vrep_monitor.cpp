//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "position_vrep_monitor.h"

PositionVREPMonitor::PositionVREPMonitor(Knowledge &knowledge):Monitor(knowledge)
{
}

PositionVREPMonitor::PositionVREPMonitor(Knowledge knowledge_, Sensor<Position> *sensor_)
	:Monitor(knowledge_, sensor_)
{
}

Position PositionVREPMonitor::interpret(Position raw)
{
//	std::cout << raw << "\n";
	return raw;
}
