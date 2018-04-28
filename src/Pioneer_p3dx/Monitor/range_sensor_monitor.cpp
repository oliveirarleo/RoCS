//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include "range_sensor_monitor.h"

RangeSensorMonitor::RangeSensorMonitor(const SonarVREP &sensor, const std::vector<MonitorObserver> &observers)
	: Monitor(sensor, observers)
{
}
