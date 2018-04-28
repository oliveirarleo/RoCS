//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef RANGE_SENSOR_MONITOR_H_
#define RANGE_SENSOR_MONITOR_H_

#include "Monitor/monitor.h"
#include "sonar_vrep_publisher.h"
#include "../Sensors/sonar_vrep.h"

class RangeSensorMonitor : public Monitor<SonarVREP>
{
public:
	RangeSensorMonitor(const SonarVREP &sensor, const std::vector<MonitorObserver> &observers);

};


#endif // RANGE_SENSOR_MONITOR_H_
