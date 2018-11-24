//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "position_vrep_monitor.h"

PositionVREPMonitor::PositionVREPMonitor(std::vector<PositionVREPSensor *> &sensors_) : Monitor(
				(std::vector<Sensor<Position> *> &) sensors_)
{
}

Position PositionVREPMonitor::interpret(Position raw)
{
	return raw;
}
