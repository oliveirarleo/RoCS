//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_TURN_ANGLE_H_
#define PIONEER_TURN_ANGLE_H_


#include <Execute/action.h>
#include "../../Actuators/wheel_vrep.h"

class TurnAngle: public Action
{
private:
	RobotModel &robot;
	std::vector<WheelVREP *> &wheels;

	double angle;
	double base_speed;

public:
	void setAngle(double angle);

public:
	TurnAngle(RobotModel &robot, std::vector<WheelVREP *> &wheels);
	void act() override;

};


#endif // PIONEER_TURN_ANGLE_H_
