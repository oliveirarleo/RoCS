//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "range_vrep_monitor.h"

RangeVREPMonitor::RangeVREPMonitor(Knowledge &knowledge):Monitor(knowledge)
{
}

RangeVREPMonitor::RangeVREPMonitor(Knowledge knowledge_, std::vector<RangeVREPSensor *> &sensors_)
	:Monitor(knowledge_, (std::vector<Sensor<Position> *> &) sensors_)
{
}

Position RangeVREPMonitor::interpret(Position raw)
{
//	std::cout << raw << "\n";
	return raw;
}
