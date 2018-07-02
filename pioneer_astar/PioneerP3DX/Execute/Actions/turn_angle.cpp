//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#include <iostream>
#include "turn_angle.h"

void TurnAngle::act()
{
	std::cout << "Turning " << angle << std::endl;
	wheels[0]->setSpeed(base_speed*(angle-base_angle)/3.14);
	wheels[1]->setSpeed(-base_speed*(angle-base_angle)/3.14);
//	wheels[0]->setSpeed(1);
//	wheels[1]->setSpeed(-1);
}

TurnAngle::TurnAngle(RobotModel &robot, std::vector<WheelVREP *> &wheels) : robot(robot), wheels(wheels), angle(0), base_speed(1), Action(2), base_angle(0)
{
}

void TurnAngle::setAngle(double angle)
{
	TurnAngle::angle = angle;
}

TurnAngle::TurnAngle(RobotModel &robot, std::vector<WheelVREP *> &wheels, double angle, double base_angle_)
				: Action(20), robot(robot), wheels(wheels), angle(angle), base_angle(base_angle_),base_speed(1)
{
}
