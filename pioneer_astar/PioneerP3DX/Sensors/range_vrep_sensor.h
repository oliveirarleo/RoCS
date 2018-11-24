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
#include "../Knowledge/Data/range_output.h"

class RangeVREPSensor : public Range<RangeOutput>
{
private:
	int handle;
	RobotModel &robot;
	Connection &connection;

public:
	int getHandle() const;

	RangeVREPSensor(const std::string &name_, RobotModel &robot_);

	bool getData(RangeOutput &value) override;

	bool getData(RangeOutput &value, char &state);


};

#endif // PIONEER_SONAR_VREP_H_
