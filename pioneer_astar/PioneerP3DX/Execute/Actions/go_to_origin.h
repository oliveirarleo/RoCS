//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_GO_TO_ORIGIN_H_
#define PIONEER_GO_TO_ORIGIN_H_


#include <Execute/action.h>
#include "../../Actuators/wheel_vrep.h"
#include "../../Knowledge/Data/euler_angle.h"
#include "../../Analyze/pass_orientation.h"

class GoToOrigin : public Action
{
private:
	RobotModel &robot;
	std::vector<WheelVREP *> &wheels;

	Position origin;
	PassOrientation& pass_orientation;

public:
	GoToOrigin(RobotModel &robot, std::vector<WheelVREP *> &wheels, PassOrientation& pass_orientation_);

	void act() override;

};


#endif // PIONEER_GO_TO_ORIGIN_H_
