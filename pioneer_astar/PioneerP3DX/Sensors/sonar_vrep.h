//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_SONAR_VREP_H_
#define PIONEER_SONAR_VREP_H_

#include <Sensors/range.h>
#include <Knowledge/robot_model.h>
#include "../Connection/connection.h"

class SonarVREP: public Range<Position>
{
private:
	int handle;
	RobotModel& robot;
	Connection& connection;

public:
	SonarVREP(const std::string &name_, RobotModel& robot_);

	bool getData(Position &value) override;



};

#endif // PIONEER_SONAR_VREP_H_
