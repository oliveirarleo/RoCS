//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_POSITION_VREP_MONITOR_H
#define PIONEER_POSITION_VREP_MONITOR_H


#include <Util/position.h>
#include <Monitor/monitor.h>

class PositionVREPMonitor : public Monitor<Position, Position>
{
public:
	explicit PositionVREPMonitor(Knowledge &knowledge);

	PositionVREPMonitor(Knowledge knowledge_, Sensor<Position> *sensor_);

	Position interpret(Position raw) override;
};


#endif //PIONEER_POSITION_VREP_MONITOR_H
