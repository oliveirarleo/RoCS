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

class GoToOrigin : public Action
{
private:
	RobotModel &robot;
	std::vector<WheelVREP *> &wheels;

	Position origin;
	Position position;
	EulerAngle angle;

public:
	GoToOrigin(RobotModel &robot, std::vector<WheelVREP *> &wheels, const Position &position, const EulerAngle &angle);

	void act() override;

};


#endif // PIONEER_GO_TO_ORIGIN_H_
