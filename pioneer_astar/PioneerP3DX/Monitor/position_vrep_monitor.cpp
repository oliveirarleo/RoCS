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

void PositionVREPMonitor::publishLoop()
{
	while (publishing)
	{
		std::vector<Position> position{1};
		int i = 0;
		for (Sensor<Position> *s: sensors)
		{
			s->getData(position[i]);
//			std::cout<< "GetDAta" << position[i] << std::endl;
			i++;
		}
		publish(position);
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}

}
