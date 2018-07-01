//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_POSITION_VREP_MONITOR_H_
#define PIONEER_POSITION_VREP_MONITOR_H_


#include <Knowledge/position.h>
#include <Monitor/monitor.h>
#include "../Sensors/position_vrep_sensor.h"

class PositionVREPMonitor : public Monitor<Position>
{
public:
	PositionVREPMonitor(std::vector<PositionVREPSensor *> &sensors_);

	void publishLoop() override;

};


#endif // PIONEER_POSITION_VREP_MONITOR_H_
