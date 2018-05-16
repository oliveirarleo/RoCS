//
// Created by kaiju on 15/05/18.
//

#ifndef PIONEER_WHEEL_VREP_H
#define PIONEER_WHEEL_VREP_H

#include "Actuators/rotary_motor.h"
#include "Knowledge/robot_model.h"
#include "../Connection/connection.h"


class WheelVREP : public RotaryMotor
{
private:
	RobotModel& robot;

	int handle;
	Connection& connection;
public:
//	WheelVREP();

	WheelVREP(std::string name_, RobotModel &robot_);

	WheelVREP(std::string name_, RobotModel &robot_, Connection &connection);

	void setName(std::string name_);

	void setSpeed(double speed);
};

#endif //PIONEER_WHEEL_VREP_H
