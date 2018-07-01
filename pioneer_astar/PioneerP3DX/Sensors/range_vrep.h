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
#include "../Knowledge/Data/sonar_output.h"

class RangeVREP : public Range<SonarOutput>
{
private:
	int handle;
	RobotModel &robot;
	Connection &connection;

public:
	int getHandle() const;

	RangeVREP(const std::string &name_, RobotModel &robot_);

	bool getData(SonarOutput &value) override;

	bool getData(SonarOutput &value, char &state);


};

#endif // PIONEER_SONAR_VREP_H_
