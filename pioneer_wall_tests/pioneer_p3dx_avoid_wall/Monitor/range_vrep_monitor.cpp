//
// Created by leleco on 05/12/18.
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
