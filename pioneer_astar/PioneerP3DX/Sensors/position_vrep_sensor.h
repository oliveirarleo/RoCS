//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_POSITION_SENSOR_H_
#define PIONEER_POSITION_SENSOR_H_


#include <Knowledge/position.h>
#include <Sensors/sensor.h>
#include <Knowledge/robot_model.h>
#include "../Connection/connection.h"

class PositionVREPSensor : public Sensor<Position>
{
public:
	RobotModel &robot;

	PositionVREPSensor(const std::string &name_, RobotModel &robot);

	bool getData(Position &value) override;

	Connection &connection;
	int handle;
};


#endif // PIONEER_POSITION_SENSOR_H_
