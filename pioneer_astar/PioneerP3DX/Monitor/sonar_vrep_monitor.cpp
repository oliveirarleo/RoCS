//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "sonar_vrep_monitor.h"

SonarVREPMonitor::SonarVREPMonitor(Sensor<Position> &sensor_) : Monitor(sensor_)
{
}


void SonarVREPMonitor::publishLoop()
{
	while(publishing)
	{
//		publish();

		std::cout <<sensor.getName() << std::endl;

		using namespace std::chrono_literals;
		std::this_thread::sleep_for(1s);
	}
}

