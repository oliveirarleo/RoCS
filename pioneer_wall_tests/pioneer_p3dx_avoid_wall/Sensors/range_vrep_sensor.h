//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_SONAR_VREP_H_
#define PIONEER_SONAR_VREP_H_

#include <Sensors/range.h>
#include <Knowledge/robot_model.h>
#include <Util/position.h>
#include "../Connection/connection.h"

class RangeVREPSensor : public Range<Position>
{
private:
	int handle;
	RobotModel &robot;
	Connection &connection;

public:
	int getHandle() const;

	RangeVREPSensor(const std::string &name_, RobotModel &robot_);

	bool getData(Position &value);



};

#endif // PIONEER_SONAR_VREP_H_
