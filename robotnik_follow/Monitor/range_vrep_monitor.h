//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_RANGE_VREP_MONITOR_H
#define PIONEER_RANGE_VREP_MONITOR_H

#include <Monitor/monitor.h>
#include "../Sensors/range_vrep_sensor.h"

class RangeVREPMonitor : public Monitor<Position, Position>
{
public:
	explicit RangeVREPMonitor(Knowledge &knowledge);

	RangeVREPMonitor(Knowledge knowledge_, std::vector<RangeVREPSensor *> &sensors_);

	Position interpret(Position raw) override;
};


#endif //PIONEER_RANGE_VREP_MONITOR_H
