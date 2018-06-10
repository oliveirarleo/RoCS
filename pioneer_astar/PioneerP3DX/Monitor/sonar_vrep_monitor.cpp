//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <remoteApi/extApiPlatform.h>
#include "sonar_vrep_monitor.h"

SonarVREPMonitor::SonarVREPMonitor(Sensor<SonarOutput> &sensor_) : Monitor(sensor_)
{
}


void SonarVREPMonitor::publishLoop()
{
	while(publishing)
	{
		SonarOutput position{};
		sensor.getData(position);
		publish(position);
		extApi_sleepMs(50);
	}
}