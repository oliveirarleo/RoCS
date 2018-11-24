//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <remoteApi/extApiPlatform.h>
#include "range_vrep_monitor.h"

RangeVREPMonitor::RangeVREPMonitor(std::vector<RangeVREPSensor *> &sensors_) : Monitor(
				(std::vector<Sensor<RangeOutput> *> &) sensors_)
{
}


void RangeVREPMonitor::publishLoop()
{
	while (publishing)
	{
		std::vector<RangeOutput> positions{16};
		int i = 0;
		for (Sensor<RangeOutput> *s: sensors)
		{
			s->getData(positions[i]);
			i++;
		}
		publish(positions);
		extApi_sleepMs(50);
	}
}

RangeOutput RangeVREPMonitor::interpret(RangeOutput raw) {
	return RangeOutput();
}
