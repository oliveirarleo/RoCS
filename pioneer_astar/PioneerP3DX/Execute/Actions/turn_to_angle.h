//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_TURN_TO_ORIGIN_H_
#define PIONEER_TURN_TO_ORIGIN_H_


#include <Execute/action.h>
#include <Knowledge/robot_model.h>
#include "../../Actuators/wheel_vrep.h"
#include "../../Knowledge/Data/euler_angle.h"
#include "../../Analyze/pass_orientation.h"

class TurnToAngle: Action
{
private:
	RobotModel& robot;
	std::vector<WheelVREP * >& wheels;

	PassOrientation& pass_orientation;

public:

	TurnToAngle(double value_, RobotModel &robot, std::vector<WheelVREP *> &wheels, PassOrientation& pass_orientation_);

	void act() override;

};


#endif // PIONEER_TURN_TO_ORIGIN_H_
