//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_WHEEL_VREP_H_
#define PIONEER_WHEEL_VREP_H_

#include <Actuators/rotary_motor.h>
#include <Knowledge/robot_model.h>
#include "../Connection/connection.h"

class WheelVREP : public RotaryMotor
{
private:
	int handle;
	RobotModel &robot;
	Connection &connection;
public:
	WheelVREP(const std::string &name_, RobotModel &robot);

	void setName(std::string name_);

	void setSpeed(double speed);

};


#endif // PIONEER_WHEEL_VREP_H_
