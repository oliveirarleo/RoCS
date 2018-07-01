//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "orientation_vrep_monitor.h"

void OrientationVREPMonitor::publishLoop()
{
	while(publishing)
	{
		std::vector<EulerAngle > angle{1};
		int i = 0;
		for(Sensor<EulerAngle>* s: sensors)
		{
			s->getData(angle[i]);
			i++;
		}
		publish(angle);
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}

}

OrientationVREPMonitor::OrientationVREPMonitor(std::vector< OrientationSensor *> &sensors_) : Monitor((std::vector< Sensor<EulerAngle> * > &)sensors_)
{
}
