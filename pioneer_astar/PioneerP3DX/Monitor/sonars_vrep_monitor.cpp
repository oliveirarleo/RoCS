//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <remoteApi/extApiPlatform.h>
#include "sonars_vrep_monitor.h"
#include "../Sensors/range_vrep.h"

SonarsVREPMonitor::SonarsVREPMonitor(std::vector<RangeVREP *>& sensors_) : Monitor((std::vector< Sensor<SonarOutput> * > &)sensors_)
{
}


void SonarsVREPMonitor::publishLoop()
{
	while(publishing)
	{
		std::vector<SonarOutput >positions{16};
		int i = 0;
		for(Sensor<SonarOutput>* s: sensors)
		{
			s->getData(positions[i]);
			i++;
		}
		publish(positions);
		extApi_sleepMs(50);
	}
}